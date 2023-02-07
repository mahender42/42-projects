/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:31:04 by angalsty          #+#    #+#             */
/*   Updated: 2022/10/06 13:13:49 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printdec(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_hex(unsigned int num, const char format);
int		ft_printpercent(void);
void	ft_putstr(char *str);
int		ft_digit_len(unsigned int num);
int		ft_ptr_len(uintptr_t n);
void	ft_put_ptr(uintptr_t n);
char	*ft_uitoa(unsigned int n);
int		ft_hex_len(unsigned int num);
void	ft_put_hex(unsigned int num, const char format);

#endif
