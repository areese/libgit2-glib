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

ASSERT_ENUM (GGIT_DIFF_BINARY_NONE,    GIT_DIFF_BINARY_NONE);
ASSERT_ENUM (GGIT_DIFF_BINARY_LITERAL, GIT_DIFF_BINARY_LITERAL);
ASSERT_ENUM (GGIT_DIFF_BINARY_DELTA,   GIT_DIFF_BINARY_DELTA);

ASSERT_ENUM (GGIT_BRANCH_LOCAL,  GIT_BRANCH_LOCAL);
ASSERT_ENUM (GGIT_BRANCH_REMOTE, GIT_BRANCH_REMOTE);

ASSERT_ENUM (GGIT_FEATURE_THREADS, GIT_FEATURE_THREADS);
ASSERT_ENUM (GGIT_FEATURE_HTTPS,   GIT_FEATURE_HTTPS);
ASSERT_ENUM (GGIT_FEATURE_SSH,     GIT_FEATURE_SSH);

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

ASSERT_ENUM (GGIT_DIFF_FORMAT_PATCH,         GIT_DIFF_FORMAT_PATCH);
ASSERT_ENUM (GGIT_DIFF_FORMAT_PATCH_HEADER,  GIT_DIFF_FORMAT_PATCH_HEADER);
ASSERT_ENUM (GGIT_DIFF_FORMAT_RAW,           GIT_DIFF_FORMAT_RAW);
ASSERT_ENUM (GGIT_DIFF_FORMAT_NAME_ONLY,     GIT_DIFF_FORMAT_NAME_ONLY);
ASSERT_ENUM (GGIT_DIFF_FORMAT_NAME_STATUS,   GIT_DIFF_FORMAT_NAME_STATUS);


ASSERT_ENUM (GGIT_DIFF_NORMAL,                     GIT_DIFF_NORMAL);
ASSERT_ENUM (GGIT_DIFF_REVERSE,                    GIT_DIFF_REVERSE);
ASSERT_ENUM (GGIT_DIFF_INCLUDE_IGNORED,            GIT_DIFF_INCLUDE_IGNORED);
ASSERT_ENUM (GGIT_DIFF_RECURSE_IGNORED_DIRS,       GIT_DIFF_RECURSE_IGNORED_DIRS);
ASSERT_ENUM (GGIT_DIFF_INCLUDE_UNTRACKED,          GIT_DIFF_INCLUDE_UNTRACKED);
ASSERT_ENUM (GGIT_DIFF_RECURSE_UNTRACKED_DIRS,     GIT_DIFF_RECURSE_UNTRACKED_DIRS);
ASSERT_ENUM (GGIT_DIFF_INCLUDE_UNMODIFIED,         GIT_DIFF_INCLUDE_UNMODIFIED);
ASSERT_ENUM (GGIT_DIFF_INCLUDE_TYPECHANGE,         GIT_DIFF_INCLUDE_TYPECHANGE);
ASSERT_ENUM (GGIT_DIFF_INCLUDE_TYPECHANGE_TREES,   GIT_DIFF_INCLUDE_TYPECHANGE_TREES);
ASSERT_ENUM (GGIT_DIFF_IGNORE_FILE_MODE,           GIT_DIFF_IGNORE_FILEMODE);
ASSERT_ENUM (GGIT_DIFF_IGNORE_SUBMODULES,          GIT_DIFF_IGNORE_SUBMODULES);
ASSERT_ENUM (GGIT_DIFF_IGNORE_CASE,                GIT_DIFF_IGNORE_CASE);
ASSERT_ENUM (GGIT_DIFF_DISABLE_PATHSPEC_MATCH,     GIT_DIFF_DISABLE_PATHSPEC_MATCH);
ASSERT_ENUM (GGIT_DIFF_SKIP_BINARY_CHECK,          GIT_DIFF_SKIP_BINARY_CHECK);
ASSERT_ENUM (GGIT_DIFF_ENABLE_FAST_UNTRACKED_DIRS, GIT_DIFF_ENABLE_FAST_UNTRACKED_DIRS);
ASSERT_ENUM (GGIT_DIFF_FORCE_TEXT,                 GIT_DIFF_FORCE_TEXT);
ASSERT_ENUM (GGIT_DIFF_FORCE_BINARY,               GIT_DIFF_FORCE_BINARY);
ASSERT_ENUM (GGIT_DIFF_IGNORE_WHITESPACE,          GIT_DIFF_IGNORE_WHITESPACE);
ASSERT_ENUM (GGIT_DIFF_IGNORE_WHITESPACE_CHANGE,   GIT_DIFF_IGNORE_WHITESPACE_CHANGE);
ASSERT_ENUM (GGIT_DIFF_IGNORE_WHITESPACE_EOL,      GIT_DIFF_IGNORE_WHITESPACE_EOL);
ASSERT_ENUM (GGIT_DIFF_SHOW_UNTRACKED_CONTENT,     GIT_DIFF_SHOW_UNTRACKED_CONTENT);
ASSERT_ENUM (GGIT_DIFF_SHOW_UNMODIFIED,            GIT_DIFF_SHOW_UNMODIFIED);
ASSERT_ENUM (GGIT_DIFF_PATIENCE,                   GIT_DIFF_PATIENCE);
ASSERT_ENUM (GGIT_DIFF_MINIMAL,                    GIT_DIFF_MINIMAL);
ASSERT_ENUM (GGIT_DIFF_SHOW_BINARY,                GIT_DIFF_SHOW_BINARY);

ASSERT_ENUM (GGIT_DIFF_FLAG_VALID_ID,   GIT_DIFF_FLAG_VALID_ID);
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

ASSERT_ENUM (GGIT_FILE_MODE_UNREADABLE, GIT_FILEMODE_UNREADABLE);
ASSERT_ENUM (GGIT_FILE_MODE_TREE, GIT_FILEMODE_TREE);
ASSERT_ENUM (GGIT_FILE_MODE_BLOB, GIT_FILEMODE_BLOB);
ASSERT_ENUM (GGIT_FILE_MODE_BLOB_EXECUTABLE, GIT_FILEMODE_BLOB_EXECUTABLE);
ASSERT_ENUM (GGIT_FILE_MODE_LINK, GIT_FILEMODE_LINK);
ASSERT_ENUM (GGIT_FILE_MODE_COMMIT, GIT_FILEMODE_COMMIT);

ASSERT_ENUM (GGIT_MERGE_FILE_FAVOR_NORMAL, GIT_MERGE_FILE_FAVOR_NORMAL);
ASSERT_ENUM (GGIT_MERGE_FILE_FAVOR_OURS, GIT_MERGE_FILE_FAVOR_OURS);
ASSERT_ENUM (GGIT_MERGE_FILE_FAVOR_THEIRS, GIT_MERGE_FILE_FAVOR_THEIRS);
ASSERT_ENUM (GGIT_MERGE_FILE_FAVOR_UNION, GIT_MERGE_FILE_FAVOR_UNION);

ASSERT_ENUM (GGIT_MERGE_TREE_FIND_RENAMES, GIT_MERGE_TREE_FIND_RENAMES);

ASSERT_ENUM (GGIT_REMOTE_DOWNLOAD_TAGS_UNSPECIFIED, GIT_REMOTE_DOWNLOAD_TAGS_UNSPECIFIED);
ASSERT_ENUM (GGIT_REMOTE_DOWNLOAD_TAGS_AUTO, GIT_REMOTE_DOWNLOAD_TAGS_AUTO);
ASSERT_ENUM (GGIT_REMOTE_DOWNLOAD_TAGS_NONE, GIT_REMOTE_DOWNLOAD_TAGS_NONE);
ASSERT_ENUM (GGIT_REMOTE_DOWNLOAD_TAGS_ALL, GIT_REMOTE_DOWNLOAD_TAGS_ALL);

ASSERT_ENUM (GGIT_REMOTE_COMPLETION_DOWNLOAD, GIT_REMOTE_COMPLETION_DOWNLOAD);
ASSERT_ENUM (GGIT_REMOTE_COMPLETION_INDEXING, GIT_REMOTE_COMPLETION_INDEXING);
ASSERT_ENUM (GGIT_REMOTE_COMPLETION_ERROR,    GIT_REMOTE_COMPLETION_ERROR);

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


ASSERT_ENUM (GGIT_SUBMODULE_IGNORE_UNSPECIFIED, GIT_SUBMODULE_IGNORE_UNSPECIFIED);
ASSERT_ENUM (GGIT_SUBMODULE_IGNORE_NONE, GIT_SUBMODULE_IGNORE_NONE);
ASSERT_ENUM (GGIT_SUBMODULE_IGNORE_UNTRACKED, GIT_SUBMODULE_IGNORE_UNTRACKED);
ASSERT_ENUM (GGIT_SUBMODULE_IGNORE_DIRTY, GIT_SUBMODULE_IGNORE_DIRTY);
ASSERT_ENUM (GGIT_SUBMODULE_IGNORE_ALL, GIT_SUBMODULE_IGNORE_ALL);


ASSERT_ENUM (GGIT_SUBMODULE_RECURSE_NO, GIT_SUBMODULE_RECURSE_NO);
ASSERT_ENUM (GGIT_SUBMODULE_RECURSE_YES, GIT_SUBMODULE_RECURSE_YES);
ASSERT_ENUM (GGIT_SUBMODULE_RECURSE_ONDEMAND, GIT_SUBMODULE_RECURSE_ONDEMAND);


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
ASSERT_ENUM (GGIT_SUBMODULE_UPDATE_NONE,     GIT_SUBMODULE_UPDATE_NONE);
ASSERT_ENUM (GGIT_SUBMODULE_UPDATE_DEFAULT,  GIT_SUBMODULE_UPDATE_DEFAULT);

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
ASSERT_ENUM (GGIT_STATUS_SHOW_INDEX_ONLY,        GIT_STATUS_SHOW_INDEX_ONLY);
ASSERT_ENUM (GGIT_STATUS_SHOW_WORKDIR_ONLY,      GIT_STATUS_SHOW_WORKDIR_ONLY);

ASSERT_ENUM (GGIT_BLAME_NORMAL,                 GIT_BLAME_NORMAL);
ASSERT_ENUM (GGIT_BLAME_TRACK_COPIES_SAME_FILE, GIT_BLAME_TRACK_COPIES_SAME_FILE);

ASSERT_ENUM (GGIT_ATTRIBUTE_CHECK_FILE_THEN_INDEX, GIT_ATTR_CHECK_FILE_THEN_INDEX);
ASSERT_ENUM (GGIT_ATTRIBUTE_CHECK_INDEX_THEN_FILE, GIT_ATTR_CHECK_INDEX_THEN_FILE);
ASSERT_ENUM (GGIT_ATTRIBUTE_CHECK_INDEX_ONLY,      GIT_ATTR_CHECK_INDEX_ONLY);
ASSERT_ENUM (GGIT_ATTRIBUTE_CHECK_NO_SYSTEM,       GIT_ATTR_CHECK_NO_SYSTEM);

ASSERT_ENUM (GGIT_PACKBUILDER_STAGE_ADDING_OBJECTS, GIT_PACKBUILDER_ADDING_OBJECTS);
ASSERT_ENUM (GGIT_PACKBUILDER_STAGE_DELTAFICATION, GIT_PACKBUILDER_DELTAFICATION);

ASSERT_ENUM (GGIT_CHECKOUT_NONE,                    GIT_CHECKOUT_NONE);
ASSERT_ENUM (GGIT_CHECKOUT_SAFE,                    GIT_CHECKOUT_SAFE);
ASSERT_ENUM (GGIT_CHECKOUT_FORCE,                   GIT_CHECKOUT_FORCE);
ASSERT_ENUM (GGIT_CHECKOUT_RECREATE_MISSING,        GIT_CHECKOUT_RECREATE_MISSING);
ASSERT_ENUM (GGIT_CHECKOUT_ALLOW_CONFLICTS,         GIT_CHECKOUT_ALLOW_CONFLICTS);
ASSERT_ENUM (GGIT_CHECKOUT_REMOVE_UNTRACKED,        GIT_CHECKOUT_REMOVE_UNTRACKED);
ASSERT_ENUM (GGIT_CHECKOUT_REMOVE_IGNORED,          GIT_CHECKOUT_REMOVE_IGNORED);
ASSERT_ENUM (GGIT_CHECKOUT_UPDATE_ONLY,             GIT_CHECKOUT_UPDATE_ONLY);
ASSERT_ENUM (GGIT_CHECKOUT_DONT_UPDATE_INDEX,       GIT_CHECKOUT_DONT_UPDATE_INDEX);
ASSERT_ENUM (GGIT_CHECKOUT_NO_REFRESH,              GIT_CHECKOUT_NO_REFRESH);
ASSERT_ENUM (GGIT_CHECKOUT_SKIP_UNMERGED,           GIT_CHECKOUT_SKIP_UNMERGED);
ASSERT_ENUM (GGIT_CHECKOUT_USE_OURS,                GIT_CHECKOUT_USE_OURS);
ASSERT_ENUM (GGIT_CHECKOUT_USE_THEIRS,              GIT_CHECKOUT_USE_THEIRS);
ASSERT_ENUM (GGIT_CHECKOUT_DISABLE_PATHSPEC_MATCH,  GIT_CHECKOUT_DISABLE_PATHSPEC_MATCH);
ASSERT_ENUM (GGIT_CHECKOUT_SKIP_LOCKED_DIRECTORIES, GIT_CHECKOUT_SKIP_LOCKED_DIRECTORIES);
ASSERT_ENUM (GGIT_CHECKOUT_DONT_OVERWRITE_IGNORED,  GIT_CHECKOUT_DONT_OVERWRITE_IGNORED);
ASSERT_ENUM (GGIT_CHECKOUT_CONFLICT_STYLE_MERGE,    GIT_CHECKOUT_CONFLICT_STYLE_MERGE);
ASSERT_ENUM (GGIT_CHECKOUT_CONFLICT_STYLE_DIFF3,    GIT_CHECKOUT_CONFLICT_STYLE_DIFF3);
ASSERT_ENUM (GGIT_CHECKOUT_DONT_REMOVE_EXISTING,    GIT_CHECKOUT_DONT_REMOVE_EXISTING);
ASSERT_ENUM (GGIT_CHECKOUT_DONT_WRITE_INDEX,        GIT_CHECKOUT_DONT_WRITE_INDEX);
ASSERT_ENUM (GGIT_CHECKOUT_UPDATE_SUBMODULES,       GIT_CHECKOUT_UPDATE_SUBMODULES);
ASSERT_ENUM (GGIT_CHECKOUT_UPDATE_SUBMODULES_IF_CHANGED, GIT_CHECKOUT_UPDATE_SUBMODULES_IF_CHANGED);

ASSERT_ENUM (GGIT_CHECKOUT_NOTIFY_NONE,      GIT_CHECKOUT_NOTIFY_NONE);
ASSERT_ENUM (GGIT_CHECKOUT_NOTIFY_CONFLICT,  GIT_CHECKOUT_NOTIFY_CONFLICT);
ASSERT_ENUM (GGIT_CHECKOUT_NOTIFY_DIRTY,     GIT_CHECKOUT_NOTIFY_DIRTY);
ASSERT_ENUM (GGIT_CHECKOUT_NOTIFY_UPDATED,   GIT_CHECKOUT_NOTIFY_UPDATED);
ASSERT_ENUM (GGIT_CHECKOUT_NOTIFY_UNTRACKED, GIT_CHECKOUT_NOTIFY_UNTRACKED);
ASSERT_ENUM (GGIT_CHECKOUT_NOTIFY_IGNORED,   GIT_CHECKOUT_NOTIFY_IGNORED);
ASSERT_ENUM (GGIT_CHECKOUT_NOTIFY_ALL,       GIT_CHECKOUT_NOTIFY_ALL);

ASSERT_ENUM (GGIT_DIFF_FIND_BY_CONFIG,                  GIT_DIFF_FIND_BY_CONFIG);
ASSERT_ENUM (GGIT_DIFF_FIND_RENAMES,                    GIT_DIFF_FIND_RENAMES);
ASSERT_ENUM (GGIT_DIFF_FIND_RENAMES_FROM_REWRITES,      GIT_DIFF_FIND_RENAMES_FROM_REWRITES);
ASSERT_ENUM (GGIT_DIFF_FIND_COPIES,                     GIT_DIFF_FIND_COPIES);
ASSERT_ENUM (GGIT_DIFF_FIND_COPIES_FROM_UNMODIFIED,     GIT_DIFF_FIND_COPIES_FROM_UNMODIFIED);
ASSERT_ENUM (GGIT_DIFF_FIND_REWRITES,                   GIT_DIFF_FIND_REWRITES);
ASSERT_ENUM (GGIT_DIFF_BREAK_REWRITES,                  GIT_DIFF_BREAK_REWRITES);
ASSERT_ENUM (GGIT_DIFF_FIND_AND_BREAK_REWRITES,         GIT_DIFF_FIND_AND_BREAK_REWRITES);
ASSERT_ENUM (GGIT_DIFF_FIND_FOR_UNTRACKED,              GIT_DIFF_FIND_FOR_UNTRACKED);
ASSERT_ENUM (GGIT_DIFF_FIND_ALL,                        GIT_DIFF_FIND_ALL);
ASSERT_ENUM (GGIT_DIFF_FIND_IGNORE_LEADING_WHITESPACE,  GIT_DIFF_FIND_IGNORE_LEADING_WHITESPACE);
ASSERT_ENUM (GGIT_DIFF_FIND_IGNORE_WHITESPACE,          GIT_DIFF_FIND_IGNORE_WHITESPACE);
ASSERT_ENUM (GGIT_DIFF_FIND_DONT_IGNORE_WHITESPACE,     GIT_DIFF_FIND_DONT_IGNORE_WHITESPACE);
ASSERT_ENUM (GGIT_DIFF_FIND_EXACT_MATCH_ONLY,           GIT_DIFF_FIND_EXACT_MATCH_ONLY);
ASSERT_ENUM (GGIT_DIFF_BREAK_REWRITES_FOR_RENAMES_ONLY, GIT_DIFF_BREAK_REWRITES_FOR_RENAMES_ONLY);
ASSERT_ENUM (GGIT_DIFF_FIND_REMOVE_UNMODIFIED,          GIT_DIFF_FIND_REMOVE_UNMODIFIED);

ASSERT_ENUM (GGIT_DIFF_FORMAT_EMAIL_NONE, GIT_DIFF_FORMAT_EMAIL_NONE);
ASSERT_ENUM (GGIT_DIFF_FORMAT_EMAIL_EXCLUDE_SUBJECT_PATCH_MARKER, GIT_DIFF_FORMAT_EMAIL_EXCLUDE_SUBJECT_PATCH_MARKER);

ASSERT_ENUM (GGIT_CREDTYPE_USERPASS_PLAINTEXT, GIT_CREDTYPE_USERPASS_PLAINTEXT);
ASSERT_ENUM (GGIT_CREDTYPE_SSH_KEY, GIT_CREDTYPE_SSH_KEY);
ASSERT_ENUM (GGIT_CREDTYPE_SSH_CUSTOM, GIT_CREDTYPE_SSH_CUSTOM);
ASSERT_ENUM (GGIT_CREDTYPE_DEFAULT, GIT_CREDTYPE_DEFAULT);
ASSERT_ENUM (GGIT_CREDTYPE_SSH_INTERACTIVE, GIT_CREDTYPE_SSH_INTERACTIVE);

ASSERT_ENUM (GGIT_DIRECTION_FETCH, GIT_DIRECTION_FETCH);
ASSERT_ENUM (GGIT_DIRECTION_PUSH, GIT_DIRECTION_PUSH);

ASSERT_ENUM (GGIT_CLONE_LOCAL_AUTO, GIT_CLONE_LOCAL_AUTO);
ASSERT_ENUM (GGIT_CLONE_LOCAL_LOCAL, GIT_CLONE_LOCAL);
ASSERT_ENUM (GGIT_CLONE_LOCAL_NO_LOCAL, GIT_CLONE_NO_LOCAL);
ASSERT_ENUM (GGIT_CLONE_LOCAL_NO_LINKS, GIT_CLONE_LOCAL_NO_LINKS);

ASSERT_ENUM (GGIT_MERGE_FILE_DEFAULT, GIT_MERGE_FILE_DEFAULT);
ASSERT_ENUM (GGIT_MERGE_FILE_STYLE_MERGE, GIT_MERGE_FILE_STYLE_MERGE);
ASSERT_ENUM (GGIT_MERGE_FILE_STYLE_DIFF3, GIT_MERGE_FILE_STYLE_DIFF3);
ASSERT_ENUM (GGIT_MERGE_FILE_SIMPLIFY_ALNUM, GIT_MERGE_FILE_SIMPLIFY_ALNUM);
ASSERT_ENUM (GGIT_MERGE_FILE_IGNORE_WHITESPACE, GIT_MERGE_FILE_IGNORE_WHITESPACE);
ASSERT_ENUM (GGIT_MERGE_FILE_IGNORE_WHITESPACE_CHANGE, GIT_MERGE_FILE_IGNORE_WHITESPACE_CHANGE);
ASSERT_ENUM (GGIT_MERGE_FILE_IGNORE_WHITESPACE_EOL, GIT_MERGE_FILE_IGNORE_WHITESPACE_EOL);
ASSERT_ENUM (GGIT_MERGE_FILE_DIFF_PATIENCE, GIT_MERGE_FILE_DIFF_PATIENCE);
ASSERT_ENUM (GGIT_MERGE_FILE_DIFF_MINIMAL, GIT_MERGE_FILE_DIFF_MINIMAL);

/* ex:set ts=8 noet: */
