/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Slot.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:47:54 by gleger            #+#    #+#             */
/*   Updated: 2015/03/16 11:31:42 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Slot.class.hpp>

Slot::Slot()
{
	Slot(0,0);
	Slot::_nbSlot+=1;
}

Slot::Slot(int x, int y) : xval(x), yval(y)
{
	Slot::_nbSlot+=1;
	return;
}

Slot::~Slot()
{
	Slot::_nbSlot-=1;
	return;
}

int				Slot::getNbServer(void)
{
	return Slot::_nbSlot;
}

int				Slot::_nbSlot = 0;
