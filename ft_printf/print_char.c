/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 02:48:51 by yong-lee          #+#    #+#             */
/*   Updated: 2021/02/28 02:51:44 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_char(int c, t_info *info)
{
	int		res;

	res = 0;
	if (info->type == '%' && info->minus == 1)
		info->zero = 0;
	if (info->minus == 1)
		res += ft_putchar(c);
	res += print_width(info->width, 1, info->zero);
	if (info->minus == 0)
		res += ft_putchar(c);
	return (res);
}

int			print_width(int width, int len, int zero)
{
	int		res;

	res = 0;
	while (len < width)
	{
		if (zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len++;
		res++;
	}
	return (res);
}
