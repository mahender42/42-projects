/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:41:27 by mahender          #+#    #+#             */
/*   Updated: 2022/06/07 21:12:31 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*void	imprimir (t_list **lst)
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
	nodo3.content = "nodo3";
	lst = &nodo1;
	ft_lstadd_front(&lst, &nodo3);
	imprimir(&lst);
	return (0);
}*/
