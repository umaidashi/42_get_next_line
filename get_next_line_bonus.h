/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:28:05 by yoishi            #+#    #+#             */
/*   Updated: 2024/05/04 15:23:08 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# define FD_MAX 10240

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read_file_b(int fd, char *stack);
int		ft_strlen2c_b(char *str, char c);
char	*ft_strjoin_b(char *s1, char *s2);
char	*ft_strdup_b(char *str);
char	*ft_cut_line_b(char *stack);
char	*ft_next_line_b(char *stack);

#endif
