/*Mnemonics are shortcut keys that activate a widget 
that supports mnemonics. They can be used with labels, 
buttons, or menu items. 
The mnemonic is created by adding the _ character (underscore) 
to the widget's label. 
It causes the next character to be the mnemonic. 
The character is combined with the mouseless modifier, usually Alt. 

The chosen character is underlined, but it may be emphasized
 in a platform specific manner. On some platforms, 
 the character is only underlined after pressing the mouseless modifier.
 */

#include <gtk/gtk.h>

void print_msg(GtkWidget *widget, gpointer window) {

  g_print("Button clicked\n");
}

int main(int argc, char *argv[]) {

  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Mnemonic");
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
  gtk_container_set_border_width(GTK_CONTAINER(window), 15);

    //This method of adding buttons gets rid of the gtk_alignment_new
    /* Here we construct the container that is going pack our buttons */
  grid = gtk_grid_new ();

  /* Pack the container in the window */
  gtk_container_add (GTK_CONTAINER (window), grid);
  
  //So, ALT-B should activate our button
  button = gtk_button_new_with_mnemonic("_Button");
  
  g_signal_connect(button, "clicked", G_CALLBACK(print_msg), NULL);  

  /* Place the first button in the grid cell (0, 0), and make it fill
   * just 1 cell horizontally and vertically (ie no spanning)
   */
  gtk_grid_attach (GTK_GRID (grid), button, 0, 0, 1, 1);

  gtk_widget_show_all(window);
  
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL); 

  gtk_main();

  return 0;
}