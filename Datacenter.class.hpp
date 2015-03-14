/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Datacenter.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 10:34:47 by gleger            #+#    #+#             */
/*   Updated: 2015/03/14 11:49:40 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATACENTER_CLASS_HPP
# define DATACENTER_CLASS_HPP

# include <iostream>

class Datacenter
{
	public:
		int		rows;
		int		r_size;
		int		nb_na;
		int		nb_grp;
		int		nb_srv;

		Datacenter();
		virtual ~Datacenter();
		
		std::string		tostring() const;
		static int		getNbDatacenter(void);

	private:
		Datacenter(Datacenter const & ref);

		static int	_nbDatacenter;
};

std::ostream & operator<<(std::ostream & o, Datacenter const & rhs);

# endif