/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_map.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 01:30:15 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 16:17:08 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MOUSE_MAP_H
# define MOUSE_MAP_H
# ifdef _linux_

# define M_NONE 0
# define M_LCLICK 1
# define M_RCLICK 2
# define M_WHEELCLICK 3
# define M_WHEELUP 4
# define M_WHEELDOWN 5
# define MAX_MBUTTON 6

# else

# define M_NONE 0
# define M_LCLICK 1
# define M_RCLICK 2
# define M_WHEELCLICK 3
# define MAX_MBUTTON 6
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# endif
#endif
