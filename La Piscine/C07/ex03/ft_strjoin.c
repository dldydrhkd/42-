/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 19:48:48 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/20 19:55:28 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_length(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_join(char *dest, char *src, int *k)
{
	int j;

	j = 0;
	while (src[j])
	{
		dest[*k] = src[j];
		j++;
		*k = *k + 1;
	}
}

void	ft_strcat(char *dest, char **src, char *sep, int size)
{
	int	i;
	int k;

	k = 0;
	i = 0;
	while (i < size)
	{
		ft_join(dest, src[i], &k);
		if (i != size - 1)
			ft_join(dest, sep, &k);
		i++;
	}
	dest[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		length;

	if (size == 0)
	{
		result = (char *)malloc(sizeof(char) * 1);
		result[0] = 0;
		return (result);
	}
	length = count_length(sep) * (size - 1);
	i = 0;
	while (i < size)
	{
		length += count_length(strs[i]);
		i++;
	}
	result = (char *)malloc(sizeof(char) * (length + 1));
	ft_strcat(result, strs, sep, size);
	return (result);
}
