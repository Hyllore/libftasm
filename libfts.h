/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 10:30:25 by droly             #+#    #+#             */
/*   Updated: 2018/05/11 14:09:26 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H

#include <strings.h>

void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *dest, const char *src);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
char	*ft_strncat(char *s1, const char *s2, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_puts(const char *string);
size_t	ft_strlen(const char *s);


#endif
