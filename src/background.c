#include "include.h"

gboolean update_scroll_position(gpointer user_data)
{
    AllStructs *allStructs = (AllStructs *)user_data;

    allStructs->background.scrollPos += 2;
    if (allStructs->background.scrollPos >= gdk_pixbuf_get_width(allStructs->background.background)) {
        allStructs->background.scrollPos = 0;
    }

    gtk_widget_queue_draw(allStructs->appWidgets.drawingArea);

    return TRUE;
}