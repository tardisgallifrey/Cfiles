#ifndef GTKMM_EXAMPLE_BUTTONS_H
#define GTKMM_EXAMPLE_BUTTONS_H  //Required to load header only once

#include <gtkmm/window.h>  //required to create a window
#include <gtkmm/button.h>  //required to create a button

//Class file.  This is the one closest to a C# class file
//Buttons inherits from Gtk::Window, it has to be public to be used
class Buttons : public Gtk::Window
{
  public:                 //This is a public class
    Buttons();            //Constructor declaration
    virtual ~Buttons();   //Destructor declaration

  protected:                    //This method is protected (private?)
    //Signal handlers:
    void on_button_clicked();   //prototype for on_button_clicked() method of Button class

    //Child widgets:
    Gtk::Button m_button;       //create a button of type Gtk::Button
    //Gtk::Button* m_button = new Gtk::Button();  Use it like this if you want a pointer
};

#endif //GTKMM_EXAMPLE_BUTTONS_H