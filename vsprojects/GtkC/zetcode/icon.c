#include <gtk/gtk.h>

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
    
  GtkWidget *window;
  GdkPixbuf *icon;
  //My change, a string for the icon file
  char *filestring = "/usr/share/icons/hicolor/48x48/apps/mate-typing-monitor.png";

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Icon");
  gtk_window_set_default_size(GTK_WINDOW(window), 230, 150);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  
  //These two lines are added from Center.c to add an icon
  //Icons are all in /usr/share/icons/...
  //48x48 are good for app icons
  icon = create_pixbuf(filestring);  
  gtk_window_set_icon(GTK_WINDOW(window), icon);
  
  gtk_widget_show(window);

  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
      
      /*The g_object_unref() decreases the reference count of the pixbuf object. 
      When its reference count drops to 0,
       the object is finalized (i.e. its memory is freed).--zetcode instructions
       
       Possibly, this means it's another way to clean up after a destroy???*/

  g_object_unref(icon);    

  gtk_main();

  return 0;
}