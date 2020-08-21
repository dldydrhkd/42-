/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 23:23:32 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/21 07:33:11 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		pow_(int digit, int a);
char	*allocate(int i, int minus);
void	cal(long temp, int digit, int *i, int *arr);
char	*zero(char *base);

int		check_error(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' ||
				(base[i] >= 9 && base[i] <= 13))
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (1);
	return (0);
}

int		check_char(char c, char *base)
{
	int		i;

	i = 0;
	if (c == ' ' || (c >= 9 && c <= 13))
		return (0);
	if (c == '-')
		return (1);
	if (c == '+')
		return (2);
	while (base[i])
	{
		if (base[i] == c)
			return (3);
		i++;
	}
	return (-3);
}

long	from_to_int(char *nbr, char *base_from, int digit)
{
	long	temp;
	int		i;
	int		j;
	int		index;

	temp = 0;
	i = 0;
	while (nbr[i] && check_char(nbr[i], base_from) == 3)
		i++;
	index = i - 1;
	i = 0;
	while (i <= index)
	{
		j = 0;
		while (base_from[j])
		{
			if (nbr[i] == base_from[j])
				temp += j * pow_(digit, index - i);
			j++;
		}
		i++;
	}
	return (temp);
}

char	*int_to_base(long temp, char *base_to)
{
	int		arr[40];
	char	*ptr;
	int		i;
	int		minus;

	minus = 0;
	i = 0;
	if (temp == 0)
		return (zero(base_to));
	if (temp < 0)
	{
		minus = 1;
		temp = -temp;
	}
	cal(temp, ft_strlen(base_to), &i, arr);
	ptr = allocate(i, minus);
	i--;
	while (i >= 0)
	{
		ptr[minus] = base_to[arr[i]];
		i--;
		minus++;
	}
	return (ptr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		sign;
	long	temp;

	sign = 1;
	i = 0;
	if (check_error(base_from) || check_error(base_to))
		return (0);
	while (check_char(*nbr, base_from) == 0)
		nbr++;
	while (check_char(*nbr, base_from) == 1 || check_char(*nbr, base_from) == 2)
	{
		if (check_char(*nbr, base_from) == 1)
			sign *= -1;
		nbr++;
	}
	temp = from_to_int(nbr, base_from, ft_strlen(base_from)) * sign;
	return (int_to_base(temp, base_to));
}
