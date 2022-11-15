/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:12:49 by mahender          #+#    #+#             */
/*   Updated: 2022/05/16 20:03:01 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*sorc;
	size_t				i;

	dest = (unsigned char *)dst;
	sorc = (const unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dest > sorc)
		while (len-- > 0)
			dest[len] = sorc[len];
	else
		ft_memcpy(dest, sorc, len);
	return (dst);
}

/*int	main(void)
{
	unsigned char		dst[] = "Hola Hola Hola";
	const unsigned char	src[] = "Hello Hello Hi Hi";
	size_t				len = 10;

	printf("%s", ft_memmove(dst +1, src, len));
	return (0);
}*/
