/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team sudo <sballet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:44 by sudo              #+#    #+#             */
/*   Updated: 2013/11/23 04:39:29 by sudo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "get_next_line.h"
# include "op.h"
# include <fcntl.h>

typedef struct			s_list
{
	int					data;
	int					nb_oc;
	struct s_list		*next;
}						t_list;

typedef struct			s_lstlabel
{
	char				*label;
	int					adr1;
	int					adr2;
	struct s_lstlabel	*next;
}						t_lstlabel;

typedef struct			s_inc
{
	int					nb_line;
	t_op				*op_tab;
	char				*new;
	char				*buff;
	char				**split;
	char				**args;
	int					out;
	int					count;
	int					nb;
	char				*name;
	char				*comment;
	t_list				*lst;
	t_lstlabel			*label1;
	t_lstlabel			*label2;
	int					biin;
}						t_inc;

char		*ft_cleaninfo(char *str);
int			ft_check_string(char *name);
int			ft_convert(int i, int nb_oc);
int			ft_endian(void);
int			ft_findname(t_inc *inc, t_op *op_tab);
int			ft_islabel(char *s);
int			ft_isnbr(const char *s);
int			ft_nblist(t_list *lst);
int			ft_isnewlabel(char *s);
int			ft_isreg_number(char *s);
int			ft_istype(char *s);
int			ft_occ_nb(char *str, char c);
int			ft_open(char *file);
void		ft_error_line(char *error, int nb);
void		ft_error_name(t_inc *inc, char *name);
void		ft_error_instruction(t_inc *inc);
void		ft_error_arg(t_inc *inc, int arg);
void		ft_read_champion(t_inc *inc, int fd);
void		ft_arg_dir(t_inc *inc, char *arg);
void		ft_arg_ind(t_inc *inc, char *arg);
void		ft_change_adr(t_list **lst, int adr1, int adr2);
void		ft_check_comment(t_inc *inc);
void		ft_check_name(t_inc *inc);
void		ft_everyargs(t_inc *inc, t_op *op_tab);
void		ft_filllabel(t_inc *inc);
void		ft_incdel(t_inc **inc, char *error);
void		ft_lstadd(t_list **lst, int nb, int nb_oc);
void		ft_lstdel(t_list **lst);
void		ft_lstlabel_add(t_lstlabel **lst, char *label, int adr1, int adr2);
void		ft_lstlabeldel(t_lstlabel **lst);
void		ft_parseargs(t_inc *inc);
void		ft_print(t_inc *inc);
void		ft_putarg(t_inc *inc);
void		ft_putchartob(char *str, t_inc *inc);
void		ft_putchartob2(char *str, t_inc *inc);
void		ft_putlst(t_list *lst, int fd);
void		ft_putnb_comment(int fd, t_list *lst);
void		ft_width(t_inc *inc, int nb, int nb_oc);
t_inc		*ft_incinit(char *file);
t_list		*ft_lst_getnbr(t_list *lst, int nb);
t_lstlabel	*ft_lstlabel_chr(t_lstlabel *lst, char *label);


#endif /* ASM_H */
