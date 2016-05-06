//
// Display.hh for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Mon May  2 17:12:19 2016 Thomas Bogard
// Last update Fri May  6 03:30:14 2016 Thomas Bogard
//

#ifndef		__DISPLAY_HH__
# define	__DISPLAY_HH__

# include	<map>
# include	<vector>
# include	<irrlicht.h>
# include	<driverChoice.h>

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

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


class		Display
{
public:
  class Event;
  enum Action
    {
      STAND,
      RUN,
      DROP
    };

  Display();
  ~Display();

  // methods
  int		driverChoice();
  void		showFpsDriver(int last_tick);
  int		createDevice();
  void		createCamera();
  void		createGround();
  void		createSkybox();

  irr::scene::IAnimatedMeshSceneNode*	createModel(const irr::io::path &model, const irr::io::path &texture,
						    const int &x, const int &y, const int &z,
						    const irr::u32& rotation,
						    const irr::u32& scale);

  void		updateModel(irr::scene::IAnimatedMeshSceneNode *model,
			    const irr::core::vector3df &model_position);
  void		eventPlayer(Event receiver);
  void		init();
  void		launch();
  bool		collision(irr::scene::IAnimatedMeshSceneNode *mesh1,
			  irr::scene::IAnimatedMeshSceneNode *mesh2);

  // debug
  void		showPosCam();
  // against error
  void		puterr(const char * const err)
  {
    std::cerr << err << std::endl;
    exit(EXIT_FAILURE);
  }

protected:
  // scene
  irr::IrrlichtDevice			*m_device;
  irr::video::E_DRIVER_TYPE		driverType;
  irr::video::IVideoDriver		*m_driver;
  irr::scene::ICameraSceneNode		*m_camera;
  irr::scene::ISceneManager		*m_smgr;

  // models
  irr::scene::ISceneNode		*m_ground;
  irr::scene::ISceneNode		*m_skybox;
  irr::scene::IAnimatedMeshSceneNode	*m_model;
  std::vector<irr::scene::IAnimatedMeshSceneNode *> mv_models;
  Action				m_action;

  // positions
  irr::core::vector3df			m_model_position;
  irr::core::vector3df			m_camera_position;
public:

  // class for multiple event with keyboard
  class		Event : public irr::IEventReceiver
  {
  public:
    Event()
    {
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
    bool                          KeyIsDown[irr::KEY_KEY_CODES_COUNT];
  };

};

# endif		// __DISPLAY_HH__
