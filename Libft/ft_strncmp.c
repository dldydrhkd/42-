/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:12:54 by yong-lee          #+#    #+#             */
/*   Updated: 2020/12/05 22:28:01 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	int			res;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	i = (i <= j) ? i + 1 : j + 1;
	i = (i <= n) ? i : n;
	res = ft_memcmp(s1, s2, i);
	return (res);
}
