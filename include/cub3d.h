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
    int save;
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

#endif
