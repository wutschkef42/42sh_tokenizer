
#ifndef FSM_H
# define FSM_H

# define TOK_BUF_SIZE 1024

# include <stdio.h>

typedef enum {
	STATE_find_tok,
	STATE_read_op,
	STATE_read_word,
	MAX_STATES
}				ParserState;


typedef enum {
	EVENT_whitespace,
	EVENT_reg_char,
	EVENT_op_char,
	EVENT_semic,
	MAX_EVENTS
}				EventType;

typedef struct	s_fsm
{
	char		current_tok[TOK_BUF_SIZE];
	size_t		current_tok_len;
	ParserState	parser_state;
	EventType	event_type;
	int			pos;
}				t_fsm;

EventType	get_new_event(char c);
int			run_state_machine(char *input);

void		action_find_tok_whitespace(t_fsm *fsm, int c);
void		action_find_tok_reg_char(t_fsm *fsm, int c);
void		action_find_tok_op_char(t_fsm *fsm, int c);
void		action_find_tok_semic(t_fsm *fsm, int c);

void		action_read_op_whitespace(t_fsm *fsm, int c);
void		action_read_op_reg_char(t_fsm *fsm, int c);
void		action_read_op_op_char(t_fsm *fsm, int c);
void		action_read_op_semic(t_fsm *fsm, int c);

void		action_read_word_whitespace(t_fsm *fsm, int c);
void		action_read_word_reg_char(t_fsm *fsm, int c);
void		action_read_word_op_char(t_fsm *fsm, int c);
void		action_read_word_semic(t_fsm *fsm, int c);

void		add_char_to_current_tok(t_fsm *fsm, int c);

#endif

