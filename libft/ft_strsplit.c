/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 07:43:53 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/19 16:15:22 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_letter(char const *s, char c)
{
	int cpt_letter;
	int	i;

	i = -1;
	cpt_letter = 0;
	while (s[++i] != c && s[i])
		cpt_letter++;
	return (cpt_letter);
}

static char	*ft_fill(char const *s, char **tab_split, int cpt_letter, int *p)
{
	int	j;

	j = -1;
	if (!((*tab_split) = (char *)malloc(cpt_letter + 1)))
		return (NULL);
	while (++j < cpt_letter && s[*p])
		(*tab_split)[j] = s[(*p)++];
	(*tab_split)[j] = '\0';
	return (*tab_split);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		cpt_letter;
	int		j;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (NULL);
	j = 0;
	while (s[j])
	{
		cpt_letter = 0;
		while (s[j] == c)
			j++;
		cpt_letter = ft_count_letter(s + j, c);
		if (cpt_letter != 0 && ++i)
		{
			*split = ft_fill(s, split, cpt_letter, &j);
			split++;
		}
	}
	*split = NULL;
	return (split - i);
}
