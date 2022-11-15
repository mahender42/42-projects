/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:42:19 by mahender          #+#    #+#             */
/*   Updated: 2022/05/16 20:06:48 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	char			chr;
	size_t			i;

	str = (unsigned char *)s;
	chr = (char)c;
	i = 0;
	while (i < n)
	{
		if ((char)str[i] == chr)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	s[] = "bonjourno";
	int			c = 'n';
	size_t		n = 2;

	printf("%s", ft_memchr(s, c, n));
	return (0);
}*/
