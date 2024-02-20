#include "include.h" // Assurez-vous que ce fichier inclut "struct.h"

void create_and_configure_window(AllStructs *allStructs, GtkApplication *app)
{
    allStructs->appWidgets.window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(allStructs->appWidgets.window), allStructs->WindowParams.title);
    gtk_window_set_default_size(GTK_WINDOW(allStructs->appWidgets.window), allStructs->WindowParams.width, allStructs->WindowParams.height);
    gtk_window_set_resizable(GTK_WINDOW(allStructs->appWidgets.window), allStructs->WindowParams.resizable);
    apply_window_settings(GTK_WINDOW(allStructs->appWidgets.window), &allStructs->WindowParams);
}

void apply_window_settings(GtkWindow *window, const WindowParams *params)
{
    if (params->fullscreen) {
        gtk_window_fullscreen(window);
    }
    if (params->maximized) {
        gtk_window_maximize(window);
    }
    gtk_window_set_decorated(window, params->decorated);
    gtk_window_set_accept_focus(window, params->accept_focus);
    gtk_window_set_modal(window, params->modal);
    // Ajoutez ici d'autres configurations
}
