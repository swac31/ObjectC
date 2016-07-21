/*
 * Copyright (C) 2016  Bastien Penavayre
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#pragma once

#define M(var, name, args...)						\
    (((typeof(var))__tmp_pointer__((void *)var))                    \
     ->_virtual->name(((typeof(var))__tmp_pointer__((void *)0x42))->this, ##args))
    
typedef struct Object Object;

struct	Object__virtual
{
  void	(*dtor)(void *);
  const char *(*toString)(const void *);
  const Type *(*getType)(const void *);
};

struct Object__interfaces
{
};

struct	Object__data_weak
{
  const Type *__class_type;
};

struct	Object__data
{
  Object *Object__this;
  char	Object__private[sizeof(struct Object__data_weak)];
};

struct	Object__private
{
  Object *this;
  const struct Object__virtual *_virtual;
  Object *Object__this;
  struct Object__data_weak;
};

struct	Object
{
  Object *this;
  const struct Object__virtual *_virtual;
  struct Object__data;
};

void	Object__dtor(void *);
void	Object__ctor(void *);

extern const Type * const Object__type_instance;
extern const struct Object__virtual * const Object__vtable_instance;

void	*Object__pre_ctor(struct Object__private *);
