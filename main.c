#include <mlx.h>

int main(void)
{
  void *mlx_ptr;
  void *mlx_win;

  mlx_ptr = mlx_init();// Connecting to the minilibx and save the ID connection to mlx_ptr
  mlx_win = mlx_new_window(mlx_ptr, 500, 500, "Hello world!");// Creating a new window and saving the ID of the window to mlx_window
  mlx_loop(mlx_ptr);// A loop to keep the connection up
}
