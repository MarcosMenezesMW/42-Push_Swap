/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 00:32:37 by mameneze          #+#    #+#             */
/*   Updated: 2021/11/11 00:28:10 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void swap_array(t_pile *stack_a, int *pos_array)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		stack_a->number[i] = pos_array[i];
		i++;
	}	
}

void	get_pos(t_pile* stack_a)
{
	int	*pos;
	int	i;
	int j;

	i = 0;
	pos = malloc(sizeof(int) * stack_a->size);
	while (i < stack_a->size)
	{
		j = 0;
		pos[i] = 0;
		while (j < stack_a->size)
		{
			if (stack_a->number[i] > stack_a->number[j])
				pos[i]++;
			j++;
		}
		i++;
	}
	swap_array(stack_a, pos);
	free(pos);
}

void	bit_ops(t_pile *stack_a, t_pile *stack_b, int pos, int size)
{
	int	j;
	int	top;

	j = 0;
	while (j < size)
	{
		top = stack_a->number[0];
		if (((top >> pos)&1) == 1)
			rotate_arg(stack_a, 'a');
		else
			push_arg(stack_b, stack_a, 'b');
		j++;
	}
}
void	big_sort(t_pile *stack_a, t_pile *stack_b)
{
	int	i;
	int	size;

	size = stack_a->size;
	i = 0;
	get_pos(stack_a);
	while (!is_sorted(stack_a))
	{
		bit_ops(stack_a, stack_b, i, size);
		while (stack_b->size != 0)
			push_arg(stack_a, stack_b, 'a');
		i++;
	}
}