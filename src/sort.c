/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:48:38 by mameneze          #+#    #+#             */
/*   Updated: 2021/10/16 19:33:55 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_pile stack)
{
	int	i;

	i = 0	;
	while (i < stack.size - 1)
	{
		if(stack.number[i] > stack.number[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	simple_sort(t_pile *stack_a, t_pile *stack_b)
{
	
}