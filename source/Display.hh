//
// Display.hh for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Mon May  2 17:12:19 2016 Thomas Bogard
// Last update Tue May 17 17:57:27 2016 Thomas Bogard
//

#ifndef		__DISPLAY_HH__
# define	__DISPLAY_HH__

# include	<map>
# include	<vector>
# include	"irrlicht.h"
# include	"driverChoice.h"
# include	"Entity.hh"

# include	"./components/AnimationComponent.hh"
# include	"./components/ModelComponent.hh"
# include	"./components/PositionComponent.hh"

#ifdef _MSC_VER
# pragma comment(lib, "Irrlicht.lib")
#endif

// limits
# define	lim_min_x	(-150)
# define	lim_max_x	(7190)
# define	lim_min_z	(5050)
# define	lim_max_z	(12300)

// model3d
# define	M_RUN		"./models/BOMBERRUN.b3d"
# define	M_STAND		"./models/BOMBERSTAND.b3d"
# define	M_DROP		"./models/BOMBERDROP.b3d"

// textures
# define	T_BLACK		"./textures/bomberman_black.png"
# define	T_BLUE		"./textures/bomberman_blue.png"
# define	T_GREEN		"./textures/bomberman_green.png"
# define	T_LBLUE		"./textures/bomberman_lblue.png"
# define	T_ORANGE	"./textures/bomberman_orange.png"
# define	T_PINK		"./textures/bomberman_pink.png"
# define	T_PURPLE	"./textures/bomberman_purple.png"
# define	T_RED		"./textures/bomberman_red.png"
# define	T_WARNING	"./textures/warning.png"

enum Context
  {
    GAME = 0,
    MENU_ENABLE,
    MENU_DISABLE,
    GAMEOVER,
    RESTART
  };

enum Key
  {
    NONE = 0,
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_Z, KEY_W,
    KEY_S,
    KEY_D,
    KEY_Q, KEY_A,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_0,
    KEY_SPACE,
    KEY_ESCAPE
  };

class		Display
{
public:
  Display();
  ~Display();

  class Event;

  enum Animation
    {
      STAND = 0,
      RUN,
      DROP
    };


  void		setContext(const Context& context);
  Context	getContext() const;


  void		setKey(const Key& key);
  Key		getKey() const;

  irr::IrrlichtDevice	*getDevice() const;

protected:
  Animation	_animation;
  Context	_context;
  Key		_key;
  Key		_lastkey;
  Key		_actukey;

private:
  // private methods
  int		driverChoice();
  void		showFpsDriver(int last_tick);
  int		createDevice();
  void		createCamera();
  void		createGround();
  void		createSkybox();

  std::map<unsigned int, irr::scene::IAnimatedMeshSceneNode *> _mapmodel;


  // collision
  const bool	collision(irr::scene::IAnimatedMeshSceneNode *mesh1,
			  irr::scene::IAnimatedMeshSceneNode *mesh2);
  const bool	collision(irr::scene::IAnimatedMeshSceneNode *mesh1,
			  irr::scene::IAnimatedMeshSceneNode *mesh2, const int& size);

  // debug
  void		showPosCam();
  void		showPosModel();


public:
  // public methods
  int		init();
  int		refreshScreen();
  int		closeDisplay();
  void		eventPlayer(const Event &receiver);
  int		createModel(unsigned int id,
			    ModelComponent model,
			    AnimationComponent animation,
			    PositionComponent pos);
  int		updateModel(unsigned int id,
			    ModelComponent model,
			    AnimationComponent animation,
			    PositionComponent pos);
  const bool	getIfBlocked(Entity *entity);

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

protected:
  // video and device
  irr::IrrlichtDevice			*_device;
  irr::video::E_DRIVER_TYPE		_driverType;
  irr::video::IVideoDriver		*_driver;

  // scene
  irr::scene::ICameraSceneNode		*_camera;
  irr::scene::ISceneManager		*_smgr;
  irr::scene::ISceneNode		*_ground;
  irr::scene::ISceneNode		*_skybox;
  irr::scene::IAnimatedMeshSceneNode	*_model;

  // gui
  irr::gui::IGUIEnvironment		*_env;
  irr::gui::IGUISkin			*_skin;
  irr::gui::IGUIFont			*_font;
  irr::gui::IGUIImage			*_img;

  // current animation
  Animation				_action;
  bool					_dropped;
  int					_timer_drop;

  // positions
  irr::core::vector3df			_model_position;
  irr::core::vector3df			_camera_position;

public:
  // class for multiple event with keyboard
  class		Event : public irr::IEventReceiver
  {
  public:
    Event()
    {
      for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
	this->_KeyIsDown[i] = false;
    }

    virtual bool OnEvent(const irr::SEvent& event)
    {
      if (event.EventType == irr::EET_KEY_INPUT_EVENT)
	this->_KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
      return false;
    }

    virtual bool IsKeyUp(const irr::EKEY_CODE &keyCode) const
    {
      return this->_KeyIsDown[keyCode];
    }

    virtual bool IsKeyDown(const irr::EKEY_CODE &keyCode) const
    {
      return this->_KeyIsDown[keyCode];
    }

  private:
    bool                          _KeyIsUp[irr::KEY_KEY_CODES_COUNT];
    bool                          _KeyIsDown[irr::KEY_KEY_CODES_COUNT];
  };

};

# endif		// __DISPLAY_HH__
