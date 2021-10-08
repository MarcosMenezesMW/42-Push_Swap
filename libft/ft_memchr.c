/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mwmms@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:03:48 by user42            #+#    #+#             */
/*   Updated: 2021/06/07 20:34:11 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_s;
	size_t			i;

	p_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p_s[i] == (unsigned char)c)
			return (p_s + i);
		i++;
	}
	return (NULL);
}
