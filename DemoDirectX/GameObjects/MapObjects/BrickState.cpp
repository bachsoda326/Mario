#include "BrickState.h"


BrickState::BrickState(BrickData *brickData)
{
	this->mBrickData = brickData;
}

BrickState::BrickState()
{

}

BrickState::~BrickState()
{
}

void BrickState::Update(float dt)
{

}

void BrickState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{

}