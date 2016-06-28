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

#ifndef __OBJECT_C_COMPILER__
#error Compiling using the non ObjectC wrapper of gcc
#endif

#define __HASH_WORD__ #
#define __NL__ /*
*/
#define __CREATE_MACRO__(symb, name, val, args...) __NL__       \
    symb ifdef name __NL__                                      \
    symb undef name __NL__                                      \
    symb endif __NL__                                           \
    symb define name(args) val __NL__

#define __CREATE_MACRO_NF__(symb, name, val) __NL__             \
    symb ifdef name __NL__                                      \
    symb undef name __NL__                                      \
    symb endif __NL__                                           \
    symb define name val __NL__

#define __IF_DEF_ERROR__(symb, name, errorM...) __NL__  \
    symb ifdef name __NL__                              \
    symb error errorM __NL__                            \
    symb endif __NL__

#define __UNDEF_MACRO__(symb, name) __NL__      \
    symb undef name __NL__

#define __DEF_LOCK__(symb, name, errorM...)            \
    __IF_DEF_ERROR__(symb, name, errorM)               \
    symb defile name __NL__