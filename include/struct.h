#ifndef STRUCT_H
#define STRUCT_H

#include <gtk/gtk.h>

typedef struct {
    int x, y; // Position de l'astéroïde
    GdkPixbuf *image; // Image de l'astéroïde
} Asteroid;


typedef struct {
    GdkPixbuf *background; // Image de fond
    int scrollPos; // Position de défilement du fond
} AppBackground;

typedef struct {
    GdkPixbuf *image; // Image du sprite
} Sprite;

typedef struct {
    int x, y; // Position du rectangle
    int width, height; // Taille du rectangle
} Rectangle;

// Structure pour les ennemis
typedef struct {
    int x, y; // Position de l'ennemi
    int health; // Points de vie de l'ennemi
    // Autres propriétés spécifiques à l'ennemi...
} Enemy;

// Structure pour le joueur
typedef struct {
    int x, y; // Position du joueur
    int health; // Points de vie du joueur
} Player;

typedef struct {
    int width, height; // Taille de la fenêtre
    const char *title; // Titre de la fenêtre
    gboolean resizable; // La fenêtre est-elle redimensionnable ?
    gboolean fullscreen; // La fenêtre est-elle en plein écran ?
    gboolean maximized; // La fenêtre est-elle maximisée ?
    gboolean decorated; // La fenêtre est-elle décorée ?
    gboolean keep_above; // La fenêtre est-elle toujours au premier plan ?
    gboolean keep_below; // La fenêtre est-elle toujours en arrière-plan ?
    gboolean sticky; // La fenêtre est-elle collante ?
    gboolean skip_taskbar; // La fenêtre est-elle cachée de la barre des tâches ?
    gboolean skip_pager; // La fenêtre est-elle cachée du commutateur de bureau ?
    gboolean accept_focus; // La fenêtre accepte-t-elle le focus ?
    gboolean focus_on_click; // La fenêtre prend-elle le focus au clic ?
    gboolean focus_visible; // Le focus est-il visible ?
    gboolean modal; // La fenêtre est-elle modale ?
    gboolean destroy_with_parent; // La fenêtre est-elle détruite avec son parent ?
    gboolean hide_titlebar_when_maximized; // La barre de titre est-elle cachée en mode maximisé ?
    gboolean auto_startup_notification; // La fenêtre est-elle notifiée au démarrage ?
} WindowParams;

typedef struct {
    GtkWidget *window; // Fenêtre principale
    GtkWidget *drawingArea; // Zone de dessin
    GtkWidget *label;
} AppWidgets;


typedef struct {
    AppWidgets appWidgets; // Widgets de l'application
    WindowParams WindowParams; // Paramètres de la fenêtre
    Player player; // Données du joueur
    Enemy enemy; // Données de l'ennemi
    Rectangle rectangle; // Le rectangle contrôlable
    Sprite sprite; // Le sprite contrôlable
    AppBackground background; // Arrière-plan de l'application
    Asteroid asteroid; // Données de l'astéroïde
    // Ajoutez d'autres structures ou données ici selon vos besoins
} AllStructs;

#endif // STRUCT_H
