/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaitre <smaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:09:27 by smaitre           #+#    #+#             */
/*   Updated: 2025/03/06 21:59:31 by smaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_pt2		t_pt2;
typedef struct s_pt3i		t_pt3i;
typedef struct s_line		t_line;
typedef struct s_prmline	t_prmline;
typedef struct s_rawmap		t_rawm;
typedef struct s_bounds		t_bounds;
typedef struct s_img		t_img;
typedef struct s_keyb		t_keyb;
typedef struct s_mouse		t_mouse;
typedef struct s_quat		t_quat;
typedef struct s_vec3		t_vec3;
typedef struct s_vec4		t_vec4;
typedef struct s_mat4		t_mat4;
typedef struct s_screen		t_screen;
typedef struct s_mapinfo	t_mapinfo;
typedef struct s_camera		t_camera;
typedef struct s_canvas		t_canvas;
typedef struct s_pipe		t_pipe;
typedef struct s_win		t_win;
typedef struct s_trsfm		t_trsfm;
typedef struct s_proj		t_proj;
typedef struct s_fdf		t_fdf;

# ifndef WIDTH
#  define WIDTH 0
# endif

# ifndef HEIGHT
#  define HEIGHT 0
# endif

# define V_CONIC 0x63
# define V_ISOMETRIC 0x69
# define V_EYEFISH 0x65
# define M_OBJECT 0x6F
# define M_SCENE 0x73

# define C_RANDOM 0x6E
# define C_AUTO 0x61
# define C_LAPINOU 0x6C

/**
* Touches de rotation
* X + : 65433 2
* X - : 65431 8
* Y + : 65429 7
* Y - : 65434 9
* Z + : 65430 4
* Z - : 65432 6
*/

# define ROT_XL 65433
# define ROT_XR 65431
# define ROT_YL 65429
# define ROT_YR 65434
# define ROT_ZL 65430
# define ROT_ZR 65432

/**
* Touches de translation
* X + : 65361 XK_Left
* X - : 65363 XK_Right
* Y + : 65362 XK_Up
* Y - : 65364 XK_Down
* Z + : 65437 5
* Z - : 65438 0
*/

# define TRS_XL 65361
# define TRS_XR 65363
# define TRS_YL 65362
# define TRS_YR 65364
# define TRS_ZL 65437
# define TRS_ZR 65438

/**
* Touches de scale
* Z + : 65436 1
* Z - : 65435 3
*/

# define SCL_DOWN 65436
# define SCL_UP 65435

/**
* Touches de changement
* FOV + : 0x66
* FOV - : 0x67
* Distance + : 0x74
* Distance - : 0x72
*/

# define E_FOV_UP 0x66
# define E_FOV_DOWN 0x67
# define E_DISTANCE_UP 0x74
# define E_DISTANCE_DOWN 0x72

# define M_LSHIFT 0xFFE1
# define M_RSHIFT 0xFFE2
# define M_LCTRL 0xFFE3
# define M_RCTRL 0xFFE4
# define M_LALT 0xFFE9
# define M_RALT 0xFFEA

# define C_RESETCANVAS 0x20

typedef enum e_redraw
{
	REDRAW_STOP = 1,
	REDRAW_FULL_NO_AUTO = 2,
	REDRAW_FULL_AUTO = 4,
	REDRAW_VIEW_ONLY = 8
}	t_redraw;

# define M_PI 3.14159265358979323846

typedef struct s_pt2
{
	int	x;
	int	y;
}	t_pt2;

typedef struct s_pt3i
{
	int	x;
	int	y;
	int	z;
}	t_pt3i;

typedef struct s_line
{
	t_pt3i	pt_0;
	t_pt3i	pt_1;
	int		gcolor0;
	int		gcolor1;
}	t_line;

typedef struct s_prmline
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	max;
	int	x;
	int	y;
	int	e2;
}	t_prmline;

typedef struct s_bounds
{
	float	x_min;
	float	y_min;
	float	z_min;
	float	x_max;
	float	y_max;
	float	z_max;
}	t_bounds;

typedef struct s_img
{
	void	*ptr;
	char	*dat;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_keyb
{
	t_bool		l_shift;
	t_bool		r_shift;
	t_bool		l_ctrl;
	t_bool		r_ctrl;
	t_bool		l_alt;
	t_bool		r_alt;
}	t_keyb;

typedef struct s_mouse
{
	int	x;
	int	y;
	int	prev_x;
	int	prev_y;
	int	button;
	int	prev_button;
}	t_mouse;

typedef struct s_quat
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_quat;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec4;

typedef struct s_mat4
{
	double	m[4][4];
}	t_mat4;

typedef struct s_screen
{
	int		width;
	int		height;
}	t_screen;

typedef struct s_mapinfo
{
	int			nb_x;
	int			nb_y;
	int			nb;
	int			r_mode;
	int			v_mode;
	int			c_mode;
	float		seed;
	t_bounds	bounds;
	int			gcolor_l;
	int			gcolor_z;
	int			gcolor_u;
	t_mat4		center;
}	t_mapinfo;

typedef struct s_camera
{
	double		pan_x;
	double		pan_y;
	double		zoom;
	double		distance;
	t_mat4		pos;
	t_quat		rot;
}	t_camera;

typedef struct s_canvas
{
	double		offset_x;
	double		offset_y;
	double		zoom;
}	t_canvas;

typedef struct s_trsfm
{
	t_quat		rot_model;
	t_quat		rot_model_local;
	t_quat		rot_camera;
	t_quat		rot_camera_local;
	t_mat4		trs_model;
	t_mat4		trs_model_local;
	t_vec3		rot_model_euler;
	t_vec3		rot_model_local_euler;
	t_vec3		rot_camera_euler;
	t_vec3		rot_camera_local_euler;
	t_mat4		adjustment;
}	t_trsfm;

typedef struct s_pipe
{
	t_mat4		t_cntr_n;
	t_mat4		t_cntr_i;
	t_mat4		r_local;
	t_mat4		t_local;
	t_mat4		r_centered;
	t_mat4		l_part;
	t_mat4		t_global;
	t_mat4		r_global;
	t_mat4		m_scale;
	t_mat4		proj;
	t_mat4		adjust;
	t_mat4		view;
	t_mat4		viewport;
	t_mat4		total;
	t_mat4		canvas2d;
	t_mat4		zoom;
	t_mat4		pan;
	t_mat4		dist;
	t_mat4		cam;
}	t_pipe;

typedef struct s_proj
{
	float		fov;
	float		near;
	float		far;
	t_vec3		scale;
	t_camera	camera;
	t_canvas	canvas;
	t_mat4		mat;
	t_trsfm		transform;
	t_pipe		pipe;
	void		(*update_proj)(t_proj *p);
	void		(*reset_proj)(t_fdf *fdf, t_proj *p);
}	t_proj;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}	t_win;

typedef struct s_elem
{
	int				line;
	int				col;
	int				value;
	int				color;
	struct s_elem	*next;
}	t_elem;

typedef struct s_fdf
{
	t_win		win;
	t_img		img;
	t_mapinfo	mapinfo;
	t_elem		*map_raw;
	t_elem		*last_raw_elem;
	t_vec4		*map_pts;
	t_vec4		*map_view;
	int			*map_colors;
	t_proj		*cur_proj;
	t_proj		projs[3];
	t_mouse		mouse;
	int			frame_count;
	t_keyb		keyb;
	t_redraw	state;
}	t_fdf;

/*
** CORE
*/

void	compute_display_points(t_fdf *fdf, int params);
void	bressenham_path(t_fdf *c, t_line *line, t_bool use_gradient);
int		liang_barsky_clip(t_line *line, t_fdf *fdf, float u1, float u2);
void	render_view(t_fdf *fdf, t_vec4 *view);
void	global_render(t_fdf *fdf);
void	show_infos_top(t_fdf *fdf);
void	show_infos_bottom(t_fdf *fdf);
void	draw_triangle_right(t_fdf *fdf, int size, t_pt2 pos, int color);
void	compute_display_points(t_fdf *fdf, int params);
void	compute_total_transform(t_fdf *fdf, t_pipe *p, t_trsfm *t, int a);

/*
** HELPERS
*/

void	show_angles_scene(t_fdf *fdf, int x, int y);
void	show_angles_object(t_fdf *fdf, int x, int y);
void	show_pos_object(t_fdf *fdf, int x, int y);
void	show_pos_scene(t_fdf *fdf, int x, int y);
void	show_obj_scale(t_fdf *fdf, int x, int y);
int		interpolate_colors(int c0, int c1, double t);
void	angle_to_str(t_fdf *fdf, float angle, int x, int y);
void	float_to_str(t_fdf *fdf, float f, int cds[2], int precision);
int		random_bright_color(t_fdf *fdf);
t_elem	*get_last_elem(t_elem *head);
void	append_elem(t_fdf *fdf, t_elem *new_elem);

/*
** HOOKS
*/

int		main_hook_loop(t_fdf *fdf);
int		main_hook_close(t_fdf *fdf);
int		main_hook_keypress(int keycode, t_fdf *fdf);
int		main_hook_keyrelease(int keycode, t_fdf *fdf);
int		main_hook_mouseclick(int button, int x, int y, t_fdf *fdf);
int		main_hook_mousemove(int x, int y, t_fdf *fdf);
int		main_hook_mouserelease(int button, int x, int y, t_fdf *fdf);

void	hook_modes(int keycode, t_fdf *fdf);
void	hook_translate(int keycode, t_fdf *fdf);
void	hook_rotate(int keycode, t_fdf *fdf);
void	hook_effects(int keycode, t_fdf *fdf);

void	do_rotate_z(t_fdf *fdf, float delta);
void	do_rotate_x(t_fdf *fdf, float delta);
void	do_rotate_y(t_fdf *fdf, float delta);
void	do_translate_x(t_fdf *fdf, float delta);
void	do_translate_y(t_fdf *fdf, float delta);
void	do_translate_z(t_fdf *fdf, float delta);
void	do_translate_view(t_fdf *fdf, float delta_x, float delta_y);
void	do_scale_z(t_fdf *fdf, float delta);
void	do_scale_view(t_fdf *fdf, float delta, int x, int y);
void	do_change_fov(t_fdf *fdf, float delta);
void	do_change_distance(t_fdf *fdf, float delta);
void	do_change_color(t_fdf *fdf, int keycode);
void	do_define_rotation_mode(t_fdf *fdf, int keycode);
void	do_define_view_mode(t_fdf *fdf, int keycode);
void	do_modif_keys(t_fdf *fdf, int keycode, t_bool press);
void	do_reset_canvas(t_fdf *fdf);

/*
** MATH
*/

t_vec4	mat4_apply(t_mat4 m, t_vec4 v);
t_mat4	mat4_mul(t_mat4 a, t_mat4 b);
t_vec3	trans_mat4_to_vec3(t_mat4 m);
t_mat4	quat_to_mat4(t_quat q);
t_quat	quat_multiply(t_quat a, t_quat b);
t_mat4	create_translate_mat4(double tx, double ty);
t_mat4	create_zoom_mat4(double z);
t_mat4	create_scale_mat4(t_vec3 v);
t_mat4	create_viewport_mat4(float width, float height, double zoom);
t_mat4	create_identity_mat4(void);
t_mat4	create_canvas_mat4(t_fdf *fdf, t_canvas cv);
t_quat	quat_angle(t_vec3 axis, double angle);
void	init_identity_quaternion(t_quat *q);
void	quat_normalize(t_quat *q);
void	init_identity_mat4(t_mat4 *m);
void	translate_mat4(t_mat4 *m, t_vec3 v);
void	acc_rot_global(t_quat *orientation, t_vec3 axis, double angle);
void	acc_rot_local(t_quat *orientation, t_vec3 axis, double angle);
t_mat4	center_map_mat4(t_fdf *fdf);
t_mat4	transpose_mat4(t_mat4 m);
void	scale_mat4_by(t_mat4 *m, double s);
t_mat4	invert_mat4_(t_mat4 m);
t_mat4	compute_autoview_mat4(t_fdf *fdf, t_mat4 proj_view_mv);
double	compute_diag(t_fdf *fdf);

/*
** MAP
*/

int		build_map(t_fdf *fdf);
int		check_rawmap(t_fdf *fdf, int r_code);
int		read_raw_map(char *map_name, t_fdf *fdf);
int		check_built_map(t_fdf *fdf, int r_code);

/*
** MEMORY
*/

void	init_fdf(t_fdf *fdf);
void	init_mlx_elements(t_fdf *fdf);
int		close_fdf(void *params);
int		crash_fdf(void *params, int err_code);
void	free_rawline(char **line);
void	free_mlx_elements(t_fdf *fdf);
void	free_maps(t_fdf *fdf);
void	free_raw_elems(t_elem *elem);
int		*get_map_int(t_fdf *fdf);
t_vec4	*get_map_pts(t_fdf *fdf);

/*
** PROJECTIONS
*/

t_proj	init_iso_view(t_fdf *fdf);
t_proj	init_conic_view(t_fdf *fdf);
void	reset_pan_zoom(t_fdf *fdf);
void	init_transform(t_proj *p);

#endif
