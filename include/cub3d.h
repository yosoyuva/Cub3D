#include <mlx.h>
#include <stdio.h>

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct s_mlx_id
{
  void *mlx_ptr;
  void *mlx_win;
}               t_mlx_id;
