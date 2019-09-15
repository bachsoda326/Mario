#pragma once

#include "EnemyData.h"
#include"../Entity.h"
#include "../../GameComponents/GameCollision.h"
#include <map>

class EnemyState
{
public:
	enum StateName
	{
		Running,
		Die
	};

	~EnemyState();

	virtual void Update(float dt);

	//side va cham voi enemy
	virtual void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	virtual StateName GetState() = 0;

protected:
	EnemyState(EnemyData *enemyData);
	EnemyState();

	EnemyData *mEnemyData;
};