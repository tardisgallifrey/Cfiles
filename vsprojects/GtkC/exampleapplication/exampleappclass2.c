#include <gtk/gtk.h>

#include "exampleapp.h"
#include "exampleappwin.h"

static void example_app_startup (GApplication *app);
static void example_app_window_init (ExampleAppWindow *win);
static void example_app_window_class_init (ExampleAppWindowClass *class);
ExampleAppWindow *example_app_window_new (ExampleApp *app);
void example_app_window_open (ExampleAppWindow *win, GFile *file);
static void preferences_activated (GSimpleAction *action, GVariant *parameter, gpointer app);
static void quit_activated (GSimpleAction *action, GVariant *parameter, gpointer app);


struct _ExampleAppWindow
{
  GtkApplicationWindow parent;
};

struct _ExampleAppWindowPrivate
{
  GtkWidget *stack;
};

typedef struct _ExampleAppWindowPrivate ExampleAppWindowPrivate;

G_DEFINE_TYPE(ExampleAppWindow, example_app_window, GTK_TYPE_APPLICATION_WINDOW);
//DEFINE_TYPE_WITH_PRIVATE(ExampleAppWindow, example_app_window, GTK_TYPE_APPLICATION_WINDOW);


static void example_app_window_init (ExampleAppWindow *win)
{
  gtk_widget_init_template (GTK_WIDGET (win));
}

static void example_app_window_class_init (ExampleAppWindowClass *class)
{
  gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (class), "/org/gtk/exampleapp/GtkHeaderBar.xml");
  gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (class), ExampleAppWindow, stack);
  G_APPLICATION_CLASS (class)->startup = example_app_startup;
}

ExampleAppWindow *example_app_window_new (ExampleApp *app)
{
  return g_object_new (EXAMPLE_APP_WINDOW_TYPE, "application", app, NULL);
}

void example_app_window_open (ExampleAppWindow *win, GFile *file)
{
  ExampleAppWindowPrivate *priv;
  gchar *basename;
  GtkWidget *scrolled, *view;
  gchar *contents;
  gsize length;

  priv = example_app_window_get_instance_private (win);
  basename = g_file_get_basename (file);

  scrolled = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolled);
  gtk_widget_set_hexpand (scrolled, TRUE);
  gtk_widget_set_vexpand (scrolled, TRUE);
  view = gtk_text_view_new ();
  gtk_text_view_set_editable (GTK_TEXT_VIEW (view), FALSE);
  gtk_text_view_set_cursor_visible (GTK_TEXT_VIEW (view), FALSE);
  gtk_widget_show (view);
  gtk_container_add (GTK_CONTAINER (scrolled), view);
  gtk_stack_add_titled (GTK_STACK (priv->stack), scrolled, basename, basename);

  if (g_file_load_contents (file, NULL, &contents, &length, NULL, NULL))
    {
      GtkTextBuffer *buffer;

      buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));
      gtk_text_buffer_set_text (buffer, contents, length);
      g_free (contents);
    }

  g_free (basename);
}

static void preferences_activated (GSimpleAction *action, GVariant *parameter, gpointer app)
{
}

static void quit_activated (GSimpleAction *action, GVariant *parameter, gpointer app)
{
  g_application_quit (G_APPLICATION (app));
}

static GActionEntry app_entries[] =
{
  { "preferences", preferences_activated, NULL, NULL, NULL },
  { "quit", quit_activated, NULL, NULL, NULL }
};

static void example_app_startup (GApplication *app)
{
  GtkBuilder *builder;
  GMenuModel *app_menu;
  const gchar *quit_accels[2] = { "<Ctrl>Q", NULL };

  G_APPLICATION_CLASS (example_app_window_parent_class)->startup (app);

  g_action_map_add_action_entries (G_ACTION_MAP (app), app_entries, G_N_ELEMENTS (app_entries), app);
  gtk_application_set_accels_for_action (GTK_APPLICATION (app), "app.quit", quit_accels);

  builder = gtk_builder_new_from_resource ("/org/gtk/exampleapp/menu.xml");
  app_menu = G_MENU_MODEL (gtk_builder_get_object (builder, "menubar"));
  gtk_application_set_app_menu (GTK_APPLICATION (app), app_menu);
  g_object_unref (builder);
}
