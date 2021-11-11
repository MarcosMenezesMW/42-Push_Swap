/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 00:18:20 by mameneze          #+#    #+#             */
/*   Updated: 2021/11/11 02:22:29 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	medium_sort(t_pile *stack_a, t_pile *stack_b)
{
	int	i;
	int	size;

	i = 0;
	size = stack_a->size;
	get_pos(stack_a);
	while (i < size)
	{
		if (stack_a->number[0] >= 3)
			push_arg(stack_b, stack_a, 'b');
		else
			rotate_arg(stack_a, 'a');
		i++;
	}
	if (!is_sorted(stack_a))
		small_sort(stack_a, 'a');
	if (!is_sorted(stack_b))
		swap_arg(stack_b, 'b');
	while (stack_b->size > 0)
	{
		push_arg(stack_a, stack_b, 'a');
		rotate_arg(stack_a, 'a');
	}
}
