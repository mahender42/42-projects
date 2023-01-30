/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:23:22 by mahender          #+#    #+#             */
/*   Updated: 2022/06/08 20:05:38 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*int	main(void)
{
	t_list  *lst;
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
	printf("En esta lista hay %d nodo/s", ft_lstsize(lst));
	return (0);
}*/
