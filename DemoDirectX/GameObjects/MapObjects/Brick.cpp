#include "Brick.h"
#include "../../GameComponents/GameGlobal.h"
#include "../../GameComponents/GameCollision.h"


Brick::Brick()
{
	mAnimationBreak = new Animation("Resources/brokenbrick.png", 1, 1, 1, 1.0f);
}

Brick::~Brick()
{

}

bool Brick::init(D3DXVECTOR3 position)
{
	mCurrentAnimation = new Animation(FileName(), TotalFrame(), Row(), Column(), SecondPerFrame());
	
    SetPosition(position);

	Entity::SetWidth(mCurrentAnimation->GetWidth());
	Entity::SetHeight(mCurrentAnimation->GetHeight());

    return true;
}

void Brick::OnSetPosition(D3DXVECTOR3 pos)
{
	mCurrentAnimation->SetPosition(pos);
}

void Brick::Update(float dt)
{
	mCurrentAnimation->Update(dt);
}

void Brick::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	mCurrentAnimation->SetPosition(this->GetPosition());
	mCurrentAnimation->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);
}

void Brick::Draw(D3DXVECTOR2 transform)
{
	mCurrentAnimation->SetPosition(this->GetPosition());
	mCurrentAnimation->Draw(D3DXVECTOR2(transform));
}

void Brick::SetAnimation()
{
	mCurrentAnimation = mAnimationBreak;
}

void Brick::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{
	switch (side)
	{
	case Entity::Left:
	{		
		break;
	}

	case Entity::Right:
	{		
		break;
	}

	case Entity::TopRight: case Entity::TopLeft: case Entity::Top:
	{		
		break;
	}

	case Entity::BottomRight: case Entity::BottomLeft: case Entity::Bottom:
	{
		//mCurrentAnimation = mAnimationBreak;
	}

	default:
		break;
	}
}