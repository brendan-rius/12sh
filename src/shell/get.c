/*
** get.c for 42sh in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun May 24 00:51:39 2015 Louis Person
** Last update Sun May 24 00:53:29 2015 Louis Person
*/

#include "shell.h"

struct s_shell	*sh_get()
{
  return (g_shell);
}
