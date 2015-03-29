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

void		printmap(Datacenter *dc, std::vector<std::vector< int > >map, Server **tab)
{
	int			buffer=0;

	for ( std::vector<std::vector< int > >::size_type i = 0; i < map.size(); i++ )
	{
		for ( std::vector<int>::size_type j = 0; j < map[i].size(); j++ )
		{
			buffer = map[i][j];

			if (buffer == 625)
				buffer=0;
			if (buffer == -1)
				std::cout << "\033[0;30;40mX\033[0m ";
			else 
			{
				switch	(tab[buffer]->grp)
				{
					case 0:std::cout << "\033[1;31;40m" << buffer << "\033[0m ";
						break;
					// case 1:std::cout << "\033[1;33;40m" << buffer << "\033[0m ";
					// 	break;
					// case 2:std::cout << "\033[1;34;40m" << buffer << "\033[0m ";
					// 	break;
					// case 3:std::cout << "\033[1;35;40m" << buffer << "\033[0m ";
					// 	break;
					// case 4:std::cout << "\033[1;36;40m" << buffer << "\033[0m ";
					// 	break;
					// case 5:std::cout << "\033[1;37;40m" << buffer << "\033[0m ";
					// 	break;
					// case 6:std::cout << "\033[0;31;40m" << buffer << "\033[0m ";
					// 	break;
					// case 7:std::cout << "\033[0;32;40m" << buffer << "\033[0m ";
					// 	break;
					// case 8:std::cout << "\033[0;33;40m" << buffer << "\033[0m ";
					// 	break;
					// case 9:std::cout << "\033[0;34;40m" << buffer << "\033[0m ";
					// 	break;
					// case 10:std::cout << "\033[1;31;40m" << buffer << "\033[0m ";
					// 	break;
					// case 11:std::cout << "\033[1;33;40m" << buffer << "\033[0m ";
					// 	break;
					// case 12:std::cout << "\033[1;34;40m" << buffer << "\033[0m ";
					// 	break;
					// case 13:std::cout << "\033[1;35;40m" << buffer << "\033[0m ";
					// 	break;
					// case 14:std::cout << "\033[1;36;40m" << buffer << "\033[0m ";
					// 	break;
					// case 15:std::cout << "\033[1;37;40m" << buffer << "\033[0m ";
					// 	break;
					// case 16:std::cout << "\033[0;31;40m" << buffer << "\033[0m ";
					// 	break;
					// case 17:std::cout << "\033[0;32;40m" << buffer << "\033[0m ";
					// 	break;
					// case 18:std::cout << "\033[0;33;40m" << buffer << "\033[0m ";
					// 	break;
					// case 19:std::cout << "\033[0;34;40m" << buffer << "\033[0m ";
					// 	break;
					// case 20:std::cout << "\033[1;31;40m" << buffer << "\033[0m ";
					// 	break;
					// case 21:std::cout << "\033[1;33;40m" << buffer << "\033[0m ";
					// 	break;
					// case 22:std::cout << "\033[1;34;40m" << buffer << "\033[0m ";
					// 	break;
					// case 23:std::cout << "\033[1;35;40m" << buffer << "\033[0m ";
					// 	break;
					// case 24:std::cout << "\033[1;36;40m" << buffer << "\033[0m ";
					// 	break;
					// case 25:std::cout << "\033[1;37;40m" << buffer << "\033[0m ";
					// 	break;
					// case 26:std::cout << "\033[0;31;40m" << buffer << "\033[0m ";
					// 	break;
					// case 27:std::cout << "\033[0;32;40m" << buffer << "\033[0m ";
					// 	break;
					// case 28:std::cout << "\033[0;33;40m" << buffer << "\033[0m ";
					// 	break;
					// case 29:std::cout << "\033[0;34;40m" << buffer << "\033[0m ";
					// 	break;
					// case 30:std::cout << "\033[1;31;40m" << buffer << "\033[0m ";
					// 	break;
					// case 31:std::cout << "\033[1;33;40m" << buffer << "\033[0m ";
					// 	break;
					// case 32:std::cout << "\033[1;34;40m" << buffer << "\033[0m ";
					// 	break;
					// case 33:std::cout << "\033[1;35;40m" << buffer << "\033[0m ";
					// 	break;
					// case 34:std::cout << "\033[1;36;40m" << buffer << "\033[0m ";
					// 	break;
					// case 35:std::cout << "\033[1;37;40m" << buffer << "\033[0m ";
					// 	break;
					// case 36:std::cout << "\033[0;31;40m" << buffer << "\033[0m ";
					// 	break;
					// case 37:std::cout << "\033[0;32;40m" << buffer << "\033[0m ";
					// 	break;
					// case 38:std::cout << "\033[0;33;40m" << buffer << "\033[0m ";
					// 	break;
					// case 39:std::cout << "\033[0;34;40m" << buffer << "\033[0m ";
					// 	break;
					// case 40:std::cout << "\033[1;31;40m" << buffer << "\033[0m ";
					// 	break;
					// case 41:std::cout << "\033[1;33;40m" << buffer << "\033[0m ";
					// 	break;
					// case 42:std::cout << "\033[1;34;40m" << buffer << "\033[0m ";
					// 	break;
					// case 43:std::cout << "\033[1;35;40m" << buffer << "\033[0m ";
					// 	break;
					// case 44:std::cout << "\033[1;36;40m" << buffer << "\033[0m ";
					// 	break;
					default:std::cout << "\033[1;32;40m" << buffer << "\033[0m ";
						break;
				}
			}
		}
		std::cout << std::endl << std::endl;
	}
	(void)dc;
	(void)tab;
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

int		calc_potential(int group, Server **tab)
{
	int		pot=0;
	int		loop=-1;
	int		*bkp;
	int 	val=0;

	std::cout << "\033[1;32;40m" << "group : "<<group<< "\033[0m "<<std::endl;
	bkp = new int[625/45];
	for (int i=0; i<625; i++)
	{
		if (tab[i]->grp==group && tab[i]->used)
		{
			bkp[++loop]=tab[i]->cap;
			std::cout<<tab[i]->index<<" : ";
			std::cout<<bkp[loop]<<std::endl;
		}
	}
	int max = bkp[0];
	for (int i=0; i<loop; i++)
	{
		if (bkp[i]>max)
			max = bkp[i];
		val+=bkp[i];
		//std::cout<<bkp[i]<<std::endl;
	}
	std::cout<<"max : "<<max<<std::endl;
	std::cout<<"total : "<<val<<std::endl;
	std::cout<<"garanty : "<<val-max<<std::endl;
	return (pot);
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
		//printmap(bigD, slots, list);
		reorder(bigD, list);
		// for (int i=0; i<625; i++)
		// 	std::cout<<*list[i]<<std::endl;
		//makefile(list);
		printmap(bigD, slots, list);
		//for (int i=0; i<45; i++)
			calc_potential(15, list);
			calc_potential(30, list);
			calc_potential(37, list);
			calc_potential(35, list);
			calc_potential(36, list);
			calc_potential(38, list);
			
	}
	else
		std::cout<<"If you give me no file i'm useless try again"<<std::endl;
	
	return (0);
}
