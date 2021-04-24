#ifndef _CUB3D_H
# define _CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../lib/libft.h"
# include <math.h>
# define INT_MAX 2147483647
# define BUFFER_SIZE	4096
# define ROTATE_LEFT	65361
# define ROTATE_RIGHT	65363
# define FORWARD_W_Z	119
# define BACK_S_S		115
# define RIGHT_D_D		100
# define LEFT_A_Q		97
# define ESC_ESC 65307

typedef struct  s_data {
    void        *img;
    int         *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    int         area;
    int         i;
    void        *ptr;
    void        *win;
    int         forward;
    int         back;
    int         left;
    int         right;
    int         rotate_right;
    int         rotate_left;
    int	   			width;
	  int		   		height;

    void			*img2;
    int				*addr2;

}               t_data;

typedef struct  s_ray
{
    double         posx;
    double         posy;
    double			dirx;
	  double			diry;
	  double			planx;
	  double			plany;
	  double			raydirx;
	  double			raydiry;
	  double			camerax;
    int				mapx; // position (x)
	  int				mapy; // position (y)
    double deltadistx; // small hypo (x)
    double deltadisty; // small hypo (y)
    //length of ray from current position to next x or y-side
    double sidedistx;
    double sidedisty;
    //what direction to step in x or y-direction (either +1 or -1)
    int stepx;
    int stepy;
    int hit; //was there a wall hit?
    int side; //was a NS or a EW wall hit?
    int x; // l'indice de la colone a afficher sur l'ecran (ou la position du trace)
    double perpwalldist; // the distance perpenducilar from the wall hit point to the camera plane instead of Euclidean distance to the player point, to avoid making straight walls look rounded.
    int lineheight;
    int drawstart;
    int drawend;
    double movespeed;
    double rotspeed;
}               t_ray;

typedef struct s_text
{
  double wallx; // the x coordonate of where the wall was hit
  int texface; // numero de la texture (no, so, ea, ea, s)
  int texy;
  int texx;
  double step;
  double texpos;
}               t_text;

typedef struct  s_sprite
{
  double    *zbuffer;
  int       numspr;
  int				*order;
	double		*dist;
  double    spritex;
  double    spritey;
  double    invdet;
  int				spritescreenx;
	int				spriteheight;
  double		transformx;
	double		transformy;
  int				drawstartx;
	int				drawstarty;
	int				drawendy;
	int				drawendx;
	int				spritewidth;
}               t_sprite;

typedef struct  s_sxy
{
  double x;
  double y;
}               t_sxy;

typedef struct  s_get
{
    int rx;//resolution
    int ry;
    int map_on;
    char *no;// chemin vers la texture nord
    char *so;
    char *we;
    char *ea;
    char *s;// chemin vers le sprite
    int f;// couleur du resolution
    int c;// couleur du plafond
    int comma;
    /* error = 0 ==> pas d'erreur
       error = 7 ==> erreur au niveau de la resolution
       error = 71 ==> resolution apparu plus d'une fois sur le fichier description .cub
     */
    int error; // initialement a 0
    int save;
    char depart;
    int dx; // depart
    int dy;
    int nblines;
    int linesize;
    char **map;
    int screen_rx;
    int screen_ry;
    t_data textures[5]; //mettre les info relaifsaux textures
    t_ray ray;
    t_data mlx;
    t_text text;
    t_sprite sprite;
    t_sxy    *sxy;
}               t_get;

/* get_next_line struct */
struct	s_variables
{
	char		*buf;
	char		*tmp;
	int			ret;
}		;

int		ft_iswhite_spaces(int *i, const char *str);
int ft_parsing(char *file, t_get *get);
void ft_error(t_get *get, char *str);
int ft_cub3d(char *str, t_get *get);
void ft_init(t_get *get);
void ft_parsing_check_errors(char *file, t_get *get);
void ft_get_depart(t_get *get);
void ft_init_deltas(t_get *get);
void ft_sidedist_step(t_get *get);
void ft_dda(t_get *get);
void ft_init_texture(t_get *get);
int ft_key_press(int keycode, t_get *get);
int ft_key_release(int keycode, t_get *get);
void ft_draw_sprite(t_get *get, int y, int texx, int stripe);
void ft_sprite(t_get *get);
void ft_sprite_aux(t_get *get);
void ft_dist_order(t_get *get);
void ft_order_sprites(t_get *get);
void ft_forward_back(t_get *get);
void ft_left_right(t_get *get);
void	ft_rotate_right_left(t_get *get);
void	ft_rotate_left(t_get *get, double olddirx, double oldplanx);
void ft_draw_color(t_get *get);
void ft_draw(t_get *get, int y);
int ft_raycasting(t_get *get);
int ft_mlx(t_get *get);
void ft_dist(t_get *get);
void ft_mlx_win_img(t_get *get);
void ft_init_sprites(t_get *get);
void	ft_init_sprite2(t_get *get, int i, int j, int s);
void ft_init_raycasting2(t_get *get);
void	ft_init_dir(t_get *get);
void ft_init_raycasting(t_get *get);
void ft_get_texture_addr(t_get *get);
void ft_get_texture(t_get *get);
int		ft_exit(t_get *get);
/* get_next_line functions */
int		get_next_line(const int fd, char **line, t_get *get);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(int size, int a);
char	*ft_strchr(const char *s, int c);
int		ft_aux(char **red, char **line, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcat(char *s1, const char *s2);
int		ft_new_line(char **s, char **line, int fd, int ret);
void	ft_strdel(char **as);
/* get_next_line function stop */
void ft_texture_no(t_get *get, char *read, int *i);
void ft_texture_so(t_get *get, char *read, int *i);
void ft_texture_we(t_get *get, char *read, int *i);
void ft_texture_ea(t_get *get, char *read, int *i);
void ft_texture_sprite(t_get *get, char *read, int *i);
void ft_resolution(t_get *get, char *read, int *i);
void ft_color_floor(t_get *get, char *read, int *i);
void ft_color_ceiling(t_get *get, char *read, int *i);
int		ft_iswhite_space(int *i, const char *str);
int		ft_atoi_cub(const char *str, int *i);
int ft_map(t_get *get, char *str, int *i);
int ft_is_map(char *str);
void ft_copy_map_aux(char *str, char *map);
void ft_verify(t_get *get);
//void ft_mlx_win_img(t_get *get, t_data *mlx);
int		ft_create_rgb(int a, int r, int g, int b);
int ft_strlen2(char *str);
char *ft_get_path(char *str, int *i, t_get *get);
void ft_get_cub_info(t_get *get, char *read);
int ft_copy_map(char *file, char *read, t_get *get);
int ft_rest_is_wspace(char *str, int *i);
int ft_check_fencing(t_get *get);
int ft_check_line_fencing(char *str);
/* ft_fencing.c */
int ft_check_fencing_case1(t_get *get);
int ft_check_fencing_case2(t_get *get);
int ft_check_fencing_case3(t_get *get);
int ft_check_fencing_case4(t_get *get);
int ft_check_high_and_low_fence(char *str1, char *str2);
#endif
