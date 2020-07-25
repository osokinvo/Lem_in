/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 05:24:33 by val               #+#    #+#             */
/*   Updated: 2020/07/25 22:46:39 by val              ###   ########.fr       */
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

typedef struct	s_room_addition
{
	char	*name;
	int		lem;
}				t_room_addition;

typedef struct	s_room
{
	int				key;
	int				vertex;
	int				*tube_out;
	int				count_tube;
	int				*tube_in; //1 - действительное значение веса,  - недействительное значение веса, -1 - приоритетное значение веса.
	int				visited;
	t_room_addition	*add;
}				t_room;

typedef struct	s_path
{
	int					count_rooms;
	int					*rooms;
	struct s_path		*next;
}				t_path;

typedef struct	s_list_path
{
	int		count_path;
	int		heigth;
	t_path	*paths;
}				t_list_path;

typedef	struct	s_storage
{
	int			count_ants;
	int			max_count_path;
	int			count_rooms;
	int			key_start;
	char		*file_name;
	int			fd;
	char		*name_start;
	int			key_end;
	char		*name_end;
	int			link;
	t_list_hesh	*table_hesh;
	t_room		*head;
	t_list_path	*path_list;
}				t_storage;

# define INVALID_TUBE -1

# define ACTUAL_WEIGTH 1
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
void		ft_free_head(t_room *head, int count_rooms);
void		ft_free_storage(t_storage *st);

t_list_path	*ft_create_list_path(void);
void		ft_feee_list_paths(t_list_path *paths);
void		ft_free_path(t_path *path);

t_list_hesh	*ft_create_list_hesh(char *name, int x, int y, t_storage *st);
t_list_hesh	*ft_create_list_hesh(char *name, int x, int y, t_storage *st);
int			hesh_install_key(int key, t_list_hesh *list);
int			hesh_get_key(char *name, t_storage *st);
char		*hash_get_name(int key, t_list_hesh *list);
void		ft_free_list_hash(t_list_hesh *list);
void		ft_free_list_hash1(t_list_hesh *list);
#endif
