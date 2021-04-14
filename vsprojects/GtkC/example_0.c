#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>


//Minimum required to build a window application

//Required for every file.  Might be larger, won't be smaller
static void activate (GtkApplication* app, gpointer user_data)
{
  GtkWidget *window;
  int size = GPOINTER_TO_INT(user_data);

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), size, size);
  gtk_widget_show_all (window);
}

int main (int    argc, char **argv)
{
  //Same program flow needed for all windows applicatins.
  GtkApplication *app;
  int status;

  int size = 500;
  gpointer ptr = GINT_TO_POINTER(size);

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), ptr);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}