#pragma once
#include "Init.h"
#include <stack>
#include <list>
using namespace std;

class GameMap;

class Dijkstra
{
	GameMap* m_gameMap;
	stack<point> m_path; // Path information with currentNode from startNode
	list<point> m_spt;
	bool m_bFound;
public:
	Dijkstra(GameMap* map) : m_gameMap(map), m_bFound(false) {}
	~Dijkstra() {}

	void choose(point& choicePos); // Min Extract
	bool findPath(point sp, point ds); // sp : startNode, ds targetNode
	void draw();
};

