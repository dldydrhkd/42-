/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:25:23 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/21 08:28:10 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count_word(char *str, int *c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!c[(int)str[i]] && (c[(int)str[i + 1]] || !str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strdup(char *str, int i, int j)
{
	char	*ptr;
	int		index;

	index = 0;
	ptr = (char *)malloc(sizeof(char) * (j - i + 2));
	if (ptr == 0)
		return (0);
	while (i + index <= j)
	{
		ptr[index] = str[i + index];
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}

void	ft_strstr(char *str, int *c, char **res)
{
	int		i;
	int		j;
	int		cnt;

	cnt = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (c[(int)str[i]] && !c[(int)str[i + 1]])
			j = i + 1;
		if (!c[(int)str[i]] && (c[(int)str[i + 1]] || !str[i + 1]))
		{
			res[cnt] = ft_strdup(str, j, i);
			cnt++;
		}
		i++;
	}
	res[cnt] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		c[256];

	i = 0;
	while (i < 256)
	{
		c[i] = 0;
		i++;
	}
	i = 0;
	while (charset[i])
	{
		c[(int)charset[i]] = 1;
		i++;
	}
	res = (char **)malloc(sizeof(char *) * (ft_count_word(str, c) + 1));
	ft_strstr(str, c, res);
	return (res);
}
