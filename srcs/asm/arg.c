/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <sballet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_arg_ind(t_inc *inc, char *arg)
{
	if (ft_isnbr(arg))
		ft_width(inc, ft_atoi(arg), T_IND);
	else
	{
		ft_lstlabel_add(&(inc->label2), arg + 1, inc->nb, ft_nblist(inc->lst));
		ft_width(inc, 0, 2);
	}
}

void	ft_arg_dir(t_inc *inc, char *arg)
{
	int		nb_oc;

	nb_oc = 0;
	if (ft_strcmp(inc->split[0], "live") == 0 ||
		ft_strcmp(inc->split[0], "lld") == 0)
		nb_oc += 2;
	if (ft_isnbr(arg + 1))
		ft_width(inc, ft_atoi(arg + 1), (T_DIR + nb_oc));
	else
	{
		ft_lstlabel_add(&(inc->label2), arg + 2, inc->nb, ft_nblist(inc->lst));
		ft_width(inc, 0, (2 + nb_oc));
	}
}
