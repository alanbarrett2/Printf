/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:31:36 by albarret          #+#    #+#             */
/*   Updated: 2019/06/13 17:12:42 by albarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "ft_printf.h"

int		ft_main_parse(const char *fmt, int i)
{
	t_main *head;
	head = NULL;

	head = ft_memery_s_main();

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
			head->conversion_switch = 1;
			//printf("%i\n", head_ptr->conversion_switch);
			ft_flag_parse(fmt, i, head);
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
	ft_width_parse(fmt, i, head);
}

void	ft_width_parse(const char *fmt, int i, t_main *head)
{
	int count;
	char *cpy;
	int n;

	count = i;
	cpy = NULL;
	n = 0;

	if (fmt[i] == '.')
		ft_precision_parse(fmt, i, head);
	printf("The fmt in width_parse is: %c\n", fmt[i]);
	if (fmt[i] == '*')
	{
		head->width_star_switch = 1;
		i++;
		count = i;
		while (fmt[count] >= '0' && fmt[count] <= '9' && (fmt[count]))
		{
			i++;
			count++;
		} 
		n = 0;
	}
	if (fmt[i] >= '0' && fmt[i] <= '9')
	{
		head->width_switch = 1;
		printf("Width_switch is: %i\n", head->width_switch);
		printf("Count before is: %i\n", count);
		while (fmt[count] >= '0' && fmt[count] <= '9')
		{
			count++;
		}
		printf("The fmt string is %s\n", fmt); //Why is my fmt null?
		printf("Index is %i\n", i);
		printf("char is: %c\n", fmt[i]);
		printf("The count is: %i\n", count);

		count = count - i;
		printf("Correct count%i\n", count); 
		cpy = (char*)malloc(sizeof(count + 1));
		while (count > 0) // This is where the mistake is. my count number used index i, and then added to it throwing off the correct count. I should have subtracted i.
		{
			cpy[n] = fmt[i];
			printf("The cpy value is:%c\n", cpy[n]); // It placed numbers instead of chars. 
			i++;
			n++;
			count--;
		}
		cpy[n] = '\0';
		head->width_numbers = cpy;
		//printf("This is width_numbers:%s\n", head->width_numbers);

	}
	ft_precision_parse(fmt, i, head);
}

void	ft_precision_parse(const char *fmt, int i, t_main *head)
{
	int count;
	char *cpy;
	int n;

	n = 0;
	cpy = NULL;
	if (fmt[i] >= '0' && fmt[i] <= '9')
	{
		ft_width_parse(fmt, i, head); // width comes before precision.
	}
	if (fmt[i] == '.')
	{
		printf("ENTERED PRECISION\n");
		head->precision_switch = 1;
		//head->precision_numbers[0] = '0';  Oh, I can't do this because I have not create memery for it. 
		i++; //this moves past '.'
		if (fmt[i] == '*')
		{
			head->precision_star_switch = 1;
			i++;
			while (fmt[i] >= '0' && fmt[i] <= '9' && (fmt[i]))
			{
				head->precision_star_numbers[n] = fmt[i];
				i++;
				n++;
			}
			n = 0;
		}
		count = i;
		printf("This should be a number:%c\n", fmt[i]);
		while (fmt[count] >= '0' && fmt[count] <= '9' && (fmt[count]))
		{
			count++;
		}
		printf("this is count: %i\n", count);
		printf("This is i:%i\n", i);
		count = count - i;
		cpy = (char*)malloc(sizeof count + 1);
		printf("this is count %i\n", count); // Why is my count -1?
		while (count > 0)
		{
			cpy[n] = fmt[i];
			printf("This is cpy[n]:%c", cpy[n]);
			n++;
			i++;
			count--;
		}
		cpy[n] = '\0';
		head->precision_numbers = cpy;
		printf("\n");
		printf("This is precision_numbers string: %s\n", head->precision_numbers);
	}	
	ft_length_parse(fmt, i, head); // (correct place?) Check for length this defines input.
}

void	ft_length_parse(const char *fmt, int i, t_main *head)
{
	printf("made it to length_parse%c\n", fmt[i]);
	if (fmt[i] == 'h' && fmt[i + 1] == 'h') //Take note this is two char's and has not been taking care of.
	{
		printf("found hh");
		head->length_type = 'H'; //Note in order to save time I just made my own flag.
		head->length_switch = 1;
		i++;
		i++;
	}
	if (fmt[i] == 'h')
	{
		printf("found h");
		head->length_switch = 1;
		head->length_type = 'h';
		i++;
	}
	if (fmt[i] == 'l' && fmt[i + 1] == 'l')
	{
		head->length_type = 'E'; //Same here.
		head->length_switch = 1;
		i++;
		i++;
	}
	if (fmt[i] == 'l')
	{
		head->length_type = 'l';
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

void	ft_conversion_parse(const char *fmt, int i, t_main *head)
{
		printf("Made it to conversion parse\n");
		printf("The fmt is:%c\n", fmt[i]);
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
		{
			printf("is this working?\n");
			i++;
		}
		printf("Are we at null?%c\n", fmt[i]);  
		if (fmt[i] == '\0')
		{
			printf("yes\n");
			ft_convert_main(fmt, i, head);
		}
			
		// fmt is one big string I need a new node for each fmt section.
}
