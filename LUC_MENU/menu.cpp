#include "menu.hh"

menu::menu()
{
}

menu::~menu()
{
}

irr::gui::IGUIButton* menu::createButon(int left, int leftmid, int right, int rightmid, const char *img)
{
  irr::gui::IGUIButton *bouton;

  bouton = this->_gui->addButton(irr::core::rect<irr::s32>(left,leftmid,right,rightmid), 0, -1);
  bouton->setImage(this->_driver->getTexture(img));
  return (bouton);
}


void			menu::resetWindow()
{
  this->_gui->clear();
  
  this->_ss = this->_device->getVideoDriver()->getScreenSize();
  this->_middleOfScreen = this->_ss.Width / 2;
  this->_left = this->_middleOfScreen-164;
  this->_leftmid = this->_middleOfScreen-32;
  this->_right = this->_middleOfScreen+164;
  this->_rightmid = this->_middleOfScreen+32;
  this->_bouton_quit = createButon(this->_left,this->_leftmid,this->_right,this->_rightmid, "textures/exit.png");
}

void			menu::resize()
{
  if (this->_device->getVideoDriver()->getScreenSize() != this->_ss)
    resetWindow();
} 

int			menu::checkButon()
{
  if (this->_bouton_quit->isPressed() == true)
    {
      this->_driver->endScene ();
      return (-1);
    }
  return (0);
}

void			menu::drawGui()
{
  this->_gui->drawAll();
}

void			menu::init()
{
  this->_device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1200,800), 32);
  this->_device->setResizable(true);
  this->_driver = this->_device->getVideoDriver();
  this->_sceneManager = this->_device->getSceneManager();
  this->_image = this->_driver->getTexture ("textures/space.jpg");
  this->_gui = this->_device->getGUIEnvironment();
  this->_ss = this->_device->getVideoDriver()->getScreenSize();
 
  this->_middleOfScreen = this->_ss.Width / 2;
  this->_left = this->_middleOfScreen-164;
  this->_leftmid = this->_middleOfScreen-32;
  this->_right = this->_middleOfScreen+164;
  this->_rightmid = this->_middleOfScreen+32;
  this->_bouton_quit = createButon(this->_left,this->_leftmid,this->_right,this->_rightmid, "textures/exit.png");
}

void                  menu::drawAll()
{
  init();
  while(this->_device->run())
    {
      resize();
      if (checkButon() == -1)
       	break;
      this->_driver->beginScene(true, true,
  				irr::video::SColor (0,120,120,120));
      this->_driver->draw2DImage(this->_image,                                    // dessin de l'image                              
  				 irr::core::position2d<irr::s32>(0,0),
  				 irr::core::rect<irr::s32>(0,0, this->_ss.Width, this->_ss.Height),
  				 0,
  				 irr::video::SColor (255,255,255,255),
  				 true);
      drawGui();
      this->_driver->endScene();
    }
}

void		menu::clear()
{
  this->_gui->clear();
}

int	main()
{
  menu	aff;

  aff.drawAll();
}
