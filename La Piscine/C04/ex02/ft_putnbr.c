/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:07:30 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/13 14:14:03 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int nb)
{
	int		num[10];
	int		i;
	char	c;

	i = 0;
	while (nb > 0)
	{
		num[i] = nb % 10;
		nb /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		c = '0' + num[i];
		write(1, &c, 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		print_num(nb * -1);
	}
	else if (nb > 0)
	{
		print_num(nb);
	}
}
