/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <sballet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_change_adr(t_list **lst, int adr1, int adr2)
{
	int		nb;

	nb = (adr1 - adr2);
	if (ft_endian() != 0)
		nb = ft_convert(nb, (*lst)->nb_oc);
	(*lst)->data = nb;
}

void	ft_filllabel(t_inc *inc)
{
	t_lstlabel	*tmp1;
	t_lstlabel	*tmp2;
	t_list		*lst1;

	tmp2 = inc->label2;
	while (tmp2)
	{
		if ((tmp1 = ft_lstlabel_chr(inc->label1, tmp2->label)))
		{
			lst1 = ft_lst_getnbr(inc->lst, tmp2->adr2);
			if (lst1)
			ft_change_adr(&lst1, tmp1->adr1, tmp2->adr1);
			else
				ft_incdel(&inc, "Error.");
		}
		else
		{
			ft_putstr(tmp2->label);
			ft_incdel(&inc, " is a bad label.");
		}
		tmp2 = tmp2->next;
	}
}

int		ft_isnewlabel(char *s)
{
	int		i;

	i = 0;
	while (s[i] && ft_strchr(LABEL_CHARS, s[i]) != NULL)
		i++;
	if (s[i] == LABEL_CHAR)
		i++;
	if (s[i])
		return (0);
	return (1);
}

int		ft_findname(t_inc *inc, t_op *op_tab)
{
	inc->count = 0;
	while (op_tab[inc->count].name != NULL)
	{
		if (ft_strcmp(inc->split[0], op_tab[inc->count].name) == 0)
		{
			ft_lstadd(&(inc->lst), op_tab[inc->count].bin,
				sizeof(unsigned char));
			if (inc->split[1])
			{
				inc->args = ft_strsplit_trim(inc->split[1], SEPARATOR_CHAR);
				if (op_tab[inc->count].oct)
					ft_parseargs(inc);
				ft_putarg(inc);
				ft_splitdel(&(inc->args));
			}
			else
			{
				ft_error_line("No such args for ", inc->nb_line);
				ft_incdel(&inc, op_tab[inc->count].name);
			}
			return (0);
		}
		inc->count++;
	}
	return (1);
}

void	ft_incdel(t_inc **inc, char *error)
{
	if (*inc)
	{
		ft_splitdel(&((*inc)->split));
		ft_splitdel(&((*inc)->args));
		ft_strdel(&((*inc)->new));
		ft_strdel(&((*inc)->buff));
		ft_strdel(&((*inc)->name));
		ft_strdel(&((*inc)->comment));
		ft_lstdel(&((*inc)->lst));
		ft_lstlabeldel(&((*inc)->label1));
		ft_lstlabeldel(&((*inc)->label2));
		free(*inc);
	}
	if (error)
		ft_putendl(error);
	exit(0);
}
