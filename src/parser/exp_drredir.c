/*
** exp_drredir.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon May 18 20:28:28 2015 Brendan Rius
** Last update Sun May 24 20:44:53 2015 Brendan Rius
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "tokenizer/token.h"
#include "tokenizer/tokenizer.h"
#include "my/my.h"
#include "parser/parser.h"
#include "ast.h"

int			parse_exp_drredir(struct s_iterator *i,
					  struct s_btree *node)
{
  struct s_ast_node_cmd	*cmd;
  struct s_ast_node	*ast;
  struct s_token	*t;
  char			*copyfile;

  ast = btree_get(node);
  if (ast == NULL)
    return (-1);
  cmd = &(ast->value.cmd);
  if (cmd->rtype != RT_RUNKNOWN)
    return (fprintf(stderr, "error: multiple right redirections\n"), -1);
  (void) NEXT(i);
  if (!HAS_NEXT(i))
    return (fprintf(stderr,
		    "expected string token after redirection"
		    " but no token was found\n"), -1);
  t = NEXT(i);
  if (t->type != TT_STRING)
    return (fprintf(stderr, "expected string token after redirection\n"), -1);
  if ((copyfile = strdup(t->string._string)) == NULL)
    return (fprintf(stderr, "strdup failed\n"), -1);
  cmd->rtype = RT_RDOUBLE;
  cmd->rredir = copyfile;
  return (0);
}
