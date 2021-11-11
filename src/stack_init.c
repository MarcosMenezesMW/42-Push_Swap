/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:49:26 by mameneze          #+#    #+#             */
/*   Updated: 2021/11/11 02:49:59 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_args(char c, t_pile *stack_a)
{
	if (!ft_isdigit(c) && c != '-')
	{
		free(stack_a->number);
		return (write(STDERR_FILENO, ERR, 7), 0);
	}
	return (1);
}

static void	check_duplicates(char c, t_pile *stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->number[i] == c)
		{
			free(stack_a->number);
			write(STDERR_FILENO, ERR, 7);
			exit(1);
		}
		i++;
	}
}

void	string_args(t_pile *stack_a, t_pile *stack_b, char *argv[])
{
	char	**string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	string = ft_split(argv[1], ' ');
	while (string[i] != NULL)
		i++;
	while (j < i)
	{
		if (!check_args(*string[j], stack_a))
			exit(0);
		if (ft_atol(string[j]) > MAX_INT
			|| ft_atol(string[j]) < MIN_INT)
		{
			write(STDERR_FILENO, ERR, 7);
			exit(0);
		}
		stack_a->number[j] = ft_atoi(string[j]);
		check_duplicates(stack_a->number[j], stack_a);
		stack_a->size++;
		j++;
	}
	stack_b->number = malloc((stack_a->size) * sizeof(int));
}

void	fill_stack(t_pile *stack_a, t_pile *stack_b, char **argv, int argc)
{
	int	i;

	i = 0;
	if (argc > 2)
	{
		while (i + 1 < argc)
		{
			if (!check_args(*argv[i + 1], stack_a))
				exit(0);
			if (ft_atol(argv[i + 1]) > MAX_INT
				|| ft_atol(argv[i + 1]) < MIN_INT)
			{
				write(STDERR_FILENO, ERR, 7);
				exit(0);
			}
			stack_a->number[i] = ft_atoi(argv[i + 1]);
			check_duplicates(stack_a->number[i], stack_a);
			stack_a->size++;
			i++;
		}
		stack_b->number = malloc((stack_a->size) * sizeof(int));
	}
	else
		string_args(stack_a, stack_b, argv);
}

void	init_stack(t_pile *stack_a, t_pile *stack_b, int argc)
{
	stack_a->number = malloc((argc - 1) * sizeof(int));
	stack_a->size = 0;
	stack_b->size = 0;
}
