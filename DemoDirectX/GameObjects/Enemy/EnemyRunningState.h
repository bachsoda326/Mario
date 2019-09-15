#pragma once
#include "Enemy.h"
#include "EnemyState.h"

class EnemyRunningState : public EnemyState
{
public:
	EnemyRunningState(EnemyData *enemyData);
	~EnemyRunningState();

	void OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data);

	virtual StateName GetState();

protected:
	float acceleratorX;
};
