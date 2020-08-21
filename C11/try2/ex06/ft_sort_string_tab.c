/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 09:27:43 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/21 09:37:40 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_cmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			break ;
		i++;
	}
	return (str1[i] - str2[i]);
}

void	ft_swap(char **tab, int i, int j)
{
	char *temp;

	temp = tab[i];
	tab[i] = tab[j];
	tab[j] = temp;
}

void	ft_sort_string_tab(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_cmp(tab[i], tab[j]) > 0)
				ft_swap(tab, i, j);
			j++;
		}
		i++;
	}
}
