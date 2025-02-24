/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychedmi <ychedmi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:23:01 by ychedmi           #+#    #+#             */
/*   Updated: 2024/11/20 15:46:51 by ychedmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	lenof(long int l)
{
	int	numlen;

	numlen = 0;
	if (l == -2147483648)
		return (11);
	if (l == 0)
		return (1);
	if (l < 0)
		numlen++;
	while (l != 0)
	{
		l = (l / 10);
		numlen++;
	}
	return (numlen);
}

char	*ft_itoa(int n)
{
	char		*p;
	int			t;
	long int	bn;

	bn = n;
	t = lenof(bn);
	p = malloc((t + 1) * sizeof(char));
	if (!p)
		return (NULL);
	p[t] = '\0';
	(bn == 0) && (p[0] = '0');
	(bn < 0) && (bn *= -(1)) && (p[0] = '-');
	while (bn != 0)
	{
		t--;
		p[t] = ((bn % 10) + 48);
		bn = (bn / 10);
	}
	return (p);
}
