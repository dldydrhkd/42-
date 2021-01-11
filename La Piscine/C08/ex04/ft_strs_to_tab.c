/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 00:41:11 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/18 04:05:27 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strcpy(char *str, int size)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr == 0)
		return (0);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*res;
	int					i;

	if (ac < 0)
		return (0);
	res = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (res == 0)
		return (0);
	res[ac].str = 0;
	i = 0;
	while (i < ac)
	{
		res[i].size = ft_strlen(av[i]);
		res[i].str = ft_strcpy(av[i], ft_strlen(av[i]));
		res[i].copy = ft_strcpy(av[i], ft_strlen(av[i]));
		i++;
	}
	return (res);
}
