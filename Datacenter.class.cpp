/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Datacenter.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 10:36:43 by gleger            #+#    #+#             */
/*   Updated: 2015/03/16 13:41:08 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Datacenter.class.hpp>
#include <string>

Datacenter::Datacenter()
{
	rows = 0;
	r_size = 0;
	nb_na = 0;
	nb_grp = 0;
	nb_srv = 0;
	std::cout<<"Datacenter is up !!"<<std::endl;
	Datacenter::_nbDatacenter+=1;
}

Datacenter::Datacenter(Datacenter const & ref)
{
	Datacenter::_nbDatacenter++;
	std::cout << "Datacenter Copy called." << std::endl;
	*this = ref;
	return;
}

Datacenter::~Datacenter()
{
	std::cout<<"Datacenter is down !!"<<std::endl;
	Datacenter::_nbDatacenter-=1;
	return;
}

std::string			Datacenter::tostring() const
{
	std::string		txt;
	
	txt.append("Rows 			: ");
	txt.append(std::to_string(this->rows));
	txt.append("\nRows size 		: ");
	txt.append(std::to_string(this->r_size));
	txt.append("\nUnavailable slots 	: ");
	txt.append(std::to_string(this->nb_na));
	txt.append("\nGroups 			: ");
	txt.append(std::to_string(this->nb_grp));
	txt.append("\nSevers 			: ");
	txt.append(std::to_string(this->nb_srv));
	return (txt);
}

std::ostream & operator<<(std::ostream & o, Datacenter const & rhs)
{
	return o << "[BigD] : Here is the datacenter number " << rhs.getNbDatacenter()-1 << std::endl << rhs.tostring() << std::endl;
}

int				Datacenter::getNbDatacenter(void)
{
	return Datacenter::_nbDatacenter;
}

int				Datacenter::_nbDatacenter = 0;
