/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:31:31 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/05/09 15:22:55 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"

int	error_exit(char *cmd, char *err, int exit_code)
{
	g_manager.exit_code = exit_code;
	error_general(cmd, NULL, err);
	free_ast(g_manager.ast);
	exit(g_manager.exit_code);
	return (EXIT_FAILURE);
}

// int main(void)
// {
// 	error_exit("pwd", "error", 1);
// }