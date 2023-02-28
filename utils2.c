/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:18:21 by kel-baam          #+#    #+#             */
/*   Updated: 2023/02/28 02:18:25 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_info	new_info(t_data data, int size)
{
	t_info	info;

	info.is_empty = 0;
	info.up = 1;
	info.op_count = 0;
	info.diff1 = abs_(data.pos_firs_min) - 1;
	info.diff2 = abs_(size - data.pos_last_min);
	return (info);
}

int	get_chunks_num(int size)
{
	if (size <= 100)
		return (BIG_CHUNKS);
	else
		return (SMALL_CHUNKS);
}
