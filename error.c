/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:14:25 by kel-baam          #+#    #+#             */
/*   Updated: 2023/02/27 12:14:28 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_error(void)
{
	write(STDERR_FILENO, MSG_ERR, ft_strlen(MSG_ERR));
	exit(1);
}

unsigned int	abs_(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}
