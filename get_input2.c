/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:15:13 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/12 15:16:11 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *arr, size_t size)
{
	size_t	min;
	size_t	i;
	size_t	j;
	int		temp;

	i = 0;
	while (i < size)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min])
				min = j;
			++j;
		}
		if (i != min)
		{
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
		++i;
	}
}

int		is_nums(const char **argv)
{
	const char	*str;
	const char	**iter;

	iter = argv + 1;
	while (*iter)
	{
		str = *iter;
		while (*str)
		{
			if (ft_isdigit(*str))
				return (1);
			++str;
		}
		++iter;
	}
	return (0);
}

int		is_repeats(const t_stack *a)
{
	size_t	a_size;
	size_t	iter;
	int		*arr;

	a_size = lstsize(a);
	arr = get_arr(a, a_size);
	sort_array(arr, a_size);
	iter = 0;
	while (iter < a_size - 1)
	{
		if (arr[iter] == arr[iter + 1])
			return (1);
		++iter;
	}
	free(arr);
	return (0);
}
