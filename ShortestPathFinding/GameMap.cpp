#include "GameMap.h"

void GameMap::initMap()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			m_map[y][x] = 1000;
			m_visitInfo[y][x] = false;
		}
	}
}

#include <iostream>
using namespace std;
void GameMap::draw()
{
	cout << "==================================================" << endl;
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			if (m_map[y][x] == 1000)
				cout << "X\t";
			else
				cout << m_map[y][x] << "\t";
		}
		cout << endl;
	}
}
