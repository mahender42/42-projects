/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:51:34 by mahender          #+#    #+#             */
/*   Updated: 2022/06/07 21:12:05 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nodo1;

	nodo1 = (t_list *)malloc(sizeof(*nodo1));
	if (!nodo1)
		return (NULL);
	nodo1->content = content;
	nodo1->next = NULL;
	return (nodo1);
}

/*int main(void)
{
	char    *str;
	str = "Valentina";
	t_list  *nodo2;
	nodo2 = ft_lstnew(str);
	printf("%s", (char *)nodo2->content);
	return (0);
}*/
