#include <vector>
#include <fstream>
#include <sstream>
#include <Server.class.hpp>
#include <Datacenter.class.hpp>

float		med_cap(std::vector<Server> *buff)
{
	float medium=0;

	for (int i=0; i < (int)buff->size(); i++)
	{
		medium+=buff->at(i).cap;
	}
	return (medium / buff->size());
}

float		med_size(std::vector<Server> *buff)
{
	float medium=0;

	for (int i=0; i < (int)buff->size(); i++)
	{
		medium+=buff->at(i).size;
	}
	return (medium / buff->size());
}

int			parser(char *file, Server *tab, Datacenter *dc)
{
	// int	nb_rg = 0;
	// int	size_rg = 0;
	// int	nb_ind = 0;
	// int	nb_grp = 0;
	// int	nb_serveur = 0;
	bool	define = false;
	//bool	ind = false;
	//int	nb_ind_inc = 0;
	//std::vector<std::vector<int> > vec;
	//std::vector<Server> servers;
	//(*servers).push_back(Server(0, 0, 0));
	int n;
	//int x;
	//int y;
	//int i=1;
	std::string 	str;
	std::ifstream	inputfile(file);
	(void) tab;

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
			while (1)
			{
				stream >> n;
				if (!stream)
					break ;
				if (dc->rows == 0)
					dc->rows = n;
				else if (dc->r_size == 0)
					dc->r_size = n;
				else if (dc->nb_na == 0)
					dc->nb_na = n;
				else if (dc->nb_grp == 0)
					dc->nb_grp = n;
				else if (dc->nb_srv == 0)
				{
					dc->nb_srv = n;
					//*vec = create_vector(nb_rg, size_rg);
					define = true;
					// std::cout << "nb_rg = " << nb_rg << std::endl;
					// std::cout << "size_rg = " << size_rg << std::endl;
				}
				else
					std::cout << "wut " << n << std::endl;
			}
			continue ;
		}
		// if (nb_ind_inc < nb_ind)
		// {
		// 	x = -1;
		// 	x = -1;
		// 	while (1)
		// 	{
		// 		stream >> n;
		// 		if (!stream)
		// 			break ;
		// 		if (x == -1)
		// 			x = n;
		// 		else
		// 		{
		// 			y = n;
		// 			std::cout << "x = " << x << std::endl;
		// 			std::cout << "y = " << y << std::endl;
		// 			(*vec)[x][y] = -1;
		// 		}
		// 	}
		// 	nb_ind_inc++;
		// }
		// else
		// {
		// 	x = -1;
		// 	x = -1;
		// 	while (1)
		// 	{
		// 		stream >> n;
		// 		if (!stream)
		// 			break ;
		// 		if (x == -1)
		// 			x = n;
		// 		else
		// 		{
		// 			y = n;
		// 			(*servers).push_back(Server(x, y, i));
		// 			i++;
		// 		}
		// 	}
		// }
	}
	return (0);
}

int		main(int argc, char **argv)
{
	//std::vector<Server> Vserver;
	//Server		*buff;
	Server			list[650];
	Datacenter		*bigD;
	int 			size;

	if (argc == 2)
	{
		bigD = new Datacenter();
		std::cout<<"hello world"<<std::endl;
		size = parser(argv[1], list, bigD);
		std::cout<<"we have 1 datacenter with : "<<size<<" Servers"<<std::endl;
		//bigD->printdc();
		std::cout<<std::endl;
		std::cout<<*bigD;
		// std::cout<<Vserver.size()<<std::endl;
		// std::cout<<med_size(&Vserver)<<std::endl;
		// std::cout<<med_cap(&Vserver)<<std::endl;
	}
	else
		std::cout<<"If you give me no file or more than one i'm lost try again"<<std::endl;
	
	return (0);
}
