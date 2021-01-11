/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 22:53:32 by yong-lee          #+#    #+#             */
/*   Updated: 2020/08/20 18:06:48 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_space(int *i, char *str)
{
	while (str[*i])
	{
		if (str[*i] == ' ' || str[*i] == '\f' || str[*i] == '\n' ||
				str[*i] == '\r' || str[*i] == '\t' || str[*i] == '\v')
			*i = *i + 1;
		else
			break ;
	}
}

void	check_sign(int *i, int *count, char *str)
{
	while (str[*i])
	{
		if (str[*i] == '-')
		{
			*count = *count + 1;
			*i = *i + 1;
		}
		else if (str[*i] == '+')
		{
			*i = *i + 1;
		}
		else
		{
			break ;
		}
	}
}

int		ft_atoi(char *str)
{
	int		i;
	int		count;
	int		num;

	num = 0;
	i = 0;
	count = 0;
	check_space(&i, str);
	check_sign(&i, &count, str);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + str[i] - '0';
			i++;
		}
		else
		{
			break ;
		}
	}
	if (count % 2 == 1)
		return (num * -1);
	else
		return (num);
}
