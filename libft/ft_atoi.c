/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: charles <charles@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 14:17:48 by charles      #+#   ##    ##    #+#       */
/*   Updated: 2019/07/03 14:30:01 by charles     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int neg;
	int res;

	res = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v' || *str == '\r'
		|| *str == '\f' || *str == ' ')
		str++;
	neg = (*str == '-') ? -1 : 1;
	str += (*str == '-' || *str == '+') ? 1 : 0;
	while (*str && ft_isdigit(*str))
		res = res * 10 + *(str++) - '0';
	return (neg * res);
}
