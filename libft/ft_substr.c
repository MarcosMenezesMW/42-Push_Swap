/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:33:13 by mameneze          #+#    #+#             */
/*   Updated: 2021/06/06 12:41:17 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	max_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start < s_len)
		max_len = s_len - start;
	else
		max_len = 0;
	if (max_len > len)
		max_len = len;
	substr = malloc(sizeof(char) * (max_len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, max_len + 1);
	return (substr);
}
