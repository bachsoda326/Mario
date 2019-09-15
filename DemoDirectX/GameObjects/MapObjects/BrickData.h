#pragma once
class BrickState;
class Brick;

class BrickData
{
public:
	BrickData();
	~BrickData();

	Brick      *brick;
	BrickState *state;

protected:

};

