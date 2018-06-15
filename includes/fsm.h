
#ifndef FSM_H
# define FSM_H

# define TOK_BUF_SIZE 1024

# include <stdio.h>
# include "libft.h"



// TOKENIZER STUFF 

/* operator precedence */

//		;
//		||
//		&&
//		

/*
	the idea is to build a syntax tree that groups the input stream into ; delimited commands.
	each of those is further divided by logial operators
	in between logical operators the command name is the leftest word, followed by its arguments
	and with redirects sprinkled in between
	once the tree has subtrees where each represents the command between two logical operators
	its time to setup the redirects (one for output one for input), then call the command and its
	arguments in a subshell or as a builtin.

*/

/* grammar tokens */

# define LESS	"<"
# define DLESS	"<<"
# define GREAT	">"
# define AND_IF	"&&"
# define AND_OR	"||"
# define SEMIC	";"
# define SQUOT	'\''
# define DQUOT	'\"'


typedef enum {
	STATE_find_tok,
	STATE_read_op,
	STATE_read_word,
	STATE_read_squot,
	STATE_read_dquot,
	MAX_STATES
}				ParserState;


typedef enum {
	EVENT_whitespace,
	EVENT_reg_char,
	EVENT_op_char,
	EVENT_semic,
	EVENT_squot,
	EVENT_dquot,
	MAX_EVENTS
}				EventType;

typedef enum {
	TYPE_less,
	TYPE_dless,
	TYPE_great,
	TYPE_and_if,
	TYPE_and_or,
	TYPE_semic,
	TYPE_op,
	TYPE_word,
	TYPE_squot,
	TYPE_dquot,
	TYPE_pipe,
	MAX_TYPES
}				TokType;



typedef struct	s_fsm
{
	char		current_tok[TOK_BUF_SIZE];
	size_t		current_tok_len;
	ParserState	parser_state;
	EventType	event_type;
	int			pos;
}				t_fsm;

typedef struct	s_tok
{
	TokType		type;
	char		*id;
}				t_tok;

EventType	get_new_event(char c);
t_list		*run_state_machine(char *input);

void		action_find_tok_whitespace(t_fsm *fsm, t_list **tokens, int c);
void		action_find_tok_reg_char(t_fsm *fsm, t_list **tokens, int c);
void		action_find_tok_op_char(t_fsm *fsm, t_list **tokens, int c);
void		action_find_tok_semic(t_fsm *fsm, t_list **tokens, int c);
void		action_find_tok_squot(t_fsm *fsm, t_list **tokens, int c);
void		action_find_tok_dquot(t_fsm *fsm, t_list **tokens, int c);

void		action_read_op_whitespace(t_fsm *fsm, t_list **tokens, int c);
void		action_read_op_reg_char(t_fsm *fsm, t_list **tokens, int c);
void		action_read_op_op_char(t_fsm *fsm, t_list **tokens, int c);
void		action_read_op_semic(t_fsm *fsm, t_list **tokens, int c);
void		action_read_op_squot(t_fsm *fsm, t_list **tokens, int c);
void		action_read_op_dquot(t_fsm *fsm, t_list **tokens, int c);

void		action_read_word_whitespace(t_fsm *fsm, t_list **tokens, int c);
void		action_read_word_reg_char(t_fsm *fsm, t_list **tokens, int c);
void		action_read_word_op_char(t_fsm *fsm, t_list **tokens, int c);
void		action_read_word_semic(t_fsm *fsm, t_list **tokens, int c);
void		action_read_word_squot(t_fsm *fsm, t_list **tokens, int c);
void		action_read_word_dquot(t_fsm *fsm, t_list **tokens, int c);

void		action_read_squot_whitespace(t_fsm *fsm, t_list **tokens, int c);
void		action_read_squot_reg_char(t_fsm *fsm, t_list **tokens, int c);
void		action_read_squot_op_char(t_fsm *fsm, t_list **tokens, int c);
void		action_read_squot_semic(t_fsm *fsm, t_list **tokens, int c);
void		action_read_squot_squot(t_fsm *fsm, t_list **tokens, int c);
void		action_read_squot_dquot(t_fsm *fsm, t_list **tokens, int c);

void		action_read_dquot_whitespace(t_fsm *fsm, t_list **tokens, int c);
void		action_read_dquot_reg_char(t_fsm *fsm, t_list **tokens, int c);
void		action_read_dquot_op_char(t_fsm *fsm, t_list **tokens, int c);
void		action_read_dquot_semic(t_fsm *fsm, t_list **tokens, int c);
void		action_read_dquot_squot(t_fsm *fsm, t_list **tokens, int c);
void		action_read_dquot_dquot(t_fsm *fsm, t_list **tokens, int c);

void		add_char_to_current_tok(t_fsm *fsm, int c);
void		print_tokenstream(t_list *lst);

int			process_tokens(t_list **tokens);





#endif

