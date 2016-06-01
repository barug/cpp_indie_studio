#include "menu.hh"

Menu::Menu() : _state(MENU1)
{
}

Menu::~Menu()
{
}

void			Menu::init()
{
  this->_device =
    irr::createDevice(irr::video::EDT_OPENGL,
		      irr::core::dimension2d<irr::u32>(1200, 800),
		      32, false, true, false, &receiver);
  this->_device->setResizable(true);
  this->_driver = this->_device->getVideoDriver();
  this->_sceneManager = this->_device->getSceneManager();
  this->_background = this->_driver->getTexture ("menu_textures/background.png");
  _gui = this->_device->getGUIEnvironment();
  this->_screenSize = this->_device->getVideoDriver()->getScreenSize();
}

irr::gui::IGUIButton*	Menu::createButton(const int &x1, const int &y1,
					  const int &x2, const int &y2,
					  const std::string &image)
{
  irr::gui::IGUIButton *bouton =
    _gui->addButton(irr::core::rect<irr::s32>(x1, y1, x2, y2), 0, -1);
  bouton->setImage(this->_driver->getTexture(image.c_str()));
  return (bouton);
}

void			Menu::displayButtonsMenu1()
{
  this->_resizable = (this->_screenSize.Width / 2);
  this->_bnewgame = createButton(this->_resizable - 140,
				 this->_resizable - 300,
				 this->_resizable + 140,
				 this->_resizable - 208,
				 "menu_textures/newgame.png");
  this->_bsave = createButton(this->_resizable - 140,
			      this->_resizable - 200,
			      this->_resizable + 140,
			      this->_resizable - 108,
			      "menu_textures/save.png");
  this->_bquit = createButton(this->_resizable - 140,
  			      this->_resizable - 100,
  			      this->_resizable + 140,
  			      this->_resizable - 8,
  			      "menu_textures/quit.png");
}

void			Menu::displayButtonsMenu2()
{
  this->_resizable = (this->_screenSize.Width / 2);
  this->_bsolo = createButton(this->_resizable - 140,
				 this->_resizable - 300,
				 this->_resizable + 140,
				 this->_resizable - 208,
				 "menu_textures/solo.png");
  this->_bmulti = createButton(this->_resizable - 140,
			      this->_resizable - 200,
			      this->_resizable + 140,
			      this->_resizable - 108,
			      "menu_textures/multi.png");
  this->_bquit = createButton(this->_resizable - 140,
  			      this->_resizable - 100,
  			      this->_resizable + 140,
  			      this->_resizable - 8,
  			      "menu_textures/quit.png");
}

void			Menu::resetWindow()
{
  if (this->_device->getVideoDriver()->getScreenSize() != this->_screenSize)
    {
      this->_screenSize = this->_device->getVideoDriver()->getScreenSize();
      if (this->_state == MENU1)
	{
	  _gui->clear();
	  this->displayButtonsMenu1();
	}
      else if (this->_state == MENU2)
	{
	  _gui->clear();
	  this->displayButtonsMenu2();
	}
    }
  else if (this->_state == MENU2)
    {
      _gui->clear();
      this->displayButtonsMenu2();
      _gui->drawAll();
    }
}

int			Menu::checkButton()
{
  if (this->_bsave->isPressed())
    {
      if (!_listb)
	{
	  std::cout << "Save button activated" << std::endl;
	  // irr::gui::IGUIListBox * listbox = _gui->addListBox(irr::core::rect<irr::s32>(800, 200, 1100, 600));
	  _gui->addFileOpenDialog(L"Please choose a file to load.", true, 0, -1, true);
	  // listbox->addItem();
	  _listb = false;
	}
    }
  else if (this->_bnewgame->isPressed())
    {
      this->_state = MENU2;
    }
  return (0);
}

void			Menu::drawAll()
{
  this->init();
  this->displayButtonsMenu1();
  this->_listb = false;
  while (this->_device->run())
    {
      this->resetWindow();
      if (this->_bquit->isPressed())
	{
	  this->_driver->endScene();
	  break;
	}
      if (this->_state == MENU1)
	checkButton();
      this->_driver->beginScene(true, true, 0);
      this->_driver->draw2DImage(this->_background,
  				 irr::core::position2d<irr::s32>(0, 0),
  				 irr::core::rect<irr::s32>(0, 0,
							   this->_screenSize.Width,
							   this->_screenSize.Height),
  				 0,
  				 irr::video::SColor (255,255,255,255),
  				 true);
      _gui->drawAll();
      this->_driver->endScene();
    }
}

void			Menu::drawGui()
{
  _gui->drawAll();
}

void			Menu::clearGui()
{
  _gui->clear();
}

void			Menu::setSkinTransparency(irr::s32 alpha, irr::gui::IGUISkin * skin)
{
  for (irr::s32 i=0; i<irr::gui::EGDC_COUNT ; ++i)
    {
      irr::video::SColor col = skin->getColor((irr::gui::EGUI_DEFAULT_COLOR)i);
      col.setAlpha(alpha);
      skin->setColor((irr::gui::EGUI_DEFAULT_COLOR)i, col);
    }
}

int			main()
{
  Menu			aff;

  aff.drawAll();
}
