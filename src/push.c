/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 00:57:35 by mameneze          #+#    #+#             */
/*   Updated: 2021/11/11 02:22:36 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static int	push(t_pile *stack_b, t_pile *stack_a)
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

void	push_arg(t_pile *stack_a, t_pile *stack_b, char c)
{
	if (push(stack_a, stack_b) != 0)
	{
		write(STDOUT_FILENO, "p", 1);
		write(STDOUT_FILENO, &c, 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}
