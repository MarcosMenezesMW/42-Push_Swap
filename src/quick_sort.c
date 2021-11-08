/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 00:32:37 by mameneze          #+#    #+#             */
/*   Updated: 2021/11/08 00:38:46 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_small_sort(t_pile *stack, char c)
{
	int	high;
	int	low;

	high = check_higher_pos(stack);
	low = check_lower_pos(stack);
	if (high == 2 && low == 1)
		swap_arg(stack, c);
	else if (high == 0 && low == 2)
	{
		rotate_arg(stack, c);
		swap_arg(stack, c);
	}
	else if (high == 1 && low == 2)
		rev_rotate_arg(stack, c);
	else if (high == 1 && low == 0)
	{
		rev_rotate_arg(stack, c);
		swap_arg(stack, c);
	}
	else 
		rotate_arg(stack, 'a');
}

void	quick_sort(t_pile *stack_a, t_pile *stack_b)
{
	int	med;
	int	below;

	med = check_med(stack_a);
	below = check_below(stack_a);
	printf("MED = %d\nABOVE = %d\n", med, below);
	while (below > 0)
	{
		if (stack_a->number[0] <= med)
		{
			push_arg(stack_b, stack_a, 'b');
			below--;
		}
		else
			rotate_arg(stack_a, 'a');
	}
}