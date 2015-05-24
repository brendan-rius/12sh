/*
** last.c for vectors in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Tue Apr 28 18:29:28 2015 Brendan Rius
** Last update Tue Apr 28 18:30:01 2015 Brendan Rius
*/

#include <assert.h>
#include "my.h"

int	vec_last(struct s_vec *vec, void **ptr)
{
  assert(vec != NULL);
  assert(ptr != NULL);
  if (vec->size == 0)
    return (-1);
  *ptr = vec->_data[vec->size];
  return (0);
}
