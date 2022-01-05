/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:49:34 by sashin            #+#    #+#             */
/*   Updated: 2021/12/14 15:10:20 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(void)
{
	char	*new;

	new = (char *)malloc(sizeof(char));
	if (new == NULL)
		return (NULL);
	new[0] = '\0';
	return (new);
}
