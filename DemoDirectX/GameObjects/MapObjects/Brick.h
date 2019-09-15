#pragma once

#include "./../../GameComponents/Animation.h"
#include "../Entity.h"
#include "GameObject.h"
#include "BrickData.h"
#include "BrickState.h"

//vien gach
class Brick : public Entity
{
public:
    ~Brick();

    void Update(float dt);

    void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

    void Draw(D3DXVECTOR2 transform);

	virtual int DisplayResourceNAMessageBox()
	{
		int msgboxID = MessageBox(
			NULL,
			(LPCWSTR)L"Brick",
			(LPCWSTR)L"Account Details",
			MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
		);

		switch (msgboxID)
		{
		case IDCANCEL:
			// TODO: add code
			break;
		case IDTRYAGAIN:
			// TODO: add code
			break;
		case IDCONTINUE:
			// TODO: add code
			break;
		}

		return msgboxID;
	}	

	void OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side);

	void SetAnimation();

protected:
    Brick();

    bool init(D3DXVECTOR3 position);

    void OnSetPosition(D3DXVECTOR3 poks);

    virtual const char* FileName() = 0; // bat buoc phai override ham nay
    virtual int TotalFrame() = 0; //so frame cua animation
    virtual int Row() = 0; // so row cua resource hinh anh animation
    virtual int Column() = 0; // so cot cua resource hinh anh animation
    virtual float SecondPerFrame() = 0; //so giay de chuyen frame cua animation

	BrickData *mBrickData;

	Animation *mCurrentAnimation,
		      *mAnimationDefault,
		      *mAnimationBreak;
};
