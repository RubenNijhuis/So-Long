/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 09:46:16 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/06/30 20:42:43 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

// Conversion
int64_t		ft_atoi(const char *s);
char		*ft_itoa(int64_t nb);

// Is type
int32_t		ft_isalnum(int32_t c);
int32_t		ft_isalpha(int32_t c);
int32_t		ft_isascii(int32_t c);
int32_t		ft_isdigit(int32_t c);
int32_t		ft_isprint(int32_t c);

// Linked list
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
uint32_t	ft_lstsize(t_list *lst);

// Memory
void		*ft_bzero(void *ptr, size_t len);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memchr(const void *src, int32_t c, size_t n);
int32_t		ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, void const *src, size_t len);
void		*ft_memmove(void *dest, void *src, size_t len);
void		*ft_memset(void *ptr, int32_t c, size_t len);

// Misc
size_t		ft_2d_arrlen(char **arr);
void		ft_error(char *str);
void		ft_free_2d_array(char ***arr, uint32_t item_amount);
uint32_t	ft_nbrlen(int64_t c);

// String
int32_t		ft_isinset(const char *set, char c);
uint32_t	ft_str_occur(char *str, char c);

void		ft_putchar_fd(char s, uint32_t fd);
void		ft_putendl_fd(char *s, uint32_t fd);
void		ft_putnbr_fd(int64_t nb, uint32_t fd);
void		ft_putstr_fd(char *s, uint32_t fd);

void		ft_repl_chr(char *line, char cur, char new);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int32_t c);
char		*ft_strdup(const char *s1);
void		ft_striteri(char *s, void (*f)(uint32_t, char*));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(char const *s, char (*f)(uint32_t, char));
int32_t		ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *h, const char *n, size_t len);
char		*ft_strrchr(const char *s, int32_t c);
char		*ft_strtrim(char const *src, char const *set);
char		*ft_substr(char const *s, uint32_t start, size_t len);

int32_t		ft_tolower(int32_t c);
int32_t		ft_toupper(int32_t c);

int			ft_str_contains_char(const char *s, const int c);
char		*ft_strtolower(char *s);
char		*ft_strtoupper(char *s);

#endif
