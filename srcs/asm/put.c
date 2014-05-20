/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <sballet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "asm.h"

void	ft_putchartob2(char *str, t_inc *inc)
{
	int		i;
	int		zero;

	zero = 0;
	i = 0;
	ft_putstr("Comment : \"");
	if (str)
		ft_putstr(str);
	ft_putendl("\"");
	while (str && str[i] != 0)
	{
		write(inc->out, &str[i], sizeof(unsigned char));
		i++;
	}
	while (i < COMMENT_LENGTH)
	{
		write(inc->out, &zero, sizeof(unsigned char));
		i++;
	}
}

void	ft_putchartob(char *str, t_inc *inc)
{
	int		i;
	int		zero;

	zero = 0;
	i = 0;
	ft_putstr("Name :\t  \"");
	if (str)
		ft_putstr(str);
	ft_putendl("\"");
	while (str && str[i] != 0)
	{
		write(inc->out, &str[i], sizeof(unsigned char));
		i++;
	}
	while (i < PROG_NAME_LENGTH)
	{
		write(inc->out, &zero, sizeof(unsigned char));
		i++;
	}
}

void	ft_putarg(t_inc *inc)
{
	char	**args;
	int		i;
	int		j;

	j = 0;
	args = inc->args;
	while (args[j])
	{
		i = 0;
		if ((ft_istype(args[j]) & inc->op_tab[inc->count].arg[j]) == 0)
			ft_error_arg(inc, inc->op_tab[inc->count].arg[j]);
		if (ft_istype(args[j]) == T_REG)
			ft_width(inc, ft_atoi(args[j] + 1), T_REG);
		else if (ft_istype(args[j]) == T_IND)
			ft_arg_ind(inc, args[j]);
		else if (ft_istype(args[j]) == T_DIR)
			ft_arg_dir(inc, args[j]);
		j++;
	}
	if (inc->op_tab[inc->count].arg[j])
		ft_error_name(inc, "too few argument for ");
}

void	ft_putnb_comment(int fd, t_list *lst)
{
	int		nb;

	nb = ft_nblist(lst);
	if (ft_endian() != 0)
		nb = ft_convert(nb, sizeof(int));
	write(fd, &nb, sizeof(int));
}

void	ft_print(t_inc *inc)
{
	inc->out = open(inc->new, O_WRONLY | O_CREAT | O_TRUNC, 0755);
	write(inc->out, &(inc->biin), sizeof(int));
	ft_putchartob(inc->name, inc);
	ft_putnb_comment(inc->out, inc->lst);
	ft_putchartob2(inc->comment, inc);
	ft_putlst(inc->lst, inc->out);
	close(inc->out);
}
