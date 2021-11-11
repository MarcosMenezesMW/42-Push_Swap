/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 00:54:19 by mameneze          #+#    #+#             */
/*   Updated: 2021/11/11 00:57:24 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_pile *stack)
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

void	rotate_arg(t_pile *stack, char c)
{
	rotate(stack);
	write(STDOUT_FILENO, "r", 1);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, "\n", 1);
}

void	rr(t_pile *stack_a, t_pile *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(STDOUT_FILENO, "rr\n", 3);
}
