/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:50:07 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/05/12 18:07:05 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "env.h"
# include "builtin.h"
# include "error.h"
# include "utils.h"
# include "ast.h"
# include "exec.h"
# include "parser.h"
# include "redirect.h"
# include "subshell.h"
# include "mini_signal.h"
# include "test.h"
# include "../libft/libft/include/libft.h"
# include "../libft/ft_printf/include/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <stdio.h>
# include <signal.h>
# include <sys/ioctl.h>

# define TRUE 1
# define FALSE 0
# define PS1 "\e[38;5;0m\e[48;5;231m\u2593\u2592\u2591 🐚 \e[0m\e[0m\
\e[38;5;231m\e[48;5;22m\uE0B0\e[0m\e[0m\
\e[1m\e[48;5;22m minishell \e[0m\
\e[1m\e[38;5;0m\e[48;5;231m\u2591\u2592\u2593\e[0m\n\
\e[38;1;31m\u276f \e[0m\e[38;5;10m "
# define PS2 "> "

typedef struct s_env	t_env;
typedef struct s_ast	t_ast;
/* 	1. env - stores the information about environment variables
 	2. command_line - stores command line arguments input by user
	3. rc - read cursor is used to keep track of the number of 
		charecters that have been read so far from the users
		input command line so as to resume parsing the command line
		from where it left off the next time it is called.
	4. quote_error - updated if the program encounters an error 
	   related to quotation marks or other special characters in
	   the command line
	5. exit_code - represents the exit code of the program.*/
typedef struct s_manager
{
	t_env				*env;
	t_ast				*ast;
	char				*command_line;
	int					rc;
	int					quote_error;
	int					exit_code;
}						t_manager;

extern t_manager		g_manager;

#endif