/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 10:05:33 by gleger            #+#    #+#             */
/*   Updated: 2015/03/14 11:12:39 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Server.class.hpp>

Server::Server()
{
	Server(0,0);
	Server::_nbServer+=1;
}

Server::Server(int size, int cap) : size(size), cap(cap)
{
	std::cout<<"server number "<<getNbServer()+1<<std::endl;
	row = 0;
	location = 0;
	grp = 0;
	used = 0;
	Server::_nbServer+=1;
	return;
}

Server::~Server()
{
	Server::_nbServer-=1;
	return;
}

int				Server::getNbServer(void)
{
	return Server::_nbServer;
}

int				Server::_nbServer = 0;