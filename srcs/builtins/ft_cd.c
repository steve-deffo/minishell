/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:55:04 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/05/09 15:38:54 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

static	int	check_ret(int ret, t_env *pwd)
{
	if (ret < 0)
	{
		perror("chdir");
		return (EXIT_FAILURE);
	}
	pwd->value = getcwd(NULL, 0);
	if (!pwd->value)
	{
		perror("getcwd");
		return (EXIT_FAILURE);
	}
	else
	{
		ft_putstr_fd ("cd: error retrieving previous directory\n",
			STDERR_FILENO);
		return (EXIT_FAILURE);
	}
}

static	int	change_pwd(t_env *pwd)
{
	char	*tmp;
	t_env	*oldpwd;
	int		ret;

	if (!pwd)
		return (EXIT_FAILURE);
	tmp = pwd->value;
	pwd->value = getcwd(NULL, 0);
	if (!pwd->value)
	{
		oldpwd = get_env("OLDPWD");
		if (oldpwd && oldpwd->value && *oldpwd->value)
		{
			ret = chdir(oldpwd->value);
			check_ret(ret, pwd);
		}
	}
	if (tmp)
		free(tmp);
	return (EXIT_SUCCESS);
}

static	int	cd_home(void)
{
	t_env	*ptr;
	char	*home;
	int		exit_code;

	exit_code = change_pwd(get_env("OLDPWD"));
	ptr = get_env("HOME");
	if (!ptr)
		return (error_general("cd", NULL, strerror(errno)));
	home = ptr->value;
	exit_code = chdir(home);
	if (exit_code < 0)
		return (error_general("cd", NULL, strerror(errno)));
	exit_code = change_pwd(get_env("PWD"));
	return (EXIT_SUCCESS);
}

int	ft_cd(char **argv)
{
	int	exit_code;

	exit_code = change_pwd(get_env("OLDPWD"));
	if (!*(argv + 1))
		return (cd_home());
	if (check_option(*(argv + 1)) == EXIT_FAILURE)
		return (error_usage("cd", *(argv + 1)));
	exit_code = chdir(*(argv + 1));
	if (exit_code < 0)
		return (error_general("cd", *(argv + 1), strerror(errno)));
	exit_code = change_pwd(get_env("PWD"));
	return (exit_code);
}
