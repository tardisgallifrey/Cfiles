#include <gtkmm.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  auto app =
    Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

  Gtk::Frame my_frame;
  

  Gtk::Window window;
  window.set_default_size(200, 200);

  return app->run(window);
}