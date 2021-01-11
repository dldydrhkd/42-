/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:03:30 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/06 15:16:52 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		cmp_(char *s1, char *s2, int size)
{
	unsigned char	c1;
	unsigned char	c2;
	int				result;

	c1 = *(s1 + size);
	c2 = *(s2 + size);
	result = c1 - c2;
	return (result);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			break ;
		}
	}
	return (cmp_(s1, s2, i));
}
