/*
 * $Id: splay.h,v 1.9 2001/01/07 14:44:32 hno Exp $
 */

#ifndef _SPLAY_H
#define _SPLAY_H

typedef struct _splay_node {
    void *data;
    struct _splay_node *left;
    struct _splay_node *right;
} splayNode;

typedef int SPLAYCMP(const void *a, const void *b);
typedef void SPLAYWALKEE(void *nodedata, void *state);
typedef void SPLAYFREE(void *);

extern int splayLastResult;

extern splayNode *splay_insert(void *, splayNode *, SPLAYCMP *);
extern splayNode *splay_splay(const void *, splayNode *, SPLAYCMP *);
extern void splay_destroy(splayNode *, SPLAYFREE *);
extern void splay_walk(splayNode *, SPLAYWALKEE *, void *);

#endif /* _SPLAY_H */
