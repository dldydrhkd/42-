#include "mlx.h"

int main(void)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx_projet");
	mlx_loop(mlx);
}
