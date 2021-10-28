/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:48:38 by mameneze          #+#    #+#             */
/*   Updated: 2021/10/28 18:45:05 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_pile *stack)
{
	int	i;

	i = 0	;
	while (i < stack->size - 1)
	{
		if(stack->number[i] > stack->number[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	check_lower_pos(t_pile *stack_a)
{
	int	num;
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	num =  stack_a->number[i];
	while (i < stack_a->size)
	{
		if (stack_a->number[i] < num)
		{
			num = stack_a->number[i];
			pos = i;
		}
		i++;			
	}
	return (pos);
}

static int	check_higher_pos(t_pile *stack_a)
{
	int	num;
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	num =  stack_a->number[i];
	while (i < stack_a->size)
	{
		if (stack_a->number[i] > num)
		{
			num = stack_a->number[i];
			pos = i;
		}
		i++;			
	}
	return (pos);
}

void	small_sort(t_pile *stack_a)
{
	int	high;
	int low;

	high = check_higher_pos(stack_a);
	low = check_lower_pos(stack_a);
	if (high == stack_a->size && low == 1) /* 2 1 3 */
		sa(stack_a);
	else if (high == 0 && low == stack_a->size - 1) /* 3 2 1 */
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (high == 1 && low == stack_a->size - 1) /* 2 3 1 */
		rra(stack_a);
	else if (high == 1 && low == 0) /* 1 3 2 */
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	simple_sort(t_pile *stack_a, t_pile *stack_b)
{
	while (!is_sorted(stack_a))
	{
		while(stack_a->size > 1)
		{
			if (stack_a->number[0] > stack_a->number[1])
			{
				swap(stack_a);
				write(STDOUT_FILENO, "sa\n", 3);
			}
			else
			{
				push(stack_a, stack_b);
				write(STDOUT_FILENO, "pb\n", 3);
			}
		}
		while(stack_b->size > 0)
		{
			push(stack_b, stack_a);
			write(STDOUT_FILENO, "pa\n", 3);
		}
	}
}
