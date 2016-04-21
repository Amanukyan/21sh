#ifndef FT_21SH_H
# define FT_21SH_H

# include "ft_printf.h"
# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <sys/types.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>

# define PROMPT "$> "

typedef struct 		s_line
{
	char 			*cmd;
	int 			prompt;
	// int				prompt_y;
	int 			size_prompt;
	int 			curs_x;
	int 			curs_x_win;
	int 			curs_y;
	int 			win_col;
	int 			win_row;
	int 			size_x;
	int 			size_y;
	char			*clipboard;
}					t_line;

extern t_line		main_line;

typedef struct		s_hist
{
	char 			*cmd;
	int 			size;
	struct s_hist	*next;
	struct s_hist	*prev;
}					t_hist;

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

//********************************************//
// 					42SH                  	  //
//********************************************//

// history.c
t_hist				*init_history(t_hist *history);
t_hist				*add_line_to_history(t_hist *history);
int 				print_history(t_hist *history);

//********************************************//
// 					TERMCAPS                  //
//********************************************//

// init_term.c
int 				raw_terminal_mode(void);
int 				default_terminal_mode(void);

// utils.c
void				ft_puts(char *res);
void				fmove(int x, int y);
void				fmovex(int x);
void				print_line(int edit);


// signals.c
void				ft_signal(void);
void				handle_ctrl_d(void);

// get_key.c
int					get_key(t_env *env_list);

// press_arrow.c
void				press_arrow(char key, t_hist *history, t_hist **tmp);

// print_letter.c
void				print_letter(char *key);
void				edit_add_char(char key);

// press_delete.c
void				press_delete(void);

// press_enter.c
t_hist				*press_enter(t_env *env_list, t_hist *history);

// special_keys.c
void				go_to_start(void);
void				go_to_end(void);
void				cut_entire_line(void);
void				cut_end_of_line(void);
void				paste(void);

// window_size.c
void				resize(void);
void				get_window_size(void);
void				clr_screen(void);

//********************************************//
// 					MINISHELL                 //
//********************************************//

// env_variables.c
void				print_env(t_env *head);
char				*search_in_env(char *name, t_env *list);
int					ft_setenv(char *name, char *value, t_env **head);
int					ft_unsetenv(char *name, t_env **list);
void				change_env_variable(char *name, char *new_value, t_env *list);

// builtins.c
void				change_cwd(char **args, t_env **list);
void				ft_echo(char **args, t_env *list);
int					builtin_commands(char *name, char **args, t_env **env_list);

// commands.c
char				*find_command(char *command, t_env *env_list);
int					execute_command(char *user_entry, t_env **env_list, char **environ);
void				run_commands(char *user_entry, t_env **env_list, char **environ);

// prompt.c
int 				prompt(t_env *env_list, char *current_line);

// line.c
void				init_line(int size_prompt);
void				init_new_line(void);
void				free_line(t_line *line);
int					chars_by_line(int line_nb);

//********************************************//
// 					AST                       //
//********************************************//

# include <stdlib.h>
# include <string.h>
# include <term.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>


# include <dirent.h>



# define TOKEN_CMD	0
# define TOKEN_PIPE	1
# define TOKEN_DOUBLE_WRITE	2
# define TOKEN_SIMPLE_WRITE	3
# define TOKEN_SIMPLE_READ	4
# define TOKEN_DOUBLE_READ	5
# define TOKEN_AND	6
# define TOKEN_OR	7	


# define TRUE	1
# define FALSE	0



typedef struct      s_tree
{
	int 			token;

	int 			fd_in;
	int 			fd_out;
	
	
	char 			**cmd;

	int 			from;
	int 			to;
	
	struct s_tree	*left;
	struct s_tree	*right;


}					t_tree;


typedef struct      s_token_info
{
	int 			type;
	int 			pos;
}					t_token_info;




t_env	*store_env_variables(char **env);



int					ft_handle_cmdline();
char				**ft_separate_cmd(char *str, t_token_info *token_info);
void 				ft_build_recursive(t_tree *node, char *cmd, t_token_info *token_info);
void 				ft_build_simple_cmd(t_tree *node, char *cmd);
t_tree				*ft_build_tree(char *cmd_line);

int                 ft_exec_tree(t_tree *node, t_env *env_list);
void                ft_choose_exec(t_tree *node, t_env *env_list);
int					ft_exec_cmd(t_tree *node, t_env *env_list);

void				ft_and(t_tree *node, t_env *env_list);
void				ft_or(t_tree *node, t_env *env_list);
void                ft_simple_read(t_tree *node, t_env *env_list);
void				ft_double_read(t_tree *node, t_env *env_list);
void                ft_write(t_tree *node, t_env *env_list);
void                ft_pipe(t_tree *node, t_env *env_list);

char				*ft_parentheses();

char				*ft_complete_cmd(char special, char *separator);
char				*ft_handle_quote();

void				ft_handle_fd_redirection(t_tree *node);

void				ft_find_operator(char *str, t_token_info *token_info);









char	*search_in_env(char *name, t_env *list);


#endif
