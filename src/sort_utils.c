/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:04:28 by mameneze          #+#    #+#             */
/*   Updated: 2021/11/12 01:08:02 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_pile *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->number[i] > stack->number[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_lower_pos(t_pile *stack)
{
	int	num;
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	num = stack->number[i];
	while (i < stack->size)
	{
		if (stack->number[i] < num)
		{
			num = stack->number[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	check_higher_pos(t_pile *stack)
{
	int	num;
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	num = stack->number[i];
	while (i < stack->size)
	{
		if (stack->number[i] > num)
		{
			num = stack->number[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}
