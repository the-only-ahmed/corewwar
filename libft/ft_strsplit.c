/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <sballet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_nbsplit(char const *s, char c)
{
	size_t		count;
	size_t		i;

	count = 0;
	i = 0;
	while (s != NULL && s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char		**ft_getsplit(char const *s, char c, char **split, size_t len)
{
	size_t		i;
	size_t		start;
	size_t		end;
	size_t		nb;

	i = 0;
	nb = 0;
	while (nb < len)
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		split[nb] = ft_strsub(s, start, end - start);
		nb++;
	}
	return (split);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**split;
	size_t		count;

	count = ft_nbsplit(s, c);
	split = (char **) malloc(sizeof(*split) * (count + 1));
	if (split == NULL)
		return (NULL);
	split = ft_getsplit(s, c, split, count);
	split[count] = NULL;
	return (split);
}
