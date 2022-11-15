/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:25:43 by mahender          #+#    #+#             */
/*   Updated: 2022/09/23 12:27:26 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *s, ...);
int		printer(va_list args, const char c);
size_t	ft_strlen(const char *str);
int		nlen(long n);
char	*ft_itoa(int nb);
int		ad_putchar_fd(char c, int fd);
int		ad_putstr_fd(char *s, int fd);
int		ad_putstr(char *s);
int		printer(va_list args, const char c);
int		ft_print(char const *s, ...);
char	*ft_strdup(const char *s1);
int		ft_printptr(unsigned long long ptr);
void	putptr(unsigned long ptr);
int		hexa_len(unsigned long ptr);
int		printper(void);
char	*ft_uitoa(unsigned int nb);
int		ft_printhexa(unsigned int hexa, char x);
void	puthexa(unsigned int hexa, char x);

#endif
