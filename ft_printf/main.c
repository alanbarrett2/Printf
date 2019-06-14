/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 06:39:15 by albarret          #+#    #+#             */
/*   Updated: 2019/06/13 17:12:45 by albarret         ###   ########.fr       */
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
	//ft_printf("%-100i");   // This is width_test.
	//ft_printf("%+.456789d"); //This is precision_numbers test.
	//ft_printf("%#5.5i"); //This is precision and width test.
	//ft_printf("This has a string%-2.4hhi");
	//ft_printf("%+2.4hi");
	//ft_printf("this has a string%-2.4lli");
	ft_printf("%#3.4li");
	return(0);
}
