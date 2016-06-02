#ifndef _MENU_HH_
# define _MENU_HH_

#include "driverChoice.h"
#include "irrlicht.h"
#include "IGUIImage.h"
#include <vector>
#include <iostream>

irr::gui::IGUIEnvironment	*_gui;

class MyEventReceiver : public irr::IEventReceiver
{
public:
  MyEventReceiver()
  {
  }

  virtual bool OnEvent(const irr::SEvent& event)
  {
    if (event.EventType == irr::EET_GUI_EVENT)
      {
	switch (event.GUIEvent.EventType)
          {
          case irr::gui::EGET_FILE_SELECTED:
	    {
	      irr::gui::IGUIFileOpenDialog* file =
		(irr::gui::IGUIFileOpenDialog*)event.GUIEvent.Caller;
	      std::cout << "ITEM HAS BEEN SELECTED !! "
			<< irr::core::stringc(file->getFileName()).c_str()
			<< std::endl;
	    }
	    break;
	  default:
	    break;
	  }
      }
    return false;
  }
};

typedef enum	e_state
  {
    BASE,
    NEWGAME,
    SOLO,
    MULTI
  }		t_state;

class Menu
{
public:
  Menu();
  ~Menu();

  void			clearGui();
  void			drawGui();
  void			drawAll();
  void			setSkinTransparency(irr::s32 alpha, irr::gui::IGUISkin * skin);
  irr::IrrlichtDevice		*_device;

private:
  int		        resetWindow();
  void			init();
  void			initButtons();

private:
  //device
  irr::video::IVideoDriver	*_driver;
  irr::scene::ISceneManager	*_sceneManager;
  irr::video::ITexture		*_background;
  irr::gui::IGUIListBox		*_listbox;
  MyEventReceiver	       receiver;

  //responsive
  irr::core::dimension2d<irr::u32> _screenSize;
  unsigned int			_resizable;
  bool				_listb;

  //boutons
  irr::gui::IGUIButton		*_first;
  irr::gui::IGUIButton		*_second;
  irr::gui::IGUIButton		*_third;
  irr::gui::IGUIButton		*_fourth;
  bool				_isSet;
  t_state			_state;

};


#endif /* MENU_HH_ */
