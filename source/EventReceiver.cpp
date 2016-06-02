//
// EventReceiver.cpp for indieStudio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 18 15:24:05 2016 Barthelemy Gouby
// Last update Thu Jun  2 21:49:22 2016 Barthelemy Gouby
//

#include <iostream>
#include "EventReceiver.hh"

EventReceiver::EventReceiver(bool *fileIsSelected, bool *textIsEntered)
  : _fileIsSelected(fileIsSelected), _textIsEntered(textIsEntered)
{
  for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
    this->_KeyIsDown[i] = false;
}

bool EventReceiver::OnEvent(const irr::SEvent& event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT)
    {
      std::cout << "key event" << std::endl;
      this->_KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    }
  if (event.EventType == irr::EET_GUI_EVENT)
    {
      std::cout << "file event" << std::endl;
      if (event.GUIEvent.EventType == irr::gui::EGET_FILE_SELECTED)
	{
	  irr::gui::IGUIFileOpenDialog* file =
	    (irr::gui::IGUIFileOpenDialog*)event.GUIEvent.Caller;
	  std::cout << "ITEM HAS BEEN SELECTED !! "
		    << irr::core::stringc(file->getFileName()).c_str()
		    << std::endl;
	  *(this->_fileIsSelected) = true;
	}
      if (event.GUIEvent.EventType == irr::gui::EGET_EDITBOX_MARKING_CHANGED)
	{
	  std::cout << "enter happened" << std::endl;
	  // *(this->_textIsEntered) = true;
	}
    }
  return false;
}

bool EventReceiver::IsKeyUp(const irr::EKEY_CODE &keyCode) const
{
  return this->_KeyIsUp[keyCode];
}

bool EventReceiver::IsKeyDown(const irr::EKEY_CODE &keyCode) const
{
  return this->_KeyIsDown[keyCode];
}

