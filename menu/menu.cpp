#include "menu.hh"

Menu::Menu() : _state(BASE), _isSet(false)
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

void			Menu::initButtons()
{
  this->_resizable = (this->_screenSize.Width / 2);
  this->_first = _gui->addButton(irr::core::rect<irr::s32>(this->_resizable - 140,
							   this->_resizable - 300,
							   this->_resizable + 140,
							   this->_resizable - 208), 0, -1);
  this->_second = _gui->addButton(irr::core::rect<irr::s32>(this->_resizable - 140,
							    this->_resizable - 200,
							    this->_resizable + 140,
							    this->_resizable - 108), 0, -1);
  this->_third = _gui->addButton(irr::core::rect<irr::s32>(this->_resizable - 140,
							   this->_resizable - 100,
							   this->_resizable + 140,
							   this->_resizable - 8), 0, -1);
  this->_fourth = _gui->addButton(irr::core::rect<irr::s32>(this->_resizable - 140,
							    this->_resizable,
							    this->_resizable + 140,
							    this->_resizable + 92), 0, -1);
  this->_first->setImage(this->_driver->getTexture("menu_textures/newgame.png"));
  this->_second->setImage(this->_driver->getTexture("menu_textures/load.png"));
  this->_third->setImage(this->_driver->getTexture("menu_textures/back.png"));
  this->_fourth->setImage(this->_driver->getTexture("menu_textures/quit.png"));
}

int			Menu::resetWindow()
{
  if (this->_device->getVideoDriver()->getScreenSize() != this->_screenSize)
    {
      this->_screenSize = this->_device->getVideoDriver()->getScreenSize();
      _gui->clear();
      this->initButtons();
    }
  if (this->_state == BASE)
    {
      if (!this->_isSet)
	{
	  this->_first->setImage(this->_driver->getTexture("menu_textures/newgame.png"));
	  this->_second->setImage(this->_driver->getTexture("menu_textures/load.png"));
	  this->_isSet = true;
	}
      if (this->_first->isPressed())
	{
	  this->_state = NEWGAME;
	  this->_isSet = false;
	}
      else if (this->_second->isPressed())
	{
  	  if (!_listb)
  	    {
  	      // _gui->addFileOpenDialog(L"Please choose a file to load.", true, 0, -1, true);
  	      _gui->addFileOpenDialog(L"Please choose a file to load.", true, 0, 10);
  	      _listb = false;
  	    }
	}
      else if (this->_third->isPressed())
	{
	  std::cout << "back to game" << std::endl;
	}
      else if (this->_fourth->isPressed())
	return (-1);
    }
  else if (this->_state == NEWGAME)
    {
      if (!this->_isSet)
	{
	  this->_first->setImage(this->_driver->getTexture("menu_textures/solo.png"));
	  this->_second->setImage(this->_driver->getTexture("menu_textures/multi.png"));
	  this->_isSet = true;
	}
      if (this->_first->isPressed())
	{
	  std::cout << "solo mode" << std::endl;
	}
      else if (this->_second->isPressed())
	{
	  std::cout << "multi player mode" << std::endl;
	  this->_state = MULTI;
	  this->_isSet = false;
	}
      else if (this->_third->isPressed())
	{
	  this->_state = BASE;
	  this->_isSet = false;
	}
      else if (this->_fourth->isPressed())
	return (-1);
    }
  else if (this->_state == MULTI)
    {
      if (!this->_isSet)
	{
	  this->_first->setImage(this->_driver->getTexture("menu_textures/versus.png"));
	  this->_second->setImage(this->_driver->getTexture("menu_textures/vsai.png"));
	  this->_isSet = true;
	}
      if (this->_first->isPressed())
	{
	  std::cout << "versus mode" << std::endl;
	}
      else if (this->_second->isPressed())
	{
	  std::cout << "vsai mode" << std::endl;
	}
      else if (this->_third->isPressed())
	{
	  this->_state = NEWGAME;
	  this->_isSet = false;
	}
      else if (this->_fourth->isPressed())
	return (-1);
    }
  return (0);
}

void			Menu::drawAll()
{
  this->init();
  this->initButtons();
  this->_listb = false;
  while (this->_device->run())
    {
      this->_driver->beginScene(true, true, 0);
      if (this->resetWindow() == -1)
	break;
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
