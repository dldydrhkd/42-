/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:58:34 by yong-lee          #+#    #+#             */
/*   Updated: 2020/12/05 18:46:38 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	find;
	int		i;

	find = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == find)
		{
			return ((char *)(s + i));
		}
		i--;
	}
	return (NULL);
}
