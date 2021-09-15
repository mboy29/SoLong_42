/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:08:49 by mboy              #+#    #+#             */
/*   Updated: 2021/09/07 17:23:40 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../ToolBox/Libft/libft.h"
# include "../ToolBox/MiniLibX/mlx.h"

# define SQUARE 	64
# define KEY_EXIT   53
# define KEY_UP     13
# define KEY_DOWN   1
# define KEY_RIGHT  2
# define KEY_LEFT   0

typedef struct s_mlx
{
	void			*init;
	void			*win;
	void			*img;
	char			*img_add;
	int				img_bpp;
	int				img_len;
	int				img_end;
}				t_mlx;

typedef struct s_key
{
	int				press;
	int				exit;
	int				up_zw;
	int				down_ss;
	int				right_qa;
	int				left_dd;
}				t_key;

typedef struct s_text
{
	char			text;
	char			*path;
	void			*img;
	char			*img_add;
	int				img_bpp;
	int				img_len;
	int				img_end;
	struct s_text	*next;
	struct s_text	*prev;
}				t_text;

typedef struct s_idx
{
	int				map_start[2];
	int				map_end[2];
	int				pix[2];
}				t_idx;

typedef struct s_solong
{
	int				win_xy[2];
	int				player_step;
	double			player_xy[2];
	int				exit_xy[2];
	char			**map;
	int				map_xy[2];
	int				collect;
	int				collected;
	int				**collect_xy;
	char			text_c[5];
	char			*text_path[5];
	t_text			*text;
	t_mlx			*mlx;
	t_key			*key;
	t_idx			*idx;
}				t_solong;

/*=======================MAIN FUNCTIONS=======================*/

int				main(int ac, char **av);
int				solong(t_solong *data);
void			solong_init(t_solong *data);
void			solong_loop(t_solong *data);
void			solong_exit(t_solong *data, int ex, char *mess);

/*=======================INIT FUNCTIONS=======================*/

t_solong		*init_solong(void);
t_key			*init_key(void);
t_mlx			*init_mlx(void);
t_text			*init_text(char idx, char *path, t_text *prev, t_text *next);

/*=====================PARSING  FUNCTIONS====================*/

void			parse(t_solong *data, char *mapath);
void			parse_map(t_solong *data, char *mapath);
void			parse_data(t_solong *data);
void			parse_data_collect(t_solong *data);
void			parse_data_doublon(t_solong *data, int idx0, int idx1);

/*====================KEY & MOVE FUNCTIONS===================*/

int				key_press(int keycode, t_solong *data);
int				key_release(int keycode, t_solong *data);
int				key_exit(t_solong *data);

/*=====================DRAWING FUNCTIONS=====================*/

void			draw_pixel(t_mlx *img, int x, int y, int color);
void			draw_map_basic(t_solong *data);
void			draw_map(t_solong *data);
void			draw_map_idx(t_solong *data, int select);
void			draw_map_rescale(t_solong *data);

/*====================TEXTURES  FUNCTIONS====================*/

void			text_list(t_solong *data, char text, char *path);
void			text_images(t_solong *data);
void			text_images_struct(t_solong *data);
unsigned int	text_color(t_solong *data, int text_x, int text_y);
void			text_rescale(t_solong *data, int start_x,
					int start_y, char text);

/*=======================MAP FUNCTIONS=======================*/

void			map(t_solong *data);
int				map_line(char *line);
void			map_xy(t_solong *data, int fd);
void			map_check(t_solong *data);
void			map_check_bis(t_solong *data);

/*=====================PLAYER  FUNCTIONS=====================*/

void			player(t_solong *data);
void			player_move(t_solong *data);
void			player_move_exit(t_solong *data);
void			player_move_count(t_solong *data,
					double player_x, double player_y);
char			**player_update_map(t_solong *data, char **new_map);

/*=====================COLLECT FUNCTIONS=====================*/

void			collect(t_solong *data);
int				collect_idx(t_solong *data);
int				**collect_update(t_solong *data, int collected);
char			**collect_update_map(t_solong *data);
char			**collect_update_map_bis(t_solong *data, char **new_map);

#endif