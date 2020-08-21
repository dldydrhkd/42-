/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 01:24:54 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/20 01:47:50 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_print_size(int a)
{
	char	c;
	int		i;
	int		num[15];

	i = 0;
	if (a == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (a > 0)
	{
		num[i] = a % 10;
		a /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		c = num[i] + '0';
		write(1, &c, 1);
		i--;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	size;
	int i;

	size = 0;
	while (par[size].str)
		size++;
	i = 0;
	while (i < size)
	{
		ft_print_str(par[i].str);
		write(1, "\n", 1);
		ft_print_size(par[i].size);
		write(1, "\n", 1);
		ft_print_str(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
