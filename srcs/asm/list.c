/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <sballet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_lstadd(t_list **lst, int nb, int nb_oc)
{
	t_list	*tmp;
	t_list	*new;

	if ((new = (t_list *) malloc(sizeof(*new))) == NULL)
		return ;
	new->data = nb;
	new->nb_oc = nb_oc;
	new->next = NULL;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_putlst(t_list *lst, int fd)
{
	while (lst)
	{
		write(fd, &(lst->data), lst->nb_oc);
		lst = lst->next;
	}
}

t_list	*ft_lst_getnbr(t_list *lst, int nb)
{
	int		i;

	i = 0;
	while (i < nb && lst)
	{
		i += lst->nb_oc;
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstdel(t_list **lst)
{
	if (*lst)
	{
		ft_lstdel(&((*lst)->next));
		free(*lst);
		*lst = NULL;
	}
}

int		ft_nblist(t_list *lst)
{
	int		nb;

	nb = 0;
	while (lst)
	{
		nb += lst->nb_oc;
		lst = lst->next;
	}
	return (nb);
}
