/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <sballet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

t_inc	*ft_incinit(char *file)
{
	t_inc	*new;
	char	*tmp;

	new = (t_inc *) malloc(sizeof(*new));
	tmp = ft_strdup(file);
	tmp[ft_strlen(tmp) - 1] = 0;
	new->new = ft_strjoin(tmp, "cor");
	free(tmp);
	new->lst = NULL;
	new->name = NULL;
	new->comment = NULL;
	if (ft_endian() != 0)
		new->biin = ft_convert(COREWAR_EXEC_MAGIC, sizeof(int));
	else
		new->biin = COREWAR_EXEC_MAGIC;
	new->op_tab = op_tab;
	new->args = NULL;
	new->split = NULL;
	new->label1 = NULL;
	new->label2 = NULL;
	new->nb_line = 0;
	return (new);
}

int		ft_open(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("bad open\n");
		exit(0);
	}
	return (fd);
}

int		main(int ac, char **av)
{
	int			fd;
	t_inc		*inc;
	size_t		len;

	if (ac != 2)
		return (ft_putendl("Need Argument\n"), 0);
	len = ft_strlen(av[1]);
	if (len < 3 || av[1][len - 1] != 's' || av[1][len - 2] != '.')
	{
		ft_putstr(av[1]);
		ft_putstr(" is a bad file\n");
		return (0);
	}
	fd = ft_open(av[1]);
	inc = ft_incinit(av[1]);
	ft_read_champion(inc, fd);
	ft_filllabel(inc);
	ft_print(inc);
	close(fd);
	ft_incdel(&inc, NULL);
	return (0);
}

void	ft_read_champion(t_inc *inc, int fd)
{
	while (get_next_line(fd, &(inc->buff)) > 0)
	{
		inc->nb_line++;
		if (inc->buff[0] != '\0')
			ft_everyargs(inc, op_tab);
		ft_splitdel(&(inc->split));
		ft_strdel(&(inc->buff));
	}
}
