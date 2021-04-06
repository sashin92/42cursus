#include "cub3d.h"



int		ft_init(char *cub)
{
	t_mlx	mlx;
	t_win	win;
	
	mlx.ptr = mlx_init();
	win.ptr = mlx_new_window(mlx.ptr, 500, 500, "untitiled");

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