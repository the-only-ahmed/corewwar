/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_todo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <ael-kadh@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_addid(t_data *data, int id)
{
	int		i;

	i = 0;
	while (data->idplayer[i])
	{
		if (data->idplayer[i] == id)
			ft_error(17);
		i++;
	}
	data->idplayer[i] = id;
}

void	ft_fillplayer(int ac, char **av, t_data *data, int i)
{
	int		nb_player;

	nb_player = 0;
	while (i < ac)
	{
		data->player[nb_player] = (t_player *)malloc(sizeof(t_player));
		data->player[nb_player]->id = 0;
		if (ft_strcmp(av[i], "-n") == 0)
		{
			if (i + 1 >= ac || !ft_isnbr(av[i + 1]))
				|| ft_atoi(av[i + 1] <= 0)
						ft_error(17);
			ft_addid(data, ft_atoi(av[i + 1]));
			data->player[nb_player]->id = ft_atoi(av[i + 1]);
			i += 2;
		}
		data->player[nb_player]->carry = 0;
		ft_putincode(data, nb_player, av[i]);
		data->player[nb_player]->position = (MEM_SIZE / ac) * (nb_player);
		data->player[nb_player]->reg = ft_createreg();
		data->player[nb_player]->pc->n = 0;
		nb_player++;
		i++;
	}
	data->player[nb_player] = NULL;
}


int		ft_findid(int *tab, int id, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		if (tab[i] == id)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_listid(int *tab, int nb)
{
	char	*new;
	int		i;

	new = (char *) malloc(sizeof(*new) * MAX_PLAYERS);
	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (!ft_findid(tab, i + 1, nb))
			new[i] = i + 1;
		i++;
	}
	return (new);
}

int		ft_minid(char **tab)
{
	int		i;
	int		nb;

	i = 0;
	while ((*tab)[i] == 0)
		i++;
	nb = (*tab)[i];
	(*tab)[i] = 0;
	return (nb);
}
