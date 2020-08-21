/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:43:13 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/06 20:55:18 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		cmp_(char *s1, char *s2, unsigned int size)
{
	unsigned char	c1;
	unsigned char	c2;
	int				result;

	c1 = *(s1 + size);
	c2 = *(s2 + size);
	result = c1 - c2;
	return (result);
}

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			break ;
		}
		if (i == n)
		{
			return (0);
		}
	}
	return (cmp_(s1, s2, i));
}
