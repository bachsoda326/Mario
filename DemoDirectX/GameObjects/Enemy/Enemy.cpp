#include "Enemy.h"
#include "EnemyRunningState.h"
#include "../../GameComponents/GameCollision.h"

Enemy::Enemy(D3DXVECTOR3 position)
{		
	mAnimationDie = new Animation("Resources/enemy/die.png", 1, 1, 1, 0);
	mAnimationRunning = new Animation("Resources/enemy/runningleft.png", 2, 1, 2, 0.4f);

	this->mEnemyData = new EnemyData();
	this->mEnemyData->enemy = this;
	
	this->SetState(new EnemyRunningState(this->mEnemyData));

	SetPosition(position);
}

Enemy::~Enemy()
{

}

void Enemy::Update(float dt)
{
	mCurrentAnimation->Update(dt);

	if (this->mEnemyData->state)
	{
		this->mEnemyData->state->Update(dt);
	}

	Entity::Update(dt);
}

void Enemy::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}

void Enemy::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	mCurrentAnimation->FlipVertical(mCurrentReverse);
	mCurrentAnimation->SetPosition(this->GetPosition());
	mCurrentAnimation->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);
}

void Enemy::Draw(D3DXVECTOR2 transform)
{
	mCurrentAnimation->FlipVertical(mCurrentReverse);
	mCurrentAnimation->SetPosition(this->GetPosition());
	mCurrentAnimation->Draw(D3DXVECTOR2(transform));
}

void Enemy::SetState(EnemyState *newState)
{
	delete this->mEnemyData->state;

	this->mEnemyData->state = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}

void Enemy::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{
	this->mEnemyData->state->OnCollision(impactor, side, data);
}

RECT Enemy::GetBound()
{	
	if (isBound)
	{
		bound.left = posX - width / 2;
		bound.right = posX + width / 2;
		bound.top = posY - height / 2;
		bound.bottom = posY + height / 2;
	}	

	return bound;
}

void Enemy::changeAnimation(EnemyState::StateName state)
{
	switch (state)
	{
	case EnemyState::Running:
		mCurrentAnimation = mAnimationRunning;
		break;

	case EnemyState::Die:
		mCurrentAnimation = mAnimationDie;
		break;

	default:
		break;
	}

	this->width = mCurrentAnimation->GetWidth();
	this->height = mCurrentAnimation->GetHeight();
}

Enemy::MoveDirection Enemy::getMoveDirection()
{
	if (this->vx > 0)
	{
		return MoveDirection::MoveToRight;
	}
	else if (this->vx < 0)
	{
		return MoveDirection::MoveToLeft;
	}

	return MoveDirection::None;
}

void Enemy::OnNoCollisionWithBottom()
{
	/*if (mCurrentState != EnemyState::Jumping && mCurrentState != EnemyState::Falling)
	{
		this->SetState(new PlayerFallingState(this->mPlayerData));
	}*/
}

EnemyState::StateName Enemy::getState()
{
	return mCurrentState;
}

