/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:43:04 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/04 11:14:32 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_(int n, int *num)
{
	char	c;
	int		i;

	i = 0;
	while (i < n)
	{
		c = num[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (!(num[0] == 10 - n && num[n - 1] == 9))
		write(1, ", ", 2);
}

void	cal(int i, int j, int *num)
{
	int k;

	if (i == j)
		print_(i, num);
	else
	{
		if (j == 0)
			k = 0;
		else
			k = num[j - 1] + 1;
		while (k <= 9)
		{
			num[j] = k;
			cal(i, j + 1, num);
			k++;
		}
	}
}

void	ft_print_combn(int n)
{
	int num[10];

	cal(n, 0, num);
}
