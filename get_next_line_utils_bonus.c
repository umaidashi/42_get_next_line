/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:27:45 by yoishi            #+#    #+#             */
/*   Updated: 2024/05/03 20:40:57 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_b(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (ft_strdup_b(s2));
	if (s1 && !s2)
		return (free(s1), NULL);
	new = (char *)malloc(ft_strlen2c_b(s1, '\0') + ft_strlen2c_b(s2, '\0') + 1);
	if (!new)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*ft_strdup_b(char *str)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char) * (ft_strlen2c_b(str, '\0') + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
