/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 23:20:31 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/13 21:49:03 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_next_prime(int nb)
{
	int i;
	int check;

	if (nb <= 2)
		return (2);
	while (nb <= 2147483647)
	{
		i = 2;
		check = 1;
		while (i <= 46341 && i < nb)
		{
			if (nb % i == 0)
			{
				check = 0;
				break ;
			}
			i++;
		}
		if (check)
			return (nb);
		if (nb == 2147483647)
			break ;
		nb++;
	}
	return (0);
}
