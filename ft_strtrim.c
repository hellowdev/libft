/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:11:13 by ychedmi           #+#    #+#             */
/*   Updated: 2024/11/19 16:23:53 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	firstchar(const char *str, const char *set)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (str[i] && set[j])
	{
		j = 0;
		while (set[j] && str[i] != set[j])
		{
			if (set[j + 1] == '\0')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

static int	lastchar(const char *str, const char *stk)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(str) - 1;
	while (len >= 0 && stk[j])
	{
		j = 0;
		while (stk[j] && str[len] != stk[j])
		{
			if (stk[j + 1] == '\0')
				return (len);
			j++;
		}
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len; 
	char	*p;
	int		u;
	int		i;

	u = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	i = firstchar(s1, set);
	if (i != len)
		len = lastchar(s1, set) + 1;
	p = malloc(len - i + 1);
	if (p == NULL)
		return (NULL);
	while (i <= len - 1)
	{
		p[u] = s1[i];
		u++;
		i++;
	}
	p[u] = '\0';
	return (p);
}
