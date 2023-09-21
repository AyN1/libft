/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:56:28 by atbicer           #+#    #+#             */
/*   Updated: 2023/09/21 19:55:09 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	triple(t_list *node)
{
	int	*ptr;

	printf("1: %p\n", &node->content);
	ptr = (int *)&node->content;
	*ptr *= 3;
}

int	main(int argc, char *argv[])
{
	t_list	*head;

	(void)argc;
	(void)argv;
	head = NULL;
	head = malloc(sizeof(t_list));
	head->content = (int *)42;
	head->next = NULL;
	printf("%p\n", head);
	printf("%d\n", head->content);
	triple(head);
	printf("%d\n", head->content);
	printf("size: %d\n", ft_lstsize(head));
	return (0);
}
