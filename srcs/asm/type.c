/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <sballet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "asm.h"

int		ft_isnbr(const char *s)
{
	int		i;

	i = 0;
	if ((s[i] == '+' || s[i] == '-') && s[i + 1])
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_islabel(char *s)
{
	int		i;

	i = 1;
	if (s[0] != LABEL_CHAR)
		return (0);
	while (s[i] && ft_strchr(LABEL_CHARS, s[i]) != NULL)
		i++;
	if (s[i])
		return (0);
	return (1);
}

int		ft_isreg_number(char *s)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (ft_isdigit(s[i]))
	{
		nb = (nb * 10) + (s[i] - '0');
		i++;
	}
	if (s[i] != '\0' || nb > REG_NUMBER)
		return (0);
	return (1);
}

int		ft_istype(char *s)
{
	if (s[0] == 'r' && ft_isreg_number(s + 1))
		return (T_REG);
	if (ft_islabel(s) || ft_isnbr(s))
		return (T_IND);
	if (s[0] == DIRECT_CHAR && (ft_islabel(s + 1) || ft_isnbr(s + 1)))
		return (T_DIR);
	return (0);
}
