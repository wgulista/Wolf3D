/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <wgulista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:21:24 by wgulista          #+#    #+#             */
/*   Updated: 2015/12/31 13:44:11 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_issign(char c)
{
	return (c == '+' || c == '-');
}

static char		*ft_test_sign(const char *s, int *i, int *ispositive)
{
	char	*new;

	new = (char *)s;
	if (new[*i] == '+')
		new++;
	else if (new[*i] == '-')
	{
		*ispositive = -1;
		*i = *i + 1;
	}
	return (new);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			result;
	int			ispositive;
	char		*tmp;

	i = 0;
	result = 0;
	ispositive = 1;
	tmp = ft_strtrim(str);
	while (tmp[i] != 0 && ft_isspace(tmp[i]) && ft_isalpha(tmp[i]))
		i++;
	if (!ft_isdigit(tmp[i]) && !ft_issign(tmp[i]))
		return (0);
	tmp = ft_test_sign(tmp, &i, &ispositive);
	while (ft_isdigit(tmp[i]))
	{
		result = result * 10 + (tmp[i] - 48);
		i++;
	}
	free(tmp);
	return (result * (int)ispositive);
}
