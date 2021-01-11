/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 21:10:32 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/20 18:34:34 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (base[i] == '-' || base[i] == '+' || base[i] == '\t' ||
				base[i] == ' ' || base[i] == '\n' || base[i] == '\r'
				|| base[i] == '\v' || base[i] == '\f')
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

int		pow_(int digit, int n)
{
	int		temp;
	int		i;

	i = 0;
	temp = 1;
	while (i < n)
	{
		temp *= digit;
		i++;
	}
	return (temp);
}

void	cal(int *temp, char *str, char *base, int digit)
{
	int		i;
	int		j;
	int		index;

	i = 0;
	while (str[i])
		i++;
	i--;
	index = i;
	while (i >= 0)
	{
		j = 0;
		while (base[j])
		{
			if (base[j] == str[i])
			{
				if (str[0] == '-')
					*temp -= j * pow_(digit, index - i);
				else
					*temp += j * pow_(digit, index - i);
			}
			j++;
		}
		i--;
	}
}

int		ft_atoi_base(char *str, char *base)
{
	int		digit;
	int		temp;

	temp = 0;
	digit = 0;
	while (base[digit])
		digit++;
	if (check_error(digit, base))
		return (temp);
	cal(&temp, str, base, digit);
	return (temp);
}
