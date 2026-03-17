/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:27:03 by asadik            #+#    #+#             */
/*   Updated: 2026/03/17 12:43:48 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling.h"

static void	check_sign(const char **nptr, int *negative)
{
	if (**nptr == '-')
	{
		*negative = -1;
		*nptr = *nptr + 1;
	}
	else if (**nptr == '+')
		*nptr = *nptr + 1;
}

static t_result	init(void)
{
	t_result	result;

	result.type = ERROR;
	result.value.error = "Not a valid Number";
	return (result);
}

/// Converts initial string to an int skipping leading whitespace
/// characters and handling an optional '+' or '-' sign.
/// Processes numeric chars until a non-digit is encountered and
/// returns the resulting integer, accounting for negative values if applicable.
t_result	ft_atoi(const char *nptr)
{
	int			negative;
	t_result	result;

	result = init();
	negative = 0;
	while ((*nptr == ' ' || (*nptr >= 9 && *nptr <= 13)) && *nptr != '\0')
		nptr++;
	check_sign(&nptr, &negative);
	if (*nptr >= '0' && *nptr <= '9' && *nptr != '\0')
	{
		result.type = INT;
		result.value.n = 0;
	}
	while (*nptr >= '0' && *nptr <= '9' && *nptr != '\0')
	{
		result.value.n *= 10;
		result.value.n += *nptr - '0';
		nptr++;
	}
	if ((*nptr < '0' || *nptr > '9') && *nptr != '\0')
		result = init();
	if (negative)
		result.value.n *= negative;
	return (result);
}
