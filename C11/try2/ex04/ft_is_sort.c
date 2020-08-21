/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 09:02:14 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/21 12:48:44 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		up_sorted;
	int		down_sorted;

	i = 0;
	up_sorted = 1;
	down_sorted = 1;
	if (length < 2)
		return (1);
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			up_sorted = 0;
		if (f(tab[i], tab[i + 1]) > 0)
			down_sorted = 0;
		i++;
	}
	if (up_sorted || down_sorted)
		return (1);
	return (0);
}
