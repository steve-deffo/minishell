/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:49:28 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/05/09 14:09:17 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_unbrlen_base(unsigned long long int nbr, size_t base)
{
	size_t	i;

	i = 1;
	while (nbr >= (unsigned long long int)base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}
