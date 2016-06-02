# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/barthe_g/rendu/tek2/c++/cpp_indie_studio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/barthe_g/rendu/tek2/c++/cpp_indie_studio

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/CMakeFiles /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named cpp_indie_studio

# Build rule for target.
cpp_indie_studio: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 cpp_indie_studio
.PHONY : cpp_indie_studio

# fast build rule for target.
cpp_indie_studio/fast:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/build
.PHONY : cpp_indie_studio/fast

source/Display.o: source/Display.cpp.o

.PHONY : source/Display.o

# target to build an object file
source/Display.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/Display.cpp.o
.PHONY : source/Display.cpp.o

source/Display.i: source/Display.cpp.i

.PHONY : source/Display.i

# target to preprocess a source file
source/Display.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/Display.cpp.i
.PHONY : source/Display.cpp.i

source/Display.s: source/Display.cpp.s

.PHONY : source/Display.s

# target to generate assembly for a file
source/Display.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/Display.cpp.s
.PHONY : source/Display.cpp.s

source/Engine.o: source/Engine.cpp.o

.PHONY : source/Engine.o

# target to build an object file
source/Engine.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/Engine.cpp.o
.PHONY : source/Engine.cpp.o

source/Engine.i: source/Engine.cpp.i

.PHONY : source/Engine.i

# target to preprocess a source file
source/Engine.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/Engine.cpp.i
.PHONY : source/Engine.cpp.i

source/Engine.s: source/Engine.cpp.s

.PHONY : source/Engine.s

# target to generate assembly for a file
source/Engine.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/Engine.cpp.s
.PHONY : source/Engine.cpp.s

source/Entity.o: source/Entity.cpp.o

.PHONY : source/Entity.o

# target to build an object file
source/Entity.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/Entity.cpp.o
.PHONY : source/Entity.cpp.o

source/Entity.i: source/Entity.cpp.i

.PHONY : source/Entity.i

# target to preprocess a source file
source/Entity.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/Entity.cpp.i
.PHONY : source/Entity.cpp.i

source/Entity.s: source/Entity.cpp.s

.PHONY : source/Entity.s

# target to generate assembly for a file
source/Entity.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/Entity.cpp.s
.PHONY : source/Entity.cpp.s

source/EntityFactory.o: source/EntityFactory.cpp.o

.PHONY : source/EntityFactory.o

# target to build an object file
source/EntityFactory.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/EntityFactory.cpp.o
.PHONY : source/EntityFactory.cpp.o

source/EntityFactory.i: source/EntityFactory.cpp.i

.PHONY : source/EntityFactory.i

# target to preprocess a source file
source/EntityFactory.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/EntityFactory.cpp.i
.PHONY : source/EntityFactory.cpp.i

source/EntityFactory.s: source/EntityFactory.cpp.s

.PHONY : source/EntityFactory.s

# target to generate assembly for a file
source/EntityFactory.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/EntityFactory.cpp.s
.PHONY : source/EntityFactory.cpp.s

source/EntityManager.o: source/EntityManager.cpp.o

.PHONY : source/EntityManager.o

# target to build an object file
source/EntityManager.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/EntityManager.cpp.o
.PHONY : source/EntityManager.cpp.o

source/EntityManager.i: source/EntityManager.cpp.i

.PHONY : source/EntityManager.i

# target to preprocess a source file
source/EntityManager.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/EntityManager.cpp.i
.PHONY : source/EntityManager.cpp.i

source/EntityManager.s: source/EntityManager.cpp.s

.PHONY : source/EntityManager.s

# target to generate assembly for a file
source/EntityManager.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/EntityManager.cpp.s
.PHONY : source/EntityManager.cpp.s

source/EventListener.o: source/EventListener.cpp.o

.PHONY : source/EventListener.o

# target to build an object file
source/EventListener.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/EventListener.cpp.o
.PHONY : source/EventListener.cpp.o

source/EventListener.i: source/EventListener.cpp.i

.PHONY : source/EventListener.i

# target to preprocess a source file
source/EventListener.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/EventListener.cpp.i
.PHONY : source/EventListener.cpp.i

source/EventListener.s: source/EventListener.cpp.s

.PHONY : source/EventListener.s

# target to generate assembly for a file
source/EventListener.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/EventListener.cpp.s
.PHONY : source/EventListener.cpp.s

source/EventReceiver.o: source/EventReceiver.cpp.o

.PHONY : source/EventReceiver.o

# target to build an object file
source/EventReceiver.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/EventReceiver.cpp.o
.PHONY : source/EventReceiver.cpp.o

source/EventReceiver.i: source/EventReceiver.cpp.i

.PHONY : source/EventReceiver.i

# target to preprocess a source file
source/EventReceiver.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/EventReceiver.cpp.i
.PHONY : source/EventReceiver.cpp.i

source/EventReceiver.s: source/EventReceiver.cpp.s

.PHONY : source/EventReceiver.s

# target to generate assembly for a file
source/EventReceiver.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/EventReceiver.cpp.s
.PHONY : source/EventReceiver.cpp.s

source/Main.o: source/Main.cpp.o

.PHONY : source/Main.o

# target to build an object file
source/Main.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/Main.cpp.o
.PHONY : source/Main.cpp.o

source/Main.i: source/Main.cpp.i

.PHONY : source/Main.i

# target to preprocess a source file
source/Main.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/Main.cpp.i
.PHONY : source/Main.cpp.i

source/Main.s: source/Main.cpp.s

.PHONY : source/Main.s

# target to generate assembly for a file
source/Main.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/Main.cpp.s
.PHONY : source/Main.cpp.s

source/components/Component.o: source/components/Component.cpp.o

.PHONY : source/components/Component.o

# target to build an object file
source/components/Component.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/Component.cpp.o
.PHONY : source/components/Component.cpp.o

source/components/Component.i: source/components/Component.cpp.i

.PHONY : source/components/Component.i

# target to preprocess a source file
source/components/Component.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/Component.cpp.i
.PHONY : source/components/Component.cpp.i

source/components/Component.s: source/components/Component.cpp.s

.PHONY : source/components/Component.s

# target to generate assembly for a file
source/components/Component.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/Component.cpp.s
.PHONY : source/components/Component.cpp.s

source/components/ExplosionComponent.o: source/components/ExplosionComponent.cpp.o

.PHONY : source/components/ExplosionComponent.o

# target to build an object file
source/components/ExplosionComponent.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/ExplosionComponent.cpp.o
.PHONY : source/components/ExplosionComponent.cpp.o

source/components/ExplosionComponent.i: source/components/ExplosionComponent.cpp.i

.PHONY : source/components/ExplosionComponent.i

# target to preprocess a source file
source/components/ExplosionComponent.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/ExplosionComponent.cpp.i
.PHONY : source/components/ExplosionComponent.cpp.i

source/components/ExplosionComponent.s: source/components/ExplosionComponent.cpp.s

.PHONY : source/components/ExplosionComponent.s

# target to generate assembly for a file
source/components/ExplosionComponent.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/ExplosionComponent.cpp.s
.PHONY : source/components/ExplosionComponent.cpp.s

source/components/ExplosiveComponent.o: source/components/ExplosiveComponent.cpp.o

.PHONY : source/components/ExplosiveComponent.o

# target to build an object file
source/components/ExplosiveComponent.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/ExplosiveComponent.cpp.o
.PHONY : source/components/ExplosiveComponent.cpp.o

source/components/ExplosiveComponent.i: source/components/ExplosiveComponent.cpp.i

.PHONY : source/components/ExplosiveComponent.i

# target to preprocess a source file
source/components/ExplosiveComponent.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/ExplosiveComponent.cpp.i
.PHONY : source/components/ExplosiveComponent.cpp.i

source/components/ExplosiveComponent.s: source/components/ExplosiveComponent.cpp.s

.PHONY : source/components/ExplosiveComponent.s

# target to generate assembly for a file
source/components/ExplosiveComponent.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/ExplosiveComponent.cpp.s
.PHONY : source/components/ExplosiveComponent.cpp.s

source/components/HealthComponent.o: source/components/HealthComponent.cpp.o

.PHONY : source/components/HealthComponent.o

# target to build an object file
source/components/HealthComponent.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/HealthComponent.cpp.o
.PHONY : source/components/HealthComponent.cpp.o

source/components/HealthComponent.i: source/components/HealthComponent.cpp.i

.PHONY : source/components/HealthComponent.i

# target to preprocess a source file
source/components/HealthComponent.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/HealthComponent.cpp.i
.PHONY : source/components/HealthComponent.cpp.i

source/components/HealthComponent.s: source/components/HealthComponent.cpp.s

.PHONY : source/components/HealthComponent.s

# target to generate assembly for a file
source/components/HealthComponent.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/HealthComponent.cpp.s
.PHONY : source/components/HealthComponent.cpp.s

source/components/ModelComponent.o: source/components/ModelComponent.cpp.o

.PHONY : source/components/ModelComponent.o

# target to build an object file
source/components/ModelComponent.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/ModelComponent.cpp.o
.PHONY : source/components/ModelComponent.cpp.o

source/components/ModelComponent.i: source/components/ModelComponent.cpp.i

.PHONY : source/components/ModelComponent.i

# target to preprocess a source file
source/components/ModelComponent.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/ModelComponent.cpp.i
.PHONY : source/components/ModelComponent.cpp.i

source/components/ModelComponent.s: source/components/ModelComponent.cpp.s

.PHONY : source/components/ModelComponent.s

# target to generate assembly for a file
source/components/ModelComponent.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/ModelComponent.cpp.s
.PHONY : source/components/ModelComponent.cpp.s

source/components/PlayerInputComponent.o: source/components/PlayerInputComponent.cpp.o

.PHONY : source/components/PlayerInputComponent.o

# target to build an object file
source/components/PlayerInputComponent.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/PlayerInputComponent.cpp.o
.PHONY : source/components/PlayerInputComponent.cpp.o

source/components/PlayerInputComponent.i: source/components/PlayerInputComponent.cpp.i

.PHONY : source/components/PlayerInputComponent.i

# target to preprocess a source file
source/components/PlayerInputComponent.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/PlayerInputComponent.cpp.i
.PHONY : source/components/PlayerInputComponent.cpp.i

source/components/PlayerInputComponent.s: source/components/PlayerInputComponent.cpp.s

.PHONY : source/components/PlayerInputComponent.s

# target to generate assembly for a file
source/components/PlayerInputComponent.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/PlayerInputComponent.cpp.s
.PHONY : source/components/PlayerInputComponent.cpp.s

source/components/PositionComponent.o: source/components/PositionComponent.cpp.o

.PHONY : source/components/PositionComponent.o

# target to build an object file
source/components/PositionComponent.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/PositionComponent.cpp.o
.PHONY : source/components/PositionComponent.cpp.o

source/components/PositionComponent.i: source/components/PositionComponent.cpp.i

.PHONY : source/components/PositionComponent.i

# target to preprocess a source file
source/components/PositionComponent.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/PositionComponent.cpp.i
.PHONY : source/components/PositionComponent.cpp.i

source/components/PositionComponent.s: source/components/PositionComponent.cpp.s

.PHONY : source/components/PositionComponent.s

# target to generate assembly for a file
source/components/PositionComponent.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/PositionComponent.cpp.s
.PHONY : source/components/PositionComponent.cpp.s

source/components/PowerUpComponent.o: source/components/PowerUpComponent.cpp.o

.PHONY : source/components/PowerUpComponent.o

# target to build an object file
source/components/PowerUpComponent.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/PowerUpComponent.cpp.o
.PHONY : source/components/PowerUpComponent.cpp.o

source/components/PowerUpComponent.i: source/components/PowerUpComponent.cpp.i

.PHONY : source/components/PowerUpComponent.i

# target to preprocess a source file
source/components/PowerUpComponent.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/PowerUpComponent.cpp.i
.PHONY : source/components/PowerUpComponent.cpp.i

source/components/PowerUpComponent.s: source/components/PowerUpComponent.cpp.s

.PHONY : source/components/PowerUpComponent.s

# target to generate assembly for a file
source/components/PowerUpComponent.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/PowerUpComponent.cpp.s
.PHONY : source/components/PowerUpComponent.cpp.s

source/components/SolidityComponent.o: source/components/SolidityComponent.cpp.o

.PHONY : source/components/SolidityComponent.o

# target to build an object file
source/components/SolidityComponent.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/SolidityComponent.cpp.o
.PHONY : source/components/SolidityComponent.cpp.o

source/components/SolidityComponent.i: source/components/SolidityComponent.cpp.i

.PHONY : source/components/SolidityComponent.i

# target to preprocess a source file
source/components/SolidityComponent.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/SolidityComponent.cpp.i
.PHONY : source/components/SolidityComponent.cpp.i

source/components/SolidityComponent.s: source/components/SolidityComponent.cpp.s

.PHONY : source/components/SolidityComponent.s

# target to generate assembly for a file
source/components/SolidityComponent.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/SolidityComponent.cpp.s
.PHONY : source/components/SolidityComponent.cpp.s

source/components/SpeedComponent.o: source/components/SpeedComponent.cpp.o

.PHONY : source/components/SpeedComponent.o

# target to build an object file
source/components/SpeedComponent.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/SpeedComponent.cpp.o
.PHONY : source/components/SpeedComponent.cpp.o

source/components/SpeedComponent.i: source/components/SpeedComponent.cpp.i

.PHONY : source/components/SpeedComponent.i

# target to preprocess a source file
source/components/SpeedComponent.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/SpeedComponent.cpp.i
.PHONY : source/components/SpeedComponent.cpp.i

source/components/SpeedComponent.s: source/components/SpeedComponent.cpp.s

.PHONY : source/components/SpeedComponent.s

# target to generate assembly for a file
source/components/SpeedComponent.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/components/SpeedComponent.cpp.s
.PHONY : source/components/SpeedComponent.cpp.s

source/systems/ExplosionSystem.o: source/systems/ExplosionSystem.cpp.o

.PHONY : source/systems/ExplosionSystem.o

# target to build an object file
source/systems/ExplosionSystem.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/ExplosionSystem.cpp.o
.PHONY : source/systems/ExplosionSystem.cpp.o

source/systems/ExplosionSystem.i: source/systems/ExplosionSystem.cpp.i

.PHONY : source/systems/ExplosionSystem.i

# target to preprocess a source file
source/systems/ExplosionSystem.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/ExplosionSystem.cpp.i
.PHONY : source/systems/ExplosionSystem.cpp.i

source/systems/ExplosionSystem.s: source/systems/ExplosionSystem.cpp.s

.PHONY : source/systems/ExplosionSystem.s

# target to generate assembly for a file
source/systems/ExplosionSystem.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/ExplosionSystem.cpp.s
.PHONY : source/systems/ExplosionSystem.cpp.s

source/systems/ExplosiveSystem.o: source/systems/ExplosiveSystem.cpp.o

.PHONY : source/systems/ExplosiveSystem.o

# target to build an object file
source/systems/ExplosiveSystem.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/ExplosiveSystem.cpp.o
.PHONY : source/systems/ExplosiveSystem.cpp.o

source/systems/ExplosiveSystem.i: source/systems/ExplosiveSystem.cpp.i

.PHONY : source/systems/ExplosiveSystem.i

# target to preprocess a source file
source/systems/ExplosiveSystem.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/ExplosiveSystem.cpp.i
.PHONY : source/systems/ExplosiveSystem.cpp.i

source/systems/ExplosiveSystem.s: source/systems/ExplosiveSystem.cpp.s

.PHONY : source/systems/ExplosiveSystem.s

# target to generate assembly for a file
source/systems/ExplosiveSystem.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/ExplosiveSystem.cpp.s
.PHONY : source/systems/ExplosiveSystem.cpp.s

source/systems/guiSystem.o: source/systems/guiSystem.cpp.o

.PHONY : source/systems/guiSystem.o

# target to build an object file
source/systems/guiSystem.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/guiSystem.cpp.o
.PHONY : source/systems/guiSystem.cpp.o

source/systems/guiSystem.i: source/systems/guiSystem.cpp.i

.PHONY : source/systems/guiSystem.i

# target to preprocess a source file
source/systems/guiSystem.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/guiSystem.cpp.i
.PHONY : source/systems/guiSystem.cpp.i

source/systems/guiSystem.s: source/systems/guiSystem.cpp.s

.PHONY : source/systems/guiSystem.s

# target to generate assembly for a file
source/systems/guiSystem.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/guiSystem.cpp.s
.PHONY : source/systems/guiSystem.cpp.s

source/systems/healthSystem.o: source/systems/healthSystem.cpp.o

.PHONY : source/systems/healthSystem.o

# target to build an object file
source/systems/healthSystem.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/healthSystem.cpp.o
.PHONY : source/systems/healthSystem.cpp.o

source/systems/healthSystem.i: source/systems/healthSystem.cpp.i

.PHONY : source/systems/healthSystem.i

# target to preprocess a source file
source/systems/healthSystem.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/healthSystem.cpp.i
.PHONY : source/systems/healthSystem.cpp.i

source/systems/healthSystem.s: source/systems/healthSystem.cpp.s

.PHONY : source/systems/healthSystem.s

# target to generate assembly for a file
source/systems/healthSystem.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/healthSystem.cpp.s
.PHONY : source/systems/healthSystem.cpp.s

source/systems/movementSystem.o: source/systems/movementSystem.cpp.o

.PHONY : source/systems/movementSystem.o

# target to build an object file
source/systems/movementSystem.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/movementSystem.cpp.o
.PHONY : source/systems/movementSystem.cpp.o

source/systems/movementSystem.i: source/systems/movementSystem.cpp.i

.PHONY : source/systems/movementSystem.i

# target to preprocess a source file
source/systems/movementSystem.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/movementSystem.cpp.i
.PHONY : source/systems/movementSystem.cpp.i

source/systems/movementSystem.s: source/systems/movementSystem.cpp.s

.PHONY : source/systems/movementSystem.s

# target to generate assembly for a file
source/systems/movementSystem.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/movementSystem.cpp.s
.PHONY : source/systems/movementSystem.cpp.s

source/systems/playerInputSystem.o: source/systems/playerInputSystem.cpp.o

.PHONY : source/systems/playerInputSystem.o

# target to build an object file
source/systems/playerInputSystem.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/playerInputSystem.cpp.o
.PHONY : source/systems/playerInputSystem.cpp.o

source/systems/playerInputSystem.i: source/systems/playerInputSystem.cpp.i

.PHONY : source/systems/playerInputSystem.i

# target to preprocess a source file
source/systems/playerInputSystem.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/playerInputSystem.cpp.i
.PHONY : source/systems/playerInputSystem.cpp.i

source/systems/playerInputSystem.s: source/systems/playerInputSystem.cpp.s

.PHONY : source/systems/playerInputSystem.s

# target to generate assembly for a file
source/systems/playerInputSystem.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/playerInputSystem.cpp.s
.PHONY : source/systems/playerInputSystem.cpp.s

source/systems/powerUpSystem.o: source/systems/powerUpSystem.cpp.o

.PHONY : source/systems/powerUpSystem.o

# target to build an object file
source/systems/powerUpSystem.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/powerUpSystem.cpp.o
.PHONY : source/systems/powerUpSystem.cpp.o

source/systems/powerUpSystem.i: source/systems/powerUpSystem.cpp.i

.PHONY : source/systems/powerUpSystem.i

# target to preprocess a source file
source/systems/powerUpSystem.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/powerUpSystem.cpp.i
.PHONY : source/systems/powerUpSystem.cpp.i

source/systems/powerUpSystem.s: source/systems/powerUpSystem.cpp.s

.PHONY : source/systems/powerUpSystem.s

# target to generate assembly for a file
source/systems/powerUpSystem.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_indie_studio.dir/build.make CMakeFiles/cpp_indie_studio.dir/source/systems/powerUpSystem.cpp.s
.PHONY : source/systems/powerUpSystem.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... cpp_indie_studio"
	@echo "... source/Display.o"
	@echo "... source/Display.i"
	@echo "... source/Display.s"
	@echo "... source/Engine.o"
	@echo "... source/Engine.i"
	@echo "... source/Engine.s"
	@echo "... source/Entity.o"
	@echo "... source/Entity.i"
	@echo "... source/Entity.s"
	@echo "... source/EntityFactory.o"
	@echo "... source/EntityFactory.i"
	@echo "... source/EntityFactory.s"
	@echo "... source/EntityManager.o"
	@echo "... source/EntityManager.i"
	@echo "... source/EntityManager.s"
	@echo "... source/EventListener.o"
	@echo "... source/EventListener.i"
	@echo "... source/EventListener.s"
	@echo "... source/EventReceiver.o"
	@echo "... source/EventReceiver.i"
	@echo "... source/EventReceiver.s"
	@echo "... source/Main.o"
	@echo "... source/Main.i"
	@echo "... source/Main.s"
	@echo "... source/components/Component.o"
	@echo "... source/components/Component.i"
	@echo "... source/components/Component.s"
	@echo "... source/components/ExplosionComponent.o"
	@echo "... source/components/ExplosionComponent.i"
	@echo "... source/components/ExplosionComponent.s"
	@echo "... source/components/ExplosiveComponent.o"
	@echo "... source/components/ExplosiveComponent.i"
	@echo "... source/components/ExplosiveComponent.s"
	@echo "... source/components/HealthComponent.o"
	@echo "... source/components/HealthComponent.i"
	@echo "... source/components/HealthComponent.s"
	@echo "... source/components/ModelComponent.o"
	@echo "... source/components/ModelComponent.i"
	@echo "... source/components/ModelComponent.s"
	@echo "... source/components/PlayerInputComponent.o"
	@echo "... source/components/PlayerInputComponent.i"
	@echo "... source/components/PlayerInputComponent.s"
	@echo "... source/components/PositionComponent.o"
	@echo "... source/components/PositionComponent.i"
	@echo "... source/components/PositionComponent.s"
	@echo "... source/components/PowerUpComponent.o"
	@echo "... source/components/PowerUpComponent.i"
	@echo "... source/components/PowerUpComponent.s"
	@echo "... source/components/SolidityComponent.o"
	@echo "... source/components/SolidityComponent.i"
	@echo "... source/components/SolidityComponent.s"
	@echo "... source/components/SpeedComponent.o"
	@echo "... source/components/SpeedComponent.i"
	@echo "... source/components/SpeedComponent.s"
	@echo "... source/systems/ExplosionSystem.o"
	@echo "... source/systems/ExplosionSystem.i"
	@echo "... source/systems/ExplosionSystem.s"
	@echo "... source/systems/ExplosiveSystem.o"
	@echo "... source/systems/ExplosiveSystem.i"
	@echo "... source/systems/ExplosiveSystem.s"
	@echo "... source/systems/guiSystem.o"
	@echo "... source/systems/guiSystem.i"
	@echo "... source/systems/guiSystem.s"
	@echo "... source/systems/healthSystem.o"
	@echo "... source/systems/healthSystem.i"
	@echo "... source/systems/healthSystem.s"
	@echo "... source/systems/movementSystem.o"
	@echo "... source/systems/movementSystem.i"
	@echo "... source/systems/movementSystem.s"
	@echo "... source/systems/playerInputSystem.o"
	@echo "... source/systems/playerInputSystem.i"
	@echo "... source/systems/playerInputSystem.s"
	@echo "... source/systems/powerUpSystem.o"
	@echo "... source/systems/powerUpSystem.i"
	@echo "... source/systems/powerUpSystem.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

