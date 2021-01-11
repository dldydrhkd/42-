/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:46:51 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/21 03:33:59 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	cal_hex(int n)
{
	if (n < 10)
		return (n + '0');
	else
		return (n + 'a' - 10);
}

void			convert_to_dot(void *addr, unsigned int size)
{
	unsigned char	c;
	unsigned int	i;

	i = 0;
	write(1, " ", 1);
	while (i < size)
	{
		c = *((unsigned char *)addr + i);
		if (!(c >= 32 && c <= 126))
			write(1, ".", 1);
		else
			write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void			print_character(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	temp;
	unsigned char	c[3];

	i = 0;
	c[0] = ' ';
	while (i < 16)
	{
		if (i < size)
		{
			temp = *((unsigned char *)addr + i);
			c[1] = cal_hex(temp / 16 % 16);
			c[1] = cal_hex(temp % 16);
		}
		else
		{
			c[1] = ' ';
			c[2] = ' ';
		}
		if (++i % 2 == 1)
			write(1, &c, 3);
		else
			write(1, &c[1], 2);
	}
	convert_to_dot(addr, size);
}

void			print_addr(void *addr)
{
	unsigned char	address[17];
	long			temp;
	int				i;

	temp = (long)addr;
	i = 15;
	address[16] = ':';
	while (i >= 0)
	{
		address[i] = cal_hex(temp % 16);
		temp /= 16;
		i--;
	}
	write(1, address, 17);
}

void			*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int temp;
	unsigned int i;

	if (size == 0)
		return (addr);
	else
	{
		i = 0;
		temp = size / 16;
		while (i < temp)
		{
			print_addr((unsigned char *)addr + (16 * i));
			print_character((unsigned char *)addr + (16 * i), 16);
			i++;
		}
		temp = size % 16;
		print_addr((unsigned char *)addr + size - temp);
		print_character((unsigned char *)addr + size - temp, temp);
		return (addr);
	}
}
