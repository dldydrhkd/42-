/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 03:04:53 by yong-lee          #+#    #+#             */
/*   Updated: 2021/02/28 22:59:07 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_pointer_prefix(char **buf)
{
	*buf = ft_strjoin("0x", *buf, 2);
	return (ft_strlen(*buf));
}

int				print_minus(t_info *info, char **buf)
{
	int		len_to_add;

	len_to_add = 0;
	if ((info->type == 'i' || info->type == 'd') &&
			info->zero == 0 && info->nbr_sign == -1)
	{
		*buf = ft_strjoin("-", *buf, 2);
		len_to_add = 1;
	}
	return (len_to_add);
}

int				print_minus2(int buf_len, t_info *info, char **buf)
{
	int		len_to_add;

	len_to_add = 0;
	if (info->nbr_sign == -1 && info->zero == 1)
	{
		if (buf_len >= info->width)
		{
			*buf = ft_strjoin("-", *buf, 2);
			len_to_add = 1;
		}
		else if (buf_len < info->width)
			*buf[0] = '-';
	}
	return (len_to_add);
}

int				print_str_prec(unsigned long long nbr, t_info *info, char **buf)
{
	int		buf_len;
	int		res;
	int		i;

	buf_len = ft_nbrlen(nbr, info);
	res = (info->prec > buf_len) ? info->prec : buf_len;
	if (!(*buf = (char *)malloc(sizeof(char) * res + 1)))
		return (0);
	i = 0;
	(*buf)[res] = '\0';
	while (buf_len + i < res)
	{
		(*buf)[i] = '0';
		i++;
	}
	i = 1;
	if (nbr == 0 && info->prec != 0)
		(*buf)[res - i] = '0';
	while (nbr)
	{
		(*buf)[res - i] = ft_baseset(info->type)[nbr % info->nbr_base];
		nbr /= info->nbr_base;
		i++;
	}
	return (buf_len);
}

int				print_nbr(unsigned long long nbr, t_info *info)
{
	char	*buf;
	int		buf_len;
	int		res;

	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->nbr_base = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)nbr < 0)
	{
		info->nbr_sign = -1;
		nbr = -nbr;
	}
	buf_len = print_str_prec(nbr, info, &buf);
	buf_len += print_minus(info, &buf);
	if (info->type == 'p')
		buf_len = print_pointer_prefix(&buf);
	res = print_str_width(&buf, info);
	res += print_minus2(buf_len, info, &buf);
	ft_putstr(buf);
	free(buf);
	return (res);
}
