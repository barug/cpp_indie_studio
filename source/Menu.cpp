//
// Menu.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Thu Jun  2 14:44:36 2016 Barthelemy Gouby
// Last update Sun Jun  5 16:51:48 2016 Thomas Bogard
//

#include "Menu.hh"

Menu::Menu()
  : _menuContext(BASE),
    _isSet(false)
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
		      32, false, true, false, &_receiver);
  this->_device->setResizable(true);
  this->_driver = this->_device->getVideoDriver();
  this->_sceneManager = this->_device->getSceneManager();
  this->_background = this->_driver->getTexture("textures/menu/background.png");
  this->_gui = this->_device->getGUIEnvironment();
  this->_screenSize = this->_device->getVideoDriver()->getScreenSize();
}

void			Menu::initButtons()
{
  unsigned int		heightMiddle = this->_screenSize.Height / 2;
  unsigned int		widthMiddle = this->_screenSize.Width / 2;


  if (this->_fileDialogOpen)
    this->_fileDialog = this->_gui->addFileOpenDialog(L"Please choose a file to load.",
						      true, 0, -1, true);
  this->_first =
    this->_gui->addButton(irr::core::rect<irr::s32>(widthMiddle - BUTTON_WIDTH / 2,
						    heightMiddle - (2 * BUTTON_SPACING + 2 * BUTTON_HEIGHT),
						    widthMiddle + BUTTON_WIDTH / 2,
						    heightMiddle - (2 * BUTTON_SPACING + BUTTON_HEIGHT)),
			  0,-1);
  this->_second =
    this->_gui->addButton(irr::core::rect<irr::s32>(widthMiddle - BUTTON_WIDTH / 2,
						    heightMiddle - (BUTTON_SPACING + BUTTON_HEIGHT),
						    widthMiddle + BUTTON_WIDTH / 2,
						    heightMiddle - BUTTON_SPACING),
			  0,-1);
  this->_third =
    this->_gui->addButton(irr::core::rect<irr::s32>(widthMiddle - BUTTON_WIDTH / 2,
						    heightMiddle + BUTTON_SPACING,
						    widthMiddle + BUTTON_WIDTH / 2,
						    heightMiddle + (BUTTON_SPACING + BUTTON_HEIGHT)),
			  0,-1);
  this->_fourth =
    this->_gui->addButton(irr::core::rect<irr::s32>(widthMiddle - BUTTON_WIDTH / 2,
						    heightMiddle + (2 * BUTTON_SPACING + BUTTON_HEIGHT),
						    widthMiddle + BUTTON_WIDTH / 2,
						    heightMiddle + (2 * BUTTON_SPACING + 2 * BUTTON_HEIGHT)),
			  0, -1);
  irr::gui::IGUIImage *img_music =
    this->_gui->addImage(irr::core::rect<irr::s32>(widthMiddle - SCROLL_WIDTH / 2,
						   heightMiddle + (4 * SCROLL_SPACING + SCROLL_HEIGHT) + 100,
						   widthMiddle + SCROLL_WIDTH / 2,
						   heightMiddle + (4 * SCROLL_SPACING + 2 * SCROLL_HEIGHT) + 100));
  img_music->setImage(this->_driver->getTexture("./textures/music.png"));
  this->_scrollMusic =
    this->_gui->addScrollBar(true,
			     irr::core::rect<irr::s32>(widthMiddle - SCROLL_WIDTH / 2,
						       heightMiddle + (4 * SCROLL_SPACING + SCROLL_HEIGHT) + 100,
						       widthMiddle + SCROLL_WIDTH / 2,
						       heightMiddle + (4 * SCROLL_SPACING + 2 * SCROLL_HEIGHT) + 100),
			     0, -1);
  irr::gui::IGUIImage *img_sound =
    this->_gui->addImage(irr::core::rect<irr::s32>(widthMiddle - SCROLL_WIDTH / 2,
						   heightMiddle + (8 * SCROLL_SPACING + SCROLL_HEIGHT) + 100,
						   widthMiddle + SCROLL_WIDTH / 2,
						   heightMiddle + (8 * SCROLL_SPACING + 2 * SCROLL_HEIGHT) + 100));
  img_sound->setImage(this->_driver->getTexture("./textures/soundeffects.png"));
  this->_scrollSound =
    this->_gui->addScrollBar(true,
			     irr::core::rect<irr::s32>(widthMiddle - SCROLL_WIDTH / 2,
						       heightMiddle + (8 * SCROLL_SPACING + SCROLL_HEIGHT) + 100,
						       widthMiddle + SCROLL_WIDTH / 2,
						       heightMiddle + (8 * SCROLL_SPACING + 2 * SCROLL_HEIGHT) + 100),
			     0, -1);

  this->_scrollMusic->setMax(100);
  this->_scrollSound->setMax(100);
  this->_scrollMusic->setPos(50);
  this->_scrollSound->setPos(100);
  this->setSkinTransparency(50, this->_gui->getSkin());
  this->_first->setImage(this->_driver->getTexture("textures/menu/newgame.png"));
  this->_second->setImage(this->_driver->getTexture("textures/menu/load.png"));
  this->_third->setImage(this->_driver->getTexture("textures/menu/back.png"));
  this->_fourth->setImage(this->_driver->getTexture("textures/menu/quit.png"));
}

void			Menu::doButtonsActions()
{
  unsigned int		heightMiddle = this->_screenSize.Height / 2;
  unsigned int		widthMiddle = this->_screenSize.Width / 2;

  this->_engine.setVolumeMusic(this->_scrollMusic->getPos());
  this->_engine.setVolumeSound(this->_scrollSound->getPos());

  switch (this->_menuContext)
    {
    case BASE:
      if (!this->_isSet)
	{
	  this->_first->setImage(this->_driver->getTexture("textures/menu/newgame.png"));
	  this->_second->setImage(this->_driver->getTexture("textures/menu/load.png"));
	  this->_third->setImage(this->_driver->getTexture("textures/menu/back.png"));
	  this->_fourth->setImage(this->_driver->getTexture("textures/menu/quit.png"));
	  this->_isSet = true;
	}
      if (this->_first->isPressed())
	{
	  this->_menuContext = NEWGAME;
	  this->_isSet = false;
	}
      else if (this->_second->isPressed())
	{
	  // this->_engine.loadSave("./save_file", &this->_receiver, this->_device);
	  // this->_engine.gameLoop();
	}
      else if (this->_third->isPressed())
	{
	  std::cout << "back to game" << std::endl;
	}
      else if (this->_fourth->isPressed())
	this->_menuIsOn = false;
      break;

    case NEWGAME:
      if (!this->_isSet)
	{
	  this->_first->setImage(this->_driver->getTexture("textures/menu/solo.png"));
	  this->_second->setImage(this->_driver->getTexture("textures/menu/multi.png"));
	  this->_third->setImage(this->_driver->getTexture("textures/menu/back.png"));
	  this->_fourth->setImage(this->_driver->getTexture("textures/menu/quit.png"));
	  this->_isSet = true;
	}
      if (this->_first->isPressed())
	{
	  this->_engine.removeEntities();
	  this->_engine.initGame(this->_device, &(this->_receiver), Engine::SOLO);
	  this->_engine.gameLoop();
	  this->_menuContext = IN_GAME;
	  std::cout << "solo mode" << std::endl;
	}
      else if (this->_second->isPressed())
	{
	  std::cout << "multi player mode" << std::endl;
	  this->_menuContext = MULTI;
	  this->_isSet = false;
	}
      else if (this->_third->isPressed())
	{
	  this->_menuContext = BASE;
	  this->_isSet = false;
	}
      else if (this->_fourth->isPressed())
	this->_menuIsOn = false;
      break;

    case MULTI:
      if (!this->_isSet)
	{
	  this->_first->setImage(this->_driver->getTexture("textures/menu/versus.png"));
	  this->_second->setImage(this->_driver->getTexture("textures/menu/vsai.png"));
	  this->_third->setImage(this->_driver->getTexture("textures/menu/back.png"));
	  this->_fourth->setImage(this->_driver->getTexture("textures/menu/quit.png"));
	  this->_isSet = true;
	}
      if (this->_first->isPressed())
	{
	  this->_engine.initGame(this->_device, &(this->_receiver), Engine::VERSUS);
	  this->_engine.gameLoop();
	  this->_menuContext = IN_GAME;
	  std::cout << "versus mode" << std::endl;
	}
      else if (this->_second->isPressed())
	{
	  this->_engine.initGame(this->_device, &(this->_receiver), Engine::COOP);
	  this->_engine.gameLoop();
	  this->_menuContext = IN_GAME;
	  std::cout << "vsai mode" << std::endl;
	}
      else if (this->_third->isPressed())
	{
	  this->_menuContext = NEWGAME;
	  this->_isSet = false;
	}
      else if (this->_fourth->isPressed())
	this->_menuIsOn = false;
      break;

    case IN_GAME:
      if (!this->_isSet)
	{
	  this->_first->setImage(this->_driver->getTexture("textures/menu/newgame.png"));
	  this->_second->setImage(this->_driver->getTexture("textures/menu/save.png"));
	  this->_third->setImage(this->_driver->getTexture("textures/menu/back.png"));
	  this->_fourth->setImage(this->_driver->getTexture("textures/menu/quit.png"));
	  this->_isSet = true;
	}
      if (this->_first->isPressed())
	{
	  this->_menuContext = NEWGAME;
	  this->_isSet = false;
	}
      else if (this->_second->isPressed())
	{
	  this->_engine.saveGame("./save_file");
	}
      else if (this->_third->isPressed())
	{
	  this->_engine.gameLoop();
	  std::cout << "back to game" << std::endl;
	}
      else if (this->_fourth->isPressed())
	this->_menuIsOn = false;
      break;
    }
}

void			Menu::drawMenu()
{
  this->_driver->beginScene(true, true, 0);
  if (this->_menuContext == IN_GAME)
    this->_sceneManager->drawAll();
  else
    this->_driver->draw2DImage(this->_background,
  			       irr::core::position2d<irr::s32>(0, 0),
  			       irr::core::rect<irr::s32>(0, 0,
  							 this->_screenSize.Width,
  							 this->_screenSize.Height),
  			       0,
  			       irr::video::SColor (255,255,255,255),
  			       true);
  this->_gui->drawAll();
  this->_driver->endScene();
}

void			Menu::startMenu()
{
  this->init();
  this->_fileDialogOpen = false;
  this->_fileIsSelected = false;
  this->_textIsEntered = false;
  this->initButtons();
  this->_menuIsOn = true;
  while (this->_device->run() && this->_menuIsOn)
    {
      if (this->_device->getVideoDriver()->getScreenSize() != this->_screenSize)
	{
	  this->_screenSize = this->_device->getVideoDriver()->getScreenSize();
	  this->_gui->clear();
	  this->initButtons();
	}
      this->doButtonsActions();
      this->drawMenu();
    }
}

void			Menu::setSkinTransparency(irr::s32 alpha, irr::gui::IGUISkin * skin)
{
  for (irr::s32 i=0; i<irr::gui::EGDC_COUNT ; ++i)
    {
      irr::video::SColor col(alpha, 255, 255, 255);
      skin->setColor((irr::gui::EGUI_DEFAULT_COLOR)i, col);
    }
}
