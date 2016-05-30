#include "menu.hh"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void			Menu::init()
{
  this->_device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1200,800), 32);
  this->_device->setResizable(true);
  this->_driver = this->_device->getVideoDriver();
  this->_sceneManager = this->_device->getSceneManager();
  this->_background = this->_driver->getTexture ("textures/background.png");
  this->_gui = this->_device->getGUIEnvironment();
  this->_screenSize = this->_device->getVideoDriver()->getScreenSize();
}

irr::gui::IGUIButton*	Menu::createButon(const int &x1, const int &y1,
					  const int &x2, const int &y2,
					  const std::string &image)
{
  irr::gui::IGUIButton *bouton =
    this->_gui->addButton(irr::core::rect<irr::s32>(x1, y1, x2, y2), 0, -1);
  bouton->setImage(this->_driver->getTexture(image.c_str()));
  return (bouton);
}

void			Menu::displayButtons()
{
  // quit button
  this->_resizable = (this->_screenSize.Width / 2);
  this->_bquit = createButon(this->_resizable - 164,
			     this->_resizable - 116,
			     this->_resizable + 164,
			     this->_resizable - 52,
			     "textures/exit.png");
  // save button
  this->_bsave = createButon(this->_resizable - 164,
			     this->_resizable - 32,
			     this->_resizable + 164,
			     this->_resizable + 32,
			     "menutext/save.png");
  // play button
  this->_bplay = createButon(this->_resizable - 164,
			     this->_resizable + 52,
			     this->_resizable + 164,
			     this->_resizable + 116,
			     "menutext/play.png");
}

void			Menu::resetWindow()
{
  if (this->_device->getVideoDriver()->getScreenSize() != this->_screenSize)
    {
      this->_gui->clear();
      this->_screenSize = this->_device->getVideoDriver()->getScreenSize();
      this->displayButtons();
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
      std::cout << "Save button activated" << std::endl;
    }
  return (0);
}

void			Menu::drawAll()
{
  this->init();
  this->displayButtons();
  while (this->_device->run())
    {
      this->resetWindow();
      if (checkButton() == -1)
       	break;
      this->_driver->beginScene(true, true,
  				irr::video::SColor (0,120,120,120));
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
}

void			Menu::drawGui()
{
  this->_gui->drawAll();
}

void			Menu::clearGui()
{
  this->_gui->clear();
}

int			main()
{
  Menu			aff;

  aff.drawAll();
}
