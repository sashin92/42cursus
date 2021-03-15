#include "cub3d.h"

int		deal_key(int keycode)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	return (0);
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "untitiled");

	mlx_hook(win_ptr, 2, 0, &deal_key, win_ptr);
	

	mlx_loop(mlx_ptr);
}
