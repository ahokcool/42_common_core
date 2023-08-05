/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:29:26 by astein            #+#    #+#             */
/*   Updated: 2023/08/05 19:34:26 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief	Allocates and returns a new node which will be initialized with
			the value of the parameter 'content'.
			The variable 'next' is initialized to NULL.
 * 
 * @param	content	The content to create the node with
 * @return	t_list* The new node
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list) * 1);
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/**
 * @brief	Adds the node 'new' at the beginning of the list.
 * 
 * @param	lst	The address of a pointer to the first link of a list.
 * @param	new	The address of a pointer to the nose to be added to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/**
 * @brief	Adds the node 'new' at the end of the list.
 * 
 * @param	lst	The address of a pointer to the first link of a list.
 * @param	new	The address of a pointer to the nose to be added to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		ft_lstadd_front(lst, new);
	else
		ft_lstlast(*lst)->next = new;
}

/**
 * @brief	Returns the last node of the list 'lst'.
 * 
 * @param	lst		The beginning of the list.
 * @return	t_list*	Last node of the list
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/**
 * @brief	Takes as a parameter a node and frees the memory of the node’s
 * 			content using the function 'del' and free the node.
 * 			The memory of 'next' will not be freed.
 * 
 * @param	lst	The node to free.
 * @param	del	The address of the function used to delete the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
	lst = NULL;
}
