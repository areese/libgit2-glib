/*
 * ggit-types.c
 * This file is part of libgit2-glib
 *
 * Copyright (C) 2012 - Garrett Regier
 *
 * libgit2-glib is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * libgit2-glib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libgit2-glib. If not, see <http://www.gnu.org/licenses/>.
 */

#include <git2.h>

#include "ggit-types.h"


/* Must cast the enums to ints to avoid enum compare warning */
#define ASSERT_ENUM(a, b) G_STATIC_ASSERT (((int) a) == ((int) b))


ASSERT_ENUM (GGIT_BRANCH_LOCAL,  GIT_BRANCH_LOCAL);
ASSERT_ENUM (GGIT_BRANCH_REMOTE, GIT_BRANCH_REMOTE);

ASSERT_ENUM (GGIT_CAP_THREADS, GIT_CAP_THREADS);
ASSERT_ENUM (GGIT_CAP_HTTPS,   GIT_CAP_HTTPS);

ASSERT_ENUM (GGIT_CONFIG_LEVEL_SYSTEM, GIT_CONFIG_LEVEL_SYSTEM);
ASSERT_ENUM (GGIT_CONFIG_LEVEL_XDG, GIT_CONFIG_LEVEL_XDG);
ASSERT_ENUM (GGIT_CONFIG_LEVEL_GLOBAL, GIT_CONFIG_LEVEL_GLOBAL);
ASSERT_ENUM (GGIT_CONFIG_LEVEL_LOCAL, GIT_CONFIG_LEVEL_LOCAL);
ASSERT_ENUM (GGIT_CONFIG_LEVEL_HIGHEST, GIT_CONFIG_HIGHEST_LEVEL);

ASSERT_ENUM (GGIT_DELTA_UNMODIFIED, GIT_DELTA_UNMODIFIED);
ASSERT_ENUM (GGIT_DELTA_ADDED,      GIT_DELTA_ADDED);
ASSERT_ENUM (GGIT_DELTA_DELETED,    GIT_DELTA_DELETED);
ASSERT_ENUM (GGIT_DELTA_MODIFIED,   GIT_DELTA_MODIFIED);
ASSERT_ENUM (GGIT_DELTA_RENAMED,    GIT_DELTA_RENAMED);
ASSERT_ENUM (GGIT_DELTA_COPIED,     GIT_DELTA_COPIED);
ASSERT_ENUM (GGIT_DELTA_IGNORED,    GIT_DELTA_IGNORED);
ASSERT_ENUM (GGIT_DELTA_UNTRACKED,  GIT_DELTA_UNTRACKED);


ASSERT_ENUM (GGIT_DIFF_NORMAL,                   GIT_DIFF_NORMAL);
ASSERT_ENUM (GGIT_DIFF_REVERSE,                  GIT_DIFF_REVERSE);
ASSERT_ENUM (GGIT_DIFF_FORCE_TEXT,               GIT_DIFF_FORCE_TEXT);
ASSERT_ENUM (GGIT_DIFF_IGNORE_WHITESPACE,        GIT_DIFF_IGNORE_WHITESPACE);
ASSERT_ENUM (GGIT_DIFF_IGNORE_WHITESPACE_CHANGE, GIT_DIFF_IGNORE_WHITESPACE_CHANGE);
ASSERT_ENUM (GGIT_DIFF_IGNORE_WHITESPACE_EOL,    GIT_DIFF_IGNORE_WHITESPACE_EOL);
ASSERT_ENUM (GGIT_DIFF_IGNORE_SUBMODULES,        GIT_DIFF_IGNORE_SUBMODULES);
ASSERT_ENUM (GGIT_DIFF_PATIENCE,                 GIT_DIFF_PATIENCE);
ASSERT_ENUM (GGIT_DIFF_INCLUDE_IGNORED,          GIT_DIFF_INCLUDE_IGNORED);
ASSERT_ENUM (GGIT_DIFF_INCLUDE_UNTRACKED,        GIT_DIFF_INCLUDE_UNTRACKED);
ASSERT_ENUM (GGIT_DIFF_INCLUDE_UNMODIFIED,       GIT_DIFF_INCLUDE_UNMODIFIED);
ASSERT_ENUM (GGIT_DIFF_RECURSE_UNTRACKED_DIRS,   GIT_DIFF_RECURSE_UNTRACKED_DIRS);


ASSERT_ENUM (GGIT_DIFF_FLAG_VALID_OID,  GIT_DIFF_FLAG_VALID_OID);
ASSERT_ENUM (GGIT_DIFF_FLAG_BINARY,     GIT_DIFF_FLAG_BINARY);
ASSERT_ENUM (GGIT_DIFF_FLAG_NOT_BINARY, GIT_DIFF_FLAG_NOT_BINARY);


ASSERT_ENUM (GGIT_DIFF_LINE_CONTEXT,       GIT_DIFF_LINE_CONTEXT);
ASSERT_ENUM (GGIT_DIFF_LINE_ADDITION,      GIT_DIFF_LINE_ADDITION);
ASSERT_ENUM (GGIT_DIFF_LINE_DELETION,      GIT_DIFF_LINE_DELETION);
ASSERT_ENUM (GGIT_DIFF_LINE_CONTEXT_EOFNL, GIT_DIFF_LINE_CONTEXT_EOFNL);
ASSERT_ENUM (GGIT_DIFF_LINE_ADD_EOFNL,     GIT_DIFF_LINE_ADD_EOFNL);
ASSERT_ENUM (GGIT_DIFF_LINE_DEL_EOFNL,     GIT_DIFF_LINE_DEL_EOFNL);
ASSERT_ENUM (GGIT_DIFF_LINE_FILE_HDR,      GIT_DIFF_LINE_FILE_HDR);
ASSERT_ENUM (GGIT_DIFF_LINE_HUNK_HDR,      GIT_DIFF_LINE_HUNK_HDR);
ASSERT_ENUM (GGIT_DIFF_LINE_BINARY,        GIT_DIFF_LINE_BINARY);


ASSERT_ENUM (GGIT_ERROR_GIT_ERROR,   GIT_ERROR);
ASSERT_ENUM (GGIT_ERROR_NOTFOUND,    GIT_ENOTFOUND);
ASSERT_ENUM (GGIT_ERROR_EXISTS,      GIT_EEXISTS);
ASSERT_ENUM (GGIT_ERROR_AMBIGUOUS,   GIT_EAMBIGUOUS);
ASSERT_ENUM (GGIT_ERROR_BUFS,        GIT_EBUFS);
ASSERT_ENUM (GGIT_ERROR_PASSTHROUGH, GIT_PASSTHROUGH);
ASSERT_ENUM (GGIT_ERROR_ITEROVER,    GIT_ITEROVER);

ASSERT_ENUM (GGIT_FILE_MODE_NEW, GIT_FILEMODE_NEW);
ASSERT_ENUM (GGIT_FILE_MODE_TREE, GIT_FILEMODE_TREE);
ASSERT_ENUM (GGIT_FILE_MODE_BLOB, GIT_FILEMODE_BLOB);
ASSERT_ENUM (GGIT_FILE_MODE_BLOB_EXECUTABLE, GIT_FILEMODE_BLOB_EXECUTABLE);
ASSERT_ENUM (GGIT_FILE_MODE_LINK, GIT_FILEMODE_LINK);
ASSERT_ENUM (GGIT_FILE_MODE_COMMIT, GIT_FILEMODE_COMMIT);

ASSERT_ENUM (GGIT_REMOTE_DOWNLOAD_TAGS_AUTO,  GIT_REMOTE_DOWNLOAD_TAGS_AUTO);
ASSERT_ENUM (GGIT_REMOTE_DOWNLOAD_TAGS_NONE,  GIT_REMOTE_DOWNLOAD_TAGS_NONE);
ASSERT_ENUM (GGIT_REMOTE_DOWNLOAD_TAGS_ALL,   GIT_REMOTE_DOWNLOAD_TAGS_ALL);

ASSERT_ENUM (GGIT_REF_INVALID,  GIT_REF_INVALID);
ASSERT_ENUM (GGIT_REF_OID,      GIT_REF_OID);
ASSERT_ENUM (GGIT_REF_SYMBOLIC, GIT_REF_SYMBOLIC);
ASSERT_ENUM (GGIT_REF_LISTALL,  GIT_REF_LISTALL);


ASSERT_ENUM (GGIT_RESET_SOFT,  GIT_RESET_SOFT);
ASSERT_ENUM (GGIT_RESET_MIXED, GIT_RESET_MIXED);
ASSERT_ENUM (GGIT_RESET_HARD, GIT_RESET_HARD);

ASSERT_ENUM (GGIT_STASH_DEFAULT, GIT_STASH_DEFAULT);
ASSERT_ENUM (GGIT_STASH_KEEP_INDEX, GIT_STASH_KEEP_INDEX);
ASSERT_ENUM (GGIT_STASH_INCLUDE_UNTRACKED, GIT_STASH_INCLUDE_UNTRACKED);
ASSERT_ENUM (GGIT_STASH_INCLUDE_IGNORED, GIT_STASH_INCLUDE_IGNORED);

ASSERT_ENUM (GGIT_SORT_NONE,        GIT_SORT_NONE);
ASSERT_ENUM (GGIT_SORT_TOPOLOGICAL, GIT_SORT_TOPOLOGICAL);
ASSERT_ENUM (GGIT_SORT_TIME,        GIT_SORT_TIME);
ASSERT_ENUM (GGIT_SORT_REVERSE,     GIT_SORT_REVERSE);


ASSERT_ENUM (GGIT_STATUS_CURRENT,                 GIT_STATUS_CURRENT);
ASSERT_ENUM (GGIT_STATUS_INDEX_NEW,               GIT_STATUS_INDEX_NEW);
ASSERT_ENUM (GGIT_STATUS_INDEX_MODIFIED,          GIT_STATUS_INDEX_MODIFIED);
ASSERT_ENUM (GGIT_STATUS_INDEX_DELETED,           GIT_STATUS_INDEX_DELETED);
ASSERT_ENUM (GGIT_STATUS_INDEX_RENAMED,           GIT_STATUS_INDEX_RENAMED);
ASSERT_ENUM (GGIT_STATUS_INDEX_TYPECHANGE,        GIT_STATUS_INDEX_TYPECHANGE);
ASSERT_ENUM (GGIT_STATUS_WORKING_TREE_NEW,        GIT_STATUS_WT_NEW);
ASSERT_ENUM (GGIT_STATUS_WORKING_TREE_MODIFIED,   GIT_STATUS_WT_MODIFIED);
ASSERT_ENUM (GGIT_STATUS_WORKING_TREE_DELETED,    GIT_STATUS_WT_DELETED);
ASSERT_ENUM (GGIT_STATUS_WORKING_TREE_TYPECHANGE, GIT_STATUS_WT_TYPECHANGE);
ASSERT_ENUM (GGIT_STATUS_IGNORED,                 GIT_STATUS_IGNORED);


ASSERT_ENUM (GGIT_SUBMODULE_IGNORE_DEFAULT, GIT_SUBMODULE_IGNORE_DEFAULT);
ASSERT_ENUM (GGIT_SUBMODULE_IGNORE_NONE, GIT_SUBMODULE_IGNORE_NONE);
ASSERT_ENUM (GGIT_SUBMODULE_IGNORE_UNTRACKED, GIT_SUBMODULE_IGNORE_UNTRACKED);
ASSERT_ENUM (GGIT_SUBMODULE_IGNORE_DIRTY, GIT_SUBMODULE_IGNORE_DIRTY);
ASSERT_ENUM (GGIT_SUBMODULE_IGNORE_ALL, GIT_SUBMODULE_IGNORE_ALL);


ASSERT_ENUM (GGIT_SUBMODULE_STATUS_IN_HEAD, GIT_SUBMODULE_STATUS_IN_HEAD);
ASSERT_ENUM (GGIT_SUBMODULE_STATUS_IN_INDEX, GIT_SUBMODULE_STATUS_IN_INDEX);
ASSERT_ENUM (GGIT_SUBMODULE_STATUS_IN_CONFIG, GIT_SUBMODULE_STATUS_IN_CONFIG);
ASSERT_ENUM (GGIT_SUBMODULE_STATUS_IN_WD, GIT_SUBMODULE_STATUS_IN_WD);
ASSERT_ENUM (GGIT_SUBMODULE_STATUS_INDEX_ADDED, GIT_SUBMODULE_STATUS_INDEX_ADDED);
ASSERT_ENUM (GGIT_SUBMODULE_STATUS_INDEX_DELETED, GIT_SUBMODULE_STATUS_INDEX_DELETED);
ASSERT_ENUM (GGIT_SUBMODULE_STATUS_INDEX_MODIFIED, GIT_SUBMODULE_STATUS_INDEX_MODIFIED);
ASSERT_ENUM (GGIT_SUBMODULE_STATUS_WD_UNINITIALIZED, GIT_SUBMODULE_STATUS_WD_UNINITIALIZED);
ASSERT_ENUM (GGIT_SUBMODULE_STATUS_WD_ADDED, GIT_SUBMODULE_STATUS_WD_ADDED);
ASSERT_ENUM (GGIT_SUBMODULE_STATUS_WD_DELETED, GIT_SUBMODULE_STATUS_WD_DELETED);
ASSERT_ENUM (GGIT_SUBMODULE_STATUS_WD_MODIFIED, GIT_SUBMODULE_STATUS_WD_MODIFIED);
ASSERT_ENUM (GGIT_SUBMODULE_STATUS_WD_INDEX_MODIFIED, GIT_SUBMODULE_STATUS_WD_INDEX_MODIFIED);
ASSERT_ENUM (GGIT_SUBMODULE_STATUS_WD_WD_MODIFIED, GIT_SUBMODULE_STATUS_WD_WD_MODIFIED);
ASSERT_ENUM (GGIT_SUBMODULE_STATUS_WD_UNTRACKED, GIT_SUBMODULE_STATUS_WD_UNTRACKED);


ASSERT_ENUM (GGIT_SUBMODULE_UPDATE_CHECKOUT, GIT_SUBMODULE_UPDATE_CHECKOUT);
ASSERT_ENUM (GGIT_SUBMODULE_UPDATE_REBASE,   GIT_SUBMODULE_UPDATE_REBASE);
ASSERT_ENUM (GGIT_SUBMODULE_UPDATE_MERGE,    GIT_SUBMODULE_UPDATE_MERGE);

ASSERT_ENUM (GGIT_STATUS_OPTION_INCLUDE_UNTRACKED, GIT_STATUS_OPT_INCLUDE_UNTRACKED);
ASSERT_ENUM (GGIT_STATUS_OPTION_INCLUDE_IGNORED, GIT_STATUS_OPT_INCLUDE_IGNORED);
ASSERT_ENUM (GGIT_STATUS_OPTION_INCLUDE_UNMODIFIED, GIT_STATUS_OPT_INCLUDE_UNMODIFIED);
ASSERT_ENUM (GGIT_STATUS_OPTION_EXCLUDE_SUBMODULES, GIT_STATUS_OPT_EXCLUDE_SUBMODULES);
ASSERT_ENUM (GGIT_STATUS_OPTION_RECURSE_UNTRACKED_DIRS, GIT_STATUS_OPT_RECURSE_UNTRACKED_DIRS);
ASSERT_ENUM (GGIT_STATUS_OPTION_DISABLE_PATHSPEC_MATCH, GIT_STATUS_OPT_DISABLE_PATHSPEC_MATCH);
ASSERT_ENUM (GGIT_STATUS_OPTION_RECURSE_IGNORED_DIRS, GIT_STATUS_OPT_RECURSE_IGNORED_DIRS);
ASSERT_ENUM (GGIT_STATUS_OPTION_RENAMES_HEAD_TO_INDEX, GIT_STATUS_OPT_RENAMES_HEAD_TO_INDEX);
ASSERT_ENUM (GGIT_STATUS_OPTION_RENAMES_INDEX_TO_WORKDIR, GIT_STATUS_OPT_RENAMES_INDEX_TO_WORKDIR);
ASSERT_ENUM (GGIT_STATUS_OPTION_SORT_CASE_INSENSITIVELY, GIT_STATUS_OPT_SORT_CASE_INSENSITIVELY);
ASSERT_ENUM (GGIT_STATUS_OPTION_SORT_CASE_SENSITIVELY, GIT_STATUS_OPT_SORT_CASE_SENSITIVELY);
ASSERT_ENUM (GGIT_STATUS_OPTION_DEFAULT, GIT_STATUS_OPT_DEFAULTS);

ASSERT_ENUM (GGIT_STATUS_SHOW_INDEX_AND_WORKDIR, GIT_STATUS_SHOW_INDEX_AND_WORKDIR);
ASSERT_ENUM (GGIT_STATUS_SHOW_INDEX_ONLY, GIT_STATUS_SHOW_INDEX_ONLY);
ASSERT_ENUM (GGIT_STATUS_SHOW_WORKDIR_ONLY, GIT_STATUS_SHOW_WORKDIR_ONLY);
ASSERT_ENUM (GGIT_STATUS_SHOW_INDEX_THEN_WORKDIR, GIT_STATUS_SHOW_INDEX_THEN_WORKDIR);

/* ex:set ts=8 noet: */
