/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 09:17:58 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/21 14:03:08 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_functions.h"

int		(*opt(char *str))(int, int)
{
	if (!str[0] || str[1])
		return (0);
	if (str[0] == '+')
		return (&ft_add);
	else if (str[0] == '-')
		return (&ft_sub);
	else if (str[0] == '*')
		return (&ft_mul);
	else if (str[0] == '/')
		return (&ft_divide);
	else if (str[0] == '%')
		return (&ft_mod);
	return (0);
}

int		check_error(int (*f)(int, int), int n2)
{
	if (f == 0)
	{
		ft_putnbr(0);
		return (1);
	}
	else if (n2 == 0 && f == ft_divide)
	{
		write(1, "Stop : division by zero\n", 24);
		return (1);
	}
	else if (n2 == 0 && f == ft_mod)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int n1;
	int n2;
	int res;
	int	(*cal)(int, int);

	if (argc != 4)
		return (0);
	n1 = ft_atoi(argv[1]);
	n2 = ft_atoi(argv[3]);
	cal = opt(argv[2]);
	if (check_error(cal, n2))
		return (0);
	res = cal(n1, n2);
	ft_putnbr(res);
	return (0);
}
