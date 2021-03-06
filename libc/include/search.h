/*-
 * Written by J.T. Conklin <jtc@netbsd.org>
 * Public domain.
 *
 *	$NetBSD: search.h,v 1.12 1999/02/22 10:34:28 christos Exp $
 * $FreeBSD: release/9.0.0/include/search.h 105250 2002-10-16 14:29:23Z robert $
 */

#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <sys/cdefs.h>
#include <sys/types.h>

typedef enum {
  preorder,
  postorder,
  endorder,
  leaf
} VISIT;

#ifdef _SEARCH_PRIVATE
typedef struct node {
  char* key;
  struct node* llink;
  struct node* rlink;
} node_t;
#endif

__BEGIN_DECLS

void insque(void*, void*) __INTRODUCED_IN(21);
void remque(void*) __INTRODUCED_IN(21);

void* lfind(const void*, const void*, size_t*, size_t, int (*)(const void*, const void*))
  __INTRODUCED_IN(21);
void* lsearch(const void*, void*, size_t*, size_t, int (*)(const void*, const void*))
  __INTRODUCED_IN(21);

void* tdelete(const void* __restrict, void** __restrict, int (*)(const void*, const void*))
  __INTRODUCED_IN(21);
void tdestroy(void*, void (*)(void*)) __INTRODUCED_IN(21);
void* tfind(const void*, void* const*, int (*)(const void*, const void*)) __INTRODUCED_IN(21);
void* tsearch(const void*, void**, int (*)(const void*, const void*)) __INTRODUCED_IN(21);
void twalk(const void*, void (*)(const void*, VISIT, int)) __INTRODUCED_IN(21);

__END_DECLS

#endif /* !_SEARCH_H_ */
