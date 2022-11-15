/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:24:41 by mahender          #+#    #+#             */
/*   Updated: 2022/08/29 12:54:15 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*lector(int fd, char *men);
char	*imprimir(char *mens);
char	*resto(char *mensa);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_free_next(char *men, char *temp);
char	*get_next_line(int fd);

#endif
