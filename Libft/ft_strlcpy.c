/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:08:50 by yong-lee          #+#    #+#             */
/*   Updated: 2020/12/06 02:46:47 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst,
		const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	cnt;

	cnt = 0;
	i = 0;
	if (dst == 0 || src == 0)
		return (0);
	while (*(src + cnt) != '\0')
		cnt++;
	if (dstsize != 0)
	{
		while (i + 1 < dstsize && *(src + i) != '\0')
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	return (cnt);
}
