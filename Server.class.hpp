/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 10:04:38 by gleger            #+#    #+#             */
/*   Updated: 2015/03/16 13:42:47 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_CLASS_HPP
# define SERVER_CLASS_HPP

# include <iostream>

class Server
{
	public:
		int		size;
		int		cap;
		int		grp;
		int		row;
		int		location;
		bool	used;
		int		index;
		float	medium;
		
		Server();
		Server(int size, int cap, int index);
		Server(Server const & ref);
		virtual ~Server();

		std::string		tostring() const;
		static int		getNbServer(void);

	private:
		static int	_nbServer;
};

std::ostream & operator<<(std::ostream & o, Server const & rhs);

# endif
