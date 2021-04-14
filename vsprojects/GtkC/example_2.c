#include <gtk/gtk.h>

//AN example on Widget packing


//Both button1 and button 2 use print_hello as a callback function
//We use message1 and message2 strings so you know which on is calling.
static void print_hello (GtkWidget *widget, gpointer   data)
{
    //Print the message we receive.
  g_print ("%s\n", (gchar*)data);
}

static void activate (GtkApplication *app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button;

  gchar* message1 = "You clicked on button 1";
  gchar* message2 = "You clicked on button 2";

  /* create a new window, and set its title */
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Widget Packing example");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 400);
  
  //This is not the outside border, but an internal border relative to the 400, 400 above.
  //Controls blank space (whitespace?) around widgets in grid.
  gtk_container_set_border_width (GTK_CONTAINER (window), 50);

  /* Here we construct the container that is going pack our buttons */
  grid = gtk_grid_new ();

  /* Pack the container in the window */
  gtk_container_add (GTK_CONTAINER (window), grid);

  button = gtk_button_new_with_label ("Button 1");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), (gpointer*)message1);

  /* Place the first button in the grid cell (0, 0), and make it fill
   * just 1 cell horizontally and vertically (ie no spanning)
   */
  //First two zeros are location in grid X by Y
  //Last two ones are size of button Columns by Rows
  //So, at XY(0,0) place a button that is 1 column by 1 row in size
  gtk_grid_attach (GTK_GRID (grid), button, 0, 0, 1, 1);

  button = gtk_button_new_with_label ("Button 2");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), (gpointer*)message2);

  /* Place the second button in the grid cell (1, 0), and make it fill
   * just 1 cell horizontally and vertically (ie no spanning)
   */
  gtk_grid_attach (GTK_GRID (grid), button, 1, 0, 3, 3);

  button = gtk_button_new_with_label ("Quit");
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);

  /* Place the Quit button in the grid cell (0, 1), and make it
   * span 2 columns.
   */
  gtk_grid_attach (GTK_GRID (grid), button, 0, 1, 1, 1);

  /* Now that we are done packing our widgets, we show them all
   * in one go, by calling gtk_widget_show_all() on the window.
   * This call recursively calls gtk_widget_show() on all widgets
   * that are contained in the window, directly or indirectly.
   */
  gtk_widget_show_all (window);

}

int main (int    argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("com.tardisgallifrey.example2", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}