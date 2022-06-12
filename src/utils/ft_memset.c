/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaiza <amaaiza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:35:42 by amaaiza           #+#    #+#             */
/*   Updated: 2021/09/18 17:35:47 by amaaiza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	slen;

	slen = len;
	while (len--)
		*(unsigned char *)b++ = (unsigned char)c;
	return (b - slen);
}
