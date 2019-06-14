/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:31:09 by albarret          #+#    #+#             */
/*   Updated: 2019/05/29 12:31:11 by albarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

/*int     ft_printf(char const *fmt, ...)
{
    int i;
    int ret;
    int s;
    va_list ap;

    ret = 0;
    i = 0;

    va_start(ap, fmt);
    ft_main_parse(fmt, i);
    s = va_arg(ap, int);
    va_end(ap);
    return (ret);
}*/

int     ft_printf(const char *fmt)
{
    int i;
    int ret;

    ret = 0;
    i = 0;
    ft_main_parse(fmt, i);
    return (ret);
}