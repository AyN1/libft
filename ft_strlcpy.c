/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 02:36:14 by atbicer           #+#    #+#             */
/*   Updated: 2023/08/28 02:54:41 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;

	src_length = ft_strlen(src);
	if (src_length >= dstsize)
	{
		ft_memcpy(dst, src, dstsize);
		dst[dstsize - 1] = '\0';
	}
	else
		ft_memcpy(dst, src, src_length + 1);
	return (src_length);
}
