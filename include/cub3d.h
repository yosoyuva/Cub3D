#ifndef _CUB3D_H
# define _CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    int         area;
    int         i;
    void *ptr;
    void *win;
}               t_data;

typedef struct s_mlx_id
{
  void *mlx_ptr;
  void *mlx_win;
}               t_mlx_id;

typedef struct  s_mystruct
{
    int         area;
    char        qwerty;
}               t_mystruct;

typedef struct  s_get
{
    int rx;//resolution
    int ry;
    char *no;// chemin vers la texture nord
    char *so;
    char *we;
    char *ea;
    char *s;// chemin vers le sprite
    int f;// couleur du resolution
    int c;// couleur du plafond
    /* error = 0 ==> pas d'erreur
       error = 7 ==> erreur au niveau de la resolution
       error = 71 ==> resolution apparu plus d'une fois sur le fichier description .cub
     */
    int error; // initialement a 0
    int save;
    int nblines;
    int linesize;
    char **map;
}               t_get;

/* get_next_line struct */
struct	s_variables
{
	char		*buf;
	char		*tmp;
	int			ret;
}		;

int ft_parsing(char *file, t_get *get);
void ft_error(t_get *get, char *str);
int cub3d(char *str, t_get *get);
void ft_init(t_get *get);
int ft_parsing_check_errors(char *file, t_get *get);
/* get_next_line functions */
int		get_next_line(int fd, char **line);
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

#endif
