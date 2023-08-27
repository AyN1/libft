/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:42:51 by atbicer           #+#    #+#             */
/*   Updated: 2023/08/27 23:59:00 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DISPLAY_TEST 0
#define DISPLAY_FAILED_TEST 1

int	ft_test_1(int (*f)(int), int (*ft)(int), int c)
{
	int	ret;
	int	ft_ret;

	ret = f(c);
	ft_ret = ft(c);
	if (DISPLAY_TEST)
	{
		printf("original(%c) ret(%d)\n", c, ret);
		printf("ft(%c) ret(%d)\n", c, ft_ret);
	}
	if (ret == ft_ret)
		return (1);
	else
	{
		if (DISPLAY_FAILED_TEST)
		{
			printf("libc:\t(%c) ret(%d)\n", c, ret);
			printf("ft:\t(%c) ret(%d)\n", c, ft_ret);
		}
		return (-1);
	}
}

void	ft_batch_test_1(int (*f)(int), int (*ft)(int), const char *str)
{
	int	i;

	printf("---%s TEST---\n", str);
	i = -1;
	while (++i <= 127)
	{
		if (ft_test_1(f, ft, i) != 1)
		{
			printf("Failure\n\n");
			return ;
		}
	}
	printf("Success\n\n");
}
char	*generate_random_string(size_t length)
{
	char	*random_string;
	int		key;

	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	random_string = NULL;
	if (length)
	{
		random_string = malloc(sizeof(char) * (length + 1));
		if (random_string)
		{
			for (size_t n = 0; n < length; n++)
			{
				key = rand() % (sizeof(charset) - 1);
				random_string[n] = charset[key];
			}
			random_string[length] = '\0';
		}
	}
	return (random_string);
}

void	ft_test_strlen(void)
{
	char	*random_str;
	size_t	original_len;
	size_t	custom_len;
	size_t	random_length;
	int		failure;

	failure = 0;
	printf("---FT_STRLEN TEST---\n");
	srand(time(NULL));       // Seed for random number generation
	int num_iterations = 10; // Number of test iterations
	for (int i = 0; i < num_iterations; i++)
	{
		random_length = rand() % 50;
		// Generate random length for the string
		random_str = generate_random_string(random_length);
		if (random_str)
		{
			// printf("Testing string: %s\n", random_str);
			original_len = strlen(random_str);
			custom_len = ft_strlen(random_str);
			if (original_len == custom_len)
				; // printf("Match! Length: %zu\n\n", original_len);
			else
			{
				failure = 1;
				printf("Mismatch! Original: %zu, Custom: %zu\n\n", original_len,
					custom_len);
			}
			free(random_str);
		}
	}
	if (strlen("") != ft_strlen(""))
		printf("Emtpy string test failed\n\n");
	if (!failure)
		printf("Success\n\n");
	else
		printf("Random string failures\n\n");
}

void	ft_test_memset(int c, size_t len)
{
	char	b[len];
	char	ft_b[len];
	char	*ret;
	char	*ft_ret;
	size_t	i;

	printf("---FT_MEMSET TEST---\n");
	ret = (char *)memset(b, c, len);
	ft_ret = (char *)ft_memset(ft_b, c, len);
	i = 0;
	while (i < len)
	{
		if (ret[i] != ft_ret[i])
		{
			printf("Failure\n");
			if (DISPLAY_FAILED_TEST)
			{
				printf("ret memset: %p - %s\n", ret, (char *)ret);
				printf("ret ft_memset: %p - %s\n", ft_ret, (char *)ft_ret);
			}
			return ;
		}
		++i;
	}
	printf("Success\n\n");
}
int	ft_test_bzero(size_t n)
{
	char buffer1[100] = "abcdefghi";
	char buffer2[100] = "abcdefghi";
	printf("---FT_BZERO TEST---\n");
	ft_bzero(buffer1 + 2, n);
	bzero(buffer2 + 2, n);
	if (DISPLAY_TEST)
	{
		printf("Buffer after ft_bzero: %s\n", buffer1);
		printf("Buffer after bzero: %s\n", buffer2);
	}
	for (int i = 0; i < 10; i++)
	{
		if (buffer1[i] != buffer2[i])
		{
			printf("Failure: Mismatch at position %d: ft_bzero=%d, bzero=%d\n",
				i, buffer1[i], buffer2[i]);
			return (1);
		}
	}
	printf("Success\n\n");
	return (0);
}

int	main(void)
{
	ft_batch_test_1(isalpha, ft_isalpha, "FT_ISALPHA");
	ft_batch_test_1(isdigit, ft_isdigit, "FT_ISDIGIT");
	ft_batch_test_1(isalnum, ft_isalnum, "FT_ISALNUM");
	ft_batch_test_1(isascii, ft_isascii, "FT_ISASCII");
	ft_batch_test_1(isprint, ft_isprint, "FT_ISPRINT");
	ft_test_strlen();
	ft_test_memset(97, 0);
	ft_test_bzero(5);
}
