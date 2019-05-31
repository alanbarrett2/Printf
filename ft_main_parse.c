/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:31:36 by albarret          #+#    #+#             */
/*   Updated: 2019/05/29 12:31:38 by albarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "ft_printf.h"

int		ft_main_parse(const char *fmt, int i)
{
	t_main head;

	head = ft_memery_s_main();
	t_main *head_ptr = &head;

	//printf("wtf\n"); Remove this but as about why it dose not work with \n
	//head_ptr->conversion_switch = 1;
	//printf("conversion_switch%i\n", head_ptr->conversion_switch);
	while(fmt[i])
	{
		if ((fmt[i] == '%' && fmt[i + 1] == '%') && (fmt[i]) && (fmt[i + 1] != '\0'))
		{
			ft_putchar(fmt[i]);
			i++;
			i++;
		}
		if ((fmt[i] == '%' && fmt[i + 1] != '%' && (fmt[i + 1] != '\0')))
		{
			head_ptr->conversion_switch = 1;
			//printf("%i\n", head_ptr->conversion_switch);
			ft_flag_parse(fmt, i, head_ptr);
			return (0);
		}
		if (fmt[i] != '\0')
		{
			ft_putchar(fmt[i]);
			i++;
		}
	}
	if (fmt[i] == '\0')
		return (0);
	return (1);
}

void	ft_flag_parse(const char *fmt, int i, t_main *head)
{
   	if (fmt[i] == '%' && fmt[i + 1] != '%')
		i++;
	while (fmt[i])
	{
		if (fmt[i] == '-' || fmt[i] == '+' || fmt[i] == ' ' || fmt[i] == '#' || fmt[i] == '0')
		{
			head->flag_switch = 1;
			head->flag = fmt[i];
			i++;
			break;
		}
	}
	ft_precision_parse(fmt, i, head);
}

void	ft_precision_parse(const char *fmt, int i, t_main *head)
{
	int count;
	int start;

	count = 0;
	if (fmt[i] == '.')
	{
		head->precision_switch = 1;
		if (fmt[i] == '.' && (fmt[i] >= '1' && fmt[i] <= '9'))
		{
			i++; //this moves past '.'
			if (fmt[i] >= '1' && fmt[i] <= '9')
				start = i;
			while (fmt[i] >= '1' && fmt[i] <= '9')
				i++;
			ft_memery_p_n(fmt, i, start, head); // Find out how to do this.
			ft_length_parse(fmt, i, head);
		}
	}
	if (fmt[i] >= '1' && fmt[i] <= '9')
		{
			ft_width_parse(fmt, i, head); // If no . then it's width.
		}
	else
		ft_length_parse(fmt, i, head);
}

void	ft_length_parse(const char *fmt, int i, t_main *head)
{
	if (fmt[i] == 'h' && fmt[i + 1] =='h') //Take note this is two char's and has not been taking care of.
	{
		head->length_type = 'H'; //Note in order to save time I just made my own flag.
		head->length_switch = 1;
		i++;
	}
	if (fmt[i] == 'h')
	{
		head->length_switch = 1;
		head->length_type = 'h';
		i++;
	}
	if (fmt[i] == 'l' && fmt[i + 1] == 'l')
	{
		head->length_type = 'E'; //Same here.
		head->length_switch = 1;
		i++;
	}
	if (fmt[i] == 'L')
	{
		head->length_switch = 1;
		head->length_type = 'L'; //Why must a char be like this : 'L' and not like this "L"?
		i++;
	}
	ft_conversion_parse(fmt, i, head);
}
void	ft_width_parse(const char *fmt, int i, t_main *head)
{
	int start;

	if (fmt[i] >= '1' && fmt[i] <= '9')
	{
		start = i;
		head->width_switch = 1;
		printf("made it here");
		while (fmt[i] >= '1' && fmt[i] <= '9')
			i++;
		ft_memery_width(fmt, i, start, head);
	}
	ft_length_parse(fmt, i, head);
}

void	ft_conversion_parse(const char *fmt, int i, t_main *head)
{
		printf("Made it here Conversion\n");
		if (fmt[i] == 'd' || fmt[i] == 'i')
			head->conversion_type = fmt[i];
		if (fmt[i] == 'c' || fmt[i] == 'C')
			head->conversion_type = fmt[i];
		if (fmt[i] == 'S' || fmt[i] == 's')
			head->conversion_type = fmt[i];
		if (fmt[i] == 'x' || fmt[i] == 'X')
			head->conversion_type = fmt[i];
		if (fmt[i] == 'f' || fmt[i] == 'F')
			head->conversion_type = fmt[i];
		if (fmt[i] == '0')
			head->conversion_type = fmt[i];
		if (fmt[i] == 'u')
			head->conversion_type = fmt[i];
		if (fmt[i] == 'p')
			head->conversion_type = fmt[i];
		if (head->conversion_type != 0)
			i++;
		if (fmt[i] == '\0')
		{
			printf("Made it here\n");
			ft_convert_main(fmt, i, head); //Why is it not getting here?
		}

		// fmt is one big string.
}
