/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:36:20 by yoishi            #+#    #+#             */
/*   Updated: 2024/05/04 15:06:23 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stack = ft_read_file(fd, stack);
	if (!stack)
		return (NULL);
	line = ft_cut_line(stack);
	if (!line)
		return (NULL);
	stack = ft_next_line(stack);
	return (line);
}

char	*ft_read_file(int fd, char *stack)
{
	int		b;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	b = 1;
	while (ft_strlen2c(stack, '\n') == -1 && b != 0)
	{
		b = read(fd, buf, BUFFER_SIZE);
		if (b == -1)
		{
			if (stack)
				free(stack);
			return (free(buf), NULL);
		}
		if (b == 0 && *buf == '\0')
			break ;
		buf[b] = '\0';
		stack = ft_strjoin(stack, buf);
		if (!stack)
			return (free(buf), NULL);
	}
	free(buf);
	return (stack);
}

int	ft_strlen2c(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (c == '\0' && str[i] == '\0')
		return (i);
	return (-1);
}

char	*ft_cut_line(char *stack)
{
	char	*line;
	int		i;
	int		nnl;

	if (!stack)
		return (NULL);
	if (*stack == '\0')
		return (free(stack), NULL);
	nnl = ft_strlen2c(stack, '\n');
	if (nnl == -1)
		nnl = ft_strlen2c(stack, '\0');
	line = (char *)malloc(sizeof(char) * (nnl + 2));
	if (!line)
		return (free(stack), NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_next_line(char *stack)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (stack[i++] == '\0')
		return (free(stack), NULL);
	next = (char *)malloc(ft_strlen2c(stack, '\0') - i + 1);
	if (!next)
		return (free(stack), NULL);
	j = 0;
	while (stack[i])
		next[j++] = stack[i++];
	next[j] = '\0';
	free(stack);
	return (next);
}

// cc -Wall -Wextra
	// -Werror get_next_line.c get_next_line.h get_next_line_utils.c
	// -D BUFFER_SIZE=100 ; ./a.out ; rm -rf a.out *.gch
// #include <fcntl.h>
// #include <libc.h>
// #include <stdio.h>
// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q gnl");
// }
// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd;
// 	fd = open("get_next_line.h", O_RDONLY);
// 	i = 0;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		// printf("line [%02d]: [%s]\n\n", i, line);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 		if (line == 0)
// 			break ;
// 	}
// 	return (0);
// }
