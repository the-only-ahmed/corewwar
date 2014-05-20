/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listlabel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <sballet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_lstlabel	*ft_lstlabel_chr(t_lstlabel *lst, char *label)
{
	while (lst)
	{
		if (ft_strcmp(lst->label, label) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void		ft_lstlabel_add(t_lstlabel **lst, char *label, int adr1, int adr2)
{
	t_lstlabel	*new;

	new = (t_lstlabel *) malloc(sizeof(*new));
	if (new == NULL)
		return ;
	new->label = ft_strdup(label);
	new->adr1 = adr1;
	new->adr2 = adr2;
	new->next = *lst;
	*lst = new;
}

void		ft_lstlabeldel(t_lstlabel **lst)
{
	if (*lst)
	{
		ft_lstlabeldel(&((*lst)->next));
		free(*lst);
		*lst = NULL;
	}
}
