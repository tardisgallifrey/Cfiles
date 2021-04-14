#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    
  GtkWidget *window;

  gtk_init(&argc, &argv);

    //This is a different way of creating a window than
    //the examples from Gnome Gtk+

    //Those examples created a gtk_application_window

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  //These three lines are all that is different from simple.c
  gtk_window_set_title(GTK_WINDOW(window), "Center");
  gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  gtk_widget_show(window);

  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_main();

  return 0;
}