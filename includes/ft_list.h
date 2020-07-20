/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 05:24:33 by val               #+#    #+#             */
/*   Updated: 2020/07/14 20:14:01 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list_hesh
{
	int					key;
	char				*name;
	int					x;
	int					y;
	struct s_list_hesh	*next;
	struct s_list_hesh	*deep;
	int					level;
}				t_list_hesh;

typedef struct	s_room
{
	int	key;
	int	vertex;
	int	*tube_out;
	int	*weight_out;
	int	count_tube_out;
	int	*tube_in;
	int	*weight_in;
	int	count_tube_in;
}				t_room;

typedef struct	s_list_path
{
	int					count_path;
	int					key_room;
	struct s_list_path	*next;
}				t_list_path;

typedef	struct	s_storage
{
	int			count_ants;
	int			max_count_path;
	int			count_room;
	int			key_start;
	char		*name_start;
	int			key_end;
	char		*name_end;
	int			link;
	t_list_hesh	*table_hesh;
	t_room		*head;
	t_room		*head_culc;
	t_list_path	*path_list;
	t_list_path	*path_list_condidate;
}				t_storage;

/*
**	ft_list
*/

/*
t_listi			*ft_create_listi(int n, t_listi *next);
void			ft_free_listi(t_listi *head);
t_storage		*ft_create_storage(void);
void			ft_free_storage(t_storage *storage);
*/


t_storage 	*ft_create_storage(void);
t_room 		*ft_create_head(t_storage *st);
void		ft_free_storage(t_storage *st);

t_list_path	*ft_create_list_path(int max_count_path);
void		ft_free_list_path(t_list_path *list_path);

t_list_hesh	*ft_create_list_hesh(char *name, int x, int y, t_storage *st);
t_list_hesh	*ft_create_list_hesh(char *name, int x, int y, t_storage *st);
int			hesh_install_key(int key, t_list_hesh *list);
int			hash_get_key(char *name, t_storage *st);
char		*hash_get_name(int key, t_list_hesh *list);
void		ft_free_list_hash(t_list_hesh *list);


#endif
