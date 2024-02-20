#include "include.h"

void on_draw_event(GtkWidget *widget, cairo_t *cr, AllStructs *allStructs)
{
    if (allStructs->background.background) {
        int width = gdk_pixbuf_get_width(allStructs->background.background);
        int height = gdk_pixbuf_get_height(allStructs->background.background);

        gdk_cairo_set_source_pixbuf(cr, allStructs->background.background, -allStructs->background.scrollPos, 0);
        cairo_paint(cr);

        if (allStructs->background.scrollPos > 0) {
            gdk_cairo_set_source_pixbuf(cr, allStructs->background.background, -allStructs->background.scrollPos + width, 0);
            cairo_paint(cr);
        }
    }

    if (allStructs->sprite.image) {
        GdkPixbuf *scaled = gdk_pixbuf_scale_simple(allStructs->sprite.image,
                                                    allStructs->rectangle.width,
                                                    allStructs->rectangle.height,
                                                    GDK_INTERP_BILINEAR);
        gdk_cairo_set_source_pixbuf(cr, scaled, allStructs->rectangle.x, allStructs->rectangle.y);
        cairo_paint(cr);
        g_object_unref(scaled);
    }

    if (allStructs->asteroid.image) {
        GdkPixbuf *scaled_ast = gdk_pixbuf_scale_simple(allStructs->asteroid.image,
                                                        allStructs->rectangle.width,  // Utilisez la largeur de la hitbox
                                                        allStructs->rectangle.height, // Utilisez la hauteur de la hitbox
                                                        GDK_INTERP_BILINEAR);
        gdk_cairo_set_source_pixbuf(cr, scaled_ast, allStructs->asteroid.x, allStructs->asteroid.y); // Utilisez scaled_ast ici
        cairo_paint(cr);
        g_object_unref(scaled_ast);
    }
}

void on_key_press_event(GtkWidget *widget, GdkEventKey *event, AllStructs *allStructs)
{
    int move_step = 10;
    int old_x = allStructs->rectangle.x;
    int old_y = allStructs->rectangle.y;

    switch (event->keyval) {
        case GDK_KEY_z: allStructs->rectangle.y -= move_step; break;  // Haut
        case GDK_KEY_s: allStructs->rectangle.y += move_step; break;  // Bas
        case GDK_KEY_q: allStructs->rectangle.x -= move_step; break;  // Gauche
        case GDK_KEY_d: allStructs->rectangle.x += move_step; break;  // Droite
    }

    int window_width, window_height;
    gtk_window_get_size(GTK_WINDOW(allStructs->appWidgets.window), &window_width, &window_height);

    if (allStructs->rectangle.x < 0) {
        allStructs->rectangle.x = 0;
    } else if (allStructs->rectangle.x + allStructs->rectangle.width > window_width) {
        allStructs->rectangle.x = window_width - allStructs->rectangle.width;
    }

    if (allStructs->rectangle.y < 0) {
        allStructs->rectangle.y = 0;
    } else if (allStructs->rectangle.y + allStructs->rectangle.height > window_height) {
        allStructs->rectangle.y = window_height - allStructs->rectangle.height;
    }

    if (old_x != allStructs->rectangle.x || old_y != allStructs->rectangle.y) {
        gtk_widget_queue_draw(widget);
    }
}