/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <sballet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "asm.h"
#include <inttypes.h>

int		ft_check_string(char *name)
{
	int		i;

	if (name == NULL || name[0] != '"')
		return (0);
	i = 1;
	while (name[i] && name[i] != '"')
		i++;
	if (name[i] == '"' && name[i + 1] == '\0')
		return (1);
	return (0);
}

void	ft_check_name(t_inc *inc)
{
	if (!ft_check_string(inc->split[1]) || inc->split[2] != NULL)
	{
		ft_error_line("Bad argument name.", inc->nb_line);
		ft_incdel(&inc, NULL);
	}
	inc->name = ft_cleaninfo(inc->split[1]);
	if (ft_strlen(inc->name) > PROG_NAME_LENGTH)
	{
		ft_error_line("Name too long.", inc->nb_line);
		ft_incdel(&inc, NULL);
	}
}

void	ft_check_comment(t_inc *inc)
{
	if (!ft_check_string(inc->split[1]) || inc->split[2] != NULL)
	{
		ft_error_line("Bad argument comment.", inc->nb_line);
		ft_incdel(&inc, NULL);
	}
	inc->comment = ft_cleaninfo(inc->split[1]);
	if (ft_strlen(inc->comment) > COMMENT_LENGTH)
	{
		ft_error_line("Comment too long.", inc->nb_line);
		ft_incdel(&inc, NULL);
	}
}

int		ft_endian(void)
{
	volatile uint32_t	i;

	i = 0x01234567;
	return (*((uint8_t *)(&i))) == 0x67;
}
