#
# IndieStudio CMake configuration file
#
# Erwan Dupard
#
# /^'--'^\

cmake_minimum_required(VERSION 3.5)

project(IndieStudio)

add_executable(cpp_indie_studio
  source/Main.cpp				
  source/Engine.cpp				
  source/EntityManager.cpp			
  source/EntityFactory.cpp			
  source/Entity.cpp				
  source/components/Component.cpp		
  source/components/PositionComponent.cpp	
  source/components/SpeedComponent.cpp		
  source/components/ModelComponent.cpp		
  source/components/PlayerInputComponent.cpp	
  source/components/SolidityComponent.cpp	
  source/components/ExplosiveComponent.cpp	
  source/components/ExplosionComponent.cpp	
  source/components/HealthComponent.cpp	
  source/components/PowerUpComponent.cpp	
  source/systems/movementSystem.cpp		
  source/systems/playerInputSystem.cpp		
  source/systems/ExplosiveSystem.cpp		
  source/systems/ExplosionSystem.cpp		
  source/systems/powerUpSystem.cpp		
  source/systems/healthSystem.cpp		
  source/systems/guiSystem.cpp			
  source/Display.cpp				
  source/EventReceiver.cpp			
  source/EventListener.cpp			
  source/DisplayExample.hh
  source/EntityFactory.hh
  source/EventListener.hh
  source/Resources.hh
  source/Display.hh
  source/Entity.hh
  source/EventReceiver.hh
  source/Engine.hh
  source/EntityManager.hh
  source/Exemple.hh
)

FIND_PACKAGE(X11)
FIND_PACKAGE(GLUT)
FIND_PACKAGE(ZLIB) 

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(./include)
link_directories(./lib)

set(IRRLICHT_LIBRARIES
  -L/usr/X11R6/lib
  -L./lib
  -lIrrlicht
  -lGL
  -lGLU
  -lXext
  -lX11
  -lXxf86vm
)

target_link_libraries(
  cpp_indie_studio
  ${X11_LIBRARIES}
  ${GLUT_LIBRARIES}
  ${ZLIB_LIBRARIES}
  ${IRRLICHT_LIBRARIES}
)
