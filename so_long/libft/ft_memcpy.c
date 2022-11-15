/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:11:31 by mahender          #+#    #+#             */
/*   Updated: 2022/05/31 20:59:05 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <string.h>*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*sorc;

	dest = (unsigned char *)dst;
	sorc = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		*dest = *sorc;
		dest++;
		sorc++;
		n--;
	}
	return (dst);
}

/*int	main(void)
{
	char	dst[] = "Hola hola hola";
	const char	src[] = "Chau chau chau";
	size_t		n = 5;

	printf("mi función %s \n", ft_memcpy(dst, src, n));
	printf("función original %s", memcpy(dst, src, n));
	return (0);
}*/
