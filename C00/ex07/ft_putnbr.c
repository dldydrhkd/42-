/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 18:23:03 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/04 12:30:20 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_minus(int *nb, int *num, int *i)
{
	write(1, "-", 1);
	num[*i] = (*nb % 10) * -1;
	(*i)++;
	*nb /= -10;
}

void	print_num(int *num, int *i)
{
	char c;

	while (*i >= 0)
	{
		c = num[*i] + '0';
		(*i)--;
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	int	num[10];
	int	i;

	i = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
		print_minus(&nb, num, &i);
	while (nb / 10 > 0)
	{
		num[i++] = nb % 10;
		nb /= 10;
	}
	if (nb != 0)
		num[i] = nb;
	else
		i--;
	print_num(num, &i);
}
