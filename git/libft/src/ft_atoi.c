/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:45:41 by armgonza          #+#    #+#             */
/*   Updated: 2023/10/31 21:13:45 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
int	main(void)
{
	char	*test1;
	char	*test2;
	char	*test3;
	char	*test4;
	char	*test5;
	char	*test6;
	char	*test7;

	test1 = "42";
	test2 = "-42";
	test3 = "     +42";
	test4 = "  \t\n\v\f\r-42";
	test5 = "42abc";
	test6 = "abc42";
	test7 = "   -abc";
	printf("ft_atoi(%s) = %d\n", test1, ft_atoi(test1));
	printf("ft_atoi(%s) = %d\n", test2, ft_atoi(test2));
	printf("ft_atoi(%s) = %d\n", test3, ft_atoi(test3));
	printf("ft_atoi(%s) = %d\n", test4, ft_atoi(test4));
	printf("ft_atoi(%s) = %d\n", test5, ft_atoi(test5));
	printf("ft_atoi(%s) = %d\n", test6, ft_atoi(test6));
	printf("ft_atoi(%s) = %d\n", test7, ft_atoi(test7));
	return (0);
}
*/
