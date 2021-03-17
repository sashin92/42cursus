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

	int		h;
	int		w;
	int		x;
	int		y;

	x = 0;
	y = 0;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "untitiled");

	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./texture/wall_s.xpm", &w, &h);


	printf("width : %d\nheigh : %d\n", w, h);

	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 200, 200);

	while (x < 100)
	{
		y = 0;
		while (y < 100)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x0000ffff);
			++y;
		}
		++x;
	}

	mlx_hook(win_ptr, 2, 0, &deal_key, win_ptr);

	mlx_loop(mlx_ptr);
}
