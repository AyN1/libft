/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abicer <abicer@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 22:25:02 by abicer            #+#    #+#             */
/*   Updated: 2020/10/21 03:12:40 by abicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] && s[i] != c)
		++i;
	if (!s[i])
		return (NULL);
	return ((char *)s + i);
}
