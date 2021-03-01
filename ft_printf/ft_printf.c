/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 22:43:24 by yong-lee          #+#    #+#             */
/*   Updated: 2021/03/01 17:20:07 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_type(va_list ap, t_info *info)
{
	int				res;
	char			type;

	res = 0;
	type = info->type;
	if (type == 'c')
		res = print_char(va_arg(ap, int), info);
	else if (type == 's')
		res = print_string(va_arg(ap, char *), info);
	else if (type == 'p')
		res = print_nbr(va_arg(ap, unsigned long long), info);
	else if (type == 'd' || type == 'i')
		res = print_nbr(va_arg(ap, int), info);
	else if (type == 'u' || type == 'x' || type == 'X')
		res = print_nbr(va_arg(ap, unsigned int), info);
	else if (type == '%')
		res = print_char('%', info);
	return (res);
}

void	width_prec_info(va_list ap, char *format, t_info *info, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (info->prec == -1)
			info->width = info->width * 10 + format[i] - '0';
		else
			info->prec = info->prec * 10 + format[i] - '0';
	}
	else if (format[i] == '*')
	{
		if (info->prec == -1)
		{
			info->width = va_arg(ap, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
		}
		else
			info->prec = va_arg(ap, int);
	}
}

void	check_flag(va_list ap, char *format, t_info *info, int i)
{
	if (format[i] == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
	else if (format[i] == '-')
		info->minus = 1;
	else if (format[i] == '.')
		info->prec = 0;
	else if (ft_isdigit(format[i]) || format[i] == '*')
		width_prec_info(ap, format, info, i);
}

int		parse_format(va_list ap, char *format)
{
	int				i;
	int				res;
	t_info			*info;

	i = 0;
	res = 0;
	if (!(info = malloc(sizeof(t_info))))
		return (-1);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
			res += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			init_info(info);
			while (format[++i] && !(ft_strchr(TYPE, format[i])))
				check_flag(ap, format, info, i);
			info->type = format[i++];
			if ((info->minus == 1 || info->prec > -1) && info->type != '%')
				info->zero = 0;
			res += print_type(ap, info);
		}
	}
	free(info);
	return (res);
}

int		ft_printf(const char *format, ...)
{
	int				res;
	va_list			ap;

	va_start(ap, format);
	res = parse_format(ap, (char *)format);
	va_end(ap);
	return (res);
}
