/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:04:45 by mel-kada          #+#    #+#             */
/*   Updated: 2020/02/24 10:04:46 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t size;
	size_t i;
	size_t j;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	size = ft_strlen(needle);
	i = 0;
	j = 0;
	while (haystack[i] && needle[j] && i < len)
	{
		if (haystack[i] == needle[j])
		{
			i++;
			j++;
			if (size == j)
				return ((char *)haystack + ((i - j)));
		}
		else
		{
			i = (i - j) + 1;
			j = 0;
		}
	}
	return (NULL);
}
