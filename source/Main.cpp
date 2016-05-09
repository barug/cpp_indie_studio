#include <irrlicht.h>
#include "driverChoice.h"

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

enum Action
  {
    STAND,
    WALK,
    DROP
  };

class MyEventReceiver : public irr::IEventReceiver
{
public:

  // ctor
  MyEventReceiver(irr::scene::ISceneNode *terrain,
		  irr::scene::ISceneNode *skybox,
		  irr::scene::ISceneNode *skydome)
    : Terrain(terrain), Skybox(skybox), Skydome(skydome),
      showBox(true), showDebug(false)
  {
    Skybox->setVisible(showBox);
    Skydome->setVisible(!showBox);
    for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
      KeyIsDown[i] = false;
  }

  virtual bool OnEvent(const irr::SEvent& event)
  {
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
      KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    return false;
  }

  virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const
  {
    return KeyIsDown[keyCode];
  }

private:
  irr::scene::ISceneNode*	Terrain;
  irr::scene::ISceneNode*	Skybox;
  irr::scene::ISceneNode*	Skydome;
  bool				showBox;
  bool				showDebug;
  bool				KeyIsDown[irr::KEY_KEY_CODES_COUNT];
};


int		main(int ac, char **av)
{
  // get driver choice
  irr::video::E_DRIVER_TYPE driverType = irr::driverChoiceConsole();
  if (driverType == irr::video::EDT_COUNT)
    return 1;

  irr::SIrrlichtCreationParameters params;
  params.DriverType = driverType;
  params.WindowSize = irr::core::dimension2d<irr::u32>(1200, 800);

  irr::IrrlichtDevice* device = createDeviceEx(params);
  if (!device)
    return 1;

  irr::video::IVideoDriver* driver = device->getVideoDriver();
  irr::scene::ISceneManager* smgr = device->getSceneManager();
  driver->setTextureCreationFlag(irr::video::ETCF_ALWAYS_32_BIT, true);

  // disable mouse cursor
  device->getCursorControl()->setVisible(false);

  // add terrain scene node
  smgr->addCubeSceneNode();
  irr::scene::ISceneNode* terrain = smgr->addCubeSceneNode();
  terrain->setPosition(irr::core::vector3df(0, 400, 5200));
  terrain->setMaterialTexture(0, driver->getTexture("./textures/moon.jpg"));
  // terrain->setMaterialTexture(0, driver->getTexture("./textures/psy2.jpg"));
  terrain->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  terrain->setScale(irr::core::vector3df(500, 40, 500));

  // create a selector for collision
  // irr::scene::ITriangleSelector* selector
  //   = smgr->createTriangleSelector(smgr->getMesh(""), terrain);
  // terrain->setTriangleSelector(selector);

  // // create collision response animator and attach it to the camera
  // irr::scene::ISceneNodeAnimator* anim =
  //   smgr->createCollisionResponseAnimator(selector, camera, irr::core::vector3df(60,100,60),
  // 					  irr::core::vector3df(0,0,0),
  // 					  irr::core::vector3df(0,50,0));
  // camera->addAnimator(anim);
  // anim->drop();

  // bomberman for character
  irr::scene::IAnimatedMeshSceneNode *bomberman =
    smgr->addAnimatedMeshSceneNode(smgr->getMesh("./models/BOMBERSTAND.b3d"));
  bomberman->setMaterialTexture(0, driver->getTexture("./textures/bomberman_red.png"));
  bomberman->setPosition(irr::core::vector3df(-2000,600,5200));
  bomberman->setAnimationSpeed(40);
  bomberman->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  bomberman->setScale(irr::core::vector3df(200.f,200.f,200.f));
  bomberman->setRotation(irr::core::vector3df(0,270,0));

  irr::scene::IAnimatedMeshSceneNode *bomb =
    smgr->addAnimatedMeshSceneNode(smgr->getMesh("./models/BomB.obj"));
  bomb->setMaterialTexture(0, driver->getTexture("./textures/BomB.png"));
  bomb->setPosition(irr::core::vector3df(-1000,600,5200));
  bomb->setAnimationSpeed(40);
  bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  bomb->setScale(irr::core::vector3df(20.f,20.f,20.f));
  bomb->setRotation(irr::core::vector3df(0,270,0));

  // collision character
  // irr::scene::ISceneNodeAnimator* collision_character =
  //   smgr->createCollisionResponseAnimator(selector, node,
  // 					  irr::core::vector3df(10,10,10),
  // 					  irr::core::vector3df(0,0,0),
  // 					  irr::core::vector3df(0,0,0));
  // node->addAnimator(collision_character);
  // collision_character->drop();
  // selector->drop();

  // add camera
  irr::scene::ICameraSceneNode* camera =
    smgr->addCameraSceneNodeFPS(0,100.0f,1.2f);
  camera->setFarValue(42000.0f);

  // create skybox and skydome
  driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
  irr::scene::ISceneNode* skybox =
    smgr->addSkyBoxSceneNode(driver->getTexture("./textures/planet.jpg"), // up
			     driver->getTexture("./textures/space.jpg"),  // down
			     driver->getTexture("./textures/space.jpg"),  // left
			     driver->getTexture("./textures/space.jpg"),  // right
			     driver->getTexture("./textures/space.jpg"),  // ft
			     driver->getTexture("./textures/space.jpg")); // bk
  irr::scene::ISceneNode* skydome =
    smgr->addSkyDomeSceneNode(driver->getTexture("./textures/skydome.jpg"), 16, 8, 0.95f, 2.0f);
  driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);

  MyEventReceiver receiver(terrain, skybox, skydome);
  irr::u32	then = device->getTimer()->getTime();
  const irr::f32 speed = 1000.f;
  bool		dropped = false;
  int		timerDrop = 0;
  int		myRot = 360;
  int		prevPosX = 0;
  int		prevPosZ = 0;
  int		lastFPS = -1;
  Action	current = STAND;

  device->setEventReceiver(&receiver);
  while (device->run() && device)
    if (device->isWindowActive())
      {
	// timer
        const irr::u32 now = device->getTimer()->getTime();
        const irr::f32 currentFrame = (irr::f32)(now - then) / 1000.f;
        then = now;

	// current position
        int posX = bomberman->getAbsolutePosition().X;
	int posY = bomberman->getAbsolutePosition().Y;
	int posZ = bomberman->getAbsolutePosition().Z;
	// std::cout << pX << " && " << pY << " && " << pZ << std::endl;

	// get actual position
	irr::core::vector3df nodePosition = bomberman->getPosition();

	// 3rd person view
	camera->setPosition(irr::core::vector3df(posX, posY + 3000, posZ + 1500));
	// camera->setTarget(irr::core::vector3df(posX + 2000, posY-2000, posZ));

	if ((posX != prevPosX || posZ != prevPosZ) && (prevPosX && prevPosZ && current != WALK))
	  {
	    bomberman->remove();
	    bomberman = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./models/BOMBERRUN.b3d"));
	    bomberman->setMaterialTexture(0, driver->getTexture("./textures/bomberman_red.png"));
	    bomberman->setAnimationSpeed(50);
	    bomberman->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	    bomberman->setScale(irr::core::vector3df(200.f, 200.f, 200.f));
	    current = WALK;
	  }
	if (posX == prevPosX && posZ == prevPosZ && current != STAND)
	  {
	    bomberman->remove();
	    bomberman = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./models/BOMBERSTAND.b3d"));
	    bomberman->setMaterialTexture(0, driver->getTexture("./textures/bomberman_red.png"));
	    bomberman->setRotation(irr::core::vector3df(0, myRot, 0));
	    bomberman->setAnimationSpeed(40);
	    bomberman->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	    bomberman->setScale(irr::core::vector3df(200.f, 200.f, 200.f));
	    current = STAND;
	  }
	prevPosX = posX;
	prevPosZ = posZ;
	if (timerDrop < device->getTimer()->getTime() && dropped)
	  {
	    current = DROP;
	    timerDrop = 0;
	    dropped = false;
	  }
	if (receiver.IsKeyDown(irr::KEY_KEY_W))
	  {
	    myRot = 0;
	    bomberman->setRotation(irr::core::vector3df(0, myRot, 0));
	    nodePosition.Z -= speed * currentFrame;
	  }
	else if (receiver.IsKeyDown(irr::KEY_KEY_S))
	  {
	    myRot = 180;
	    bomberman->setRotation(irr::core::vector3df(0, myRot, 0));
	    nodePosition.Z += speed * currentFrame;
	  }
	else if (receiver.IsKeyDown(irr::KEY_KEY_A))
	  {
	    myRot = 270;
	    bomberman->setRotation(irr::core::vector3df(0, myRot, 0));
	    nodePosition.X += speed * currentFrame;
	  }
	else if (receiver.IsKeyDown(irr::KEY_KEY_D))
	  {
	    myRot = 90;
	    bomberman->setRotation(irr::core::vector3df(0, myRot, 0));
	    nodePosition.X -= speed * currentFrame;
	  }
	else if (receiver.IsKeyDown(irr::KEY_SPACE))
	  {
	    if (!dropped && current != DROP)
	      {
		bomberman->remove();
		timerDrop = device->getTimer()->getTime() + 700;
		bomberman = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./models/BOMBERDROP.b3d"));
		bomberman->setMaterialTexture(0, driver->getTexture("./textures/bomberman_black.png"));
		bomberman->setRotation(irr::core::vector3df(0, myRot, 0));
		bomberman->setAnimationSpeed(70);
		bomberman->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		bomberman->setScale(irr::core::vector3df(200.f, 200.f, 200.f));
		dropped = true;
	      }
	  }
	else if (receiver.IsKeyDown(irr::KEY_ESCAPE))
	  exit(0);
	bomberman->setPosition(nodePosition);
	driver->beginScene(true, true, 0);
	smgr->drawAll();
	driver->endScene();

	int fps = driver->getFPS();
	if (lastFPS != fps)
	  {
	    irr::core::stringw str = L"Bomberman - driver : [";
	    str += driver->getName();
	    str += "] FPS:[";
	    str += fps;
	    str += "]";
	    device->setWindowCaption(str.c_str());
	    lastFPS = fps;
	  }
      }
  device->drop();
  return 0;
}
