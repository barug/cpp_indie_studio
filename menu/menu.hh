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
    MENU1,
    MENU2,
    MENU3
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
  irr::gui::IGUIButton	*createButton(const int &x1, const int &y1,
				      const int &x2, const int &y2,
				      const std::string &image);
  void		        resetWindow();
  int			checkButton();
  void			init();
  void			displayButtonsMenu1();
  void			displayButtonsMenu2();

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
  std::vector<irr::gui::IGUIButton *> _buttons;
  irr::gui::IGUIButton		*_bnewgame;
  irr::gui::IGUIButton		*_bquit;
  irr::gui::IGUIButton		*_bsave;
  irr::gui::IGUIButton		*_bload;
  irr::gui::IGUIButton		*_bsolo;
  irr::gui::IGUIButton		*_bmulti;


  t_state			_state;

};


#endif /* MENU_HH_ */
