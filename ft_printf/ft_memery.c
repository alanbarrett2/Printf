/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memery.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:31:26 by albarret          #+#    #+#             */
/*   Updated: 2019/06/13 16:55:18 by albarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

//Here we are making memery for the struct it's self, and makeing values = 0 to make sure we don't get garbage data. -> is used with pointers . with no ptr.

// This also returns a pointer to the struct.
t_main	*ft_memery_s_main(void)
{
	t_main *ptr;

	ptr = (t_main*)malloc(sizeof(t_main));
	ptr->flag_switch = 0;
	ptr->precision_switch = 0;
	ptr->precision_numbers = NULL;
	ptr->precision_numbers = NULL;
	ptr->width_switch = 0;
	ptr->width_numbers = NULL;
	ptr->length_switch = 0;
	ptr->length_type = 0;
	ptr->length_type = 0;
	ptr->conversion_switch = 0;
	ptr->conversion_type = 0;
	ptr->ret = 0;
	ptr->index = 0;
	ptr->width_star_switch = 0;
	ptr->precision_star_switch = 0;
	ptr->precision_star_numbers = NULL;
	ptr->width_star_numbers = NULL;
	return (ptr);
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

/*void	ft_memery_width(const char *fmt, int end, int start, t_main *head)
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
*/
