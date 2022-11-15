/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:06:59 by mahender          #+#    #+#             */
/*   Updated: 2022/06/10 20:12:56 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			aux = ft_lstlast(*lst);
			aux->next = new;
		}
	}
}

/*#include <stdio.h>
void	imprimir (t_list **lst)
{
	t_list	*nodo;

	nodo = *lst;
while (nodo->next != NULL)
	{
	printf("%s \n", (char *)nodo->content);
	nodo = nodo->next;
	}
	printf("%s \n", (char *)nodo->content);
}

int	main(void)
{
	t_list	*lst;
	t_list	nodo1;
	t_list	nodo2;
	t_list	nodo3;
	
	nodo1.content = "nodo1";
	nodo2.content = "nodo2";
	nodo1.next = &nodo2;
	nodo2.next = NULL;
	nodo3.content = "nodoNuevo";
	lst = &nodo1;
	ft_lstadd_back(&lst, &nodo3);
	imprimir(&lst);
	return (0);
}*/
