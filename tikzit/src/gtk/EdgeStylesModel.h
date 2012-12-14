/*
 * Copyright 2011-2012  Alex Merry <dev@randomguy3.me.uk>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#import "TZFoundation.h"
#import <gtk/gtk.h>

@class EdgeStyle;
@class StyleManager;

enum {
    EDGE_STYLES_NAME_COL = 0,
    EDGE_STYLES_ICON_COL,
    EDGE_STYLES_PTR_COL,
    EDGE_STYLES_N_COLS
};

@interface EdgeStylesModel: NSObject {
    GtkListStore        *store;
    StyleManager        *styleManager;
}

/*!
 @property   model
 @brief      The GTK+ tree model
 */
@property (readonly) GtkTreeModel *model;

/*!
 @property   manager
 @brief      The StyleManager to use.
 */
@property (retain)   StyleManager *styleManager;

/*!
 * Initialise with the given style manager
 */
- (id) initWithStyleManager:(StyleManager*)m;

+ (id) modelWithStyleManager:(StyleManager*)m;

- (EdgeStyle*) styleFromPath:(GtkTreePath*)path;
- (GtkTreePath*) pathFromStyle:(EdgeStyle*)style;

@end

// vim:ft=objc:ts=8:et:sts=4:sw=4
