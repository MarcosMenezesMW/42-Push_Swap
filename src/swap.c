/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 00:58:45 by mameneze          #+#    #+#             */
/*   Updated: 2021/11/11 00:59:12 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_pile *stack)
{
	int	tmp;

	if (stack->size > 1)
	{
		tmp = stack->number[0];
		stack->number[0] = stack->number[1];
		stack->number[1] = tmp;
	}
}

void	swap_arg(t_pile *stack, char c)
{
	swap(stack);
	write(STDOUT_FILENO, "s", 1);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, "\n", 1);
}
