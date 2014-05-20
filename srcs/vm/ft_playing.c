/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <ael-kadh@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_playerid(t_data *data)
{
	int		i;
	char	*tab_id;

	tab_id = ft_listid(data->idplayer, data->nb_player);
	i = 0;
	while (data->player[i])
	{
		if (data->player[i]->id == 0)
			data->player[i]->id = ft_minid(&tab_id);
		else
			ft_delid(&tab_id, data->player[i]->id);
		data->player[i]->reg[1]->data = &(data->player[i]->id);
		i++;
	}
	free(tab_id);
}

int		*ft_newidplayer(int nb)
{
	int		i;
	int		*tab;

	tab = (int *) malloc(sizeof(*tab) * nb);
	i = 0;
	while (i < nb)
		tab[i++] = 0;
	return (tab);
}
