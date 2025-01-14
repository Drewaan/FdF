/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:00:16 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/12/04 04:06:32 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include <limits.h>



// MACROS

#define W_WIDTH 1800
#define W_HEIGHT 1000
#define WHITE 0xFFFFFF
#define CYAN 0x07C1FF
#define N_PINK 0xFF007F
#define N_FREEN 0x39FF14
#define N_BLUE 0x1B03A3
#define N_YELLOW 0xFFFF34
#define N_ORANGE 0xFF6600
#define N_PURPLE 0xB026FF
#define COLOR_ERROR_MSG "\033[33m"
#define RESET_ERROR_MSG "\033[0m"
// The bitmask to apply to isolate the blue component of a color.
#define BM 0xFF
// Number of bits to shift to the right to isolate the component of a color
// 0xRRGGBBAA
// By shifting the color value 24 bits to the right, Alpha
#define AS 24
// By shifting the color value 16 bits to the right, Red
#define RS 16
// By shifting the color value 8 bits to the right, Green
#define GS 8

// UTILS
#define BASE_HEXA "0123456789ABCDEF"
#define ROT 0.01
#define ZOOM 0.01
#define TRANS 1.5
// Flattening Factor
#define FF 00.01
// Scaling Factor on Z corordinates
#define SF 10

// KEYS

#define ESC_KEY 65307
#define TAB_KEY 65289
#define UP_KEY 65362
#define DOWN_KEY 65364
#define PLUS_KEY 61
#define MINUS_KEY 45
#define C_KEY 99
#define R_KEY 114
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54

enum e_num_fdf_error
{
	SUCCESS = 0,
	FAILURE = 1,
	INVALID_ARGS_ERROR = 2,
	FILE_OPEN_ERROR = 3,
	MEM_ALLOC_ERROR = 4,
	MAP_EMPTY_ERROR = 5,
	LIBFT_ERROR = 6,
	MLX_ERROR = 7,
	CREATION_ERROR = 8,
	INVALID_FILENAME_ERROR = 9
};

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	int	width;
	int	height;
	int	**z_2d;
	int	**colors;
	int	min_z;
	int	max_z;
	int	iscolor;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addres;
	int		bpp;
	int		ln_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	t_map	*map;
	t_img	*img;
	int		shift_x;
	int		shift_y;
	int		color_change;
	bool	isometric;
	float	ff;
	float	rot_x;
	float	rot_y;
	float	rot_z;
	float	zoom;	
}	t_data;

// fdf_error

void	error_msg(int exit_msg);
void	check_filename(const char *filename);

// bresenham

int 	absolute_val(int x);
void	init_br(t_point *start, t_point *end, t_point *delta, t_point *sign);
void	bresenham(t_data *fdf, t_point start, t_point end);

// design

void	put_pixel(t_data *fdf, int x, int y, int color);
void	design_map(t_data *fdf);
void	draw_controls(t_data *fdf);

// parsing_map

int		z_value(int z, t_map *map);
int		find_width(char **split);
void	map_size(int fd, t_map *map);
void	map_mem(int fd, t_map *map);
t_map	*init_map(char *filename);
int 	convert_hex_color(char *color, t_map *map);

// free

void	ft_free(char **split);
void	map_free(t_map *map);
void	map_alloc(t_map *map);
int		close_window(t_data *fdf);

// data

int		ft_greater(int x, int y);
void	reset(t_data *fdf);
t_data	*data_init(t_map *map);

// isometric_view

void	isometric(t_data *fdf, int *x, int *y, int z);

// colors_bonus

double	calc_percentage(int start, int end, int value);
int		calc_light(int start, int end, double percentage);
void    change_color(t_data *fdf);
int		color_calc(t_point current, t_point start, t_point end, t_point delta);
int		z_color_calculator(t_data *fdf, int height);

// transformation_pont_bonus

t_point	transformation(t_data *fdf, t_point point);
t_point	create_point(int x, int y, t_data *fdf);

// rotation_bonus

void	rot_x(t_data *fdf, int *y, int *z);
void	rot_y(t_data *fdf, int *x, int *z);
void	rot_z(t_data *fdf, int *x, int *y);

// translation_bonus

void	translation(int key, t_data *fdf);

// zoom_bonus

void	zoom(int key, t_data *fdf);

// altitude_bonus

void	altitude(int key, t_data *fdf);

// key_handling_bonus

int handle_key(int key, t_data *fdf);
void	rotation(int key, t_data *fdf);

#endif