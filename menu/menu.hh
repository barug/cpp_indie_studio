#ifndef _MENU_HH_
# define _MENU_HH_

#include "irrlicht.h"
#include "IGUIImage.h"

class menu
{
private:
  //init de la fenetre
  irr::IrrlichtDevice*		_device;
  irr::video::IVideoDriver*	_driver;
  irr::scene::ISceneManager*	_sceneManager;
  irr::video::ITexture *	_image;
  irr::gui::IGUIEnvironment*	_gui;

  //init des coordonnées
  irr::core::dimension2d<irr::u32> _ss;
  int _middleOfScreen;
  int _left;
  int _leftmid;
  int _right;
  int _rightmid;

  //boutons
  irr::gui::IGUIButton		*_bquit;
  irr::gui::IGUIButton		*_bstart;
  irr::gui::IGUIButton		*_breset;
  irr::gui::IGUIButton		*_bsave;

public:
  menu();
  ~menu();
  irr::gui::IGUIButton*	createButon(int, int, int, int, const char * const);
  void			resetWindow();
  void			drawAll();
  void		        resize();
  int			checkButton();
  void			clear();
  void			drawGui();
  void			init();
};


#endif /* MENU_HH_ */
