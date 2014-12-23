/*
 * ggit-remote.h
 * This file is part of libgit2-glib
 *
 * Copyright (C) 2012 - Ignacio Casal Quinteiro
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

#include "ggit-remote.h"
#include "ggit-error.h"
#include "ggit-oid.h"
#include "ggit-ref-spec.h"
#include "ggit-repository.h"
#include "ggit-remote-callbacks.h"
#include "ggit-utils.h"

struct _GgitRemoteHead
{
	gboolean is_local;
	GgitOId *oid;
	GgitOId *local_oid;
	gchar *name;

	gint ref_count;
};

struct _GgitRemotePrivate
{
	GgitRemoteCallbacks *callbacks;
};

enum
{
	PROP_0,
	PROP_CALLBACKS
};

G_DEFINE_TYPE_WITH_PRIVATE (GgitRemote, ggit_remote, GGIT_TYPE_NATIVE)
G_DEFINE_BOXED_TYPE (GgitRemoteHead, ggit_remote_head, ggit_remote_head_ref, ggit_remote_head_unref)

static GgitRemoteHead *
_ggit_remote_head_wrap (const git_remote_head *remote_head)
{
	GgitRemoteHead *ret;

	ret = g_slice_new (GgitRemoteHead);
	ret->ref_count = 1;
	ret->is_local = remote_head->local;
	ret->oid = _ggit_oid_wrap (&remote_head->oid);
	ret->local_oid = _ggit_oid_wrap (&remote_head->loid);
	ret->name = g_strdup (remote_head->name);

	return ret;
}

GgitRemoteHead *
ggit_remote_head_ref (GgitRemoteHead *remote_head)
{
	g_atomic_int_inc (&remote_head->ref_count);
	return remote_head;
}

void
ggit_remote_head_unref (GgitRemoteHead *remote_head)
{
	if (g_atomic_int_dec_and_test (&remote_head->ref_count))
	{
		ggit_oid_free (remote_head->oid);
		ggit_oid_free (remote_head->local_oid);
		g_free (remote_head->name);

		g_slice_free (GgitRemoteHead, remote_head);
	}
}

/**
 * ggit_remote_head_get_oid:
 * @remote_head: a #GgitRemoteHead.
 *
 * Get the remote oid of the remote head.
 *
 * Returns: (transfer none): the remote oid.
 */
GgitOId *
ggit_remote_head_get_oid (GgitRemoteHead *remote_head)
{
	g_return_val_if_fail (remote_head != NULL, NULL);
	return remote_head->oid;
}

/**
 * ggit_remote_head_get_local_oid:
 * @remote_head: a #GgitRemoteHead.
 *
 * Get the local oid of the remote head.
 *
 * Returns: (transfer none): the local oid.
 */
GgitOId *
ggit_remote_head_get_local_oid (GgitRemoteHead *remote_head)
{
	g_return_val_if_fail (remote_head != NULL, NULL);
	return remote_head->local_oid;
}

/**
 * ggit_remote_head_is_local:
 * @remote_head: a #GgitRemoteHead.
 *
 * Get whether the remote head is local.
 *
 * Returns: whether the remote head is local.
 */
gboolean
ggit_remote_head_is_local (GgitRemoteHead *remote_head)
{
	g_return_val_if_fail (remote_head != NULL, FALSE);
	return remote_head->is_local;
}

/**
 * ggit_remote_head_get_name:
 * @remote_head: a #GgitRemoteHead.
 *
 * Get the remote head name.
 *
 * Returns: the remote head name.
 */
const gchar *
ggit_remote_head_get_name (GgitRemoteHead *remote_head)
{
	g_return_val_if_fail (remote_head != NULL, NULL);
	return remote_head->name;
}

GgitRemote *
_ggit_remote_wrap (git_remote *remote)
{
	GgitRemote *ret;

	ret = g_object_new (GGIT_TYPE_REMOTE, "native", remote, NULL);
	_ggit_native_set_destroy_func (ret, (GDestroyNotify)git_remote_free);

	return ret;
}

static void
ggit_remote_dispose (GObject *object)
{
	GgitRemote *remote = GGIT_REMOTE (object);
	git_remote *native;

	g_clear_object (&remote->priv->callbacks);

	native = _ggit_native_get (remote);

	if (native)
	{
		git_remote_callbacks cb = GIT_REMOTE_CALLBACKS_INIT;
		git_remote_set_callbacks (native, &cb);
	}

	G_OBJECT_CLASS (ggit_remote_parent_class)->dispose (object);
}

static void
ggit_remote_set_property (GObject      *object,
                          guint         prop_id,
                          const GValue *value,
                          GParamSpec   *pspec)
{
	GgitRemote *self = GGIT_REMOTE (object);

	switch (prop_id)
	{
		case PROP_CALLBACKS:
			ggit_remote_set_callbacks (self, g_value_get_object (value));
			break;
		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
			break;
	}
}

static void
ggit_remote_get_property (GObject    *object,
                          guint       prop_id,
                          GValue     *value,
                          GParamSpec *pspec)
{
	GgitRemote *self = GGIT_REMOTE (object);

	switch (prop_id)
	{
		case PROP_CALLBACKS:
			g_value_set_object (value, self->priv->callbacks);
			break;
		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
			break;
	}
}

static void
ggit_remote_class_init (GgitRemoteClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->dispose = ggit_remote_dispose;

	object_class->get_property = ggit_remote_get_property;
	object_class->set_property = ggit_remote_set_property;

	g_object_class_install_property (object_class,
	                                 PROP_CALLBACKS,
	                                 g_param_spec_object ("callbacks",
	                                                      "Callbacks",
	                                                      "Callbacks",
	                                                      GGIT_TYPE_REMOTE_CALLBACKS,
	                                                      G_PARAM_READWRITE |
	                                                      G_PARAM_STATIC_STRINGS));
}

static void
ggit_remote_init (GgitRemote *self)
{
	self->priv = ggit_remote_get_instance_private (self);
}

/**
 * ggit_remote_new:
 * @repository: a #GgitRepository.
 * @name: the remote's name.
 * @url: the remote repository's URL.
 * @error: a #GError for error reporting, or %NULL.
 *
 * Creates a remote with the default refspecs in memory. You can use
 * this when you have a URL instead of a remote's name.
 *
 * Returns: (transfer full): a newly allocated #GgitRemote.
 */
GgitRemote *
ggit_remote_new (GgitRepository   *repository,
                 const gchar      *name,
                 const gchar      *url,
                 GError          **error)
{
	gint ret;
	git_remote *remote;

	g_return_val_if_fail (GGIT_IS_REPOSITORY (repository), NULL);
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (url != NULL, NULL);

	ret = git_remote_create (&remote, _ggit_native_get (repository),
	                         name, url);

	if (ret != GIT_OK)
	{
		_ggit_error_set (error, ret);
		return NULL;
	}

	return _ggit_remote_wrap (remote);
}

/**
 * ggit_remote_new_anonymous:
 * @repository: a #GgitRepository.
 * @url: the remote repository's URL.
 * @fetch: the remote fetchspec.
 * @error: a #GError for error reporting, or %NULL.
 *
 * Creates a remote with the specified refspec in memory. You can use
 * this when you have a URL instead of a remote's name.
 *
 * Returns: (transfer full): a newly allocated #GgitRemote.
 */
GgitRemote *
ggit_remote_new_anonymous (GgitRepository  *repository,
                           const gchar     *url,
                           const gchar     *fetch,
                           GError         **error)
{
	gint ret;
	git_remote *remote;

	g_return_val_if_fail (GGIT_IS_REPOSITORY (repository), NULL);
	g_return_val_if_fail (url != NULL, NULL);
	g_return_val_if_fail (fetch != NULL, NULL);

	ret = git_remote_create_anonymous (&remote,
	                                   _ggit_native_get (repository),
	                                   url,
	                                   fetch);

	if (ret != GIT_OK)
	{
		_ggit_error_set (error, ret);
		return NULL;
	}

	return _ggit_remote_wrap (remote);
}

/**
 * ggit_remote_save:
 * @remote: a #GgitRemote.
 * @error: a #GError or %NULL.
 *
 * Saves a remote to its repository's configuration.
 */
void
ggit_remote_save (GgitRemote  *remote,
                  GError     **error)
{
	gint ret;

	g_return_if_fail (GGIT_IS_REMOTE (remote));
	g_return_if_fail (error == NULL || *error == NULL);

	ret = git_remote_save (_ggit_native_get (remote));

	if (ret != GIT_OK)
	{
		_ggit_error_set (error, ret);
	}
}

/**
 * ggit_remote_get_name:
 * @remote: a #GgitRemote.
 *
 * Gets the remote's name.
 *
 * Returns: the name of @remote.
 */
const gchar *
ggit_remote_get_name (GgitRemote *remote)
{
	g_return_val_if_fail (GGIT_IS_REMOTE (remote), NULL);

	return git_remote_name (_ggit_native_get (remote));
}

/**
 * ggit_remote_get_url:
 * @remote: GgitRemote.
 *
 * Gets the remote's url.
 *
 * Returns: the url of @remote.
 */
const gchar *
ggit_remote_get_url (GgitRemote *remote)
{
	g_return_val_if_fail (GGIT_IS_REMOTE (remote), NULL);

	return git_remote_url (_ggit_native_get (remote));
}

/**
 * ggit_remote_connect:
 * @remote: a #GgitRemote.
 * @direction: whether you want to receive or send data.
 * @error: a #GError for error reporting, or %NULL.
 *
 * Opens a connection to a remote.
 * The transport is selected based on the URL. The direction argument
 * is due to a limitation of the git protocol (over TCP or SSH) which
 * starts up a specific binary which can only do the one or the other.
 */
void
ggit_remote_connect (GgitRemote     *remote,
                     GgitDirection   direction,
                     GError        **error)
{
	gint ret;

	g_return_if_fail (GGIT_IS_REMOTE (remote));
	g_return_if_fail (error == NULL || *error == NULL);

	ret = git_remote_connect (_ggit_native_get (remote), direction);

	if (ret != GIT_OK)
	{
		_ggit_error_set (error, ret);
	}
}

/**
 * ggit_remote_get_connected:
 * @remote: a #GgitRemote.
 *
 * Check whether @remote is connected.
 *
 * Returns: %TRUE if it is connected.
 */
gboolean
ggit_remote_get_connected (GgitRemote *remote)
{
	g_return_val_if_fail (GGIT_IS_REMOTE (remote), FALSE);

	return git_remote_connected (_ggit_native_get (remote));
}

/**
 * ggit_remote_disconnect:
 * @remote: a #GgitRemote.
 *
 * Closes the connection to the remote and frees the underlying
 * transport.
 */
void
ggit_remote_disconnect (GgitRemote *remote)
{
	g_return_if_fail (GGIT_IS_REMOTE (remote));

	git_remote_disconnect (_ggit_native_get (remote));
}

/**
 * ggit_remote_add_fetch_spec:
 * @remote: a #GgitRemote.
 * @fetch_spec: the fetch refspec.
 * @error: a #GError for error reporting, or %NULL.
 *
 * Sets @remote's fetch spec to @fetch_spec.
 */
void
ggit_remote_add_fetch_spec (GgitRemote   *remote,
                            const gchar  *fetch_spec,
                            GError      **error)
{
	gint ret;

	g_return_if_fail (GGIT_IS_REMOTE (remote));
	g_return_if_fail (fetch_spec != NULL && fetch_spec[0] != '\0');
	g_return_if_fail (error == NULL || *error == NULL);

	ret = git_remote_add_fetch (_ggit_native_get (remote), fetch_spec);

	if (ret != GIT_OK)
	{
		_ggit_error_set (error, ret);
	}
}

/**
 * ggit_remote_get_fetch_specs:
 * @remote: a #GgitRemote.
 * @error: a #GError for error reporting, or %NULL.
 *
 * Get the list of fetch refspecs for the given remote.
 *
 * Returns: (transfer full) (allow-none): a list of fetch refspecs.
 */
gchar **
ggit_remote_get_fetch_specs (GgitRemote  *remote,
                             GError     **error)
{
	gint ret;
	git_strarray specs;

	g_return_val_if_fail (GGIT_IS_REMOTE (remote), NULL);
	g_return_val_if_fail (error == NULL || *error == NULL, FALSE);

	ret = git_remote_get_fetch_refspecs (&specs, _ggit_native_get (remote));

	if (ret != GIT_OK)
	{
		_ggit_error_set (error, ret);
		return NULL;
	}

	return ggit_utils_get_str_array_from_git_strarray (&specs);
}

/**
 * ggit_remote_set_fetch_specs:
 * @remote: a #GgitRemote.
 * @specs: (array zero-terminated=1) (allow-none): the ref specs.
 * @error: a #GError for error reporting, or %NULL.
 *
 * Set the list of fetch refspecs for the given remote.
 *
 * Returns: %TRUE if successful, or %FALSE otherwise.
 */
gboolean
ggit_remote_set_fetch_specs (GgitRemote           *remote,
                             const gchar * const  *specs,
                             GError              **error)
{
	gint ret;
	git_strarray gspecs;

	g_return_val_if_fail (GGIT_IS_REMOTE (remote), NULL);
	g_return_val_if_fail (error == NULL || *error == NULL, FALSE);

	ggit_utils_get_git_strarray_from_str_array (specs, &gspecs);

	ret = git_remote_set_fetch_refspecs (_ggit_native_get (remote), &gspecs);

	git_strarray_free (&gspecs);

	if (ret != GIT_OK)
	{
		_ggit_error_set (error, ret);
		return FALSE;
	}

	return TRUE;
}

/**
 * ggit_remote_add_push_spec:
 * @remote: a #GgitRemote.
 * @push_spec: the push refspec.
 * @error: a #GError for error reporting, or %NULL.
 *
 * Sets @remote's push spec to @fetch_spec.
 */
void
ggit_remote_add_push_spec (GgitRemote   *remote,
                           const gchar  *push_spec,
                           GError      **error)
{
	gint ret;

	g_return_if_fail (GGIT_IS_REMOTE (remote));
	g_return_if_fail (push_spec != NULL && push_spec[0] != '\0');
	g_return_if_fail (error == NULL || *error == NULL);

	ret = git_remote_add_push (_ggit_native_get (remote), push_spec);

	if (ret != GIT_OK)
	{
		_ggit_error_set (error, ret);
	}
}

/**
 * ggit_remote_get_push_specs:
 * @remote: a #GgitRemote.
 * @error: a #GError for error reporting, or %NULL.
 *
 * Get the list of push refspecs for the given remote.
 *
 * Returns: (transfer full) (allow-none): a list of push refspecs.
 */
gchar **
ggit_remote_get_push_specs (GgitRemote  *remote,
                            GError     **error)
{
	gint ret;
	git_strarray specs;

	g_return_val_if_fail (GGIT_IS_REMOTE (remote), NULL);
	g_return_val_if_fail (error == NULL || *error == NULL, FALSE);

	ret = git_remote_get_push_refspecs (&specs, _ggit_native_get (remote));

	if (ret != GIT_OK)
	{
		_ggit_error_set (error, ret);
		return NULL;
	}

	return ggit_utils_get_str_array_from_git_strarray (&specs);
}

/**
 * ggit_remote_set_push_specs:
 * @remote: a #GgitRemote.
 * @specs: (array zero-terminated=1) (allow-none): the ref specs.
 * @error: a #GError for error reporting, or %NULL.
 *
 * Set the list of push refspecs for the given remote.
 *
 * Returns: %TRUE if successful, or %FALSE otherwise.
 */
gboolean
ggit_remote_set_push_specs (GgitRemote           *remote,
                            const gchar * const  *specs,
                            GError              **error)
{
	gint ret;
	git_strarray gspecs;

	g_return_val_if_fail (GGIT_IS_REMOTE (remote), NULL);
	g_return_val_if_fail (error == NULL || *error == NULL, FALSE);

	ggit_utils_get_git_strarray_from_str_array (specs, &gspecs);

	ret = git_remote_set_push_refspecs (_ggit_native_get (remote), &gspecs);

	git_strarray_free (&gspecs);

	if (ret != GIT_OK)
	{
		_ggit_error_set (error, ret);
		return FALSE;
	}

	return TRUE;
}

/**
 * ggit_remote_list:
 * @remote: a #GgitRemote.
 * @error: a #GError for error reporting, or %NULL.
 *
 * Get a list of refs at the remote.
 *
 * Returns: (array zero-terminated=1): the remote heads.
 */
GgitRemoteHead **
ggit_remote_list (GgitRemote              *remote,
                  GError                 **error)
{
	const git_remote_head **head;
	size_t size;
	size_t i;
	GgitRemoteHead **retval;
	gint ret;

	g_return_val_if_fail (GGIT_IS_REMOTE (remote), NULL);
	g_return_val_if_fail (error == NULL || *error == NULL, NULL);

	ret = git_remote_ls (&head, &size, _ggit_native_get (remote));

	if (ret != GIT_OK)
	{
		_ggit_error_set (error, ret);
		return NULL;
	}

	retval = g_new0 (GgitRemoteHead *, size + 1);

	for (i = 0; i < size; i++)
	{
		retval[i] = _ggit_remote_head_wrap (head[i]);
	}

	return retval;
}

/**
 * ggit_remote_get_callbacks:
 * @remote: a #GgitRemote.
 *
 * Returns: (transfer none): the remote callbacks.
 */
GgitRemoteCallbacks *
ggit_remote_get_callbacks (GgitRemote *remote)
{
	g_return_val_if_fail (GGIT_IS_REMOTE (remote), NULL);

	return remote->priv->callbacks;
}

/**
 * ggit_remote_set_callbacks:
 * @remote: a #GgitRemote.
 * @callbacks: (allow-none): a #GgitRemoteCallbacks, or %NULL.
 *
 * Set the remote callbacks.
 */
void
ggit_remote_set_callbacks (GgitRemote          *remote,
                           GgitRemoteCallbacks *callbacks)
{
	g_return_if_fail (GGIT_IS_REMOTE (remote));
	g_return_if_fail (callbacks == NULL || GGIT_IS_REMOTE_CALLBACKS (callbacks));

	if (callbacks == remote->priv->callbacks)
	{
		return;
	}

	g_clear_object (&remote->priv->callbacks);

	if (callbacks)
	{
		remote->priv->callbacks = g_object_ref (callbacks);

		git_remote_set_callbacks (_ggit_native_get (remote),
		                          _ggit_remote_callbacks_get_native (callbacks));
	}
	else
	{
		git_remote_callbacks cb = GIT_REMOTE_CALLBACKS_INIT;
		git_remote_set_callbacks (_ggit_native_get (remote), &cb);
	}

	g_object_notify (G_OBJECT (remote), "callbacks");
}

/**
 * ggit_remote_is_valid_url:
 * @url: a url string.
 *
 * Checks if @url is a valid remote URL.
 *
 * Returns: whether a string is a valid remote URL.
 */
gboolean
ggit_remote_is_valid_url (const gchar *url)
{
	g_return_val_if_fail (url != NULL, FALSE);

	return git_remote_valid_url (url);
}

/**
 * ggit_remote_is_supported_url:
 * @url: a url string.
 *
 * Checks if @url is a supported remote URL.
 *
 * Returns: whether a string is a supported remote URL.
 */
gboolean
ggit_remote_is_supported_url (const gchar *url)
{
	g_return_val_if_fail (url != NULL, FALSE);

	return git_remote_supported_url (url);
}

/* ex:set ts=8 noet: */
