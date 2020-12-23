/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:48:33 by sashin            #+#    #+#             */
/*   Updated: 2020/12/23 17:07:53 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// >> memcpy와 memmove 차이? <<
// 즉, memcpy는 dest와 src가 겹치는(overlay) 상황은 정의되지 않은 상태이고,
// memmove는 겹치는 상황에서도 옮겨진다? (the copy is always done in a non-destruc-tive manner.)

void	*ft_memmove(void *dest, const void *src, size_t len) // copy byte string 해준다네
{
	
}
