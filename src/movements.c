/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:53:34 by mameneze          #+#    #+#             */
/*   Updated: 2021/11/07 21:30:25 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_pile *stack)
{
	int	tmp;

	if (stack->size > 1)
	{
		tmp = stack->number[0];
		stack->number[0] = stack->number[1];
		stack->number[1] = tmp;
	}
}

static void	push_operations(t_pile *stack_a, t_pile *stack_b, int i, int j)
{
	if (i == 0)
		stack_b->number[i] = stack_a->number[j];
	else
	{
		while (i > 0)
		{
			stack_b->number[i] = stack_b->number[i - 1];
			i--;
		}
		stack_b->number[0] = stack_a->number[0];
	}
	while (j < stack_a->size - 1)
	{
		stack_a->number[j] = stack_a->number[j + 1];
		j++;
	}
}

int	push(t_pile *stack_b, t_pile *stack_a)
{
	int	i;
	int	j;

	if (stack_a->size > 0)
	{
		stack_b->size++;
		i = stack_b->size - 1;
		j = 0;
		push_operations(stack_a, stack_b, i, j);
		return (stack_a->size--, 1);
	}
	return (0);
}

void	reverse_rotate(t_pile *stack)
{
	int	tmp;
	int	i;

	i = stack->size - 1;
	tmp = stack->number[i];
	while (i > 0)
	{
		stack->number[i] = stack->number[i - 1];
		i--;
	}
	stack->number[i] = tmp;
}

void	rotate(t_pile *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->number[0];
	while (i < stack->size - 1)
	{
		stack->number[i] = stack->number[i + 1];
		i++;
	}
	stack->number[i] = tmp;
}
