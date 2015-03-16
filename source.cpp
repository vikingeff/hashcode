#include <vector>
#include <fstream>
#include <sstream>
#include <Server.class.hpp>
#include <Datacenter.class.hpp>

int			parser(char *file, Server **tab, Datacenter *dc)
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
			std::cout<<"unavailable slot number " << index << std::endl << " x: "<< x << " y : " << y << std::endl;
		}
		else// (index > dc->nb_na && index < dc->nb_srv+dc->nb_na)
		{
			index++;
			stream >> x >> y;
			//std::cout<<"srv number " << index - dc->nb_na << std::endl << " size: "<< x << " capacity : " << y << std::endl;
			tab[index - dc->nb_na-1]= new Server (x, y);
			//break;
		}
	}
	return (index - dc->nb_na);
}

int		main(int argc, char **argv)
{
	//std::vector<Server> Vserver;
	//Server		*buff;
	Server			*list[625];
	Datacenter		*bigD;
	int 			size;

	if (argc == 2)
	{
		bigD = new Datacenter();
		std::cout<<"hello world"<<std::endl;
		size = parser(argv[1], list, bigD);
		std::cout<<"we have "<< bigD->getNbDatacenter() << " datacenter with : "<<size<<" Servers"<<std::endl;
		//bigD->printdc();
		// std::cout<<"srv number 0 " << std::endl << " size: "<< list [0]->size << " capacity : " << list [0]->cap << std::endl;
		// std::cout<<"srv number " << size << std::endl << " size: "<< list [size-1]->size << " capacity : " << list [size-1]->cap << std::endl;
		// std::cout<<std::endl;
		std::cout<<*bigD;
		// for (int i=0; i< size; i++)
		// {
		// 	list [i]->medium = (float)list [i]->cap/list [i]->size;
		// 	std::cout<<"srv number " << i << std::endl << " size: "<< list [i]->size << " capacity : " << list [i]->cap << " med : " << list [i]->medium << std::endl;
		// }
		// std::cout<<Vserver.size()<<std::endl;
		// std::cout<<med_size(&Vserver)<<std::endl;
		// std::cout<<med_cap(&Vserver)<<std::endl;
	}
	else
		std::cout<<"If you give me no file or more than one i'm lost try again"<<std::endl;
	
	return (0);
}
