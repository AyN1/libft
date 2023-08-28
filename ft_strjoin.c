/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:45:35 by atbicer           #+#    #+#             */
/*   Updated: 2023/08/29 01:57:44 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *join;
	size_t total_size;

	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	join = ft_calloc(total_size + 1, sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy(join, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcpy(join + ft_strlen(s1), (char *)s2, total_size + 1);
	return (join);
}
