/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:48:50 by yong-lee          #+#    #+#             */
/*   Updated: 2020/12/05 23:24:53 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_end(char const *s1, char const *set, size_t s_len)
{
	size_t	i;

	i = 0;
	while (i < s_len && ft_strchr(set, s1[s_len - i - 1]))
		i++;
	return (s_len - i);
}

size_t		ft_start(char const *s1, char const *set, size_t s_len)
{
	size_t	i;

	i = 0;
	while (i < s_len && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	s_len;
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup(s1));
	i = 0;
	s_len = ft_strlen(s1);
	start = ft_start(s1, set, s_len);
	end = ft_end(s1, set, s_len);
	if (start >= end)
		return (ft_strdup(""));
	if ((str = (char *)malloc(sizeof(char) * (end - start + 1))) == 0)
		return (0);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}
