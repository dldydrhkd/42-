/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 20:13:40 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/05 13:15:20 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_alpha(char str)
{
	if (str >= 'a' && str <= 'z')
		return (1);
	if (str >= 'A' && str <= 'Z')
		return (1);
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (*(str + i) != '\0')
	{
		c = *(str + i);
		if (i == 0 || check_alpha(*(str + i - 1)) == 0)
		{
			if (c >= 'a' && c <= 'z')
				*(str + i) -= ('a' - 'A');
		}
		else if (c >= 'A' && c <= 'Z')
			*(str + i) += ('a' - 'A');
		i++;
	}
	return (str);
}
