/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:01:16 by mameneze          #+#    #+#             */
/*   Updated: 2021/10/16 18:58:45 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# define ERRPARAM "Invalid Parameters!\n"
# define ERRDUP "Duplicated numbers!\n"

typedef struct s_pile{
	int	*number;
	int	size;
}				t_pile;

void	init_stack(t_pile *stack_a, t_pile *stack_b, int argc);
void	fill_stack(t_pile *stack_a, t_pile *stack_b, char **argv, int argc);
void	swap(t_pile *stack_a);
void	push(t_pile *stack_a, t_pile *stack_b);
void	rotate(t_pile *stack);
void	reverse_rotate(t_pile *stack);
int		is_sorted(t_pile stack);

#endif