/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:41:20 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/02 15:37:15 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_(int a)
{
	char c[2];

	c[0] = a / 10 + '0';
	c[1] = a % 10 + '0';
	write(1, &c, 2);
}

void	print_digit(int a, int b)
{
	if (a == 98 && b == 99)
	{
		write(1, "98 ", 3);
		write(1, "99", 2);
	}
	else
	{
		print_(a);
		write(1, " ", 1);
		print_(b);
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			print_digit(a, b);
			b++;
		}
		a++;
	}
}
