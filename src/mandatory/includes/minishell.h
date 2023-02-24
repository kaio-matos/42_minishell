/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:06:58 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/02/24 20:26:18 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <libft.h>

typedef struct s_enviroment
{
	int			argc;
	char		**argv;
	char		**envp;
}	t_enviroment;

typedef struct s_shell
{
	t_enviroment	enviroment;
	t_dlist			*history;
}	t_shell;

/******************************************************************************\
* BOOTSTRAP																	   *
\******************************************************************************/

t_shell	*bootstrap_sh(int argc, char **argv, char **envp);

/******************************************************************************\
* BUILTINS																	   *
\******************************************************************************/

void	b__cd(void);
void	b__echo(void);
void	b__env(void);
void	b__exit(void);
void	b__export(void);
void	b__pwd(void);
void	b__unset(void);

/******************************************************************************\
* VARIABLES																	   *
\******************************************************************************/

void	v__dollar(void);

#endif
