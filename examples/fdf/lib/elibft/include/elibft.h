/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elibft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:04:12 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 14:01:26 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELIBFT_H
# define ELIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdint.h>
# define BUFFER_SIZE 1024
# define SUCCESS 1
# define FAIL 0
# define CONTINUE 1
# define STOP 0
# define ERROR -1

typedef struct s_lst
{
	int				i;
	struct s_lst	*next;
	void			*item;
}	t_lst;

typedef struct s_arr
{
	size_t	len;
	size_t	size_of;
	void	*item;
}	t_arr;

typedef struct s_infarr
{
	size_t	len;
	size_t	size_of;
}	t_infarr;

typedef struct s_file
{
	int				fd;
	ssize_t			b;
	char			buf[BUFFER_SIZE];
	ssize_t			i;
	char			*line;
	size_t			ttl;
	struct s_file	*next;
}	t_file;

//array
t_arr		*arr_new(t_arr **arr, void *item, size_t size_of, size_t len);
t_arr		*arr_iter(t_arr **arr, int (*f)(t_arr **, void *), void *param);
t_arr		*arr_insert(t_arr **arr, t_arr **new, int i);
t_arr		*arr_clean(t_arr **arr, int (*f)(void *));
t_arr		*arr_add(t_arr **arr, void *item, int i, size_t size_of);
t_arr		*arr_madd(t_arr **arr, void *item, int i, size_t size_of);
t_arr		*arr_del(t_arr **arr, int i, int (*f)(void *));
void		*arr_extract(t_arr **arr, int i);
void		*arr_retrieve(t_arr **arr);

//conversion
t_lst		*arr_to_lst(t_arr **arr);
t_arr		*lst_to_arr(t_lst **lst);
int			ft_atoi(char *str, void *number, size_t size_of, int base);
t_arr		*strs_to_arr(t_arr **arr, char **strs);

//file
int			get_next_line(int fd, char **line);

//list
t_lst		*lst_new(t_lst **lst, void *item);
size_t		lst_len(t_lst **lst);
t_lst		*lst_iter(t_lst **lst, int (*f)(t_lst**, void *), void *param);
void		*lst_insert(t_lst **lst, t_lst **new, int i);
t_lst		*lst_get(t_lst **lst, int i);
t_lst		*lst_add(t_lst **lst, void *item, int i);
void		*lst_clean(t_lst **lst, int (*f)(void *));
t_lst		*lst_madd(t_lst **lst, void *item, int i, size_t size_of);
t_lst		*lst_del(t_lst **lst, int i, int (*f)(void *));
void		*lst_extract(t_lst **lst, int i);

//memory
void		*ft_alloc(void *result, size_t size_of, \
size_t depth, size_t *spans);
void		ft_bzero(void *s, size_t len);
void		*ft_calloc(size_t num, size_t size);
int			ft_free(void *p);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);

//output
int			ft_printf(const char *fstr, ...);

//parr
long long	ft_parrclean(int code, void (*del)(void *), void *arr1, void *arr2);
void		*ft_parrjoin(void *arr1, void *arr2);
size_t		ft_parrlen(void *arr);

//string
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
t_lst		*ft_split(t_lst **result, char const *s, char c);

char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s);
char		**ft_strdups(char **strs);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(const char *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
bool		is_eqlstr(const char *s1, const char *s2);

#endif
