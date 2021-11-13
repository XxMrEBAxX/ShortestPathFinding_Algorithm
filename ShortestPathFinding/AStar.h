#pragma once
#include "Init.h"
#include <stack>
#include <list>
using namespace std;

class GameMap;

class AStar
{
	GameMap* m_gameMap;
	stack<point> m_path; // Path information with currentNode from startNode
	list<point> m_spt;
	bool m_bFound;
public:
	AStar(GameMap* map) : m_gameMap(map), m_bFound(false) {}
	~AStar() {}

	void choose(point& choicePos, point ds); // Min Extract
	bool findPath(point sp, point ds); // sp : startNode, ds targetNode
	void draw();
};

