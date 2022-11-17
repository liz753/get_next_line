/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:45:46 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/17 16:45:34 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> // enlever avant le push
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_var
{
	char	*tmp_stash;
	int		nbrc;
}			t_var;

char		*get_next_line(int fd);
size_t		ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *s, int c);
int			ft_read_and_stash(t_var *var, int fd);
char		*ft_substr(char *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
char		*ft_strdup(char *s1);
char		*ft_strcpy(char *dest, char *src);
size_t		ft_strlen_n(char *s);
int			main(void);

#endif
