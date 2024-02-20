#include "include.h" // Assurez-vous que ce fichier inclut "struct.h"

gboolean update_asteroid_position(gpointer user_data) {
    AllStructs *allStructs = (AllStructs *)user_data;

    allStructs->asteroid.x -= 5;

    if (allStructs->asteroid.x < -gdk_pixbuf_get_width(allStructs->asteroid.image)) {
        int window_width, window_height;
        gtk_window_get_size(GTK_WINDOW(allStructs->appWidgets.window), &window_width, &window_height);

        allStructs->asteroid.x = window_width;
        allStructs->asteroid.y = g_random_int_range(0, window_height - gdk_pixbuf_get_height(allStructs->asteroid.image));
    }

    gtk_widget_queue_draw(allStructs->appWidgets.drawingArea);
    return TRUE;
}

void activate(GtkApplication *app, gpointer user_data)

    AllStructs *allStructs = user_data;

    create_and_configure_window(allStructs, app);

    gtk_widget_add_events(allStructs->appWidgets.window, GDK_KEY_PRESS_MASK);
    g_signal_connect(G_OBJECT(allStructs->appWidgets.window), "key-press-event", G_CALLBACK(on_key_press_event), allStructs);

    allStructs->appWidgets.drawingArea = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(allStructs->appWidgets.window), allStructs->appWidgets.drawingArea);
    g_signal_connect(G_OBJECT(allStructs->appWidgets.drawingArea), "draw", G_CALLBACK(on_draw_event), allStructs);

    g_timeout_add(33, update_scroll_position, allStructs);
    g_timeout_add(33, update_asteroid_position, allStructs);

    gtk_widget_show_all(allStructs->appWidgets.window);



int main(int argc, char *argv[])
{
    AllStructs allStructs;
    init_all_structs(&allStructs);  // Initialiser toutes les structures

    GtkApplication *app = gtk_application_new("com.example.spaceinvaders", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), &allStructs);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

