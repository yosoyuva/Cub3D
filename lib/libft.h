/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:19:54 by ymehdi            #+#    #+#             */
/*   Updated: 2021/02/02 16:47:09 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>

# include <stdlib.h>

# include <string.h>

# include <stdio.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);

void				ft_putstr(const char *s);

size_t				ft_strlen(const char *s);

void				ft_putendl(char const *s);

void				ft_putnbr(int n);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_atoi(const char *str);

char				*ft_strdup(const char *s1);

char				*ft_strcpy(char *dst, const char *src);

char				*ft_strncpy(char *dst, const char *src, size_t len);

char				*ft_strcat(char *s1, const char *s2);

char				*ft_strncat(char *s1, const char *s2, size_t n);

size_t				ft_strlcat(char *dst, const char *src, size_t size);

char				*ft_strstr(const char *haystack, const char *needle);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putnbr_fd(int n, int fd);

void				ft_putendl_fd(char const *s, int fd);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strnstr(const char *big, \
	const char *little, size_t len);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

void				*ft_memset(void *b, int c, size_t len);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

char				*ft_strtrim(char const *s1, char const *set);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

char				*ft_strnew_lib(size_t size);

char				**ft_split(const char *s, char c);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_itoa(int n);

char				*ft_substr(char const *s, unsigned int start, size_t len);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_striter(char *s, void (*f)(char *));

void				ft_strclr(char *s);

void				ft_strdel(char **as);

void				*ft_memalloc(size_t size);

int					ft_strequ(char const *s1, char const *s2);

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				*ft_memset(void *b, int c, size_t len);

void				ft_memdel(void **ap);

t_list				*ft_lstnew(void const *content);

void				*ft_calloc(size_t count, size_t size);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);

void				ft_lstadd_front(t_list **alst, t_list *new);

int					ft_lstsize(t_list *lst);

t_list				*ft_lstlast(t_list *lst);

void				ft_lstadd_back(t_list **alst, t_list *new);

void				ft_lstdelone(t_list *lst, void (*del)(void*));

void				ft_lstclear(t_list **lst, void (*del)(void*));

void				ft_lstiter(t_list *lst, void (*f)(void *));

t_list				*ft_lstmap(t_list *lst, void *(*f)(void*), \
void (*del)(void*));

int					ft_nlength(int n);

char				*ft_strnew_zero(size_t size);

char				*ft_strnew_space(size_t size);

int					ft_nlength_hex_m(long int n);

char				*ft_itoa_hex_m(long int n);

char				*ft_itoa_hex(int n);

int					ft_nlength_hex(int n);

char				*ft_itoa_hex_long(unsigned int n);

int					ft_nlength_hex_long(unsigned int n);

char				*ft_strndup(const char *s1, int size);

int					ft_nlength_u(unsigned int n);

char				*ft_itoa_u(unsigned int n);

char				*ft_strcpy_wout_frst_c(const char *src);

char				*ft_strcpy_from_pos(char *dst, const char *src, int pos);

char				*ft_strjoin_fo(char *s1, char const *s2);

char				*ft_strjoin_ft(char const *s1, char *s2);

char				*ft_strcpy_from_pos_f(char *dst, char *src, int pos);

char				*ft_strndup_fo(char *s1, int size);

char				*ft_strcpy_wout_frst_c_f(char *src);

char				*ft_strnew_space_f(char *str, size_t size);

char				*ft_strnew_zero_f(char *str, size_t size);

char				*ft_itoa_hex_long_m(unsigned int nb);

char				*ft_itoa_hex_long_p(unsigned long int nb);

int					ft_nlength_hex_long_p(unsigned long int n);

#endif
