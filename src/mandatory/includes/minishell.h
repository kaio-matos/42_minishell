/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:06:58 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/03/02 21:26:43 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <libft.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

typedef struct s_enviroment
{
	int			argc;
	char		**argv;
	char		**envp;
}	t_enviroment;

typedef struct s_command
{
	char		*raw;
	t_dlist		*flags;
	char		*executable;
	t_bool		is_builtin;
}	t_command;

typedef enum e_token_type
{
	PIPE,			// |					- allow the redirection of outputs
	RDRT_INPUT,		// <					- input redirection
	RDRT_O_OUTPUT,	// >					- is used to overwrite
	HERE_DOC,		// <<					- allow the creation of a "local file" inside the terminal. Ex: `cat << EOF`
	RDRT_A_OUTPUT,	// >>					- is used to append
	COMMAND,		// /bin files commands
	BUILTIN			// builtin commands
}	t_token_type;


typedef struct s_token
{
	char			*raw;
	t_token_type	type;
}	t_token;


typedef struct s_shell
{
	t_enviroment	enviroment;
	t_dlist			*history;
}	t_shell;

/******************************************************************************\
* BOOTSTRAP																	   *
\******************************************************************************/

t_shell		*bootstrap_sh(int argc, char **argv, char **envp);

/******************************************************************************\
* BUILTINS																	   *
\******************************************************************************/

void		b__cd(void);
void		b__echo(void);
void		b__env(void);
void		b__exit(void);
void		b__export(void);
void		b__pwd(void);
void		b__unset(void);

/******************************************************************************\
* CASTING																	   *
\******************************************************************************/

// INT
int			*c__new_int(int value);
int			c__get_int(void *content);

// STRING
char		**c__new_str(char *value);
char		*c__get_str(void *content);

/******************************************************************************\
* INPUT																	   *
\******************************************************************************/

t_command	i__request_command(void);
t_command	i__parse_command(char *command_str);

/******************************************************************************\
* VARIABLES																	   *
\******************************************************************************/

void		v__dollar(void);

#endif
