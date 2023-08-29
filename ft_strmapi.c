/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 03:32:31 by atbicer           #+#    #+#             */
/*   Updated: 2023/08/29 04:37:43 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*strmapi;
	size_t	i;

	i = 0;
	strmapi = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!strmapi)
		return (NULL);
	while (s[i])
	{
		strmapi[i] = f(i, s[i]);
		++i;
	}
	return (strmapi);
}
/*
#include <stdio.h>

char	ft_even_index_to_upper(unsigned int index, char c)
{
	if (index % 2 == 0)
		return (ft_toupper(c)); // Convert to uppercase if index is even
	else
		return (c); // Otherwise, leave it unchanged
}

int	main(void)
{
	char	*mapi;

	mapi = ft_strmapi("Hello This Is A test", ft_even_index_to_upper);
	printf("[%s]", mapi);
}
*/
