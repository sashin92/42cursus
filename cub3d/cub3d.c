#include "cub3d.h"
#define WIDTH 500
#define HEIGHT 500
#define ROW 5
#define COL 5


int		draw_grid(t_mlx *mlx, t_win *win)
{
	int		row_count;
	int		col_count;
	int		i;

	row_count = 0;
	col_count = 0;

	while (col_count++ < HEIGHT / COL)
	{
		i = 0;
		while (++i < WIDTH)
			mlx_pixel_put(mlx->ptr, win->ptr, i, col_count * (WIDTH / COL), 0x00FFFFFF);
	}
	while (row_count++ < WIDTH / ROW)
	{
		i = 0;
		while (++i < HEIGHT)
			mlx_pixel_put(mlx->ptr, win->ptr, row_count * (HEIGHT / ROW), i, 0x00FFFFFF);
	}
	return (0);
}


// move dot using key

int		move_dot(int key, t_pos *pos)
{
	if (key == KEY_W)
		printf("\n\n\n\npos : %d, %d\n", pos->x, ++pos->y);
	else if (key == KEY_S)
		printf("\n\n\n\npos : %d, %d\n", pos->x, --pos->y);
	else if (key == KEY_A)
		printf("\n\n\n\npos : %d, %d\n", --pos->x, pos->y);
	else if (key == KEY_D)
		printf("\n\n\n\npos : %d, %d\n", ++pos->x, pos->y);
	else if (key == KEY_ESCAPE)
		exit(0);
	return (0);
}

int		draw_dot(t_mlx *mlx, t_win *win, t_pos *pos)
{

}


int		ft_init(char *cub)
{
	t_mlx	mlx;
	t_win	win;
	t_pos	pos;
	
	mlx.ptr = mlx_init();
	win.ptr = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "untitiled");

	draw_grid(&mlx, &win);

	pos.x = 35;
	pos.y = 35;

	draw_dot(&mlx, &win, &pos);

	mlx_key_hook(win.ptr, move_dot, &pos);
	mlx_loop_hook(mlx.ptr, main_loop, )


	mlx_loop(mlx.ptr);

	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_init(argv[1]);
	else
		write(2, "Error : Invalid arguments\n", 26);
	return (0);
}