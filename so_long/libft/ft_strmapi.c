/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:56:44 by mahender          #+#    #+#             */
/*   Updated: 2022/06/07 21:11:18 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str || !s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*char	sumchar(unsigned int i, char c)
{
	char	chr;
	
	i = 1;
	chr = c + i;
	return (chr);
}*/

/*int	main(void)
{
	char const	st[10] = "hello 42!";
	printf("Original: %s \n", st);
	printf("Resultado: %s", ft_strmapi(st, *sumchar));
	return (0);
}*/
