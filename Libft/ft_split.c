/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:51:52 by yong-lee          #+#    #+#             */
/*   Updated: 2020/12/07 00:37:49 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			split_num(const char *str, char c)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] != c && str[i])
		{
			num++;
			while (str[i] != c && str[i])
				i++;
		}
		else if (str[i])
			i++;
	}
	return (num);
}

void			ftft_strdup(char *dst, char const *src,
		int start, int last)
{
	int	i;

	i = 0;
	while (start < last)
	{
		dst[i] = src[start];
		i++;
		start++;
	}
	dst[i] = 0;
}

static	void	*free_mem(char **allocated_mem, size_t cnt)
{
	size_t	i;

	i = 0;
	while (i < cnt)
	{
		free(allocated_mem[i]);
		i++;
	}
	free(allocated_mem);
	return (NULL);
}

static void		split(char const *s, char c, char **str)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			if ((str[j] = (char *)malloc(sizeof(char)
							* (i - start + 1))) == 0)
			{
				free_mem(str, j);
				return ;
			}
			ftft_strdup(str[j], s, start, i);
			j++;
		}
		else if (s[i] != 0)
			i++;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	size_t	n;

	if (s == 0)
		return (0);
	n = split_num(s, c);
	str = (char **)malloc(sizeof(char *) * (n + 1));
	if (str == 0)
		return (0);
	str[n] = 0;
	if (n == 0)
		return (str);
	split(s, c, str);
	return (str);
}
