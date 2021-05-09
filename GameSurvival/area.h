#pragma once
#include "player.h"
#include "enemy.h"
class area
{
	char** shoot;
	player p;
	enemy* e;
	char** map;
	int sizex;
	int sizey;
	int cameraviewx1;
	int cameraviewx2;
public:
	area();
	~area();
	void OutPut();
	player& GetPlayer();
	enemy* GetEnemy();
	char** GetShoot();
	void SetShoot(int i, int j, char user);
	void Worldgeneration();
	char** GetMap();
	void SetSizex(const int user);
	void SetSizey(const int user);
	int GetSizey();
	int GetSizex();
	int GetCameraViewBegin();
	int GetCameraViewEnd();
	void SetCameraViewBegin(const int user);
	void SetCameraViewEnd(const int user);
};

