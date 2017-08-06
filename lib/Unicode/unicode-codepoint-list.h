/* unicode-codepoint-list.h
 *
 * Originally a part of Gucharmap
 *
 * Copyright © 2017 Jerry Casiano
 *
 *
 * Copyright © 2004 Noah Levitt
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.
 *
 * If not, see <http://www.gnu.org/licenses/gpl-3.0.txt>.
*/

#ifndef __CODEPOINT_LIST_H__
#define __CODEPOINT_LIST_H__

#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

#define UNICODE_TYPE_CODEPOINT_LIST (unicode_codepoint_list_get_type())
G_DECLARE_INTERFACE(UnicodeCodepointList, unicode_codepoint_list, UNICODE, CODEPOINT_LIST, GObject)

struct _UnicodeCodepointListInterface
{
    GTypeInterface parent_iface;

    gunichar  (* get_char)         (UnicodeCodepointList *self, gint index);
    /* zero is the first index */
    gint      (* get_index)        (UnicodeCodepointList *self, gunichar wc);
    gint      (* get_last_index)   (UnicodeCodepointList *self);

};

gunichar    unicode_codepoint_list_get_char       (UnicodeCodepointList *self, gint index);
gint        unicode_codepoint_list_get_index      (UnicodeCodepointList *self, gunichar wc);
gint        unicode_codepoint_list_get_last_index (UnicodeCodepointList *self);

G_END_DECLS

#endif /* #ifndef __CODEPOINT_LIST_H__ */
