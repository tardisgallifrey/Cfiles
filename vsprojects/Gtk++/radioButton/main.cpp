#include "radioButtons.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "com.tardisgallifrey.gtkmm_radioButtons");

  RadioButtonsWindow buttons;

  //Shows the window and returns when it is closed.
  return app->run(buttons);
}