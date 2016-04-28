#include <irrlicht.h>
#include "driverChoice.h"

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif


class MyEventReceiver : public irr::IEventReceiver
{
public:
  // ctor
  MyEventReceiver(irr::scene::ISceneNode *terrain, irr::scene::ISceneNode *skybox, irr::scene::ISceneNode *skydome)
    : Terrain(terrain), Skybox(skybox), Skydome(skydome), showBox(true), showDebug(false)
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
  irr::scene::ISceneNode* Terrain;
  irr::scene::ISceneNode* Skybox;
  irr::scene::ISceneNode* Skydome;
  bool showBox;
  bool showDebug;
  bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
};

int		main()
{
  // ask user for driver
  irr::video::E_DRIVER_TYPE driverType = irr::driverChoiceConsole();
  if (driverType==irr::video::EDT_COUNT)
    return 1;
  // create device with full flexibility over creation parameters
  // you can add more parameters if desired, check irr::SIrrlichtCreationParameters
  irr::SIrrlichtCreationParameters params;
  params.DriverType=driverType;
  params.WindowSize=irr::core::dimension2d<irr::u32>(1200, 800);
  irr::IrrlichtDevice* device = createDeviceEx(params);
  if (!device)
    return 1;

  irr::video::IVideoDriver* driver = device->getVideoDriver();
  irr::scene::ISceneManager* smgr = device->getSceneManager();
  irr::gui::IGUIEnvironment* env = device->getGUIEnvironment();
  driver->setTextureCreationFlag(irr::video::ETCF_ALWAYS_32_BIT, true);

  // create msg into a rect
  env->getSkin()->setFont(env->getFont("./media/fontlucida.png"));
  env->addStaticText(L"Welcom to ZOMBIE ON THE MOON",
  		     irr::core::rect<irr::s32>(10,421,250,475), true, true, 0, -1, true);

  // add camera
  irr::scene::ICameraSceneNode* camera =
    smgr->addCameraSceneNodeFPS(0,100.0f,1.2f);

  camera->setPosition(irr::core::vector3df(2700*2,500*2,3000*2));
  camera->setTarget(irr::core::vector3df(2397*2,343*2,2200*2));
  camera->setFarValue(42000.0f);

  // disable mouse cursor
  device->getCursorControl()->setVisible(false);

  // add terrain scene node
  irr::scene::ITerrainSceneNode* terrain =
    smgr->addTerrainSceneNode(
  			      "./media/wall.bmp",
  			      // "./media/terrain-heightmap.bmp",
  			      0,					// parent node
  			      -1,					// node id
  			      irr::core::vector3df(0.f, 0.f, 0.f),	// position
  			      irr::core::vector3df(0.f, 0.f, 0.f),	// rotation
  			      irr::core::vector3df(40.f, 4.4f, 40.f),	// scale
  			      irr::video::SColor (255, 255, 255, 255),	// vertexColor
  			      5,					// maxLOD
  			      irr::scene::ETPS_17,			// patchSize
  			      4						// smoothFactor
  			      );
  terrain->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  terrain->setMaterialTexture(0, driver->getTexture("./media/wall.bmp"));
  // terrain->setMaterialTexture(0, driver->getTexture("./media/terrain-texture.jpg"));
  terrain->setMaterialTexture(1, driver->getTexture("./media/detailmap3.jpg"));
  terrain->setMaterialType(irr::video::EMT_DETAIL_MAP);
  terrain->scaleTexture(1.0f, 20.0f);

  // create triangle selector for the terrain
  irr::scene::ITriangleSelector* selector
    = smgr->createTerrainTriangleSelector(terrain, 0);
  terrain->setTriangleSelector(selector);

  // // create collision response animator and attach it to the camera
  // irr::scene::ISceneNodeAnimator* anim =
  //   smgr->createCollisionResponseAnimator(selector, camera, irr::core::vector3df(60,100,60),
  // 					  irr::core::vector3df(0,0,0),
  // 					  irr::core::vector3df(0,50,0));
  // camera->addAnimator(anim);
  // anim->drop();


  // caracter
  irr::scene::ISceneNodeAnimator* collision_character =
    smgr->createCollisionResponseAnimator(selector, camera, irr::core::vector3df(10,10,10),
  					  irr::core::vector3df(0,0,0),
  					  irr::core::vector3df(0,0,0));
  irr::scene::ISceneNode *node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("media/Archattack.md2"));
  node->setPosition(irr::core::vector3df(2700*2,355*2,2600*2));
  node->setMaterialTexture(0, driver->getTexture("./media/archattackpain1.png"));
  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);

  node->addAnimator(collision_character);
  collision_character->drop();

  selector->drop();

  /*
    If you need access to the terrain data you can also do this directly via the following code fragment.
  */
  irr::scene::CDynamicMeshBuffer* buffer =
    new irr::scene::CDynamicMeshBuffer(irr::video::EVT_2TCOORDS, irr::video::EIT_16BIT);
  terrain->getMeshBufferForLOD(*buffer, 0);
  irr::video::S3DVertex2TCoords* data =
    (irr::video::S3DVertex2TCoords*)buffer->getVertexBuffer().getData();
  // Work on data or get the IndexBuffer with a similar call.
  buffer->drop(); // When done drop the buffer again.


  // create skybox and skydome
  driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
  irr::scene::ISceneNode* skybox =
    smgr->addSkyBoxSceneNode(driver->getTexture("./media/planet.jpg"), // up
			     driver->getTexture("./media/space.jpg"),  // down
			     driver->getTexture("./media/space.jpg"),  // left
			     driver->getTexture("./media/space.jpg"),  // right
			     driver->getTexture("./media/space.jpg"),  // ft
			     driver->getTexture("./media/space.jpg")); // bk
  irr::scene::ISceneNode* skydome =
    smgr->addSkyDomeSceneNode(driver->getTexture("./media/skydome.jpg"), 16, 8, 0.95f, 2.0f);
  driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);



  // create event receiver
  MyEventReceiver receiver(terrain, skybox, skydome);
  device->setEventReceiver(&receiver);
  int		lastFPS = -1;
  irr::u32	then = device->getTimer()->getTime();
  const irr::f32 MOVEMENT_SPEED = 300.f;

  while(device->run())
    if (device->isWindowActive())
      {

        const irr::u32 now = device->getTimer()->getTime();
        const irr::f32 frameDeltaTime = (irr::f32)(now - then) / 1000.f;
        then = now;
	camera->setPosition(irr::core::vector3df(node->getAbsolutePosition().X - 300,
						 node->getAbsolutePosition().Y + 200,
						 node->getAbsolutePosition().Z));
	camera->setTarget(irr::core::vector3df(node->getAbsolutePosition().X + 300,
					       node->getAbsolutePosition().Y - 200,
					       node->getAbsolutePosition().Z));
	// gestion des events
	irr::core::vector3df nodePosition = node->getPosition();
	if (receiver.IsKeyDown(irr::KEY_KEY_W))
	  nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
	else if (receiver.IsKeyDown(irr::KEY_KEY_S))
	  nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
	if (receiver.IsKeyDown(irr::KEY_KEY_A))
	  nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
	else if (receiver.IsKeyDown(irr::KEY_KEY_D))
	  nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
	if (receiver.IsKeyDown(irr::KEY_ESCAPE))
	  exit(0);
	node->setPosition(nodePosition);

	driver->beginScene(true, true, 0 );
	smgr->drawAll();
	env->drawAll();
	driver->endScene();
	// display frames per second in window title

	int fps = driver->getFPS();
	if (lastFPS != fps)
	  {
	    irr::core::stringw str = L"Bomberman - [driver : ";
	    str += driver->getName();
	    str += " FPS:";
	    str += fps;
	    str += " Height: ";
	    str += terrain->getHeight(camera->getAbsolutePosition().X,
				      camera->getAbsolutePosition().Z);
	    str += "]";
	    device->setWindowCaption(str.c_str());
	    lastFPS = fps;
	  }
      }
  device->drop();
  return 0;
}
