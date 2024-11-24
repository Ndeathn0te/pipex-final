/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:05:46 by armgonza          #+#    #+#             */
/*   Updated: 2023/10/31 21:17:38 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
/*
int	main(void)
{
	char	*string1;
	char	*set1;
	char	*trimmed1;
	char	*string3;
	char	*set3;
	char	*trimmed3;
	char	*string4;
	char	*set4;
	char	*trimmed4;

	string1 = "xxxprueba";
	set1 = "xy";
	trimmed1 = ft_strtrim(string1, set1);
	printf("Original: %s\nTrimmed: %s\n\n", string1, trimmed1);
	free(trimmed1);
	string3 = "pruebitazzz";
	set3 = "z";
	trimmed3 = ft_strtrim(string3, set3);
	printf("Original: %s\nTrimmed: %s\n\n", string3, trimmed3);
	free(trimmed3);
	string4 = "abccPruebota2abc";
	set4 = "acb";
	trimmed4 = ft_strtrim(string4, set4);
	printf("Original: %s\nTrimmed: %s\n\n", string4, trimmed4);
	free(trimmed4);
	return (0);
}
*/
