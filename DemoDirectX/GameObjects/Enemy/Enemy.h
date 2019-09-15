#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include "../Entity.h"
#include "../../GameComponents/Animation.h"
#include "../../GameComponents/GameGlobal.h"
#include "EnemyData.h"
#include "EnemyState.h"

class Enemy : public Entity
{
public:
	Enemy(D3DXVECTOR3 position);
	~Enemy();

	enum MoveDirection
	{
		MoveToLeft, //chay tu phai sang trai
		MoveToRight, //chay tu trai sang phai
		None
	};

	void Update(float dt);

	void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

	void Draw(D3DXVECTOR2 transform);

	void SetState(EnemyState *newState);

	void OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side);

	void OnNoCollisionWithBottom();

	MoveDirection getMoveDirection();

	RECT bound;

	RECT GetBound();

	EnemyState::StateName Enemy::getState();

	void SetReverse(bool flag);

protected:
	EnemyData *mEnemyData;

	Animation   *mCurrentAnimation,
		*mAnimationRunning,
		*mAnimationDie;

	void changeAnimation(EnemyState::StateName state);

	EnemyState::StateName mCurrentState;

	bool mCurrentReverse;
};