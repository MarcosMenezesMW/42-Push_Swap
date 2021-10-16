/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:49:26 by mameneze          #+#    #+#             */
/*   Updated: 2021/10/16 17:45:20 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_args(char c, t_pile *stack_a, t_pile *stack_b)
{
	if (!ft_isdigit(c) && c != '-')
	{
		free(stack_a->number);
		free(stack_b->number);
		return (write(STDERR_FILENO, ERRPARAM, 21), 0);
	}
	return (1);
}

static int	check_duplicates(char c, t_pile *stack_a, t_pile *stack_b)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->number[i] == c)
		{
			free(stack_a->number);
			free(stack_b->number);
			return (write(STDERR_FILENO, ERRDUP, 21), 0);
		}
		i++;
	}
	return (1);
}

void	fill_stack(t_pile *stack_a, t_pile *stack_b, char **argv, int argc)
{
	int	i;

	i = 0;
	while (i + 1 < argc)
	{
		if (!check_args(*argv[i + 1], stack_a, stack_b))
			exit(0);
		stack_a->number[i] = ft_atoi(argv[i + 1]);
		if (!check_duplicates(stack_a->number[i], stack_a, stack_b))
			exit(0);
		stack_a->size++;
		i++;
	}
	stack_b->number = malloc((stack_a->size) * sizeof(int));
}

void	init_stack(t_pile *stack_a, t_pile *stack_b, int argc)
{
	stack_a->number = malloc((argc - 1) * sizeof(int));
	stack_a->size = 0;
	stack_b->size = 0;
}
