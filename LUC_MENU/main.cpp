#include <iostream>
#include "irrlicht.h"
#include "IGUIImage.h"

enum
  {
    GUI_ID_QUIT_BUTTON = 101,
    GUI_ID_NEW_WINDOW_BUTTON,
    GUI_ID_FILE_OPEN_BUTTON
  }; 

int main(void)
{
 
  irr::IrrlichtDevice* device = irr::createDevice(irr::video::EDT_OPENGL,
  						  irr::core::dimension2d<irr::u32>(1200,800), 32);

  device->setResizable(true);
  irr::video::IVideoDriver* driver = device->getVideoDriver ();
  irr::scene::ISceneManager *sceneManager = device->getSceneManager ();
 
  irr::video::ITexture *image = driver->getTexture ("textures/space.jpg");  // chargement de la texture
  irr::gui::IGUIEnvironment *gui = device->getGUIEnvironment();
 
  irr::core::dimension2d<irr::u32> ss;

  ss = device->getVideoDriver()->getScreenSize();
  irr::gui::IGUIButton *bouton_quit;
  
  ss = device->getVideoDriver()->getScreenSize();
  int middleOfScreen = ss.Width / 2;
  int left = middleOfScreen-64;
  int leftmid = middleOfScreen-32;
  int right = middleOfScreen+64;
  int rightmid = middleOfScreen+32;
  bouton_quit = gui->addButton(irr::core::rect<irr::s32>(left,leftmid,right,rightmid), 0, -1);
  bouton_quit->setImage(driver->getTexture("textures/exit2.png"));

  while(device->run ())                                             // la boucle de rendu
    {
      if (device->getVideoDriver()->getScreenSize() != ss)
	{
	  gui->clear();	  
	  ss = device->getVideoDriver()->getScreenSize();
	  middleOfScreen = ss.Width / 2;
	  left = middleOfScreen-64;
	  leftmid = middleOfScreen-32;
	  right = middleOfScreen+64;
	  rightmid = middleOfScreen+32;
	  bouton_quit = gui->addButton(irr::core::rect<irr::s32>(left,leftmid,right,rightmid), 0, -1);
	  bouton_quit->setImage(driver->getTexture("textures/exit2.png"));
	}
      driver->beginScene(true, true,
      			 irr::video::SColor (0,120,120,120));
      driver->draw2DImage(image,                                    // dessin de l'image
      			  irr::core::position2d<irr::s32>(0,0),
      			  irr::core::rect<irr::s32>(0,0, ss.Width, ss.Height),
      			  0,
      			  irr::video::SColor (255,255,255,255),
      			  true);
      gui->drawAll();
      driver->endScene ();
      if (bouton_quit->isPressed() == true) 
	{
	  gui->clear();
	  device->drop ();
	  return (0);
	}
            
    }
 
  device->drop ();
  return 0;
}
