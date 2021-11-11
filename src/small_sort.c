/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:48:38 by mameneze          #+#    #+#             */
/*   Updated: 2021/11/11 02:20:40 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	smallest_sort(t_pile *stack, char c)
{
	if (stack->number[0] > stack->number[1])
		swap_arg(stack, c);
}

void	small_sort(t_pile *stack, char c)
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
