#pragma once
#include "Scene.h"

class Scene_Play : public Scene
{
public:
	Scene_Play(GameEngine* engine);

	void update() override;
};

