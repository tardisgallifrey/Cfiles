#include "radioButtons.h"
#include <iostream>


RadioButtonsWindow::RadioButtonsWindow() :
  m_Box_Top(Gtk::ORIENTATION_VERTICAL),
  m_Box1(Gtk::ORIENTATION_VERTICAL, 10),
  m_Box2(Gtk::ORIENTATION_VERTICAL, 10),
  m_RadioButton1("button1"),
  m_RadioButton2("button2"),
  m_RadioButton3("button3"),
  m_Button_Close("close")
{
  // Set title and border of the window
  set_title("radio buttons");
  set_border_width(0);

  // Put radio buttons 2 and 3 in the same group as 1:
  m_RadioButton2.join_group(m_RadioButton1);
  m_RadioButton3.join_group(m_RadioButton1);

    /* Radio Button creation and grouping can also be done this way
        create the group, then create and add to group in one step

  Gtk::RadioButton::Group group;
  Gtk::RadioButton* m_rb1 = Gtk::manage(new Gtk::RadioButton(group, "button1"));
  Gtk::RadioButton* m_rb2 = Gtk::manage(new Gtk::RadioButton(group, "button2"));
  Gtk::RadioButton* m_rb3 = Gtk::manage(new Gtk::RadioButton(group, "button3"));
  */

  // Add outer box to the window (because the window
  // can only contain a single widget)
  add(m_Box_Top);

  //Put the inner boxes and the separator in the outer box:
  m_Box_Top.pack_start(m_Box1);
  m_Box_Top.pack_start(m_Separator);
  m_Box_Top.pack_start(m_Box2);

  // Set the inner boxes' borders
  m_Box2.set_border_width(10);
  m_Box1.set_border_width(10);

  // Put the radio buttons in Box1:
  m_Box1.pack_start(m_RadioButton1);
  m_Box1.pack_start(m_RadioButton2);
  m_Box1.pack_start(m_RadioButton3);

  // Set the second button active
  m_RadioButton2.set_active();

  // Put Close button in Box2:
  m_Box2.pack_start(m_Button_Close);

  // Make the button the default widget
  m_Button_Close.set_can_default();
  m_Button_Close.grab_default();

  // Connect the clicked signal of the button to
  // RadioButtons::on_button_clicked()
  m_Button_Close.signal_clicked().connect(sigc::mem_fun(*this, &RadioButtonsWindow::on_button_clicked) );
  m_RadioButton1.signal_clicked().connect(sigc::mem_fun(*this, &RadioButtonsWindow::radio_button_clicked) );
  m_RadioButton2.signal_clicked().connect(sigc::mem_fun(*this, &RadioButtonsWindow::radio_button_clicked) );
  m_RadioButton3.signal_clicked().connect(sigc::mem_fun(*this, &RadioButtonsWindow::radio_button_clicked) );

  // Show all children of the window
  show_all_children();
}

RadioButtonsWindow::~RadioButtonsWindow()
{
}

void RadioButtonsWindow::radio_button_clicked()
{
  if(m_RadioButton1.get_active())
  {
    std::cout<<"You chose button 1!"<<std::endl;
  }

  if(m_RadioButton2.get_active())
  {
    std::cout<<"You chose button 2!"<<std::endl;
  }

  if(m_RadioButton3.get_active())
  {
    std::cout<<"You chose button 3!"<<std::endl;
  }
}

void RadioButtonsWindow::on_button_clicked()
{
    hide(); //to close the application.
}