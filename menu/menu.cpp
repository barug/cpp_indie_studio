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
  this->_background = this->_driver->getTexture ("textures/background.png");
  _gui = this->_device->getGUIEnvironment();
  this->_screenSize = this->_device->getVideoDriver()->getScreenSize();
}

irr::gui::IGUIButton*	Menu::createButon(const int &x1, const int &y1,
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
  this->_bplay = createButon(this->_resizable - 164,
			     this->_resizable - 116,
			     this->_resizable + 164,
			     this->_resizable - 52,
			     "menutext/play.png");
  this->_bsave = createButon(this->_resizable - 164,
			     this->_resizable - 32,
			     this->_resizable + 164,
			     this->_resizable + 32,
			     "menutext/save.png");
  this->_bquit = createButon(this->_resizable - 164,
			     this->_resizable + 52,
			     this->_resizable + 164,
			     this->_resizable + 116,
			     "textures/exit.png");
}

void			Menu::displayButtonsMenu2()
{
  this->_resizable = (this->_screenSize.Width / 2);
  this->_bsolo = createButon(this->_resizable - 164,
			     this->_resizable - 116,
			     this->_resizable + 164,
			     this->_resizable - 52,
			     "menutext/play.png");
  this->_bmulti = createButon(this->_resizable - 164,
			     this->_resizable - 32,
			     this->_resizable + 164,
			     this->_resizable + 32,
			     "menutext/save.png");
}

void			Menu::resetWindow()
{
  if (this->_device->getVideoDriver()->getScreenSize() != this->_screenSize)
    {
      _gui->clear();
      this->_screenSize = this->_device->getVideoDriver()->getScreenSize();
      if (this->_state == MENU1)
	this->displayButtonsMenu1();
      else if (this->_state == MENU2)
      	this->displayButtonsMenu2();
    }
}

int			Menu::checkButton()
{
  if (this->_bquit->isPressed())
    {
      this->_driver->endScene();
      return (-1);
    }
  else if (this->_bsave->isPressed())
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
  else if (this->_bplay->isPressed())
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
      if (checkButton() == -1)
       	break;
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
