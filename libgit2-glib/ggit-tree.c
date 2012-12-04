/*
 * ggit-tree.c
 * This file is part of libgit2-glib
 *
 * Copyright (C) 2012 - Jesse van den Kieboom
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

#include <git2/errors.h>

#include "ggit-tree.h"
#include "ggit-oid.h"
#include "ggit-error.h"

G_DEFINE_TYPE (GgitTree, ggit_tree, GGIT_TYPE_OBJECT)

static void
ggit_tree_class_init (GgitTreeClass *klass)
{
}

static void
ggit_tree_init (GgitTree *self)
{
}

GgitTree *
_ggit_tree_wrap (git_tree *tree,
                 gboolean  owned)
{
	GgitTree *gtree;

	gtree = g_object_new (GGIT_TYPE_TREE,
	                      "native", tree,
	                      NULL);

	if (owned)
	{
		_ggit_native_set_destroy_func (gtree,
		                               (GDestroyNotify)git_object_free);
	}

	return gtree;
}

/**
 * ggit_tree_get_id:
 * @tree: a #GgitTree.
 *
 * Get the #GgitOId of the tree.
 *
 * Returns: (transfer full): a #GgitOId.
 *
 **/
GgitOId *
ggit_tree_get_id (GgitTree *tree)
{
	git_tree *t;
	const git_oid *oid;

	g_return_val_if_fail (GGIT_IS_TREE (tree), NULL);

	t = _ggit_native_get (tree);

	oid = git_tree_id (t);

	return _ggit_oid_wrap (oid);
}

/**
 * ggit_tree_get:
 * @tree: a #GgitTree.
 * @i: the index of the entry.
 *
 * Get a tree entry by index.
 *
 * Returns: (transfer full): a #GgitTreeEntry.
 *
 **/
GgitTreeEntry *
ggit_tree_get (GgitTree *tree,
               guint     i)
{
	git_tree *t;
	const git_tree_entry *entry;

	g_return_val_if_fail (GGIT_IS_TREE (tree), NULL);

	t = _ggit_native_get (tree);

	entry = git_tree_entry_byindex (t, i);

	return _ggit_tree_entry_wrap (entry);
}

/**
 * ggit_tree_size:
 * @tree: a #GgitTree.
 *
 * Get the number of entries in the tree.
 *
 * Returns: the number of entries in the tree.
 *
 **/
guint
ggit_tree_size (GgitTree *tree)
{
	git_tree *t;

	g_return_val_if_fail (GGIT_IS_TREE (tree), 0);

	t = _ggit_native_get (tree);

	return (guint)git_tree_entrycount (t);
}

/**
 * ggit_tree_get_by_file:
 * @tree: a #GgitTree.
 * @file: a #GFile.
 *
 * Get a tree entry by file.
 *
 * Returns: (transfer full): a #GgitTreeEntry.
 *
 **/
GgitTreeEntry *
ggit_tree_get_by_file (GgitTree *tree,
                       GFile    *file)
{
	git_tree *t;
	gchar *path;
	GgitTreeEntry *entry;

	g_return_val_if_fail (GGIT_IS_TREE (tree), NULL);

	t = _ggit_native_get (tree);

	path = g_file_get_path (file);
	entry = _ggit_tree_entry_wrap (git_tree_entry_byname (t, path));
	g_free (path);

	return entry;
}

typedef struct
{
	GgitTreeWalkCallback callback;
	gpointer user_data;
} WalkInfo;

static int
walk_callback_wrapper (const char           *root,
                       const git_tree_entry *entry,
                       gpointer              payload)
{
	gint ret;
	GgitTreeEntry *wentry;
	WalkInfo *info = (WalkInfo *)payload;

	wentry = _ggit_tree_entry_wrap (entry);

	ret = info->callback(root, wentry, info->user_data);

	ggit_tree_entry_unref (wentry);

	return ret;
}

/**
 * ggit_tree_walk:
 * @tree: a #GgitTree.
 * @mode: the walking order
 * @callback: (scope call): the callback to call for each entry
 * @user_data: (closure): user data for the callback.
 * @error: a #GError for error reporting, or %NULL.
 *
 * Walk all the entries of a tree object recursively (resolving and walking
 * subtrees of the tree as needed). The @error will be set to the error returned
 * by @callback (if any).
 *
 **/
void
ggit_tree_walk (GgitTree              *tree,
                GgitTreeWalkMode       mode,
                GgitTreeWalkCallback   callback,
                gpointer               user_data,
                GError               **error)
{
	gint ret;
	WalkInfo info = {0,};

	g_return_if_fail (GGIT_IS_TREE (tree));
	g_return_if_fail (callback != NULL);
	g_return_if_fail (error == NULL || *error == NULL);

	info.callback = callback;
	info.user_data = user_data;

	ret = git_tree_walk (_ggit_native_get (tree),
	                     mode,
	                     (git_treewalk_cb)walk_callback_wrapper,
	                     &info);

	if (ret != GIT_OK)
	{
		_ggit_error_set (error, ret);
	}
}

/* ex:set ts=8 noet: */
