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
    for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
      KeyIsDown[i] = false;
  }

  virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const
  {
    return KeyIsDown[keyCode];
  }

  virtual bool OnEvent(const irr::SEvent& event)
  {
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
      KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    if (event.EventType == irr::EET_KEY_INPUT_EVENT && !event.KeyInput.PressedDown)
      return true;
    if (event.EventType == irr::EET_GUI_EVENT)
      {
	irr::s32 id = event.GUIEvent.Caller->getID();
	switch (event.GUIEvent.EventType)
          {
	  case irr::gui::EGET_MENU_ITEM_SELECTED:
	    std::cout << "ITEM HAS BEEN CLICKED !! "
		      << std::endl;

	    // OnMenuItemSelected( (irr::gui::IGUIContextMenu*)event.GUIEvent.Caller );
	    break;

          case irr::gui::EGET_FILE_SELECTED:
	    {
	      irr::gui::IGUIFileOpenDialog* dialog =
		(irr::gui::IGUIFileOpenDialog*)event.GUIEvent.Caller;
	      std::cout << "ITEM HAS BEEN SELECTED !! "
			<< irr::core::stringc(dialog->getFileName()).c_str()
			<< std::endl;

	    }
	    break;
          case irr::gui::EGET_BUTTON_CLICKED:
            switch(id)
              {
	      // case irr::gui::GUI_ID_BUTTON_OPEN_MODEL:
              //   _gui->addFileOpenDialog(L"Please select a model file to open");
              //   break;
	      }
	    break;

	  default:
	    break;
	  }
      }
    return false;
  }
private:
  bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
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
  //init de la fenetre
  t_state			_state;
  irr::video::IVideoDriver	*_driver;
  irr::scene::ISceneManager	*_sceneManager;
  irr::video::ITexture		*_background;
  irr::gui::IGUIListBox		*_listbox;
  //init des coordonnées
  irr::core::dimension2d<irr::u32> _screenSize;
  unsigned int			_resizable;
  bool _listb;
  //boutons
  std::vector<irr::gui::IGUIButton *> _buttons;
  irr::gui::IGUIButton		*_bnewgame;
  irr::gui::IGUIButton		*_bquit;
  irr::gui::IGUIButton		*_bsave;
  irr::gui::IGUIButton		*_bsolo;
  irr::gui::IGUIButton		*_bmulti;
  MyEventReceiver	       receiver;

};


#endif /* MENU_HH_ */
