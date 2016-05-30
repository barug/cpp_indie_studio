//
// ModelComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 16:51:48 2016 Barthelemy Gouby
// Last update Fri May 27 17:47:53 2016 Barthelemy Gouby
//

#ifndef _MODEL_COMPONENT_HH_
# define _MODEL_COMPONENT_HH_

# include <string>
# include <vector>
# include "Component.hh"
# include "irrlicht.h"

class				ModelComponent : public Component
{
public:
  enum ModelType : unsigned int
    {
      DEFAULT = 0,
      RUN = 1,
      NUMBER_OF_TYPES = 2
    };

  ModelComponent();
  ModelComponent(const std::string &defaultModel,
		 const std::string &texture,
		 const unsigned int &scale);
  ModelComponent(const std::string &defaultModel,
		 const unsigned int &scale);
  ~ModelComponent();
  void					setModel(const std::string &model, ModelComponent::ModelType);
  const std::string			&getModel(ModelComponent::ModelType type) const;
  void					setTexture(const std::string &texture);
  const std::string			&getTexture() const;
  void					setScale(const unsigned int &scale);
  const unsigned int			&getScale() const;
  const ModelComponent::ModelType	&getSelectedModel() const;
  void					setSelectedModel(ModelComponent::ModelType type);
  const std::vector<std::string>	&getModels() const;
  void					setModels(const std::vector<std::string> &models);
private:
  std::vector<std::string>		_models;
  std::string				_texture;
  unsigned int				_scale;
  ModelComponent::ModelType		_selectedModel;
};

#endif /* !MODEL_COMPONENT */
