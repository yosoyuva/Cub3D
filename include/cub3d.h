#include <mlx.h>
#include <stdio.h>

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

int ft_parsing(char *file, t_get *get);
void ft_error(t_get *get, char *str);
int cub3d(char *str, t_get *get);
void ft_init(t_get *get);
int ft_get_info_check_errors(char *file, t_get *get);
