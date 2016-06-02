//
// Audio.cpp for indie studio
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Thu Jun  2 16:05:59 2016 Thomas Bogard
// Last update Thu Jun  2 17:28:35 2016 Thomas Bogard
//

# include "Audio.hh"
# include <iostream>

Audio::Audio()
{
}

Audio::~Audio()
{
}

void		Audio::makeSong(const std::string &file)
{
  if (!this->_buffer.loadFromFile(file))
    {
      std::cerr << "impossible to load " << file << std::endl;
      exit(EXIT_FAILURE);
    }
  this->_sound.setBuffer(_buffer);
  this->_sound.play();
}

void		Audio::makeMusic(const std::string &file)
{
  if (!this->_music.openFromFile(file))
    {
      std::cerr << "impossible to load " << file << std::endl;
      exit(EXIT_FAILURE);
    }
  this->_music.play();
}

void		Audio::musicPlay()
{
  this->_music.play();
}

void		Audio::musicPause()
{
  this->_music.pause();
}

void		Audio::musicStop()
{
  this->_music.stop();
}

void		Audio::musicSetVolume(const unsigned int &volume)
{
  this->_music.setVolume(volume);
}

void		Audio::musicSetLoop(const bool isloop)
{
  this->_music.setLoop(isloop);
}

void		Audio::soundSetLoop(const bool isloop)
{
  this->_sound.setLoop(isloop);
}
