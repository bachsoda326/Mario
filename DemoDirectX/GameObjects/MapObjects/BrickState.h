#pragma once
#include "BrickData.h"
#include "../Entity.h"
#include "../../GameComponents/GameCollision.h"
#include <map>

class BrickState
{
public:
	enum StateName
	{
		Default,
		Broken,
	};

	~BrickState();

	virtual void Update(float dt);

	//side va cham voi brick
	virtual void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	virtual StateName GetState() = 0;

protected:
	BrickState(BrickData *brickData);
	BrickState();

	BrickData *mBrickData;
};

