/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:11:02 by user42            #+#    #+#             */
/*   Updated: 2021/06/06 12:39:54 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	last_char;

	i = 0;
	last_char = 0;
	if (!src)
		return (0);
	while (src[i] != '\0')
	{
		if (i + 1 < size)
		{
			last_char++;
			dst[i] = src[i];
		}
		i++;
	}
	if (size > 0)
		dst[last_char] = '\0';
	return (i);
}
