/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:12:05 by mahender          #+#    #+#             */
/*   Updated: 2022/06/10 20:13:49 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/*int	main(void)
{
	t_list  *lst;
	t_list	*ver;
	t_list  nodo1;
	t_list  nodo2;
	t_list  nodo3;

	nodo1.content = "nodo1";
	nodo2.content = "nodo2";
	nodo1.next = &nodo2;
	nodo3.content = "nodo3";
	nodo2.next = &nodo3;
	nodo3.next = NULL;
	lst = &nodo1;
	ver = ft_lstlast(lst);
	printf("%s", (char *)ver->content);
	return (0);
}*/
