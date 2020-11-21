#include <gtk/gtk.h>


//This is the function to create the pixbuf.
// It uses Gdk, but is not part of Gdk
//It is user written
GdkPixbuf *create_pixbuf(const gchar * filename) {
    
   GdkPixbuf *pixbuf;
   GError *error = NULL;
   pixbuf = gdk_pixbuf_new_from_file(filename, &error);
   
   if (!pixbuf) {
       
      fprintf(stderr, "%s\n", error->message);
      g_error_free(error);
   }

   return pixbuf;
}

int main(int argc, char *argv[]) {


/* 
    A tooltip is a small rectangular window, 
    which gives a brief information about an object. 
    It is usually a GUI component;
    it is part of the help system of the application.

    --zetcode instructions
*/
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *halign;
  GdkPixbuf *icon;
  gchar *filestring = "/usr/share/icons/hicolor/48x48/apps/mate-typing-monitor.png";

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Tooltip");
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
  gtk_container_set_border_width(GTK_CONTAINER(window), 15);


  //adding icon back
  //See create_pixbuf function above
  icon = create_pixbuf(filestring);  
  gtk_window_set_icon(GTK_WINDOW(window), icon);
  
  button = gtk_button_new_with_label("Hover here to see tooltip");
  gtk_widget_set_tooltip_text(button, "This is a tooltip");

  //halign = gtk_alignment_new(0, 0, 0, 0);
  //gtk_container_add(GTK_CONTAINER(halign), button);
  //gtk_container_add(GTK_CONTAINER(window), halign);  

  gtk_widget_show_all(window);
  
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);  

    //Needed for icon use??
  g_object_unref(icon); 

  gtk_main();

  return 0;
}