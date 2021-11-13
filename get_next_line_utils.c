/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:38:28 by majjig            #+#    #+#             */
/*   Updated: 2021/11/13 21:51:48 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_add_char(char *str_static, char *c)
{
	int		len;
	char	*newstr_static;
	int		i;

	i = -1;
	len = 0;
	while (str_static[len++]){}
	newstr_static = (char *) malloc(len + 2);
	if (newstr_static == NULL)
		return (free(str_static), NULL);
	while (str_static[++i])
		newstr_static[i] = str_static[i];
	newstr_static[i++] = *c;
	newstr_static[i] = 0;
	return (free(str_static), newstr_static);
}
