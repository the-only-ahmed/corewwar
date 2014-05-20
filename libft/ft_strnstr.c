/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <sballet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(s2) > n)
		return (NULL);
	if (s2[i] == '\0')
		return ((char *) s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] == s2[j]
				&& s2[j] != '\0'
				&& s1[i + j] != '\0'
				&& i + j < n)
			j++;
		if (s2[j] == 0 && i + j <= n)
			return ((char *) (s1 + i));
		i++;
	}
	return (NULL);
}
