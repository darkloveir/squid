
/*
 * $Id: store_heap_replacement.c,v 1.2 1999/08/02 06:18:45 wessels Exp $
 *
 * DEBUG: section 20    Storage Manager Heap-based replacement
 * AUTHOR: John Dilley
 *
 * SQUID Internet Object Cache  http://squid.nlanr.net/Squid/
 * ----------------------------------------------------------
 *
 *  Squid is the result of efforts by numerous individuals from the
 *  Internet community.  Development is led by Duane Wessels of the
 *  National Laboratory for Applied Network Research and funded by the
 *  National Science Foundation.  Squid is Copyrighted (C) 1998 by
 *  Duane Wessels and the University of California San Diego.  Please
 *  see the COPYRIGHT file for full details.  Squid incorporates
 *  software developed and/or copyrighted by other sources.  Please see
 *  the CREDITS file for full details.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 */

/*
 * The code in this file is Copyrighted (C) 1999 by Hewlett Packard.
 * 
 *
 * For a description of these cache replacement policies see --
 *  http://www.hpl.hp.com/personal/John_Dilley/caching/wcw.html
 */

/*
 * Key generation function to implement the LFU-DA policy (Least
 * Frequently Used with Dynamic Aging).  Similar to classical LFU
 * but with aging to handle turnover of the popular document set.
 * Maximizes byte hit rate by keeping more currently popular objects
 * in cache regardless of size.  Achieves lower hit rate than GDS
 * because there are more large objects in cache (so less room for
 * smaller popular objects).
 * 
 * This version implements a tie-breaker based upon recency
 * (e->lastref): for objects that have the same reference count
 * the most recent object wins (gets a higher key value).
 */
static heap_key
HeapKeyGen_StoreEntry_LFUDA(void *entry, double age)
{
    StoreEntry *e = entry;
    double tie = (e->lastref > 1) ? (1.0 / e->lastref) : 1;
    return age + e->refcount - tie;
}


/*
 * Key generation function to implement the GDS-Frequency policy.
 * Similar to Greedy Dual-Size Hits policy, but adds aging of
 * documents to prevent pollution.  Maximizes object hit rate by
 * keeping more small, popular objects in cache.  Achieves lower
 * byte hit rate than LFUDA because there are fewer large objects
 * in cache.
 * 
 * This version implements a tie-breaker based upon recency
 * (e->lastref): for objects that have the same reference count
 * the most recent object wins (gets a higher key value).
 */
static heap_key
HeapKeyGen_StoreEntry_GDSF(void *entry, double age)
{
    StoreEntry *e = entry;
    double size = e->swap_file_sz ? e->swap_file_sz : 1.0;
    double tie = (e->lastref > 1) ? (1.0 / e->lastref) : 1;
    return age + ((double) e->refcount / size) - tie;
}

/* 
 * Key generation function to implement the LRU policy.  Normally
 * one would not do this with a heap -- use the linked list instead.
 * For testing and performance characterization it was useful.
 * Don't use it unless you are trying to compare performance among
 * heap-based replacement policies...
 */
static heap_key
HeapKeyGen_StoreEntry_LRU(void *entry, double age)
{
    StoreEntry *e = entry;
    return (heap_key) e->lastref;
}
