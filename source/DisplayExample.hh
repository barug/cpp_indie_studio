


class			Display
{
  std::map		map<unsigned int, irr::scene::IAnimatedMeshSceneNode>	_models;

public:
  int			createModel(unsigned int id,
				    ModelComponent model,
				    AnimationComponent animation,
				    PositionComponent position);
  int			updateModel(unsigned int id,
				    ModelComponent model,
				    AnimationComponent animation,
				    PositionComponent position);
  bool			getIfBlocked(unsigned int id,
				     SpeedComponent speed);
  std::vector<int>	getIfcolision(unsigned int id);
}

