/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_handler.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: charles <charles@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 14:47:13 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/13 17:28:36 by charles     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"
/*
** key_pressed() and mouse_pressed() are the functions passed to the 
** mlx_key_hook() and mlx_mouse_hook() respectivily to choose the right event to
** call according to the keyboard key / mouse key that was pressed and stored in
** parameter key;
** return value is not really important and needed because of mlx functions 
** implementation
*/

int		key_pressed(int key, t_mlx *mlx)
{
	if (key == ESC)
	{
		free(mlx);
		//free_hook(m_hook);
		exit(EXIT_SUCCESS);
	}
	//else if (key == LEFT || key == RIGHT || key == DOWN || key == UP)
	//	move_map(key, m_hook);

	return(0);
}

//int		mouse_pressed(int key, int x, int y, t_hook *m_hook)
//{
//	(void)x;
//	(void)y;

//	if (key == SCROLL_UP)
//	{
//		m_hook->map_info->map_scale++;
//	}
//	if (key == SCROLL_DOWN)
//	{
//		m_hook->map_info->map_scale--;
//	}
//	return (1);
//}
