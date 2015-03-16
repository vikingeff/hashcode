/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 10:05:33 by gleger            #+#    #+#             */
/*   Updated: 2015/03/16 13:53:51 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Server.class.hpp>

Server::Server()
{
	Server(0,0,0);
	Server::_nbServer+=1;
}

Server::Server(int size, int cap, int index) : size(size), cap(cap), index(index)
{
	//std::cout<<"server number "<<getNbServer()+1 << " " <<size << " , " << cap <<std::endl;
	row = 0;
	location = 0;
	grp = 0;
	used = false;
	medium = 0;
	Server::_nbServer+=1;
	return;
}

Server::Server(Server const & ref)
{
	//std::cout << "Server Copy called." << std::endl;
	*this=ref;
	Server::_nbServer+=1;
	return;
}

Server::~Server()
{
	Server::_nbServer-=1;
	return;
}

std::string			Server::tostring() const
{
	std::string		txt;
	
	txt.append("NB:");
	txt.append(std::to_string(this->index));
	txt.append("\tSIZE:");
	txt.append(std::to_string(this->size));
	txt.append("\tCAP:");
	txt.append(std::to_string(this->cap));
	txt.append("\tAV:");
	txt.append(std::to_string(this->medium));
	txt.append("\tGRP:");
	txt.append(std::to_string(this->grp));
	txt.append("\tX:");
	txt.append(std::to_string(this->row));
	txt.append("\tY:");
	txt.append(std::to_string(this->location));
	if (this->used)
		txt.append("\t USED");
	else
		txt.append("\t NOT USED");
	return (txt);
}

std::ostream & operator<<(std::ostream & o, Server const & rhs)
{
	return o << rhs.tostring();
}

int				Server::getNbServer(void)
{
	return Server::_nbServer;
}

int				Server::_nbServer = 0;