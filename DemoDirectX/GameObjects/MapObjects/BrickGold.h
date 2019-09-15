#pragma once
#include "Brick.h"

class BrickGold : public Brick
{
public:
    BrickGold(D3DXVECTOR3 position);
    ~BrickGold();

    virtual const char* FileName();
    virtual int TotalFrame();
    virtual int Row();
    virtual int Column();
    virtual float SecondPerFrame();
	int DisplayResourceNAMessageBox()
	{
		int msgboxID = MessageBox(
			NULL,
			(LPCWSTR)L"Gold",
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
};