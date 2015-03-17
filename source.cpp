#include <vector>
#include <fstream>
#include <sstream>
#include <Server.class.hpp>
#include <Datacenter.class.hpp>

#define SIZEX 16
#define SIZEY 100

std::vector<std::vector<int> > create_vector(int nb_rg, int size_rg)
{
	std::vector<std::vector<int> > vec;

	for (int i = 0; i < nb_rg; ++i)
		vec.push_back(std::vector<int>(size_rg, 0));
	return vec;
}

void		printmap(Datacenter *dc, std::vector<std::vector< int > >map)
{
	for ( std::vector<std::vector< int > >::size_type i = 0; i < map.size(); i++ )
	{
		for ( std::vector<int>::size_type j = 0; j < map[i].size(); j++ )
		{
			if (map[i][j] == -1)
				std::cout << "\033[1;31;40mx\033[0m";
			else
				std::cout << "\033[1;32;40m" << map[i][j] << "\033[0m";
		}
		std::cout << std::endl;
	}
	(void)dc;
}

int			parser(char *file, Server **tab, Datacenter *dc, std::vector<std::vector<int> > *tab_sl)
{
	bool			define = false;
	int				x = 0;
	int				y = 0;
	int				index = 0;
	std::string 	str;
	std::ifstream	inputfile(file);

	if (!inputfile)
	{
		std::cout << "FOCK " << std::endl;
		return -1;
	}
	while (getline(inputfile, str))
	{
		std::stringstream stream(str);
		if (!define)
		{
			stream>>dc->rows>>dc->r_size>>dc->nb_na>>dc->nb_grp>>dc->nb_srv;
			define = true;			
		}
		else if (index<dc->nb_na)
		{
			index++;
			stream >> x >> y;
			(*tab_sl)[x][y]=-1;
		}
		else
		{
			index++;
			stream >> x >> y;
			tab[index - dc->nb_na-1]= new Server (x, y, index - dc->nb_na-1);
		}
	}
	return (index - dc->nb_na);
}

void order(Datacenter *dc, Server **tab)
{
	Server		*buffer;

	for (int i=0; i< dc->nb_srv-1; i++)
	{
		for (int j=0; j<dc->nb_srv-1; j++)
		{
			if (tab[j]->cap<tab[j+1]->cap)
			{
				buffer = new Server (*tab[j]);
				tab[j]=tab[j+1];
				tab[j+1]=buffer;
			}
		}
	}
}

void reorder(Datacenter *dc, Server **tab)
{
	Server		*buffer;

	for (int i=0; i< dc->nb_srv-1; i++)
	{
		for (int j=0; j<dc->nb_srv-1; j++)
		{
			if (tab[j]->index>tab[j+1]->index)
			{
				buffer = new Server (*tab[j]);
				tab[j]=tab[j+1];
				tab[j+1]=buffer;
			}
		}
	}
}

int	check_s(std::vector<std::vector<int> > *tab_sl, int row, int size)
{
	int loop = 0;

	for (int i=0; i<SIZEY; i++)
	{
		if ((*tab_sl)[row][i]<0)
			loop=0;
		else if ((*tab_sl)[row][i]==0)
			loop++;
		else
		{
			i=i+loop;
			loop=0;
		}
		if (loop==size)
			return (i+1-size);
	}
	return (-1);
}

void put_srv(Datacenter *dc, Server **tab, std::vector<std::vector<int> > *tab_sl)
{
	int			index = -1;
	int			fsize=-1;
	bool		full=false;

	for (int i=0; i< 625; i++)
	{
		if (index<dc->nb_grp-1)
			index++;
		else
			index=0;
		tab[i]->grp=index;
		for (int j=0; j<dc->rows; j++)
		{
			for (int k=0; k<dc->r_size-tab[i]->size; k++)
			{
				fsize=check_s(tab_sl, j, tab[i]->size);
				if (fsize==-1)
				{
					full=true;
					break;
				}
				else
				{
					if (fsize>=0)
					{
						for (int m=fsize; m<fsize+tab[i]->size; m++)
						{
							if (tab[i]->index != 0)
								(*tab_sl)[j][m]=tab[i]->index;
							else
								(*tab_sl)[j][m]=625;
						}
						tab[i]->used=true;
						tab[i]->row=j;
						tab[i]->location=fsize;
						k=k+fsize;
						break;
					}
				}
				fsize=-1;
			}
			if (full)
			{
				full=false;
				continue;
			}
			else if (tab[i]->used)
				break;
		}
		if (tab[i]->used)
			continue;
	}
}

void makefile(Server **tab)
{
	std::ofstream	outfile("output");
	std::string		txt;

	for (int i=0; i<625; i++)
	{
		if (tab[i]->used)
		{
			txt.append(std::to_string(tab[i]->row));
			txt.append(" ");
			txt.append(std::to_string(tab[i]->location));
			txt.append(" ");
			txt.append(std::to_string(tab[i]->grp));
			txt.append("\n");
		}
		else
			txt.append("x\n");
		outfile << txt;
		txt="";
	}
	outfile.close();
}

int		main(int argc, char **argv)
{
	std::vector<std::vector<int>> slots;
	Server			*list[625];
	Datacenter		*bigD;
	int 			size;

	if (argc == 2)
	{
		slots = create_vector(SIZEX, SIZEY);
		bigD = new Datacenter();
		std::cout<<"hello world"<<std::endl;
		size = parser(argv[1], list, bigD, &slots);
		std::cout<<"we have "<< bigD->getNbDatacenter() << " datacenter with : "<<size<<" Servers"<<std::endl;
		std::cout<<*bigD;
		for (int i=0; i< size; i++)
			list [i]->medium = (float)list [i]->cap/list [i]->size;
		order(bigD, list);
		// for (int i=0; i< size; i++)
		// 	std::cout<<"srv number " << list [i]->index << std::endl << " size: "<< list [i]->size << " capacity : " << list [i]->cap << " med : " << list [i]->medium << std::endl;
		put_srv(bigD, list, &slots);
		// for (int i=0; i<625; i++)
		// 	std::cout<<*list[i]<<std::endl;
		printmap(bigD, slots);
		reorder(bigD, list);
		// for (int i=0; i<625; i++)
		// 	std::cout<<*list[i]<<std::endl;
		makefile(list);
	}
	else
		std::cout<<"If you give me no file i'm useless try again"<<std::endl;
	
	return (0);
}
