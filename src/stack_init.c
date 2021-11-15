/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:49:26 by mameneze          #+#    #+#             */
/*   Updated: 2021/11/15 19:04:29 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_args(char *c, t_pile *stack_a)
{
	printf("CHAR: %s\n", c);
	int	i;
	int	size;
	i = 0;
	size = ft_strlen(c);
	while (i < size)
	{
		if (!ft_isdigit(c[i]) && c[i] != '-')
		{
			free(stack_a->number);
			return (write(STDERR_FILENO, ERR, 7), 0);
		}
		i++;
	}
	return (1);
}

static void	check_duplicates(char c, t_pile *stack_a)
{
	int	i;
	int	size;
	int	check;

	size = stack_a->size;
	i = 0;
	check = 0;
	while (i < size)
	{
		if (stack_a->number[i] == c)
			check++;
		i++;
	}
	if (check > 1)
	{
		free(stack_a->number);
		write(STDERR_FILENO, ERR, 7);
		exit(1);
	}
}

static int	string_args(t_pile *stack_a, t_pile *stack_b, char *argv[])
{
	char	**string;
	int		i;
	int		j;

	j = 0;
	string = ft_split(argv[1], ' ');
	i = count_string_args(string);
	while (j < i)
	{
		printf("STRING %d: %s\n", j, string[j]);
		if (!check_args(string[j], stack_a))
			return (free_aux_string(string, i), exit(0), 0);
		if (ft_atol(string[j]) > MAX_INT
			|| ft_atol(string[j]) < MIN_INT)
		{
			write(STDERR_FILENO, ERR, 7);
			exit(0);
		}
		stack_a->number[j] = ft_atoi(string[j]);
		stack_a->size++;
		check_duplicates(stack_a->number[j], stack_a);
		j++;
	}
	free_aux_string(string, i);
	return (stack_b->number = malloc((stack_a->size) * sizeof(int)), 0);
}

void	fill_stack(t_pile *stack_a, t_pile *stack_b, char **argv, int argc)
{
	int	i;

	i = 0;
	if (argc > 2)
	{
		while (i + 1 < argc)
		{
			printf("STRING %d: %s\n", i, argv[i + 1]);
			if (!check_args(argv[i + 1], stack_a))
				exit(0);
			if (ft_atol(argv[i + 1]) > MAX_INT
				|| ft_atol(argv[i + 1]) < MIN_INT)
			{
				write(STDERR_FILENO, ERR, 7);
				exit(0);
			}
			stack_a->number[i] = ft_atoi(argv[i + 1]);
			stack_a->size++;
			check_duplicates(stack_a->number[i], stack_a);
			i++;
		}
		stack_b->number = malloc((stack_a->size) * sizeof(int));
	}
	else
		string_args(stack_a, stack_b, argv);
}

void	init_stack(t_pile *stack_a, t_pile *stack_b, int argc, char *argv[])
{
	int		i;
	int		j;
	char	**string;

	j = 0;
	if (argc != 2)
		stack_a->number = malloc((argc - 1) * sizeof(int));
	else
	{
		string = ft_split(argv[1], ' ');
		i = count_string_args(string);
		stack_a->number = malloc(i * sizeof(int));
		free_aux_string(string, i);
	}
	stack_a->size = 0;
	stack_b->size = 0;
}
