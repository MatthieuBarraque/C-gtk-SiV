#include "include.h"

void init_window_params(WindowParams *WindowParams)
{
    WindowParams->width = 1080;
    WindowParams->height = 720;
    WindowParams->title = "Space Invaders";
    WindowParams->resizable = TRUE;
    WindowParams->fullscreen = FALSE;
    WindowParams->maximized = FALSE;
    WindowParams->decorated = TRUE;
    WindowParams->accept_focus = TRUE;
    WindowParams->modal = FALSE;
    // Initialisez ici les autres paramètres de WindowParams selon vos besoins
}

void init_player(Player *player)
{
    player->x = 100;  // Position initiale du joueur en X
    player->y = 100;  // Position initiale du joueur en Y
    player->health = 100;  // Santé initiale du joueur
    // Initialisez ici les autres propriétés spécifiques au joueur 
}

void init_enemy(Enemy *enemy)
{
    enemy->x = 200;  // Position initiale de l'ennemi en X
    enemy->y = 50;   // Position initiale de l'ennemi en Y
    enemy->health = 50;   // Santé initiale de l'ennemi
    // Initialisez ici les autres propriétés spécifiques à l'ennemi
}

void init_app_widgets(AppWidgets *appWidgets)
{
    appWidgets->window = NULL;
    appWidgets->drawingArea = NULL;
    appWidgets->label = NULL;
    // Initialisez ici les autres widgets selon vos besoins
}

void init_rectangle(Rectangle *rectangle)
{
    rectangle->x = 100;
    rectangle->y = 100;
    rectangle->width = 50;
    rectangle->height = 50;
}

void init_sprite(Sprite *sprite, const char *file_path)
{
    GError *error = NULL;
    sprite->image = gdk_pixbuf_new_from_file(file_path, &error);
    if (!sprite->image) {
        g_printerr("Error loading sprite: %s\n", error->message);
        g_error_free(error);
    }
}

void init_background(AppBackground *background, const char *file_path) {
    GError *error = NULL;
    background->background = gdk_pixbuf_new_from_file(file_path, &error);
    if (!background->background) {
        g_printerr("Error loading background: %s\n", error->message);
        g_error_free(error);
    }
    background->scrollPos = 0;
}

void init_asteroid(Asteroid *asteroid, const char *file_path) {
    GError *error = NULL;
    asteroid->image = gdk_pixbuf_new_from_file(file_path, &error);
    if (!asteroid->image) {
        g_printerr("Error loading asteroid image: %s\n", error->message);
        g_error_free(error);
        return;
    }
    asteroid->x = 1080;
    asteroid->y = g_random_int_range(0, 720); 
}

void init_all_structs(AllStructs *allStructs)
{
    init_window_params(&allStructs->WindowParams);
    init_player(&allStructs->player);
    init_enemy(&allStructs->enemy);
    init_rectangle(&allStructs->rectangle);
    init_sprite(&allStructs->sprite, "sprite/ship.png");
    init_asteroid(&allStructs->asteroid, "sprite/asteroid.png");
    init_background(&allStructs->background, "background/space.png");
    init_app_widgets(&allStructs->appWidgets);
}
