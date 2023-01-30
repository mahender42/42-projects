/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:19:07 by mahender          #+#    #+#             */
/*   Updated: 2022/05/31 20:55:18 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	i;
	int	act;

	i = 0;
	act = 0;
	while (*s)
	{
		if (*s != c && act == 0)
		{
			act = 1;
			i++;
		}
		else if (*s == c)
			act = 0;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	int		start;
	char	**new;

	new = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!new || !s)
		return (NULL);
	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			new[j++] = ft_substr(s, (unsigned int)start, (size_t)(i - start));
			start = -1;
		}
		i++;
	}
	new[j] = 0;
	return (new);
}

/*
int	main(void)
{
	char		c;
	char const	*s = "Hola Mundo Hola Málaga";
	char		**result;
	int			i;

	i = 0;
	c = ' ';
	result = ft_split(s, c);
	while (i <= word_count(s, c))
	{
		printf("%s", result[i]);
		printf("\n");
		i++;
	}
	//printf("La string tiene %d palabras", world_count(s, c));
	return (0);
}*/
