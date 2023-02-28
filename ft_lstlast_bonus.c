/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:43:52 by kel-baam          #+#    #+#             */
/*   Updated: 2022/10/23 23:09:51 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst, int new_val, int flag)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		if (lst->content == new_val && flag)
			print_error();
		lst = lst->next;
	}
	if (lst->content == new_val && flag)
		print_error();
	return (lst);
}
