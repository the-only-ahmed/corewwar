/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execpc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <ael-kadh@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_execpc(t_data *data, char *str, int i)
{
	if (str[0] == 0b00000001)
	{
		ft_exec(10, data, i);
		if (dat->player[i]->wait == 0)
			data->cycle = ft_live(data, &str[1], i);
	}
	else if (str[0] == 0b00000010)
	{
		ft_exec(5, data, i);
		if (dat->player[i]->wait == 0)
			data->cycle = ft_ld(data, str[1], &str[2], i);
	}
	if (str[0] == 0b00000011)
	{
		ft_exec(5, data, i);
		if (dat->player[i]->wait == 0)
			data->cycle = ft_st(data, str[1], &str[2], i);
	}
	else
		ft_execpc_2(data, str, i);
	if (data->cycle != -1)
		data->cycle--;
}

void	ft_execpc_2(t_data *data, char *str, int i)
{
	if (str[0] == 0b00000100)
	{
		ft_exec(10, data, i);
		if (dat->player[i]->wait == 0)
			data->cycle = ft_add(data, str[1], &str[2], i);
	}
	else if (str[0] == 0b00000101)
	{
		ft_exec(10, data, i);
		if (dat->player[i]->wait == 0)
			data->cycle = ft_sub(data, str[1], &str[2], i);
	}
	else if (str[0] == 0b00000110)
	{
		ft_exec(6, data, i);
		if (dat->player[i]->wait == 0)
			data->cycle = ft_and(data, str[1], &str[2], i);
	}
	else
		ft_execpc_3(data, str, i);
}

void	ft_execpc_3(t_data *data, char *str, int i)
{
	if (str[0] == 0b00000111)
	{
		ft_exec(6, data, i);
		if (dat->player[i]->wait == 0)
			data->cycle = ft_or(data, str[1], &str[2], i);
	}
	else if (str[0] == 0b00001000)
	{
		ft_exec(6, data, i);
		if (dat->player[i]->wait == 0)
			data->cycle = ft_xor(data, str[1], &str[2], i);
	}
	else if (str[0] == 0b00001001 && data->player[i]->carry == 1)
	{
		ft_exec(1, data, i);
		if (dat->player[i]->wait == 0)
			data->cycle = ft_zjmp(data, &str[1], i);
	}
	else
		ft_execpc_4(data, str, i);
}

void	ft_execpc_4(t_data *data, char *str, int i)
{
	if (str[0] == 0b00001010)
	{
		ft_exec(25, data, i);
		if (dat->player[i]->wait == 0)
			data->cycle = ft_ldi(data, str[1], &str[2], i);
	}
	else if (str[0] == 0b00001011)
	{
		ft_exec(25, data, i);
		if (dat->player[i]->wait == 0)
			data->cycle = ft_sti(data, str[1], &str[2], i);
	}
	else if (str[0] == 0b00001100)
	{
		ft_exec(800, data, i);
		if (dat->player[i]->wait == 0)
			data->cycle = ft_fork(data, &str[1], i);
	}
	else
		ft_execpc_5(data, str, i);
}

void	ft_execpc_5(t_data *data, char *str, int i)
{
	if (str[0] == 0b00001101)
	{
		ft_exec(10, data, i);
		if (dat->player[i]->wait == 0)
			data->cycle = ft_lld(data, str[1], &str[2], i);
	}
	else if (str[0] == 0b00001110)
	{
		ft_exec(50, data, i);
		if (dat->player[i]->wait == 0)
			data->cycle = ft_lldi(data, str[1], &str[2], i);
	}
	else if (str[0] == 0b00001111)
	{
		ft_exec(1000, data, i);
		if (dat->player[i]->wait == 0)
			data->cycle = ft_lfork(data, &str[1], i);
	}
	else if (str[0] == 0b00010000)
	{
		ft_exec(2, data, i);
		if (dat->player[i]->wait == 0)
			data->cycle = ft_aff(data, str[1], &str[2], i);
	}
}
