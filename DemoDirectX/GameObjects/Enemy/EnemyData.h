#pragma once
class EnemyState;
class Enemy;

class EnemyData
{
public:
	EnemyData();
	~EnemyData();

	Enemy *enemy;
	EnemyState *state;
};