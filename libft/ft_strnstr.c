/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:10:20 by mahender          #+#    #+#             */
/*   Updated: 2022/05/31 21:02:11 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s1[i + j] != '\0' && s1[i + j] == s2[j] && (i + j < n))
		{
			if (s2[j + 1] == '\0')
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	size_t		n;
	const char	*s1;
	const char	*s2;

	n = 14;
	s1 = "Hola chitoVa";
	s2 = "chito";
	printf("%s", ft_strnstr(s1, s2, n));
	return (0);
}*/
