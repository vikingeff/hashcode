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
				std::cout << "\033[1;31;40mx\033[0m ";
			else
				std::cout << "\033[1;32;40m" << map[i][j] << "\033[0m ";
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
			//std::cout<<"unavailable slot number " << index << std::endl << " x: "<< x << " y : " << y << std::endl;
			(*tab_sl)[x][y]=-1;
			//(void)tab_sl;
		}
		else// (index > dc->nb_na && index < dc->nb_srv+dc->nb_na)
		{
			index++;
			stream >> x >> y;
			//std::cout<<"srv number " << index - dc->nb_na << std::endl << " size: "<< x << " capacity : " << y << std::endl;
			tab[index - dc->nb_na-1]= new Server (x, y, index - dc->nb_na-1);
			//break;
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
			if (tab[j]->medium<tab[j+1]->medium)
			{
				buffer = new Server (*tab[j]);
				tab[j]=tab[j+1];
				tab[j+1]=buffer;
			}
		}
	}
}

void put_srv(Datacenter *dc, Server **tab, std::vector<std::vector<int> > *tab_sl)
{
	int			index = -1;
	bool		free=false;

	for (int i=0; i< dc->nb_srv; i++)
	{
		if (index<dc->nb_grp)
			index++;
		else
			index=0;
		tab[i]->grp=index;
		for (int j=0; j<dc->rows; j++)
		{
			for (int k=0; k<dc->r_size-tab[i]->size; k++)
			{
				for (int l=k; l<tab[i]->size; l++)
				{
					if ((*tab_sl)[l][j]!=0)
						break;
					else
						free=true;
				}
				if (free)
				{
					for (int l=k; l<tab[i]->size; l++)
						(*tab_sl)[l][j]=i;
					tab[i]->used=true;
				}
			}
			if (tab[i]->used)
				break;
		}
	}
}

int		main(int argc, char **argv)
{
	//std::vector<Server> Vserver;
	//Server		*buff;
	//int				**slots;
	std::vector<std::vector<int>> slots;
	Server			*list[625];
	Datacenter		*bigD;
	int 			size;

	if (argc == 2)
	{
		// slots = new int *[10];
		// for(int i = 0; i <10; i++)
		// 	slots[i] = new int[10];
		slots = create_vector(SIZEX, SIZEY);
		bigD = new Datacenter();
		std::cout<<"hello world"<<std::endl;
		size = parser(argv[1], list, bigD, &slots);
		std::cout<<"we have "<< bigD->getNbDatacenter() << " datacenter with : "<<size<<" Servers"<<std::endl;
		//bigD->printdc();
		// std::cout<<"srv number 0 " << std::endl << " size: "<< list [0]->size << " capacity : " << list [0]->cap << std::endl;
		// std::cout<<"srv number " << size << std::endl << " size: "<< list [size-1]->size << " capacity : " << list [size-1]->cap << std::endl;
		// std::cout<<std::endl;
		std::cout<<*bigD;
		for (int i=0; i< size; i++)
			list [i]->medium = (float)list [i]->cap/list [i]->size;
		// std::cout<<Vserver.size()<<std::endl;
		// std::cout<<med_size(&Vserver)<<std::endl;
		// std::cout<<med_cap(&Vserver)<<std::endl;
		//printmap(bigD, slots);
		order(bigD, list);
		// for (int i=0; i< size; i++)
		// 	std::cout<<"srv number " << list [i]->index << std::endl << " size: "<< list [i]->size << " capacity : " << list [i]->cap << " med : " << list [i]->medium << std::endl;
		put_srv(bigD, list, &slots);
		for (int i=0; i<625; i++)
			std::cout<<*list[i]<<std::endl;
		//printmap(bigD, slots);
	}
	else
		std::cout<<"If you give me no file i'm useless try again"<<std::endl;
	
	return (0);
}
