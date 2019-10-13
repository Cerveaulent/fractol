/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_map.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: charles <charles@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 01:30:15 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/13 17:20:39 by charles     ###    #+. /#+    ###.fr     */
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

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# endif
#endif
