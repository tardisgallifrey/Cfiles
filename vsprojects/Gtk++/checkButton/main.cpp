#include "checkButton.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "com.tardisgallfrey.gtkmm_checkbutton");

  checkButtonWindow window;

  //Shows the window and returns when it is closed.
  return app->run(window);
}