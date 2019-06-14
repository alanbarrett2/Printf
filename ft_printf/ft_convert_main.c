/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 09:24:47 by albarret          #+#    #+#             */
/*   Updated: 2019/06/13 17:12:51 by albarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	ft_convert_main(const char *fmt, int i, t_main *head)
{
	char c;
	int n;

	n = 0;
	c = fmt[i];
	printf("This is flag_switch %i\n", head->flag_switch);
	printf("This is flag %c\n", head->flag);
	printf("This is precision Switch %i\n", head->precision_switch);
	//while (head->precision_numbers != '\0')
	//{
	//	printf("head->precision_numbers");
	//	head->precision_numbers++;
	//}
	printf("this is width switch %i\n", head->width_switch);
	//printf("this is width numbers %s\n", head->width_numbers); Why is width numbers not working? (Check when you allo memery)
	//int	*width_numbers;
	printf("this is length switch %i\n", head->length_switch);
	printf("Length type %c\n", head->length_type);
	//printf("Conversion_switch %i\n", head->conversion_switch);   WTF
	printf("Conversion_type %c\n", head->conversion_type);
	//printf("this is width_numbers:\n");
	/*while (head->width_numbers[n])  // It my be seg faluting because width numbers don't exist?
	{
		printf("%c", head->width_numbers[n]);
		n++;
	}
	*/
	printf("This is width numbers:%s\n", head->width_numbers);
	//printf("\n");
	n = 0;
	//printf("This is precision_numbers\n");
	/*while (head->precision_numbers[n] != '\0')
	{
		printf("%c", head->precision_numbers[n]);
		n++;
	}
	*/
	printf("This is precision_numbers:%s\n", head->precision_numbers); 
	head->ret = i;
	//int	index;
	//Make sure when you print numbers that you are printing them, and checking them in char form. OR what will happen is 0 = 48 and 1 = 49;


/* Note to self I think you can have a percision, and a width at the same time
 * width is numbers before . (max numbers to print)
 * precision is numbers after . (has a lot of cases)
 */
//printf("This is a precision and width test\n");
n = 0;
//printf("%-5.5i\n", n); Width and precision test
printf("This is p_star_switch:%i\n", head->precision_star_switch);
printf("This is w_star_switch:%i\n", head->width_star_switch);
printf("This is p_star_numbers:%s\n", head->precision_star_numbers);
printf("This is w_star_numbers:%s\n", head->width_star_numbers);





}

// I need to fix my code when I have width, and precision at the same time.
