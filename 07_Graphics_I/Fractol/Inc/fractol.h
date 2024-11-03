#ifndef FRACTOL_H
#define FRACTOL_H

#include "../minilibx_linux/mlx.h"
#include "../minilibx_macos/mlx.h"

typedef struct s_setting {
  char *title;
  int width;
  int height;
} t_setting;

typedef struct s_mlx {
  void *mlx;
  void *win;
  void *img;
  void *addr;
  void *bpp;
  t_setting *setting;
} t_mlx;

// src/parser.c
int **parser(char **av);

// src/render.c
void render(int **data);
void init_mlx(t_mlx **mlx);

#endif // FRACTOL_H
