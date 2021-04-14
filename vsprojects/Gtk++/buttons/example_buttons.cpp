#include <gtkmm.h>
#include <stdlib.h>
#include "buttons.h"

int main(int argc, char *argv[])
{

  auto app =
    Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

  Buttons button;

  Gtk::Button* pButton = new Gtk::Button("_Something", true);

  return app->run(button);
}