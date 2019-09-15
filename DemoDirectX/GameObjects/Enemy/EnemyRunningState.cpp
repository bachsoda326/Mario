#include "EnemyRunningState.h"

#include "../../GameComponents/GameCollision.h"
#include "../../GameDefines/GameDefine.h"

EnemyRunningState::EnemyRunningState(EnemyData *enemyData)
{
	this->mEnemyData = enemyData;

	acceleratorX = 25.0f;

	mEnemyData->enemy->SetReverse(false);

	mEnemyData->enemy->SetVx(-acceleratorX);
}

EnemyRunningState::~EnemyRunningState()
{

}

void EnemyRunningState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
    //lay phia va cham so voi enemy
    //GameCollision::SideCollisions side = GameCollision::getSideCollision(this->mPlayerData->enemy, data);

    switch (side)
    {
        case Entity::Left:
        {
            //va cham phia ben trai enemy
			if (this->mEnemyData->enemy->getMoveDirection() == Enemy::MoveToLeft)
			{
				this->mEnemyData->enemy->SetReverse(true);

				this->mEnemyData->enemy->SetVx(acceleratorX);

				//this->mEnemyData->enemy->AddPosition(data.RegionCollision.right - data.RegionCollision.left, 0);
			}

            return;
        }

        case Entity::Right: 
        {
            //va cham phia ben phai enemy
			if (this->mEnemyData->enemy->getMoveDirection() == Enemy::MoveToRight)
			{
				this->mEnemyData->enemy->SetReverse(false);

				this->mEnemyData->enemy->SetVx(-acceleratorX);

				//this->mEnemyData->enemy->AddPosition(-(data.RegionCollision.right - data.RegionCollision.left), 0);
			}			

            return;
        }

        case Entity::Top:
            break;

        case Entity::Bottom: case Entity::BottomLeft : case Entity::BottomRight:           
        {
			/*this->mEnemyData->enemy->AddPosition(0, -(data.RegionCollision.bottom - data.RegionCollision.top));

			this->mEnemyData->enemy->SetVy(0);

			return;*/
			break;
        }
    }
}

EnemyState::StateName EnemyRunningState::GetState()
{
	return EnemyState::Running;
}