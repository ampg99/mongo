/*-
 * See the file LICENSE for redistribution information.
 *
 * Copyright (c) 2008-2011 WiredTiger, Inc.
 *	All rights reserved.
 */

#include "wt_internal.h"

int
__wt_filesize(SESSION *session, WT_FH *fh, off_t *sizep)
{
	struct stat sb;

	WT_VERBOSE(S2C(session),
	    WT_VERB_FILEOPS, (session, "fileops: %s: fstat", fh->name));

	if (fstat(fh->fd, &sb) == -1) {
		__wt_err(session, errno, "%s: fstat", fh->name);
		return (WT_ERROR);
	}

	*sizep = sb.st_size;		/* Return size in bytes. */
	return (0);
}
