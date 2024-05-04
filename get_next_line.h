/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:21:01 by yoishi            #+#    #+#             */
/*   Updated: 2024/05/03 20:41:36 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *stack);
int		ft_strlen2c(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_cut_line(char *stack);
char	*ft_next_line(char *stack);

#endif
