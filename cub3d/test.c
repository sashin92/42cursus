#include "cub3d.h"

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;



	mlx_ptr = mlx_init();
	
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "sashin's window");
	printf("Hello World");

	mlx_loop(mlx_ptr);
	printf("hi");
}