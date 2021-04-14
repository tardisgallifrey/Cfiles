#ifndef GTKMM_EXAMPLE_BUTTONS_H
#define GTKMM_EXAMPLE_BUTTONS_H

#include <gtkmm/window.h>
#include <gtkmm/checkbutton.h>

class checkButtonWindow : public Gtk::Window
{
    public:
        checkButtonWindow();
        virtual ~checkButtonWindow();

    protected:
    //Signal handlers:
    void on_button_clicked();

    //Child widgets:
    Gtk::CheckButton m_button;
};

#endif //GTKMM_EXAMPLE_BUTTONS_H