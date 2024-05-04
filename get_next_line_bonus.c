/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:27:24 by yoishi            #+#    #+#             */
/*   Updated: 2024/05/04 15:31:59 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*stack[FD_MAX + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	stack[fd] = ft_read_file_b(fd, stack[fd]);
	if (!stack[fd])
		return (NULL);
	line = ft_cut_line_b(stack[fd]);
	if (!line)
		return (NULL);
	stack[fd] = ft_next_line_b(stack[fd]);
	return (line);
}

char	*ft_read_file_b(int fd, char *stack)
{
	int		b;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	b = 1;
	while (ft_strlen2c_b(stack, '\n') == -1 && b != 0)
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
		stack = ft_strjoin_b(stack, buf);
		if (!stack)
			return (free(buf), NULL);
	}
	free(buf);
	return (stack);
}

int	ft_strlen2c_b(char *str, char c)
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

char	*ft_cut_line_b(char *stack)
{
	char	*line;
	int		i;
	int		nnl;

	if (!stack)
		return (NULL);
	if (*stack == '\0')
		return (free(stack), NULL);
	nnl = ft_strlen2c_b(stack, '\n');
	if (nnl == -1)
		nnl = ft_strlen2c_b(stack, '\0');
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

char	*ft_next_line_b(char *stack)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (stack[i++] == '\0')
		return (free(stack), NULL);
	next = (char *)malloc(ft_strlen2c_b(stack, '\0') - i + 1);
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
// 	-Werror get_next_line_bonus.c get_next_line_bonus.h
// 	get_next_line_utils_bonus.c
// 	-D BUFFER_SIZE=100 ; ./a.out ; rm -rf a.out *.gch
// #include <libc.h>
// #include <stdio.h>
// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }
// int	main(void)
// {
// 	char	*line1;
// 	char	*line2;
// 	char	*line3;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;

// 	fd1 = open("get_next_line_bonus.c", O_RDONLY);
// 	fd2 = open("get_next_line_bonus.h", O_RDONLY);
// 	fd3 = open("get_next_line_utils_bonus.c", O_RDONLY);
// 	i = 1;
// 	while (i)
// 	{
// 		// printf("fd %d, %d, %d\n", fd1, fd2, fd3);
// 		if (line1)
// 		{
// 			line1 = get_next_line(fd1);
// 			// printf("line1 [%02d]: [%s]\n", i, line1);
// 			printf("%s", line1);
// 			free(line1);
// 		}
// 		if (line2)
// 		{
// 			line2 = get_next_line(fd2);
// 			// printf("line2 [%02d]: [%s]\n", i, line2);
// 			printf("%s", line2);
// 			free(line2);
// 		}
// 		if (line3)
// 		{
// 			line3 = get_next_line(fd3);
// 			// printf("line3 [%02d]: [%s]\n", i, line3);
// 			printf("%s", line3);
// 			free(line3);
// 		}
// 		i++;
// 		if (!line1 && !line2 && !line3)
// 			break ;
// 	}
// 	return (0);
// }
