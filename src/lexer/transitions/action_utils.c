

#include "lex.h"

void	add_char_to_current_tok(t_fsm *fsm, int c)
{
	if (fsm->current_tok_len < TOK_BUF_SIZE)
		fsm->current_tok[fsm->current_tok_len++] = (char)c;
}