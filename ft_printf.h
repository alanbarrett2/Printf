/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:31:17 by albarret          #+#    #+#             */
/*   Updated: 2019/05/29 12:31:19 by albarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef FT_PRINTF
 #define FT_PRINTF

typedef	struct	s_main
{
	int flag_switch;
	char	flag;
	int	precision_switch;
	int	*precision_numbers;
	int	width_switch;
	int	*width_numbers;
	int	length_switch;
	char	length_type;
	int	conversion_switch;
	char	conversion_type;
	int	ret;
	int	index;
}			t_main;

int		main(void);
//int		ft_printf(const char *fmt, ...);
int		ft_printf(const char *fmt);
int		ft_main_parse(const char *fmt, int i);
t_main	ft_memery_s_main(void);
void	ft_flag_parse(const char *fmt, int i, t_main *head);
void	ft_precision_parse(const char *fmt, int i, t_main *head);
void	ft_width_parse(const char *fmt, int i, t_main *head);
void	ft_memery_p_n(const char *fmt, int end, int start, t_main *head);
void	ft_memery_width(const char *fmt, int end, int start, t_main *head);
void	ft_conversion_parse(const char *fmt, int i, t_main *head);
void	ft_convert_main(const char *fmt, int i, t_main *head);
void	ft_putchar(char c);
void	ft_length_parse(const char *fmt, int i, t_main *head);

#endif
