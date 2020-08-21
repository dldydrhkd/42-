/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 01:36:04 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/11 02:36:09 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		g_arr[12];
int		g_cnt;

void	print_(void)
{
	int		i;
	char	c;

	i = 1;
	while (i <= 10)
	{
		c = g_arr[i] + '0' - 1;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		abs_(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

int		check(int line, int i)
{
	int j;

	j = 1;
	while (j < line)
	{
		if (abs_(j - line) == abs_(g_arr[j] - i) || g_arr[j] == i)
			return (0);
		j++;
	}
	return (1);
}

void	queen(int line)
{
	int i;
	int same;

	i = 1;
	if (line == 11)
	{
		print_();
		g_cnt++;
		return ;
	}
	while (i <= 10)
	{
		same = check(line, i);
		if (same)
		{
			g_arr[line] = i;
			queen(line + 1);
		}
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int		pos;

	pos = 1;
	while (pos <= 10)
	{
		g_arr[1] = pos;
		queen(2);
		pos++;
	}
	return (g_cnt);
}
