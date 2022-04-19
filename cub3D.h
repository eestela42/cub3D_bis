/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:51:27 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/19 16:00:06 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define RESX 1200
# define RESY 600
# define FOV 90
# define HAUTEUR 0
# define FOOT_VELOCITY		0.2
# define NECK_VELOCITY		5
# define JUMP_HEIGHT		2.0

# define ROTATE_LEFT	65361
# define ROTATE_RIGHT	65363
# define FORWARD_W_Z	119
# define BACK_S_S		115
# define RIGHT_D_D		100
# define LEFT_A_Q		97

typedef struct s_point
{
	float	x;
	float	y;
}				t_point;

typedef struct s_cam
{
	t_point	pos;
	float	angle;
}				t_cam;

typedef struct s_ray
{
	t_point	pos;
	t_point	dir;
}				t_ray;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct s_rep_sprites
{
	t_data	n;
	t_data	s;
	t_data	e;
	t_data	w;
}				t_rep_sprites;

typedef struct s_pix_column
{
	char	finder;
	float	dist;
	t_point	col;
	t_point	ray_dir;
	int		x;
}				t_pix_column;

typedef struct s_mast
{
	int				check;
	int				r;
	char			mem;
	char			**map;
	int				height;
	int				width;
	void			*mlx;
	void			*win;
	int				floor;
	int				ceil;
	int				mv_forw;
	int				mv_backw;
	int				mv_left;
	int				mv_right;
	int				rot_right;
	int				rot_left;
	float			hauteur;
	float			jump;
	t_cam			cam;
	t_rep_sprites	sp;
	t_data			img;
	t_data			mem_img;
}				t_mast;

/* PARSING */

int		parsing(t_mast *ee, char *file);
int		parsing_map(t_mast *ee, char *line, int i);
int		check_space(char **map, int x, int y);
int		check_border(char **map, int height, int width);
int		char_in_map(t_mast *ee, int x, int y);
int		error_in_map(t_mast *ee, int height, int width);
char	**error_map(char **map, int i);

/* PARSING UTILS */
int		ft_atoi(char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_strlen(const char *s);
char	*ft_substr(char *s, int start, int len);

/* FCT_TAB*/

int		fct_tab_error(t_mast *ee, char *line, int i);
int		fct_tab_map(t_mast *ee, char *line, int i);
int		fct_tab_north(t_mast *ee, char *line, int i);
int		fct_tab_south(t_mast *ee, char *line, int i);
int		fct_tab_east(t_mast *ee, char *line, int i);
int		fct_tab_west(t_mast *ee, char *line, int i);
int		fct_tab_floor(t_mast *ee, char *line, int i);
int		fct_tab_ceiling(t_mast *ee, char *line, int i);

/* KEY_PRESS */

int		key_pressed(int key, t_mast *ee);
int		key_release(int key, t_mast *ee);
int		key_action(t_mast *ee);
int		ft_strend_is(char *str, char *end);
void	destroy_mlx(t_mast *ee);


/* POINT */
t_point	add(t_point a, t_point b);
t_point	mult(float m, t_point p);
float	distance(t_point a, t_point b);
t_point	normalize(t_point a);
t_point	diff(t_point a, t_point b);
float	dot(t_point a, t_point b);

/*Collision*/
char	find_colision(t_mast *ee, t_ray ray, t_point *col);
t_point	colision_x(t_mast *ee, t_ray ray);
t_point	colision_y(t_mast *ee, t_ray ray);
void	no_columns(int y, t_mast *ee, t_pix_column column);

/*Affi_utils*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		my_mlx_pixel_get(t_data *data, int x, int y);
int		create_trgb(int t, int r, int g, int b);
float	equation_x(t_ray ray, int y);
float	equation_y(t_ray ray, int x);
void	destroy_sprites(t_mast *ee);
int		ft_end(t_mast *ee);

int		create_trgb(int t, int r, int g, int b);

int		fill_image(t_data *img, t_cam *cam, t_mast *ee);

#endif