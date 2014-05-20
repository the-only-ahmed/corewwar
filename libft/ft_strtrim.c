/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <sballet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char		*trim;
	size_t		len;
	size_t		start;
	size_t		end;

	start = 0;
	end = ft_strlen(s);
	while (s[start] && (ft_isspace(s[start]) != 0))
		start++;
	while (end > start && (ft_isspace(s[end]) != 0 || s[end] == 0))
		end--;
	if (start >= end)
		end = start - 1;
	len = end - start + 1;
	trim = ft_strsub(s, start, len);
	return (trim);
}
