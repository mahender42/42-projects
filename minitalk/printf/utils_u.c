/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:27:02 by mahender          #+#    #+#             */
/*   Updated: 2022/09/23 12:40:47 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa(unsigned int nb)
{
	char	*str;
	int		len;

	len = nlen(nb);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (nb == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (!str)
		return (0);
	str[len] = '\0';
	while (nb != 0)
	{
		str[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}

int	nlen(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	if (n == 0)
		len++;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_pf(int nb)
{
	char	*str;
	int		len;
	long	n;

	if (nb == 0)
		return (ft_strdup("0"));
	n = nb;
	len = nlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{	
		str[len--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

/*char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (s1[size])
		size++;
	ptr = malloc(sizeof(char) * size + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}*/
