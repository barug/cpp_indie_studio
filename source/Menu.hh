#ifndef _MENU_HH_
# define _MENU_HH_

# include <vector>
# include <iostream>
# include "driverChoice.h"
# include "irrlicht.h"
# include "IGUIImage.h"
# include "Engine.hh"

# define BUTTON_WIDTH	(280)
# define BUTTON_HEIGHT	(92)
# define BUTTON_SPACING (10)

enum    menuContext
  {
    BASE,
    NEWGAME,
    MULTI,
    IN_GAME
  };

// class MyEventReceiver : public irr::IEventReceiver
// {
// public:
//   MyEventReceiver(bool *fileIsSelected)
//     : _fileIsSelected(fileIsSelected)
//   {
//   }

//   virtual bool OnEvent(const irr::SEvent& event)
//   {
//     if (event.EventType == irr::EET_GUI_EVENT)
//       {
// 	switch (event.GUIEvent.EventType)
// 	  {
//           case irr::gui::EGET_FILE_SELECTED:
// 	    {
// 	      irr::gui::IGUIFileOpenDialog* file =
// 		(irr::gui::IGUIFileOpenDialog*)event.GUIEvent.Caller;
// 	      std::cout << "ITEM HAS BEEN SELECTED !! "
// 			<< irr::core::stringc(file->getFileName()).c_str()
// 			<< std::endl;
// 	      *(this->_fileIsSelected) = true;

// 	    }
// 	    break;
// 	  default:
// 	    break;
// 	  }
//       }
//     return false;
//   }

// private:
//     bool			*_fileIsSelected;
// };

class Menu
{
public:
  Menu();
  ~Menu();

  void					startMenu();
  void					clearGui();
  void					setSkinTransparency(irr::s32 alpha, irr::gui::IGUISkin * skin);

private:
  void				        doButtonsActions();
  void					drawMenu();
  void					init();
  void					initButtons();

private:
  //game engine
  Engine				_engine;

  //device
  irr::video::IVideoDriver		*_driver;
  irr::IrrlichtDevice			*_device;
  irr::scene::ISceneManager		*_sceneManager;
  irr::video::ITexture			*_background;
  irr::gui::IGUIListBox			*_listbox;
  irr::gui::IGUIEnvironment		*_gui;
  EventReceiver				_receiver;

  //responsive
  irr::core::dimension2d<irr::u32>	_screenSize;

  bool					_fileDialogOpen;
  bool					_fileIsSelected;
  bool					_textIsEntered;
  //boutons
  irr::gui::IGUIButton			*_first;
  irr::gui::IGUIButton			*_second;
  irr::gui::IGUIButton			*_third;
  irr::gui::IGUIButton			*_fourth;
  irr::gui::IGUIFileOpenDialog		*_fileDialog;
  irr::gui::IGUIEditBox			*_editBox;
  irr::gui::IGUIScrollBar		*_scrollMusic;
  irr::gui::IGUIScrollBar		*_scrollSound;
  bool					_isSet;
  bool					_menuIsOn;
  menuContext				_menuContext;
};


#endif /* MENU_HH_ */
