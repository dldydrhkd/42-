/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 00:04:47 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/21 07:33:20 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		pow_(int digit, int a)
{
	int temp;

	temp = 1;
	while (a > 0)
	{
		temp *= digit;
		a--;
	}
	return (temp);
}

void	cal(long temp, int digit, int *i, int *arr)
{
	while (temp > 0)
	{
		arr[*i] = temp % digit;
		*i = *i + 1;
		temp /= digit;
	}
}

char	*allocate(int i, int minus)
{
	char *ptr;

	if (minus)
	{
		ptr = (char *)malloc(sizeof(char) * (i + 2));
		ptr[i + 1] = '\0';
		ptr[0] = '-';
	}
	else
	{
		ptr = (char *)malloc(sizeof(char) * (i + 1));
		ptr[i] = '\0';
	}
	return (ptr);
}

char	*zero(char *base)
{
	char *ptr;

	ptr = (char *)malloc(sizeof(char) * 2);
	ptr[0] = base[0];
	ptr[1] = '\0';
	return (ptr);
}
