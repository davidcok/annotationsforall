/*
 * queue.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_QUEUE_H_
#define LIBC_SYS_QUEUE_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.
#include "../__fc_define_null.h"

/*
 * Singly-linked List definitions.
 */
#define SLIST_HEAD(name, type)                                                                         \
struct name {                                                                                  \
    struct type *slh_first; /* first element */                                                            \
}

#define SLIST_HEAD_INITIALIZER(head)                                                                       \
    { NULL }

#define SLIST_ENTRY(type)                                                                          \
struct {                                                                                   \
    struct type *sle_next;  /* next element */                                                             \
}

/*
 * Singly-linked List access methods.
 */
#define SLIST_FIRST(head)   ((head)->slh_first)
#define SLIST_END(head)     NULL
#define SLIST_EMPTY(head)   ((head)->slh_first == NULL)
#define SLIST_NEXT(elm, field)  ((elm)->field.sle_next)

#define SLIST_FOREACH(var, head, field)                                                                    \
    for((var) = (head)->slh_first;                                                                     \
        (var) != SLIST_END(head);                                                                      \
        (var) = (var)->field.sle_next)

#define SLIST_FOREACH_SAFE(var, head, field, tvar)                                                             \
    for ((var) = SLIST_FIRST((head));                                                                  \
        (var) != SLIST_END(head) &&                                                                    \
        ((tvar) = SLIST_NEXT((var), field), 1);                                                            \
        (var) = (tvar))

/*
 * Singly-linked List functions.
 */
#define SLIST_INIT(head) do {                                                                          \
    (head)->slh_first = SLIST_END(head);                                                                   \
} while (/*CONSTCOND*/0)

#define SLIST_INSERT_AFTER(slistelm, elm, field) do {                                                              \
    (elm)->field.sle_next = (slistelm)->field.sle_next;                                                        \
    (slistelm)->field.sle_next = (elm);                                                                \
} while (/*CONSTCOND*/0)

#define SLIST_INSERT_HEAD(head, elm, field) do {                                                               \
    (elm)->field.sle_next = (head)->slh_first;                                                             \
    (head)->slh_first = (elm);                                                                     \
} while (/*CONSTCOND*/0)

#define SLIST_REMOVE_AFTER(slistelm, field) do {                                                               \
    (slistelm)->field.sle_next =                                                                       \
        SLIST_NEXT(SLIST_NEXT((slistelm), field), field);                                                          \
} while (/*CONSTCOND*/0)

#define SLIST_REMOVE_HEAD(head, field) do {                                                                \
    (head)->slh_first = (head)->slh_first->field.sle_next;                                                         \
} while (/*CONSTCOND*/0)

#define SLIST_REMOVE(head, elm, type, field) do {                                                              \
    if ((head)->slh_first == (elm)) {                                                                  \
        SLIST_REMOVE_HEAD((head), field);                                                              \
    }                                                                                  \
    else {                                                                                 \
        struct type *curelm = (head)->slh_first;                                                           \
        while(curelm->field.sle_next != (elm))                                                             \
            curelm = curelm->field.sle_next;                                                           \
        curelm->field.sle_next =                                                                   \
            curelm->field.sle_next->field.sle_next;                                                        \
    }                                                                                  \
} while (/*CONSTCOND*/0)

/*
 * List definitions.
 */
#define LIST_HEAD(name, type)                                                                          \
struct name {                                                                                  \
    struct type *lh_first;  /* first element */                                                            \
}

#define LIST_HEAD_INITIALIZER(head)                                                                    \
    { NULL }

#define LIST_ENTRY(type)                                                                           \
struct {                                                                                   \
    struct type *le_next;   /* next element */                                                             \
    struct type **le_prev;  /* address of previous next element */                                                     \
}

/*
 * List access methods.
 */
#define LIST_FIRST(head)        ((head)->lh_first)
#define LIST_END(head)          NULL
#define LIST_EMPTY(head)        ((head)->lh_first == LIST_END(head))
#define LIST_NEXT(elm, field)       ((elm)->field.le_next)

#define LIST_FOREACH(var, head, field)                                                                     \
    for ((var) = ((head)->lh_first);                                                                   \
        (var) != LIST_END(head);                                                                       \
        (var) = ((var)->field.le_next))

#define LIST_FOREACH_SAFE(var, head, field, tvar)                                                              \
    for ((var) = LIST_FIRST((head));                                                                   \
        (var) != LIST_END(head) &&                                                                     \
        ((tvar) = LIST_NEXT((var), field), 1);                                                             \
        (var) = (tvar))

#define LIST_MOVE(head1, head2) do {                                                                       \
    LIST_INIT((head2));                                                                        \
    if (!LIST_EMPTY((head1))) {                                                                    \
        (head2)->lh_first = (head1)->lh_first;                                                             \
        LIST_INIT((head1));                                                                    \
    }                                                                                  \
} while (/*CONSTCOND*/0)

/*
 * List functions.
 */
#define QUEUEDEBUG_LIST_INSERT_HEAD(head, elm, field)
#define QUEUEDEBUG_LIST_OP(elm, field)
#define QUEUEDEBUG_LIST_POSTREMOVE(elm, field)

#define LIST_INIT(head) do {                                                                           \
    (head)->lh_first = LIST_END(head);                                                                 \
} while (/*CONSTCOND*/0)

#define LIST_INSERT_AFTER(listelm, elm, field) do {                                                            \
    QUEUEDEBUG_LIST_OP((listelm), field)                                                                   \
    if (((elm)->field.le_next = (listelm)->field.le_next) !=                                                       \
        LIST_END(head))                                                                        \
        (listelm)->field.le_next->field.le_prev =                                                          \
            &(elm)->field.le_next;                                                                 \
    (listelm)->field.le_next = (elm);                                                                  \
    (elm)->field.le_prev = &(listelm)->field.le_next;                                                          \
} while (/*CONSTCOND*/0)

#define LIST_INSERT_BEFORE(listelm, elm, field) do {                                                               \
    QUEUEDEBUG_LIST_OP((listelm), field)                                                                   \
    (elm)->field.le_prev = (listelm)->field.le_prev;                                                           \
    (elm)->field.le_next = (listelm);                                                                  \
    *(listelm)->field.le_prev = (elm);                                                                 \
    (listelm)->field.le_prev = &(elm)->field.le_next;                                                          \
} while (/*CONSTCOND*/0)

#define LIST_INSERT_HEAD(head, elm, field) do {                                                                \
    QUEUEDEBUG_LIST_INSERT_HEAD((head), (elm), field)                                                          \
    if (((elm)->field.le_next = (head)->lh_first) != LIST_END(head))                                                   \
        (head)->lh_first->field.le_prev = &(elm)->field.le_next;                                                   \
    (head)->lh_first = (elm);                                                                      \
    (elm)->field.le_prev = &(head)->lh_first;                                                              \
} while (/*CONSTCOND*/0)

#define LIST_REMOVE(elm, field) do {                                                                       \
    QUEUEDEBUG_LIST_OP((elm), field)                                                                   \
    if ((elm)->field.le_next != NULL)                                                                  \
        (elm)->field.le_next->field.le_prev =                                                              \
            (elm)->field.le_prev;                                                                  \
    *(elm)->field.le_prev = (elm)->field.le_next;                                                              \
    QUEUEDEBUG_LIST_POSTREMOVE((elm), field)                                                               \
} while (/*CONSTCOND*/0)

#define LIST_REPLACE(elm, elm2, field) do {                                                                \
    if (((elm2)->field.le_next = (elm)->field.le_next) != NULL)                                                    \
        (elm2)->field.le_next->field.le_prev =                                                             \
            &(elm2)->field.le_next;                                                                \
    (elm2)->field.le_prev = (elm)->field.le_prev;                                                              \
    *(elm2)->field.le_prev = (elm2);                                                                   \
    QUEUEDEBUG_LIST_POSTREMOVE((elm), field)                                                               \
} while (/*CONSTCOND*/0)

/*
 * Simple queue definitions.
 */
#define SIMPLEQ_HEAD(name, type)                                                                       \
struct name {                                                                                  \
    struct type *sqh_first; /* first element */                                                            \
    struct type **sqh_last; /* addr of last next element */                                                        \
}

#define SIMPLEQ_HEAD_INITIALIZER(head)                                                                     \
    { NULL, &(head).sqh_first }

#define SIMPLEQ_ENTRY(type)                                                                        \
struct {                                                                                   \
    struct type *sqe_next;  /* next element */                                                             \
}

/*
 * Simple queue access methods.
 */
#define SIMPLEQ_FIRST(head)     ((head)->sqh_first)
#define SIMPLEQ_END(head)       NULL
#define SIMPLEQ_EMPTY(head)     ((head)->sqh_first == SIMPLEQ_END(head))
#define SIMPLEQ_NEXT(elm, field)    ((elm)->field.sqe_next)

#define SIMPLEQ_FOREACH(var, head, field)                                                                  \
    for ((var) = ((head)->sqh_first);                                                                  \
        (var) != SIMPLEQ_END(head);                                                                    \
        (var) = ((var)->field.sqe_next))

#define SIMPLEQ_FOREACH_SAFE(var, head, field, next)                                                               \
    for ((var) = ((head)->sqh_first);                                                                  \
        (var) != SIMPLEQ_END(head) &&                                                                  \
        ((next = ((var)->field.sqe_next)), 1);                                                             \
        (var) = (next))

/*
 * Simple queue functions.
 */
#define SIMPLEQ_INIT(head) do {                                                                        \
    (head)->sqh_first = NULL;                                                                      \
    (head)->sqh_last = &(head)->sqh_first;                                                                 \
} while (/*CONSTCOND*/0)

#define SIMPLEQ_INSERT_HEAD(head, elm, field) do {                                                             \
    if (((elm)->field.sqe_next = (head)->sqh_first) == NULL)                                                       \
        (head)->sqh_last = &(elm)->field.sqe_next;                                                         \
    (head)->sqh_first = (elm);                                                                     \
} while (/*CONSTCOND*/0)

#define SIMPLEQ_INSERT_TAIL(head, elm, field) do {                                                             \
    (elm)->field.sqe_next = NULL;                                                                      \
    *(head)->sqh_last = (elm);                                                                     \
    (head)->sqh_last = &(elm)->field.sqe_next;                                                             \
} while (/*CONSTCOND*/0)

#define SIMPLEQ_INSERT_AFTER(head, listelm, elm, field) do {                                                           \
    if (((elm)->field.sqe_next = (listelm)->field.sqe_next) == NULL)                                                   \
        (head)->sqh_last = &(elm)->field.sqe_next;                                                         \
    (listelm)->field.sqe_next = (elm);                                                                 \
} while (/*CONSTCOND*/0)

#define SIMPLEQ_REMOVE_HEAD(head, field) do {                                                                  \
    if (((head)->sqh_first = (head)->sqh_first->field.sqe_next) == NULL)                                                    \
        (head)->sqh_last = &(head)->sqh_first;                                                             \
} while (/*CONSTCOND*/0)

#define SIMPLEQ_REMOVE_AFTER(head, elm, field) do {                                                            \
    if (((elm)->field.sqe_next = (elm)->field.sqe_next->field.sqe_next)                                                    \
        == NULL)                                                                               \
        (head)->sqh_last = &(elm)->field.sqe_next;                                                         \
} while (/*CONSTCOND*/0)

#define SIMPLEQ_REMOVE(head, elm, type, field) do {                                                            \
    if ((head)->sqh_first == (elm)) {                                                                  \
        SIMPLEQ_REMOVE_HEAD((head), field);                                                            \
    } else {                                                                               \
        struct type *curelm = (head)->sqh_first;                                                           \
        while (curelm->field.sqe_next != (elm))                                                            \
            curelm = curelm->field.sqe_next;                                                           \
        if ((curelm->field.sqe_next =                                                                  \
            curelm->field.sqe_next->field.sqe_next) == NULL)                                                    \
                (head)->sqh_last = &(curelm)->field.sqe_next;                                                    \
    }                                                                                  \
} while (/*CONSTCOND*/0)

#define SIMPLEQ_CONCAT(head1, head2) do {                                                                  \
    if (!SIMPLEQ_EMPTY((head2))) {                                                                     \
        *(head1)->sqh_last = (head2)->sqh_first;                                                           \
        (head1)->sqh_last = (head2)->sqh_last;                                                         \
        SIMPLEQ_INIT((head2));                                                                     \
    }                                                                                  \
} while (/*CONSTCOND*/0)

#define SIMPLEQ_LAST(head, type, field)                                                                    \
    (SIMPLEQ_EMPTY((head)) ?                                                                           \
        NULL :                                                                             \
            ((struct type *)(void *)                                                                   \
        ((char *)((head)->sqh_last) - offsetof(struct type, field))))

/*
 * Tail queue definitions.
 */
#define _TAILQ_HEAD(name, type, qual)                                                                      \
struct name {                                                                                  \
    qual type *tqh_first;       /* first element */                                                        \
    qual type *qual *tqh_last;  /* addr of last next element */                                                    \
}
#define TAILQ_HEAD(name, type)  _TAILQ_HEAD(name, struct type,)

#define TAILQ_HEAD_INITIALIZER(head)                                                                       \
    { TAILQ_END(head), &(head).tqh_first }

#define _TAILQ_ENTRY(type, qual)                                                                       \
struct {                                                                                   \
    qual type *tqe_next;        /* next element */                                                         \
    qual type *qual *tqe_prev;  /* address of previous next element */                                                   \
}
#define TAILQ_ENTRY(type)   _TAILQ_ENTRY(struct type,)

/*
 * Tail queue access methods.
 */
#define TAILQ_FIRST(head)       ((head)->tqh_first)
#define TAILQ_END(head)         (NULL)
#define TAILQ_NEXT(elm, field)      ((elm)->field.tqe_next)
#define TAILQ_LAST(head, headname)                                                    \
    (*(((struct headname *)(void *)((head)->tqh_last))->tqh_last))
#define TAILQ_PREV(elm, headname, field)                                                    \
    (*(((struct headname *)(void *)((elm)->field.tqe_prev))->tqh_last))
#define TAILQ_EMPTY(head)       (TAILQ_FIRST(head) == TAILQ_END(head))

#define TAILQ_FOREACH(var, head, field)                                                                    \
    for ((var) = ((head)->tqh_first);                                                                  \
        (var) != TAILQ_END(head);                                                                      \
        (var) = ((var)->field.tqe_next))

#define TAILQ_FOREACH_SAFE(var, head, field, next)                                                             \
    for ((var) = ((head)->tqh_first);                                                                  \
        (var) != TAILQ_END(head) &&                                                                    \
        ((next) = TAILQ_NEXT(var, field), 1); (var) = (next))

#define TAILQ_FOREACH_REVERSE(var, head, headname, field)                                                          \
    for ((var) = TAILQ_LAST((head), headname);                                                             \
        (var) != TAILQ_END(head);                                                                      \
        (var) = TAILQ_PREV((var), headname, field))

#define TAILQ_FOREACH_REVERSE_SAFE(var, head, headname, field, prev)                                                       \
    for ((var) = TAILQ_LAST((head), headname);                                                             \
        (var) != TAILQ_END(head) &&                                                                    \
        ((prev) = TAILQ_PREV((var), headname, field), 1); (var) = (prev))

/*
 * Tail queue functions.
 */

#define QUEUEDEBUG_TAILQ_INSERT_HEAD(head, elm, field)
#define QUEUEDEBUG_TAILQ_INSERT_TAIL(head, elm, field)
#define QUEUEDEBUG_TAILQ_OP(elm, field)
#define QUEUEDEBUG_TAILQ_PREREMOVE(head, elm, field)
#define QUEUEDEBUG_TAILQ_POSTREMOVE(elm, field)

#define TAILQ_INIT(head) do {                                                                          \
    (head)->tqh_first = TAILQ_END(head);                                                                   \
    (head)->tqh_last = &(head)->tqh_first;                                                                 \
} while (/*CONSTCOND*/0)

#define TAILQ_INSERT_HEAD(head, elm, field) do {                                                               \
    QUEUEDEBUG_TAILQ_INSERT_HEAD((head), (elm), field)                                                         \
    if (((elm)->field.tqe_next = (head)->tqh_first) != TAILQ_END(head))                                                   \
        (head)->tqh_first->field.tqe_prev =                                                            \
            &(elm)->field.tqe_next;                                                                \
    else                                                                                   \
        (head)->tqh_last = &(elm)->field.tqe_next;                                                         \
    (head)->tqh_first = (elm);                                                                     \
    (elm)->field.tqe_prev = &(head)->tqh_first;                                                            \
} while (/*CONSTCOND*/0)

#define TAILQ_INSERT_TAIL(head, elm, field) do {                                                               \
    QUEUEDEBUG_TAILQ_INSERT_TAIL((head), (elm), field)                                                         \
    (elm)->field.tqe_next = TAILQ_END(head);                                                               \
    (elm)->field.tqe_prev = (head)->tqh_last;                                                              \
    *(head)->tqh_last = (elm);                                                                     \
    (head)->tqh_last = &(elm)->field.tqe_next;                                                             \
} while (/*CONSTCOND*/0)

#define TAILQ_INSERT_AFTER(head, listelm, elm, field) do {                                                         \
    QUEUEDEBUG_TAILQ_OP((listelm), field)                                                                  \
    if (((elm)->field.tqe_next = (listelm)->field.tqe_next) !=                                                     \
        TAILQ_END(head))                                                                           \
        (elm)->field.tqe_next->field.tqe_prev =                                                            \
            &(elm)->field.tqe_next;                                                                \
    else                                                                                   \
        (head)->tqh_last = &(elm)->field.tqe_next;                                                         \
    (listelm)->field.tqe_next = (elm);                                                                 \
    (elm)->field.tqe_prev = &(listelm)->field.tqe_next;                                                        \
} while (/*CONSTCOND*/0)

#define TAILQ_INSERT_BEFORE(listelm, elm, field) do {                                                              \
    QUEUEDEBUG_TAILQ_OP((listelm), field)                                                                  \
    (elm)->field.tqe_prev = (listelm)->field.tqe_prev;                                                         \
    (elm)->field.tqe_next = (listelm);                                                                 \
    *(listelm)->field.tqe_prev = (elm);                                                                \
    (listelm)->field.tqe_prev = &(elm)->field.tqe_next;                                                        \
} while (/*CONSTCOND*/0)

#define TAILQ_REMOVE(head, elm, field) do {                                                                \
    QUEUEDEBUG_TAILQ_PREREMOVE((head), (elm), field)                                                           \
    QUEUEDEBUG_TAILQ_OP((elm), field)                                                                  \
    if (((elm)->field.tqe_next) != TAILQ_END(head))                                                            \
        (elm)->field.tqe_next->field.tqe_prev =                                                            \
            (elm)->field.tqe_prev;                                                                 \
    else                                                                                   \
        (head)->tqh_last = (elm)->field.tqe_prev;                                                          \
    *(elm)->field.tqe_prev = (elm)->field.tqe_next;                                                            \
    QUEUEDEBUG_TAILQ_POSTREMOVE((elm), field);                                                             \
} while (/*CONSTCOND*/0)

#define TAILQ_REPLACE(head, elm, elm2, field) do {                                                             \
        if (((elm2)->field.tqe_next = (elm)->field.tqe_next) !=                                                        \
        TAILQ_END(head))                                                                           \
                (elm2)->field.tqe_next->field.tqe_prev =                                                           \
                    &(elm2)->field.tqe_next;                                                                   \
        else                                                                                   \
                (head)->tqh_last = &(elm2)->field.tqe_next;                                                        \
        (elm2)->field.tqe_prev = (elm)->field.tqe_prev;                                                            \
        *(elm2)->field.tqe_prev = (elm2);                                                                  \
    QUEUEDEBUG_TAILQ_POSTREMOVE((elm), field);                                                             \
} while (/*CONSTCOND*/0)

#define TAILQ_CONCAT(head1, head2, field) do {                                                                 \
    if (!TAILQ_EMPTY(head2)) {                                                                     \
        *(head1)->tqh_last = (head2)->tqh_first;                                                           \
        (head2)->tqh_first->field.tqe_prev = (head1)->tqh_last;                                                    \
        (head1)->tqh_last = (head2)->tqh_last;                                                             \
        TAILQ_INIT((head2));                                                                       \
    }                                                                                  \
} while (/*CONSTCOND*/0)

/*
 * Singly-linked Tail queue declarations.
 */
#define STAILQ_HEAD(name, type)                                                                        \
struct name {                                                                                  \
    struct type *stqh_first;    /* first element */                                                        \
    struct type **stqh_last;    /* addr of last next element */                                                    \
}

#define STAILQ_HEAD_INITIALIZER(head)                                                                      \
    { NULL, &(head).stqh_first }

#define STAILQ_ENTRY(type)                                                                         \
struct {                                                                                   \
    struct type *stqe_next; /* next element */                                                             \
}

/*
 * Singly-linked Tail queue access methods.
 */
#define STAILQ_FIRST(head)  ((head)->stqh_first)
#define STAILQ_END(head)    NULL
#define STAILQ_NEXT(elm, field) ((elm)->field.stqe_next)
#define STAILQ_EMPTY(head)  (STAILQ_FIRST(head) == STAILQ_END(head))

/*
 * Singly-linked Tail queue functions.
 */
#define STAILQ_INIT(head) do {                                                                         \
    (head)->stqh_first = NULL;                                                                     \
    (head)->stqh_last = &(head)->stqh_first;                                                                   \
} while (/*CONSTCOND*/0)

#define STAILQ_INSERT_HEAD(head, elm, field) do {                                                              \
    if (((elm)->field.stqe_next = (head)->stqh_first) == NULL)                                                     \
        (head)->stqh_last = &(elm)->field.stqe_next;                                                           \
    (head)->stqh_first = (elm);                                                                    \
} while (/*CONSTCOND*/0)

#define STAILQ_INSERT_TAIL(head, elm, field) do {                                                              \
    (elm)->field.stqe_next = NULL;                                                                     \
    *(head)->stqh_last = (elm);                                                                    \
    (head)->stqh_last = &(elm)->field.stqe_next;                                                               \
} while (/*CONSTCOND*/0)

#define STAILQ_INSERT_AFTER(head, listelm, elm, field) do {                                                        \
    if (((elm)->field.stqe_next = (listelm)->field.stqe_next) == NULL)                                                   \
        (head)->stqh_last = &(elm)->field.stqe_next;                                                           \
    (listelm)->field.stqe_next = (elm);                                                                \
} while (/*CONSTCOND*/0)

#define STAILQ_REMOVE_HEAD(head, field) do {                                                                   \
    if (((head)->stqh_first = (head)->stqh_first->field.stqe_next) == NULL)                                                    \
        (head)->stqh_last = &(head)->stqh_first;                                                               \
} while (/*CONSTCOND*/0)

#define STAILQ_REMOVE(head, elm, type, field) do {                                                             \
    if ((head)->stqh_first == (elm)) {                                                                 \
        STAILQ_REMOVE_HEAD((head), field);                                                             \
    } else {                                                                               \
        struct type *curelm = (head)->stqh_first;                                                          \
        while (curelm->field.stqe_next != (elm))                                                               \
            curelm = curelm->field.stqe_next;                                                          \
        if ((curelm->field.stqe_next =                                                                 \
            curelm->field.stqe_next->field.stqe_next) == NULL)                                                    \
                (head)->stqh_last = &(curelm)->field.stqe_next;                                                    \
    }                                                                                  \
} while (/*CONSTCOND*/0)

#define STAILQ_FOREACH(var, head, field)                                                                   \
    for ((var) = ((head)->stqh_first);                                                                 \
        (var);                                                                             \
        (var) = ((var)->field.stqe_next))

#define STAILQ_FOREACH_SAFE(var, head, field, tvar)                                                            \
    for ((var) = STAILQ_FIRST((head));                                                                 \
        (var) && ((tvar) = STAILQ_NEXT((var), field), 1);                                                          \
        (var) = (tvar))

#define STAILQ_CONCAT(head1, head2) do {                                                                   \
    if (!STAILQ_EMPTY((head2))) {                                                                      \
        *(head1)->stqh_last = (head2)->stqh_first;                                                         \
        (head1)->stqh_last = (head2)->stqh_last;                                                           \
        STAILQ_INIT((head2));                                                                      \
    }                                                                                  \
} while (/*CONSTCOND*/0)

#define STAILQ_LAST(head, type, field)                                                                     \
    (STAILQ_EMPTY((head)) ?                                                                        \
        NULL :                                                                             \
            ((struct type *)(void *)                                                                   \
        ((char *)((head)->stqh_last) - offsetof(struct type, field))))

static __inline const void * __launder_type(const void *);
static __inline const void *
__launder_type(const void *__x) {
    __asm __volatile("" : "+r" (__x));
    return __x;
}
#define QUEUEDEBUG_CIRCLEQ_HEAD(head, field)
#define QUEUEDEBUG_CIRCLEQ_ELM(head, elm, field)
#define QUEUEDEBUG_CIRCLEQ_POSTREMOVE(elm, field)

#define CIRCLEQ_HEAD(name, type)                                                                       \
struct name {                                                                                  \
    struct type *cqh_first;     /* first element */                                                        \
    struct type *cqh_last;      /* last element */                                                         \
}

#define CIRCLEQ_HEAD_INITIALIZER(head)                                                                     \
    { CIRCLEQ_END(&head), CIRCLEQ_END(&head) }

#define CIRCLEQ_ENTRY(type)                                                                        \
struct {                                                                                   \
    struct type *cqe_next;      /* next element */                                                         \
    struct type *cqe_prev;      /* previous element */                                                         \
}

/*
 * Circular queue functions.
 */
#define CIRCLEQ_INIT(head) do {                                                                        \
    (head)->cqh_first = CIRCLEQ_END(head);                                                                 \
    (head)->cqh_last = CIRCLEQ_END(head);                                                                  \
} while (/*CONSTCOND*/0)

#define CIRCLEQ_INSERT_AFTER(head, listelm, elm, field) do {                                                           \
    QUEUEDEBUG_CIRCLEQ_HEAD((head), field)                                                                 \
    QUEUEDEBUG_CIRCLEQ_ELM((head), (listelm), field)                                                           \
    (elm)->field.cqe_next = (listelm)->field.cqe_next;                                                         \
    (elm)->field.cqe_prev = (listelm);                                                                 \
    if ((listelm)->field.cqe_next == CIRCLEQ_ENDC(head))                                                           \
        (head)->cqh_last = (elm);                                                                  \
    else                                                                                   \
        (listelm)->field.cqe_next->field.cqe_prev = (elm);                                                     \
    (listelm)->field.cqe_next = (elm);                                                                 \
} while (/*CONSTCOND*/0)

#define CIRCLEQ_INSERT_BEFORE(head, listelm, elm, field) do {                                                          \
    QUEUEDEBUG_CIRCLEQ_HEAD((head), field)                                                                 \
    QUEUEDEBUG_CIRCLEQ_ELM((head), (listelm), field)                                                           \
    (elm)->field.cqe_next = (listelm);                                                                 \
    (elm)->field.cqe_prev = (listelm)->field.cqe_prev;                                                         \
    if ((listelm)->field.cqe_prev == CIRCLEQ_ENDC(head))                                                           \
        (head)->cqh_first = (elm);                                                                 \
    else                                                                                   \
        (listelm)->field.cqe_prev->field.cqe_next = (elm);                                                     \
    (listelm)->field.cqe_prev = (elm);                                                                 \
} while (/*CONSTCOND*/0)

#define CIRCLEQ_INSERT_HEAD(head, elm, field) do {                                                             \
    QUEUEDEBUG_CIRCLEQ_HEAD((head), field)                                                                 \
    (elm)->field.cqe_next = (head)->cqh_first;                                                             \
    (elm)->field.cqe_prev = CIRCLEQ_END(head);                                                             \
    if ((head)->cqh_last == CIRCLEQ_ENDC(head))                                                            \
        (head)->cqh_last = (elm);                                                                  \
    else                                                                                   \
        (head)->cqh_first->field.cqe_prev = (elm);                                                         \
    (head)->cqh_first = (elm);                                                                     \
} while (/*CONSTCOND*/0)

#define CIRCLEQ_INSERT_TAIL(head, elm, field) do {                                                             \
    QUEUEDEBUG_CIRCLEQ_HEAD((head), field)                                                                 \
    (elm)->field.cqe_next = CIRCLEQ_END(head);                                                             \
    (elm)->field.cqe_prev = (head)->cqh_last;                                                              \
    if ((head)->cqh_first == CIRCLEQ_ENDC(head))                                                               \
        (head)->cqh_first = (elm);                                                                 \
    else                                                                                   \
        (head)->cqh_last->field.cqe_next = (elm);                                                          \
    (head)->cqh_last = (elm);                                                                      \
} while (/*CONSTCOND*/0)

#define CIRCLEQ_REMOVE(head, elm, field) do {                                                                  \
    QUEUEDEBUG_CIRCLEQ_HEAD((head), field)                                                                 \
    QUEUEDEBUG_CIRCLEQ_ELM((head), (elm), field)                                                               \
    if ((elm)->field.cqe_next == CIRCLEQ_ENDC(head))                                                           \
        (head)->cqh_last = (elm)->field.cqe_prev;                                                          \
    else                                                                                   \
        (elm)->field.cqe_next->field.cqe_prev =                                                            \
            (elm)->field.cqe_prev;                                                                 \
    if ((elm)->field.cqe_prev == CIRCLEQ_ENDC(head))                                                           \
        (head)->cqh_first = (elm)->field.cqe_next;                                                         \
    else                                                                                   \
        (elm)->field.cqe_prev->field.cqe_next =                                                            \
            (elm)->field.cqe_next;                                                                 \
    QUEUEDEBUG_CIRCLEQ_POSTREMOVE((elm), field)                                                            \
} while (/*CONSTCOND*/0)

#define CIRCLEQ_FOREACH(var, head, field)                                                                  \
    for ((var) = ((head)->cqh_first);                                                                  \
        (var) != CIRCLEQ_ENDC(head);                                                                   \
        (var) = ((var)->field.cqe_next))

#define CIRCLEQ_FOREACH_REVERSE(var, head, field)                                                              \
    for ((var) = ((head)->cqh_last);                                                                   \
        (var) != CIRCLEQ_ENDC(head);                                                                   \
        (var) = ((var)->field.cqe_prev))

/*
 * Circular queue access methods.
 */
#define CIRCLEQ_FIRST(head)     ((head)->cqh_first)
#define CIRCLEQ_LAST(head)      ((head)->cqh_last)
/* For comparisons */
#define CIRCLEQ_ENDC(head)      (__launder_type(head))
/* For assignments */
#define CIRCLEQ_END(head)       ((void *)(head))
#define CIRCLEQ_NEXT(elm, field)    ((elm)->field.cqe_next)
#define CIRCLEQ_PREV(elm, field)    ((elm)->field.cqe_prev)
#define CIRCLEQ_EMPTY(head)                                                                        \
    (CIRCLEQ_FIRST(head) == CIRCLEQ_ENDC(head))

#define CIRCLEQ_LOOP_NEXT(head, elm, field)                                                                \
    (((elm)->field.cqe_next == CIRCLEQ_ENDC(head))                                                             \
        ? ((head)->cqh_first)                                                                      \
        : (elm->field.cqe_next))
#define CIRCLEQ_LOOP_PREV(head, elm, field)                                                                \
    (((elm)->field.cqe_prev == CIRCLEQ_ENDC(head))                                                             \
        ? ((head)->cqh_last)                                                                       \
        : (elm->field.cqe_prev))

#endif /* LIBC_SYS_QUEUE_H_ */
