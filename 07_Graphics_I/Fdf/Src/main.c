#include "../Inc/fdf.h"

int main(int ac, char **av) {
  // t_fdf fdf;

  if (ac != 2)
    return (ft_putstr_fd("Usage: ./fdf <map_file.fdf>\n", 2), 1);

  t_map map;

  if (parser(&map, av[1]) == -1)
    return (1);

  t_cam camera;
  init_camera(&camera);

  t_mlx mlx;
  init_window(&mlx);

  render(&map, &camera, &mlx);

  // Configuramos eventos
  mlx_hook(mlx.win, 17, 0, close_window,
           mlx.mlx); // Hook para cerrar la ventana
  mlx_key_hook(mlx.win, handle_keypress, mlx.mlx); // Hook para manejar teclas

  // Bucle principal del gráfico
  mlx_loop(mlx.mlx);

  return (0);
}
