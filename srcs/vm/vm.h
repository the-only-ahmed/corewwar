/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 21:36:59 by lsirigna          #+#    #+#             */
/*   Updated: 2014/02/02 16:33:20 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

typedef struct		s_process
{
	int			father;
	int			id;
}					t_process;

typedef struct		s_data
{
	int			cycle;
	int			*idplayer;
	t_player		**player;
	int			cycle_to_die;
	t_process		**process;
	char			*vm;
	int			nbdump;
	int			nb_player;
}					t_data;

typedef struct		header_s
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					header_t;

typedef struct		s_reg
{
	int			n;
	char			*data;
}					t_reg;

typedef struct		s_player
{
	int				id;
	header_t		header;
	char			*code;
	int				position;
	t_reg			**reg;
	t_reg			*pc;
	int			wait;
	int			carry;
	char			**buff;
}					t_player;

int		*ft_newidplayer(int nb);
void	ft_playerid(t_data *data);
int		ft_parseargs(int ac, char **av, t_data *data);
t_reg	**ft_createreg();
void	*ft_putincode(t_data *data, int i, char *str);
void	ft_initvm(t_player **data);
void	ft_execcontinue(t_data *data);
void	ft_exec(int count, t_data *data, int i);
void	ft_execfirst(t_data *data);
int		ft_countplayer(int ac, char **av, int i);
void	ft_delid(char **tab, int id);
void	ft_execpc(t_data *data, char *str, int i);
void	ft_execpc_2(t_data *data, char *str, int i);
void	ft_execpc_3(t_data *data, char *str, int i);
void	ft_execpc_4(t_data *data, char *str, int i);
void	ft_execpc_5(t_data *data, char *str, int i);
void	ft_addid(t_data *data, int id);
void	ft_fillplayer(int ac, char **av, t_data *data, int i);
int		ft_findid(int *tab, int id, int nb);
char	*ft_listid(int *tab, int nb);
int		ft_minid(char **tab);

#endif /* VM_H */
