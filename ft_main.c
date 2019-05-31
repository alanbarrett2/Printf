/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 06:39:15 by albarret          #+#    #+#             */
/*   Updated: 2019/05/31 09:44:30 by albarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		main(void)
{
	//printf("printfinmain\n");
	//ft_printf("this is just as string\n");
	//ft_printf("Print a percent sign %%\n");
	//ft_printf("First test with conversion%s\n", "String added");
	//ft_printf("test%-s", "string");
	//ft_printf("test%s");
	ft_printf("%-100i");
	return(0);
}
