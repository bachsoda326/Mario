#include "EnemyState.h"

EnemyState::EnemyState(EnemyData *enemyData)
{
	this->mEnemyData = enemyData;
}

EnemyState::EnemyState()
{

}

EnemyState::~EnemyState()
{

}

void EnemyState::Update(float dt)
{

}

void EnemyState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{

}

