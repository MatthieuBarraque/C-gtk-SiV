#include "struct.h"

#include "gtk/gtk.h"
#include "gdk/gdkkeysyms.h"

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "time.h"
#include "math.h"
#include <gdk-pixbuf/gdk-pixbuf.h>

// Fonctions pour l'ennemi
void initialize_enemy(Enemy *enemy, int x, int y);
void move_enemy(Enemy *enemy, int dx, int dy);
void damage_enemy(Enemy *enemy, int damage);

// Fonctions pour le joueur
void initialize_player(Player *player, int x, int y);
void move_player(Player *player, int dx, int dy);
void damage_player(Player *player, int damage);

// Fonctions pour l'application
void activate(GtkApplication *app, gpointer user_data);

void apply_window_settings(GtkWindow *window, const WindowParams *params);
void create_and_configure_window(AllStructs *allStructs, GtkApplication *app);

void init_all_structs(AllStructs *allStructs);
void init_window_params(WindowParams *WindowParams);
void init_player(Player *player);
void init_enemy(Enemy *enemy);
void init_app_widgets(AppWidgets *appWidgets);

void init_rectangle(Rectangle *rectangle);

void on_draw_event(GtkWidget *widget, cairo_t *cr, AllStructs *allStructs);
void on_key_press_event(GtkWidget *widget, GdkEventKey *event, AllStructs *allStructs);
gboolean update_scroll_position(gpointer user_data);

