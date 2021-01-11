/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:40:24 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/11 16:34:51 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		cmp(char *a, char *b)
{
	int i;
	int result;

	i = 0;
	while (a[i] && b[i])
	{
		if (a[i] != b[i])
			break ;
		i++;
	}
	result = a[i] - b[i];
	return (result);
}

void	sort_(char **argv, int *num, int argc)
{
	int		i;
	int		j;
	int		temp;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (cmp(argv[num[i]], argv[num[j]]) >= 0)
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	print_(char **argv, int *num, int argc)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[num[i]][j])
		{
			c = argv[num[i]][j];
			write(1, &c, 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

int		main(int argc, char **argv)
{
	int		num[argc + 1];
	int		i;

	i = 0;
	while (i < argc)
	{
		num[i] = i;
		i++;
	}
	sort_(argv, num, argc);
	print_(argv, num, argc);
	return (0);
}
