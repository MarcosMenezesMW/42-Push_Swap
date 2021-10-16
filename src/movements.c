/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:53:34 by mameneze          #+#    #+#             */
/*   Updated: 2021/10/16 18:22:36 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_pile *stack_a)
{
	int	tmp;

	if (stack_a->size > 1)
	{
		tmp = stack_a->number[0];
		stack_a->number[0] = stack_a->number[1];
		stack_a->number[1] = tmp;
	}
}

void	push(t_pile *stack_a, t_pile *stack_b)
{
	int	i;
	int	j;

	stack_b->size++;
	i = stack_b->size - 1;
	j = 0;
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
	stack_a->size -= 1;
}

void	rotate(t_pile *stack)
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

void	reverse_rotate(t_pile *stack)
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