/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <lsirigna@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int ac, char **av)
{
	t_data		*data;
	int			i;

	i = 1;
	if (ac <= 1 && ac > MAX_ARGS_NUMBER + 1)
		ft_error(0);
	data = (t_data *)malloc(sizeof(t_data));
	data->cycle_to_die = CYCLE_TO_DIE;
	ft_parseargs(ac, av, data);
	ft_initvm(data);
	return (0);
}
