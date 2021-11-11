/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 00:55:39 by mameneze          #+#    #+#             */
/*   Updated: 2021/11/11 00:57:09 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_pile *stack)
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

void	rev_rotate_arg(t_pile *stack, char c)
{
	reverse_rotate(stack);
	write(STDOUT_FILENO, "rr", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, "\n", 1);
}

void	rrr(t_pile *stack_a, t_pile *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(STDOUT_FILENO, "rrr\n", 4);
}