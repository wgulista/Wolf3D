#ifndef WOLF3D_H
# define WOLF3D_H
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>

# define WIDTH				800
# define HEIGHT				600
# define ECHAP				53
# define T					17
# define H					4
# define SPACE				49
# define KEY_UP				126
# define KEY_RIGHT			124
# define KEY_DOWN			125
# define KEY_LEFT			123
# define MOUSE_CLIC_L		1
# define MOUSE_CLIC_R		2
# define MOUSE_WHEEL_UP		5
# define MOUSE_WHEEL_DOWN	4
# define KEY_1				18
# define KEY_2				19
# define KEY_3				20
# define KEYRELEASE 		3
# define KEYRELEASE_MASK	(1L<<1)
# define KEYPRESS 			2
# define KEYPRESS_MASK		(1L<<0)
# define BUTTONPRESS 		4
# define BUTTONPRESS_MASK	(1L<<10)
# define EXPOSE				12
# define EXPOSE_MASK		(1L<<15)
# define MOTION_NOTIFY		6
# define MOTION_MASK		(1L<<6)
# define DESTROY_NOTIFY		17
# define DESTROY_MASK		(1L<<17)

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				sline;
	int				endian;
}					t_img;

typedef struct 		s_arrow
{
	int				up;
	int				right;
	int				down;
	int				left;
	int				rot;
	int				run;
	int				space;
}					t_arrow;

typedef	struct		s_w3d
{
	double			pos_x;
	double			pos_y;
	double			pos_z;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			cameraX;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_pos_x;
	int				map_pos_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			step_x;
	double			step_y;
	double			side_dist_x;
	double			side_dist_y;
	double			perp_wall_dist;
	int				line_height;
	int				start;
	int				end;
	int				hit;
	int				side;
	int 			x;
}					t_w3d;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int 			mapWidth;
	int 			mapHeight;
	int				side;
	int 			help;
	int				change_color;
	int				**worldmap;
	t_img			img[5];
	t_arrow 		key;
	t_w3d			*w;
}					t_env;

int 				ft_tablen(char **tab);
void				ft_free_tab(char **tab);
void				ft_msg_error(char *msg);
int					key_hook(int keycode, t_env *e);
int					key_release(int keycode, t_env *e);
int					mouse_motion(int x, int y, t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					expose_hook(t_env *e);
void				menu_put_to_image(t_env *e);
void				sky_put_to_image(t_env *e, double x, double y);
void				ground_put_to_image(t_env *e, double x, double y);
void				pixel_put_to_image(t_env *e, double x, double y, int color);
void				display_menu(t_env *e);
int					quit_program(t_env *e);
int					check_file_error(char *file);
int					**generate_map(t_env *e, char *file);
t_w3d				*init_w3d();
void				init_arrow(t_arrow*key);
void				init_env_value(t_env *e);
int					init_texture(t_env *e);
void				init_img_value(t_env *e);
void				draw_map(t_env *e);
void				move_up(t_env *e);
void				move_right(t_env *e);
void				move_down(t_env *e);
void				move_left(t_env *e);
void				move(t_env *e);
int 				draw_vertical_line(t_env *e, double x, int start, int end);
//int 				draw_vertical_line(t_env *e, double x);

#endif