/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 17:15:56 by albarret          #+#    #+#             */
/*   Updated: 2019/06/16 22:32:32 by albarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	ft_create_struct_head(const char *fmt)
{
	int i;

	i = 0;
	t_main *head;

	head = (t_main*)malloc(sizeof(t_main));
	if (head == NULL)
		write(1, "head_memery_error\n", 18);
	head->right = NULL;
	head->left = NULL;
	head->fd = 1;
	head->char_string = NULL;
	head->arg_number = 0;
	head->flag_switch = 0;
	head->precision_switch = 0;
	head->precision_numbers = NULL;
	head->precision_numbers = NULL;
	head->width_switch = 0;
	head->width_numbers = NULL;
	head->length_switch = 0;
	head->length_type = 0;
	head->length_type = 0;
	head->conversion_switch = 0;
	head->conversion_type = 0;
	head->ret = 0;
	head->index = 0;
	head->width_star_switch = 0;
	head->precision_star_switch = 0;
	head->precision_star_numbers = NULL;
	head->width_star_numbers = NULL;
	ft_main_parse(fmt, head, i);
}

void	ft_node_create(const char *fmt, int i, int arg_count, t_main *last_node)
{
	t_main *node;
	
	node = NULL;
	node = (t_main*)malloc(sizeof(t_main));
	if (node == NULL)
		write(1, "node_memery_error\n", 18);
	node->right = NULL;
	node->left = last_node; // It's the last node used.
	node->fd = arg_count;
	node->char_string = NULL;
	node->arg_number = 0;
	node->flag_switch = 0;
	node->precision_switch = 0;
	node->precision_numbers = NULL;
	node->precision_numbers = NULL;
	node->width_switch = 0;
	node->width_numbers = NULL;
	node->length_switch = 0;
	node->length_type = 0;
	node->length_type = 0;
	node->conversion_switch = 0;
	node->conversion_type = 0;
	node->ret = 0;
	node->index = 0;
	node->width_star_switch = 0;
	node->precision_star_switch = 0;
	node->precision_star_numbers = NULL;
	node->width_star_numbers = NULL;
	ft_main_parse(fmt, node, i); //We pass this new node main parse
	// I need to pass in the current node also in order to create the left pointer to it.
	// Head should default point to null.
	// Right node is next = null;
}



