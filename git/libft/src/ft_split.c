/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:05:05 by armgonza          #+#    #+#             */
/*   Updated: 2023/11/03 04:48:40 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	ft_nextword(char const *s, char c, int i)
{
	while (s[i] == c)
		i++;
	return (i);
}

static int	ft_wordlen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i + len] && s[i + len] != c)
		len++;
	return (len);
}

static char	**fill_result(char const *s, char c, char **result)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	while (s[i])
	{
		i = ft_nextword(s, c, i);
		if (!s[i])
			break ;
		j = ft_wordlen(s, c, i);
		result[k] = ft_substr(s, i, j);
		if (!result[k])
		{
			while (k >= 0)
				free(result[k--]);
			free(result);
			return (NULL);
		}
		i += j;
		k++;
	}
	result[k] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (s == NULL)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!result)
		return (NULL);
	result = fill_result(s, c, result);
	return (result);
}

/* int	main(void)
{
	char	**result;
	char	*str;
	char	c;
	int		i;

	str = "Hola-corrector-cómo-lo llevas";
	c = '-';
	result = ft_strsplit(str, c);
	i = 0;
	while (result[i])
	{
		printf("Parte %d: %s\n", i + 1, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}
 */