/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:36:09 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/18 19:23:05 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	i = 0;
	k = 0;
	while (src[k])
		k++;
	while (dest[i])
		i++;
	if (size >= i)
	{
		j = 0;
		while (src[j] && i + j + 1 < size)
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
		return (i + k);
	}
	return (k + size);
}
