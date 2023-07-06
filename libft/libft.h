/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:19:00 by anayef            #+#    #+#             */
/*   Updated: 2023/07/06 12:04:04 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *nptr);
void	ft_putstr(char *s);
char	*ft_toupper(char *s);
void	ft_putchar(char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);

#endif
