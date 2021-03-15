#include "cub3d.h"

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;

	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_img	img;


	int		img_width;
	int		img_height;

	mlx_ptr = mlx_init();
	
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "sashin's window"); // 창 띄우기
	for(int j = 0; j < 100; j++)
		for(int i = 0; i < 100; i++)
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 56635);	// 픽셀로 채워넣기
	
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./texture/wall_e.xpm", &img_width, &img_height); // 이미지 불러오기
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 80, 80); // 불러온 이미지 삽입하기
	img.img_ptr = mlx_new_image(mlx_ptr, 110, 110);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);

	int		count_w;
	int		count_h;
	count_h = -1;
	while (++count_h < 110)
	{
		count_w = -1;
		while (++count_w < 110)
		{
			if (count_w % 2)
				img.data[count_h * 110 + count_w] = 0xFFFFFF;
			else
				img.data[count_h * 110 + count_w] = 0xFF0000;
		}
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 200, 200);

	printf("Hello World\n");

	mlx_hook(win_ptr, 17, 0, &close, win_ptr);

	mlx_loop(mlx_ptr); // 루프
	printf("hi");
}