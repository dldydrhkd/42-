/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:08:50 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/06 18:38:35 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int check;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		check = 1;
		while (str[i + j] && to_find[j])
		{
			if (str[i + j] != to_find[j])
			{
				check = 0;
				break ;
			}
			j++;
		}
		if (check && to_find[j] == '\0')
			return (str + i);
		i++;
	}
	return (0);
}
