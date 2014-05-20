/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <ael-kadh@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			ft_parseargs(int ac, char **av, t_data *data)
{
	int		i;
	int		nb_player;

	i = 1;
	data->nbdump = 0;
	if (1 < ac && ft_strcmp(av[1], "-dump") == 0)
	{
		if (ac == 2 || !ft_isnbr(av[2]))
			ft_error(17);
		data->nbdump = ft_atoi(av[2]);
		i += 2;
	}
	nb_player = ft_countplayer(ac, av, i) + 1;
	if (nb_player > MAX_PLAYERS)
		ft_error(18);
	data->nb_player = nb_player - 1;
	data->idplayer = ft_newidplayer(nb_player);
	data->player = (t_player **)malloc(sizeof(t_player *) * nb_player);
	ft_fillplayer(ac, av, data, i);
	ft_playerid(data);
	free(data->idplayer);
}

t_reg		**ft_createreg()
{
	t_reg		**reg;
	int			i;

	reg = (t_reg **)malloc(sizeof(t_reg *) * REG_NUMBER + 1);
	i = 1;
	while (i <= REG_NUMBER)
	{
		reg[i] = (t_reg *)malloc(sizeof(t_reg));
		reg[i]->n = i;
		reg[i]->data = (char *)ft_memalloc(REG_SIZE + 1);
		i++;
	}
	reg[i] = NULL;
	return (reg);
}

void		*ft_putincode(t_data *data, int i, char *str)
{
	char	*code;
	int		fd;
	char	**tab;
	int		ret;

	tab = (char **)malloc(sizeof(char *) * 3);
	fd = open(str, O_RDONLY);
	ret = read(fd, code, NAME_SIZE + 1);
	code[ret] = 0;
	if (ret != NAMESIZE)
		ft_error(5);
	data->buff[0] = (char *)malloc(sizeof(char) * ft_strlen(code));
	data->buff[0] = ft_strdup(code);
	read(fd, code, COMMENT_SIZE);
	code[ret] = 0;
	data->buff[1] = (char *)malloc(sizeof(char) * ft_strlen(code));
	data->buff[1] = ft_strdup(code);
	data->buff[2] = NULL;
	while (i < len)
	{
		read(fd, code, 1);
		data->vm[data->player[i]->pos + i] = ft_strdup(code);
		i++;
	}
	return (code);
}

void		ft_initvm(t_player **data)
{
	int		i;

	i = 0;
	data->vm = (char *)malloc(MEM_SIZE);
	while (data->player[i] != NULL)
	{
		ft_memcpy(&vm[data->player[i]->position], data->player[i]->code, \
					data->player[i - 1]->len);
		i++;
	}
}

