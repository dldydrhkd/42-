/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 21:29:43 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/11 21:40:18 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	cal_hex(int n)
{
	if (n < 10)
		return (n + '0');
	return (n + 'a' - 10);
}

void			print_(unsigned char a)
{
	unsigned char c;

	c = cal_hex(a / 16 % 16);
	write(1, &c, 1);
	c = cal_hex(a % 16);
	write(1, &c, 1);
}

void			ft_putstr_non_printable(char *str)
{
	int				i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			write(1, "\\", 1);
			print_((unsigned char)str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
