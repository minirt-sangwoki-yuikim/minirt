/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:40:41 by yuikim            #+#    #+#             */
/*   Updated: 2023/09/02 14:33:56 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_close(t_mlx *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_scene		*scene;
	t_count		element;
	t_mlx		mlx_vars;
	t_data		data;
	t_ray_info	ray_info;

	if (argc == 1)
		return (0);
	scene = parsing(argv[PATH], &element);
	__init__(&data, *(scene->c), argv, argc);
	mlx_set_window(&mlx_vars, &(data.image));
	ray_info.count = element;
	ray_info.scene = *scene;
	ft_draw(ray_info, data, mlx_vars);
	mlx_put_image_to_window(mlx_vars.mlx_ptr, mlx_vars.win_ptr, \
	mlx_vars.wins.img, 0, 0);
	mlx_key_hook(mlx_vars.win_ptr, key_code_press, &mlx_vars);
	mlx_hook(mlx_vars.win_ptr, 17, 0, ft_close, &mlx_vars);
	mlx_loop(mlx_vars.mlx_ptr);
	free_scene(scene);
	return (0);
}
