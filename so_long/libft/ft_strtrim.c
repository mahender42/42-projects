/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:35:29 by mahender          #+#    #+#             */
/*   Updated: 2022/05/31 21:13:54 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	int			j;
	int			f;
	char		*new;

	i = 0;
	j = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_strrchr(set, s1[j - 1]))
		j--;
	new = (char *)malloc(sizeof(*s1) * (j - i + 1));
	if (!new)
		return (NULL);
	f = 0;
	while (i < j && new)
	{
		new[f++] = s1[i++];
	}
	new[f] = '\0';
	return (new);
}

/*int	main(void)
{
	char const	s1[] = "xxy Holamamayy xx";
	char const	set[] = "xy";

	printf("%s", ft_strtrim(s1, set));
	return (0);
}*/

/*char *ft_strtrim(char const *s1, char const *set)
{
	int			i;
	int			j;
	int			f;
	char		*new;
//	char const	*start;
	i = 0;
	j = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_strrchr(set, s1[j - 1]))
		j--;
	new = (char *)malloc(sizeof(*s1) * (j - i + 1));
	if (!new)
		return (NULL);
	f = 0;
//	start = &s1[i - 1];
//	ft_strlcpy(new, start, (j - i));
	while (i < j && new)
	{
		new[f++] = s1[i++];
	}
	new[f] = '\0';
	return (new);
}
*/
