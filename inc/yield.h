/*
** yield.h for  in /home/penava_b/perso/Obj/ObjLang3/Tools
** 
** Made by penava_b
** Login   <penava_b@epitech.net>
** 
** Started on  Sat Dec  5 16:24:38 2015 penava_b
** Last update Mon Dec 14 23:20:02 2015 penava_b
*/

#pragma once

#include <alloca.h>
#include "Generator.h"

void    	__yield_editRet();

#define initYield()						\
  if (this != NULL && this->label != NULL)			\
    {								\
      __yield_editRet();					\
      goto *this->label;					\
    }								\
  else								\
    {								\
      if (this != NULL)						\
	{							\
	  this->alive = 0;					\
	  this->init = 42;					\
	}							\
    }

#define yield(val)							\
  if (M(this, __setjmp) == 0)						\
    {									\
      if (this->init)							\
	{								\
	  M(this, saveStack, alloca(0), __builtin_frame_address(0));	\
	  this->alive = 42;						\
	}								\
      return val;							\
    }									\
  else									\
    {									\
      if (this != NULL)							\
	{								\
	  M(this, restore, alloca(0));					\
	  this->alive = 0;						\
	}								\
    }

#define for_yield(x, Func, ret, ...)					\
  for (ret = Func(M(x, reset, Func), ##__VA_ARGS__);			\
       M(x, __continue);						\
       ret = ((__typeof__(ret)(*)(Generator *,...))(((Generator *)x)->func))(x))

#define yield_interupt(x) if ((M(x, clean), 42))