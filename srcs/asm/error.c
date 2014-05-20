/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <sballet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_error_line(char *error, int nb)
{
	ft_putstr("Error at line #");
	ft_putnbr(nb);
	ft_putstr(": ");
	ft_putstr(error);
}

void	ft_error_name(t_inc *inc, char *name)
{
	ft_error_line(name, inc->nb_line);
	ft_incdel(&inc, inc->op_tab[inc->count].name);
}

void	ft_error_instruction(t_inc *inc)
{
	ft_error_line("Instruction : \"", inc->nb_line);
	ft_putstr(inc->split[0]);
	ft_incdel(&inc, "\" not found.");
}

void	ft_error_arg(t_inc *inc, int arg)
{
	if (arg == 0)
		ft_error_name(inc, "too much argument for ");
	else
		ft_error_name(inc, "bad argument for ");
}
