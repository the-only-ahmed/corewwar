/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <sballet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t					i;
	unsigned char			*puc1;
	const unsigned char		*puc2;

	i = 0;
	puc1 = (unsigned char *) s1;
	puc2 = (const unsigned char *) s2;
	while (i < n)
	{
		puc1[i] = puc2[i];
		if (puc2[i] == (unsigned char) c)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
