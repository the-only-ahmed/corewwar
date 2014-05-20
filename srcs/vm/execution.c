/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <ael-kadh@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_execcontinue(t_data *data)
{
	int		i;

	data->cycle = 0;
	while (data->process[i])
	{
		ft_execpc(data, data->player[i]->pc->data, i);
		++i;
	}
}

void		ft_exec(int count, t_data *data, int i)
{
	if (data->player[i]->wait == -1)
		data->player[i]->wait = count;
	if (data->player[i]->wait == 0)
			data->cycle= -1;
}

void		ft_execfirst(t_data *data)
{
	int		i;

	i = 0;
	while (data->player[i])
	{
		ft_memcpy(data->player[i]->pc->data, data->player[i]->code, 5);
		data->player[i]->pc->data[6] = '\0';
		ft_execpc(data, data->player[i]->pc->data[6], i);
		i++;
	}
	ft_execcontinue(data);
}

int			ft_countplayer(int ac, char **av, int i)
{
	int		nb_player;

	nb_player = 0;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-n") == 0)
		{
			if (i + 1 >= ac || !ft_isnbr(av[i + 1]))
				ft_error(17);
			i += 2;
		}
		if (i >= ac || !ft_ischampion(av[i]))
			ft_error(17);
		nb_player++;
		i++;
	}
	if (nb_player < 2 || nb_player > MAX_PLAYERS)
		ft_error(17);
	return (nb_player);
}

void		ft_delid(char **tab, int id)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if ((*tab)[i] == id)
		{
			(*tab)[i] = 0;
			return ;
		}
		i++;
	}
}
