#ifndef _MENU_HH_
# define _MENU_HH_

#include "irrlicht.h"
#include "IGUIImage.h"
#include <vector>
#include <iostream>

class Menu
{
public:
  Menu();
  ~Menu();

  void			clearGui();
  void			drawGui();
  void			drawAll();

private:
  irr::gui::IGUIButton*	createButon(const int &x1, const int &y1,
				    const int &x2, const int &y2,
				    const std::string &);
  void		        resetWindow();
  int			checkButton();
  void			init();
  void			displayButtons();

private:
  //init de la fenetre
  irr::IrrlichtDevice*		_device;
  irr::video::IVideoDriver*	_driver;
  irr::scene::ISceneManager*	_sceneManager;
  irr::video::ITexture *	_background;
  irr::gui::IGUIEnvironment*	_gui;

  //init des coordonnées
  irr::core::dimension2d<irr::u32> _screenSize;
  unsigned int			_resizable;

  //boutons
  std::vector<irr::gui::IGUIButton *> _buttons;
  irr::gui::IGUIButton		*_bquit;
  irr::gui::IGUIButton		*_bplay;
  irr::gui::IGUIButton		*_bsave;
};


#endif /* MENU_HH_ */
