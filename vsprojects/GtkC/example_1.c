#include <gtk/gtk.h>

//Same as example 0, but button added and print to console

// g_print will output text to console (STDOUT)
//callback function receives gpointer in variable data
static void print_hello (GtkWidget *widget, gpointer   data)
{

    //cast data back to a gchar * type.
  g_print ("%s\n", (gchar*)data);
}

static void activate (GtkApplication *app, gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *button_box;

    //To pass a string through user_data in a Callback, do this first
    //gchar is a gtk character string pointer type.
  gchar* message = "Hello World, this is me.";

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (window), button_box);

  button = gtk_button_new_with_label ("Hello World");

  //Connect first to print_hello when button is clicked
  //cast the string from above as a gpointer*
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), (gpointer*)message);

  //Connect second to G_CALLBACK with window destroy
  //Thus, one button click does two things with connect_swapped
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  gtk_container_add (GTK_CONTAINER (button_box), button);

  gtk_widget_show_all (window);
}

int
main (int    argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("com.tardisgallifrey.example1", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}