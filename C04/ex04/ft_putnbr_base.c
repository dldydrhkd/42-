/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 23:49:00 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/20 18:33:19 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_minus(int *nbr, int *i, int digit, int *arr)
{
	int temp;

	temp = *nbr % digit * -1;
	arr[*i] = temp;
	*i = *i + 1;
	*nbr /= digit;
	*nbr *= -1;
	write(1, "-", 1);
}

void	cal(int nbr, int digit, int *i, int *arr)
{
	while (nbr > 0)
	{
		arr[*i] = nbr % digit;
		*i = *i + 1;
		nbr /= digit;
	}
	*i = *i - 1;
}

int		check_error(int digit, char *base)
{
	int		i;
	int		j;

	i = 0;
	if (digit <= 1)
		return (1);
	while (i < digit)
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+')
			return (1);
		while (j < digit)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		digit;
	int		arr[40];
	char	c;

	digit = 0;
	while (base[digit])
		digit++;
	if (check_error(digit, base))
		return ;
	i = 0;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	if (nbr < 0)
		print_minus(&nbr, &i, digit, arr);
	cal(nbr, digit, &i, arr);
	while (i >= 0)
	{
		c = base[arr[i]];
		write(1, &c, 1);
		i--;
	}
}
