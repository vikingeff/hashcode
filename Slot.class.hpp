/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Slot.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:47:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/16 10:56:06 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLOT_CLASS_HPP
# define SLOT_CLASS_HPP

# include <iostream>

class Slot
{

	public:
		int		xval;
		int		yval;

		Slot();
		Slot(int x, int y);
		virtual ~Slot();

		static int		getNbServer(void);

	private:
		static int	_nbSlot;
};

# endif