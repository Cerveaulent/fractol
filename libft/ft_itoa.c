/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 03:03:52 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/08 13:00:07 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_char(int n)
{
	int		cpt_char;

	cpt_char = 0;
	if (n < 0)
	{
		cpt_char++;
		n = n * -1;
	}
	while (n >= 10)
	{
		n /= 10;
		cpt_char++;
	}
	return (cpt_char);
}

char		*ft_itoa(int n)
{
	char	*str_nb;
	int		cpt_char;
	int		tmp;

	tmp = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	cpt_char = ft_count_char(n);
	if (!(str_nb = (char *)malloc(cpt_char + 1)))
		return (NULL);
	n = (n < 0 ? -n : n);
	str_nb[cpt_char + 1] = '\0';
	while (cpt_char >= 0)
	{
		if (n <= 9)
			str_nb[cpt_char--] = n % 10 + '0';
		else if (n >= 10)
		{
			str_nb[cpt_char--] = n % 10 + '0';
			n /= 10;
		}
	}
	if (tmp < 0)
		str_nb[0] = '-';
	return (str_nb);
}
