//
// Display.hh for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Mon May  2 17:12:19 2016 Thomas Bogard
// Last update Sun May 22 04:06:45 2016 Thomas Bogard
//

#ifndef		__DISPLAY_HH__
# define	__DISPLAY_HH__

# include	<map>
# include	<vector>
# include	"irrlicht.h"
# include	"driverChoice.h"
# include	"Entity.hh"
# include	"EventReceiver.hh"
# include	"EventListener.hh"
# include	"Resources.hh"

# include	"./components/AnimationComponent.hh"
# include	"./components/ModelComponent.hh"
# include	"./components/PositionComponent.hh"
# include	"./components/SpeedComponent.hh"
# include	"./components/SolidityComponent.hh"

#ifdef _MSC_VER
# pragma comment(lib, "Irrlicht.lib")
#endif

class		Display
{
public:
  Display();
  ~Display();
  int		init();
  int		refreshScreen();
  int		closeDisplay();
  const bool	windowIsActive() const;
  int		createModel(Entity *entity);
  int		updateModelAnimation(const unsigned int &id, const unsigned int &rotation,
				     const unsigned int &posX, const unsigned int &oldX,
				     const unsigned int &posY, const unsigned int &oldY);
  int		updateModelPosition(const unsigned int &id, const unsigned int &rotation,
				    const unsigned int &x, const unsigned int &y);
  const bool	collision(const unsigned int &firstId, const unsigned int &secondId);
  // event listener
  void				createEventListener(unsigned int id,
						    std::vector<irr::EKEY_CODE> keys);
  std::vector<irr::EKEY_CODE>	*getKeysDownForId(unsigned int id);

  // against error
  void		puterr(const char * const err)
  {
    std::cerr << err << std::endl;
    exit(EXIT_FAILURE);
  }

  void		puterr(const char * const err, const char * const geterr)
  {
    std::cerr << err << geterr << std::endl;
    exit(EXIT_FAILURE);
  }

  enum Animation
    {
      NONE = 0,
      STAND,
      RUN,
      DROP
    };

protected:
  // video and device
  irr::IrrlichtDevice			*_device;
  irr::video::IVideoDriver		*_driver;
  irr::video::E_DRIVER_TYPE		_driverType;

  // scene
  irr::scene::ICameraSceneNode		*_camera;
  irr::scene::ISceneManager		*_smgr;
  irr::scene::ISceneNode		*_ground;
  irr::scene::ISceneNode		*_skybox;
  irr::scene::IAnimatedMeshSceneNode	*_model;
  std::map<unsigned int, irr::scene::IAnimatedMeshSceneNode *>	_models;
  std::map<unsigned int, Animation>	_animation;

  // positions
  irr::core::vector3df			_model_position;
  irr::core::vector3df			_camera_position;

  //Event receiver
  EventReceiver				_receiver;
  std::map<unsigned int, EventListener *> _listeners;

  // gui
  irr::gui::IGUIEnvironment		*_env;

private:
  int		driverChoice();
  void		showFpsDriver(int last_tick);
  int		initDevice();
  void		initCamera();
  void		initGround();
  void		initSkybox();
  const bool	collision(irr::scene::IAnimatedMeshSceneNode *mesh1,
			  irr::scene::IAnimatedMeshSceneNode *mesh2);
  const bool	collision(irr::scene::IAnimatedMeshSceneNode *mesh1,
			  irr::scene::IAnimatedMeshSceneNode *mesh2, const int& size);
  void		showPosCam();

};

#endif		// __DISPLAY_HH__
