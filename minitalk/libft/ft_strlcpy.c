/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 20:28:29 by mahender          #+#    #+#             */
/*   Updated: 2022/05/17 12:13:23 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	i = 0;
	srcsize = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (dstsize != 0)
	{
		while ((src[i]) && (i < (dstsize - 1)))
		{	
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

/*int	main(void)
{
	char		dst[40] = "Hola";
	const char	src[40] = "Mundo";
	size_t		dstsize;

	dstsize = 10;
	printf("mi función      %zu", ft_strlcpy(dst, src, dstsize));
	return (0);
}*/
