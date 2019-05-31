/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 09:24:47 by albarret          #+#    #+#             */
/*   Updated: 2019/05/31 09:28:12 by albarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	ft_convert_main(const char *fmt, int i, t_main *head)
{
	char c;

	c = fmt[i];
	printf("head->flag_switch\n");
	printf("head->flag\n");
	printf("head->precision_switch\n");
	//while (head->precision_numbers != '\0')
	//{
	//	printf("head->precision_numbers");
	//	head->precision_numbers++;
	//}
	printf("width_switch\n");
	//int	*width_numbers;
	printf("length_switch\n");
	printf("length_type\n");
	printf("conversion_switch\n");
	printf("conversion_type\n");
	head->ret = i;
	//int	index;
}
