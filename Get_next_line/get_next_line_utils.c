/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:14:54 by mahender          #+#    #+#             */
/*   Updated: 2022/08/27 20:13:19 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		n;
	int		i;
	char	chr;

	n = (ft_strlen(s) + 1);
	i = 0;
	chr = (char)c;
	while (i < n)
	{
		if (s[i] == chr)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*cstr;
	int		size;
	int		index;
	char	*p;

	index = 0;
	size = ft_strlen((char *)str);
	cstr = malloc((size + 1) * sizeof(char));
	if (cstr == NULL)
		return (NULL);
	p = cstr;
	while (str[index])
	{
		p[index] = str[index];
		index++;
	}
	p[index] = '\0';
	return (cstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	int		i;
	int		j;
	char	*str;

	i = 0;
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	str = (char *)malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s[start] && i < len)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}
