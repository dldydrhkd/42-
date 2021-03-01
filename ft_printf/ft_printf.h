/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:56:02 by yong-lee          #+#    #+#             */
/*   Updated: 2021/03/01 17:20:38 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h>

# define TYPE "cspdiuxX%"

typedef struct	s_info
{
	int			minus;
	int			zero;
	int			width;
	int			prec;
	char		type;
	int			nbr_base;
	int			nbr_sign;
}				t_info;

int				ft_printf(const char *format, ...);
int				parse_format(va_list ap, char *format);
void			check_flag(va_list ap, char *format, t_info *info, int i);
void			width_prec_info(va_list ap, char *format,
		t_info *info, int i);
int				print_type(va_list ap, t_info *info);
int				print_char(int c, t_info *info);
int				print_width(int width, int len, int zero);
int				print_string(char *str, t_info *info);
char			*parse_buf(char *str, int end, int len);
int				print_str_width(char **buf, t_info *info);
int				print_nbr(unsigned long long nbr, t_info *info);
int				print_str_prec(unsigned long long nbr,
		t_info *info, char **buf);
int				print_minus(t_info *info, char **buf);
int				print_minus2(int buf_len, t_info *info, char **buf);
int				print_pointer_prefix(char **buf);
void			init_info(t_info *info);
int				ft_nbrlen(unsigned long long nbr, t_info *info);
char			*ft_baseset(char type);

#endif
