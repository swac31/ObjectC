/*
** implement.h for  in /home/penava_b/perso/Obj/Obj4/inc/tools
** 
** Made by penava_b
** Login   <penava_b@epitech.net>
** 
** Started on  Mon Dec 14 23:48:27 2015 penava_b
** Last update Sat Jan 23 02:05:11 2016 penava_b
*/

#pragma once

int	write(int, const char *, int);

#define implement(name, extends, ...)					\
									\
  __attribute__((no_instrument_function))				\
  static void *__pre_ctor_ ## name(name *this)				\
  {									\
    unsigned long offset = sizeof(struct __virtual_ ## extends);	\
									\
    (void)offset;							\
    this->this = this;							\
    this->_virtual = __vtable_instance_ ## name;			\
    this->__class_type = name ## _type_instance;			\
    this->this_ ## extends = (void *)this;				\
    APPLY_MACRO_VAR(__implements_in_ctor__, ##__VA_ARGS__);		\
    return this;							\
  }									\
    									\
  static Type true_ ## name ## _type_instance =				\
    {									\
      #name,								\
      0,								\
      sizeof(name),							\
      sizeof(struct __virtual_ ## name) / sizeof(void *),		\
      (const char *[sizeof(struct __virtual_ ## name) / sizeof(void *)])\
      {},								\
      (void *)__pre_ctor_ ## name,					\
      (void *)name ## _ ## dtor						\
    };									\
									\
  const Type * const name ## _type_instance =				\
    &true_ ## name ## _type_instance;					\
									\
  static struct __virtual_ ## name __true_vtable_instance_ ## name;	\
									\
  const struct __virtual_ ## name * const __vtable_instance_ ## name =	\
    &__true_vtable_instance_ ## name;					\
									\
  static void __hidden_implement_function_for_ ## name();		\
  void __implement_function_for_ ## extends();				\
  									\
  __attribute__((constructor, no_instrument_function))		        \
  void __implement_function_for_ ## name()				\
  {									\
    static char implemented = 0;					\
    unsigned long i;							\
									\
    if (implemented++ != 0)						\
      return ;								\
    true_ ## name ## _type_instance.super = extends ## _type_instance;	\
    __implement_function_for_ ## extends();				\
    for (i = 0; i < sizeof(struct __virtual_ ## extends)		\
	   / sizeof(void *); i++)					\
      {									\
	((void **)&__true_vtable_instance_ ## name)[i] =		\
	  ((void **)__vtable_instance_ ## extends)[i];			\
	true_ ## name ## _type_instance.methodsName[i] =		\
	  extends ## _type_instance->methodsName[i];			\
      }									\
    for (; i < sizeof(struct __virtual_ ## name)			\
	   / sizeof(void *); i++)					\
      {									\
	((void **)&__true_vtable_instance_ ## name)[i] = 0;		\
	true_ ## name ## _type_instance.methodsName[i] = 0;		\
      }									\
    __true_vtable_instance_ ## name.dtor = (void *)name ## _ ## dtor;	\
  }									\
      									\
  __attribute__((no_instrument_function))				\
  void		__push_method_ ## name(void *arg, const char *name_m,	\
				       size_t offset)			\
  {									\
    int		__get_current_level();					\
    void		**member =					\
      &((void **)&__true_vtable_instance_ ## name)			\
      [offset / sizeof(void *)];					\
									\
    if (__get_current_level() > 0)					\
      {									\
	write(2, "[Error]Illegal call to __push_method\n", 37);		\
	return ;							\
      }									\
    if (offset < sizeof(struct __virtual_ ## extends) &&		\
	*member != 0 && *member !=					\
	((void **)__vtable_instance_ ## extends)			\
	[offset / sizeof(void *)])					\
      {									\
	write(2, "[Error]Trying to override twice a method\n", 41);	\
	return;								\
      }									\
    *member = arg;							\
    ((void **)&__true_vtable_instance_ ## name)				\
      [offset / sizeof(void *)] = arg;					\
    true_ ## name ## _type_instance.methodsName				\
      [offset / sizeof(void *)] = name_m;				\
    for (size_t i = 0; i < sizeof(struct __virtual_ ## name)		\
	   / sizeof(void *); i++)					\
      if (((void **)__vtable_instance_ ## name)[i] == 0)		\
	return ;							\
    __hidden_implement_function_for_ ## name();				\
  }									\
									\
  __attribute__((no_instrument_function))				\
  static void __hidden_implement_function_for_ ## name()

#define superCtor(type, name, ...)		\
  type ## _ ## name(this, ##__VA_ARGS__)

#define superDtor()				\
  this->__class_type->super->dtor(this);

#define $ (*this)
