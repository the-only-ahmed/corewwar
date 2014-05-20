/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <sballet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <inttypes.h>

int		ft_convert(int i, int nb_oc)
{
	int		new;
	int		oct1;
	int		oct2;
	int		oct3;
	int		oct4;

	new = i;
	if (nb_oc == 4)
	{
		oct1 = ((i & 0xFFFF0000) >> 24);
		oct2 = (((i << 8) >> 24) << 8) & 0xFF00;
		oct3 = (((i & 0xFF00) >> 8) << 16);
		oct4 = (i << 24);
		new = oct1 + oct2 + oct3 + oct4;
	}
	else if (nb_oc == 2)
	{
		oct1 = i << 8;
		oct2 = (i & 0xFF00) >> 8;
		new = oct1 + oct2;
	}
	return (new);
}

void	ft_width(t_inc *inc, int nb, int nb_oc)
{
	if (ft_endian() != 0)
		nb = ft_convert(nb, nb_oc);
	ft_lstadd(&(inc->lst), nb, nb_oc * sizeof(unsigned char));
}


void	ft_parseargs(t_inc *inc)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (inc->args[1] || ft_strchr(inc->args[0], DIRECT_CHAR) == NULL)
	{
		while (inc->args[i])
		{
			if (ft_strchr(inc->args[i], 'r') != NULL)
				nb = (nb + REG_CODE) << 2;
			else if (ft_strchr(inc->args[i], DIRECT_CHAR) != NULL)
				nb = (nb + DIR_CODE) << 2;
			else
				nb = (nb + IND_CODE) << 2;
			i++;
		}
		while (i < 3)
		{
			nb = nb << 2;
			i++;
		}
	}
	ft_lstadd(&(inc->lst), nb, sizeof(unsigned char));
}

char	*ft_cleaninfo(char *str)
{
	char	*new;
	char	*tmp;
	char	*b;

	tmp = ft_strchr(str, '"');
	tmp++;
	b = ft_strrchr(tmp, '"');
	b[0] = '\0';
	new = ft_strdup(tmp);
	return (new);
}

void	ft_everyargs(t_inc *inc, t_op *op_tab)
{
	inc->split = ft_strsplit_trim(inc->buff, '\t');
	if (ft_strcmp(inc->split[0], NAME_CMD_STRING) == 0)
	{
		ft_check_name(inc);
		return ;
	}
	else if (ft_strcmp(inc->split[0], COMMENT_CMD_STRING) == 0)
	{
		ft_check_comment(inc);
		return ;
	}
	else if (inc->split[0][0] == COMMENT_CHAR)
		return ;
	inc->nb = ft_nblist(inc->lst);
	if (ft_findname(inc, op_tab))
	{
		if (ft_isnewlabel(inc->split[0]))
		{
			inc->split[0][ft_strlen(inc->split[0]) - 1] = '\0';
			ft_lstlabel_add(&(inc->label1), inc->split[0], inc->nb, 0);
		}
		else
			ft_error_instruction(inc);
	}
}
