#include "checkButton.h"
#include <iostream>

checkButtonWindow::checkButtonWindow() : m_button("something")
{
  set_title("checkbutton example");
  set_border_width(10);

  m_button.signal_clicked().connect(sigc::mem_fun(*this, &checkButtonWindow::on_button_clicked) );

  add(m_button);

  show_all_children();
}

checkButtonWindow::~checkButtonWindow()
{
}

void checkButtonWindow::on_button_clicked()
{
  std::cout << "The Button was clicked: state="<< (m_button.get_active() ? "true" : "false")<< std::endl;

  if(m_button.get_active())
  {
    std::cout<<"You checked the button."<<std::endl;
  }
  else
  {
    std::cout<<"You un-checked the button."<<std::endl;
  }
  
}