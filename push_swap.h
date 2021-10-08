/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:01:16 by mameneze          #+#    #+#             */
/*   Updated: 2021/10/07 21:02:06 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# define ERRPARAM "Invalid Parameters!\n"

typedef struct s_pile{
	int				number;
	struct s_pile	*next;
}				t_pile;

typedef struct s_stacks{
	struct s_pile	*stack_a;
	struct s_pile	*stack_b;
}				t_stacks;

t_pile	*create_node(int value);
void	add_node_back(t_pile **root, t_pile **node);
void	add_node_front(t_pile **root, t_pile **node);
void	swap_a(t_pile **n1, t_pile **n2);
void	push_b(t_pile **head, t_pile **b);

#endif