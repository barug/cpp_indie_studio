//
// Display.hh for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Mon May  2 17:12:19 2016 Thomas Bogard
// Last update Fri May 13 11:23:10 2016 Barthelemy Gouby
//

#ifndef		__DISPLAY_HH__
# define	__DISPLAY_HH__

# include	<map>
# include	<vector>
# include	"irrlicht.h"
# include	"driverChoice.h"
# include	"Entity.hh"

#ifdef _MSC_VER
# pragma comment(lib, "Irrlicht.lib")
#endif

// limits
# define	lim_min_x	(-150)
# define	lim_max_x	(7190)
# define	lim_min_z	(5050)
# define	lim_max_z	(12300)

// speed
# define	speed		(25)

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

class		Display
{
public:
  class Event;

  enum Animation
    {
      STAND,
      RUN,
      DROP
    };
  Display();
  ~Display();
private:
  // private methods
  int		driverChoice();
  void		showFpsDriver(int last_tick);
  int		createDevice();
  void		createCamera();
  void		createGround();
  void		createSkybox();
  void		createImage(irr::gui::IGUIImage *img);

  // model
  irr::scene::IAnimatedMeshSceneNode *	createModel(const irr::io::path &model, const irr::io::path &texture,
						    const int &x, const int &y, const int &z,
						    const irr::u32& rotation,
						    const irr::u32& scale);

  irr::scene::IAnimatedMeshSceneNode *	updateModel(irr::scene::IAnimatedMeshSceneNode *model,
						    const irr::core::vector3df &model_position,
						    const int& x, const int& y, const int& z);

  // collision
  const bool	getIfBlocked(Entity *entity);

  const bool	collision(irr::scene::IAnimatedMeshSceneNode *mesh1,
			  irr::scene::IAnimatedMeshSceneNode *mesh2);
  const bool	collision(irr::scene::IAnimatedMeshSceneNode *mesh1,
			  irr::scene::IAnimatedMeshSceneNode *mesh2, const int& size);

  // event
  void		eventPlayer(const Event &receiver);

  // debug
  void		showPosCam();
  void		showPosModel();

  void		refreshScreen();

public:
  // public methods
  void		init();
  void		run();

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
  std::vector<irr::scene::IAnimatedMeshSceneNode *> _mv_models;

  // gui
  irr::gui::IGUIEnvironment		*_env;
  irr::gui::IGUISkin			*_skin;
  irr::gui::IGUIFont			*_font;
  irr::gui::IGUIImage			*_warning;
  irr::gui::IGUIImage			*_img;
  bool					_iswarning;

  // current animation
  Animation				_action;
  Animation				_mv_action;
  bool					_dropped;
  int					_timer_drop;

  // positions
  irr::core::vector3df			_model_position;
  irr::core::vector3df			_camera_position;
  irr::u32				_rotation;
  irr::u32				_prev_x;
  irr::u32				_prev_z;
  bool					_collision;


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

    virtual bool IsKeyDown(const irr::EKEY_CODE &keyCode) const
    {
      return this->_KeyIsDown[keyCode];
    }

  private:
    bool                          _KeyIsDown[irr::KEY_KEY_CODES_COUNT];
  };

};

# endif		// __DISPLAY_HH__
