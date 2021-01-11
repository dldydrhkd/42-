/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:47:20 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/04 19:40:20 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int temp;

	if (size > 1)
	{
		i = 1;
		while (i < size)
		{
			j = i;
			while (j >= 0)
			{
				if (tab[j] < tab[j - 1])
				{
					temp = tab[j - 1];
					tab[j - 1] = tab[j];
					tab[j] = temp;
				}
				else
					break ;
				j--;
			}
			i++;
		}
	}
}
