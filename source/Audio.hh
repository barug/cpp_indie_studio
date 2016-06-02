//
// Audio.hh for indie studio
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Thu Jun  2 16:06:03 2016 Thomas Bogard
// Last update Thu Jun  2 18:43:24 2016 Barthelemy Gouby
//

#ifndef		__AUDIO_HH__
# define	__AUDIO_HH__

# include	<string>
# include	<SFML/Audio.hpp>

class		Audio
{
public:
  Audio();
  ~Audio();
  void		setSound(const std::string &file);
  void		setMusic(const std::string &file);

  // music
  void		musicPlay();
  void		musicPause();
  void		musicStop();
  void		musicSetVolume(const unsigned int &volume);
  void		musicSetLoop(const bool isloop);

  // song
  void		soundSetLoop(const bool isloop);

protected:
  sf::SoundBuffer	_buffer;
  sf::Sound		_sound;
  sf::Music		_music;
};

#endif		// __AUDIO_HH__
