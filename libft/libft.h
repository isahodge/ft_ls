/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 10:33:07 by ihodge            #+#    #+#             */
/*   Updated: 2018/01/07 19:19:14 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 42
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>

/*
** libft structs
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** get_next_line structs
*/

typedef struct		s_lst
{
	struct s_lst	*next;
	int				fd;
	char			*str;
}					t_lst;

/*
** ft_printf structs
*/

typedef struct		s_format
{
	char			conv;
	char			length;
	int				space;
	int				plus;
	int				minus;
	int				alternate;
	int				zero;
	int				mfw;
	int				precision;
	int				strlength;
}					t_format;

union				u_data_union
{
	unsigned int	uint;
	unsigned char	uchar;
	unsigned short	ushort;
	unsigned long	ulong;
	size_t			usizet;
	uintmax_t		uintmaxt;
};

/*
** get_next_line prototypes
*/

int					get_next_line(const int fd, char **line);

/*
** ft_printf function prototypes
*/

typedef char		*(*t_ufptr)(union u_data_union du, t_format *format,
		unsigned int base);
int					ft_printf(const char *str, ...);
t_format			*create_format(void);
char				*dispatcher(t_format *format, long long data);
char				*u_dispatcher(t_format *format, unsigned long data);
char				*plus_flag(char *str, long long data);
char				*space_flag(char *str, long long data);
char				*min_field_wid(char *str, t_format *format);
void				fill_after(char *str, char **result, int fill);
void				fill_before(char *str, char **result, int fill,
		char character);
char				*int_precision(char *str, int precision, int data);
char				*negative_int(char *str, long long data);
char				*ft_lltoa(long long n);
char				*ft_ultoa_base(union u_data_union du, t_format *format,
		unsigned int base);
char				*fptr_with_length(char c, char l, long long *data);
char				*ufptr_with_length(t_format *format, unsigned long *data);
char				*alt_flag(char *str, t_format *format);
int					is_flag(char c);
int					is_conv(char c);
int					is_length(char *str, t_format *format);
char				*string_conv(t_format *format, char *str);
char				*str_precision(char *str, int precision);
char				*mfw_char(char *str, t_format *format);
void				char_conv(t_format *format, unsigned char c);
void				write_arg(va_list ap, t_format *format, char conv);
void				change_conv(t_format *format);

/*
** libft prototypes
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
		size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const*s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_strrev(char *s);
int					ft_iswhitespace(char c);
char				*ft_strlower(char *s);
char				*ft_strupper(char *s);
char				*ft_strjoinc(char const *s1, char const *s2, char c);
#endif
