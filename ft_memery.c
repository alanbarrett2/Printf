/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memery.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:31:26 by albarret          #+#    #+#             */
/*   Updated: 2019/05/29 12:31:28 by albarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

//Here we are making memery for the struct it's self, and makeing values = 0 to make sure we don't get garbage data. -> is used with pointers . with no ptr.

// This also returns a pointer to the struct.
t_main	ft_memery_s_main(void)
{
	t_main *ptr;

	ptr = (t_main*)malloc(sizeof(t_main));
	ptr->flag_switch = 0;
	ptr->precision_switch = 0;
	// Turn this into a pointer ptr->precision_numbers = 0;
	ptr->precision_numbers = NULL;
	ptr->width_switch = 0;
	ptr->width_numbers = NULL;
	ptr->length_switch = 0;
	//char	length_type;
	ptr->conversion_switch = 0;
	//char	conversion_type;
	ptr->ret = 0;
	ptr->index = 0;
	return (*ptr);
}

// Now let's create speace for precision_nums

void	ft_memery_p_n(const char *fmt, int end, int start, t_main *head)
{
	// This is interesting because I am changing the data in a struct, but do I make a new struct ptr?

	//I think this is right, but this needs to be an *?
	int i;

	i = 0;
	while (start < end)
	{
		head->precision_numbers[i] = fmt[start];
		start++;
		i++;
	}
}

void	ft_memery_width(const char *fmt, int end, int start, t_main *head)
{
	// This is interesting because I am changing the data in a struct, but do I make a new struct ptr?
	int i;

	i = 0;
	while (start < end)
	{
		head->width_numbers[i] = fmt[start];
		start++;
		i++;
	}
}
