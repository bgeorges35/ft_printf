/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:06:05 by bgeorges          #+#    #+#             */
/*   Updated: 2018/03/29 16:19:02 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../includes/libft/libft.h"
# include <limits.h>

typedef struct	s_length
{
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			j;
	int			z;
}				t_length;

typedef struct	s_flags
{
	int			hashtag;
	int			zero;
	int			neg;
	int			pos;
	int			sp;
}				t_flags;

typedef struct	s_width
{
	int			point;
	int			nb;
	int			prec;
}				t_width;

typedef	struct	s_all_flags
{
	t_length	length;
	t_flags		flags;
	t_width		width;
	int			c;
	int			negative;
	int			unicode_len;
}				t_all_flags;

/*
**	ft_printf.c
*/
int				ft_printf(const char *format, ...);
/*
**	ft_find_type.c
*/
int				ft_find_type(char *format, int *i, va_list ap);
int				ft_print_char(char *str, t_all_flags *all_flags, int len);
/*
**	ft_check_specifiers_flags.c
*/
t_all_flags		*ft_check_all_flags(char *format, int *i);
char			*ft_check_specifiers(char *format, int *i, va_list ap,
											t_all_flags *all_flags);
/*
**	ft_find_flags.c ft_find_width.c ft_find_lenght.c
*/
t_flags			*ft_find_flags(t_flags *flags, char *format, int *len);
t_flags			*ft_init_flags(t_flags *flags);
t_width			*ft_find_width(t_width *width, char *format, int *len);
t_width			*ft_init_width(t_width *width);
t_length		*ft_find_length(t_length *length, char *format, int *len);
t_length		*ft_init_length(t_length *lenght);
/*
**	ft_find_specifiers.c
*/
char			*ft_do_not_found_specifier(t_all_flags *all_flags,
											int *i, char *format);
char			*ft_find_specifier_base(char *format, int *i, va_list ap,
											t_all_flags *all_flags);
char			*ft_find_specifier_dec(char *format, int *i, va_list ap,
											t_all_flags *all_flags);
char			*ft_find_specifier_str(char *format, int *i, va_list ap,
											t_all_flags *all_flags);
/*
**	ft_specifier_base.c ft_specifier_dec.c ft_specifier_str.c
*/
void			ft_check_mark(t_all_flags *all_flags, char **str, int i);
char			*ft_specifier_d_i(va_list ap, t_all_flags *all_flags);
char			*ft_specifier_x(va_list ap, t_all_flags *all_flags);
char			*ft_specifier_u(va_list ap, t_all_flags *all_flags);
char			*ft_specifier_bu(va_list ap, t_all_flags *all_flags);
char			*ft_specifier_bd(va_list ap, t_all_flags *all_flags);
char			*ft_specifier_s(va_list ap, t_all_flags *all_flags);
char			*ft_specifier_c(va_list ap, t_all_flags *all_flags);
char			*ft_specifier_bo(va_list ap, t_all_flags *all_flags);
char			*ft_specifier_o(va_list ap, t_all_flags *all_flags);
char			*ft_specifier_p(va_list ap, t_all_flags *all_flags);
char			*ft_specifier_bs(va_list ap, t_all_flags *all_flags);
char			*ft_specifier_bc(va_list ap, t_all_flags *all_flags);
/*
**	ft_dispatcher_flags.c
*/
char			*ft_get_flags(char *str, t_all_flags *all_flags, int i);
char			*ft_get_dispatcher_flags(char *str, t_all_flags *all_flags,
											int i);
/*
**	ft_change_width.c
*/
void			ft_change_width_nb(char **str, t_all_flags *all_flags, int i);
void			ft_change_width_prec(char **str, t_all_flags *all_flags);
void			ft_change_width_prec_neg(char **str, t_all_flags *all_flags);
/*
**	ft_get_flags_neg_pos_sp.c ft_get_flags_hash_zero.c
*/
char			*ft_change_hashtag(char *str, t_all_flags *all_flags, int i);
char			*ft_change_hashtag_x_o(char *str, t_all_flags *all_flags,
								int i, int tmp);
char			*ft_change_neg(char *str, t_all_flags *all_flags, int i);
char			*ft_change_pos(char *str, t_all_flags *all_flags, int i);
char			*ft_change_sp(char *str, t_all_flags *all_flags, int i);
char			*ft_change_zero(char *str, t_all_flags *all_flags, int i);
char			*ft_change_zero_bis(char *str, t_all_flags *all_flags, int i,
											int nb);
/*
**	ft_aff_unicode.c
*/
int				ft_wchar_to_char(wchar_t wchar, char *fresh, int i);
size_t			ft_wstrlen(wchar_t *ws);
int				ft_wcharlen(wchar_t wchar);
size_t			ft_wbytelen(wchar_t *ws);
/*
**	ft_transform_wchar_in_char.c
*/
char			*ft_transform_wchar_in_char(wchar_t *ws);
char			*ft_transform_wchar_in_charc(wchar_t ws);
#endif
