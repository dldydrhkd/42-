/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:34:16 by yong-lee          #+#    #+#             */
/*   Updated: 2020/12/06 03:04:11 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_zero(void)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * 2);
	if (res == 0)
		return (0);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char	*ft_negative(int i, long *a)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (i + 2));
	if (res == 0)
		return (0);
	res[0] = '-';
	res[i + 1] = '\0';
	*a = -(*a);
	return (res);
}

char	*ft_positive(int i)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == 0)
		return (0);
	res[i] = '\0';
	return (res);
}

int		number_len(long n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		temp;
	long	a;

	a = n;
	if (a == 0)
		return (res = ft_zero());
	temp = number_len(a);
	i = 0;
	if (a < 0)
		res = ft_negative(temp++, &a);
	else
		res = ft_positive(temp);
	if (res == 0)
		return (0);
	while (a)
	{
		res[temp - i - 1] = a % 10 + '0';
		a /= 10;
		i++;
	}
	return (res);
}
