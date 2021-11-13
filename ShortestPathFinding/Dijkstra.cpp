#include "Dijkstra.h"
#include "GameMap.h"
#include <iostream>
using namespace std;

void Dijkstra::choose(point& choicePos)
{
	int min = INT_MAX; // least cost
	int width = m_gameMap->getWidth();
	int height = m_gameMap->getHeight();

	// Node Infomation to choose
	point curPos;
	list<point>::reverse_iterator sptPos;
	for (sptPos = m_spt.rbegin(); sptPos != m_spt.rend(); sptPos++)
	{
		for (int ty = -1; ty <= 1; ty++)
		{
			for (int tx = -1; tx <= 1; tx++)
			{
				curPos.x = sptPos->x + tx;
				curPos.y = sptPos->y + ty;
				if (curPos.x < 0 || curPos.x > width - 1 || curPos.y < 0 || curPos.y > height - 1 || (tx == 0 && ty == 0))
				{
					continue;
				}
				if (m_gameMap->getMapVal(curPos.x, curPos.y) < min && m_gameMap->getVisitInfo(curPos.x, curPos.y) == false)
				{
					min = m_gameMap->getMapVal(curPos.x, curPos.y);
					choicePos = curPos;
				}
			}
		}
	}
}

bool Dijkstra::findPath(point sp, point ds)
{
	// initialization
	m_bFound = false;
	int width = m_gameMap->getWidth();
	int height = m_gameMap->getHeight();

	point** parent;
	parent = new point * [height];
	for (int i = 0; i < height; i++)
		parent[i] = new point[width];

	point choicePos;
	m_gameMap->setMapVal(sp.x, sp.y, 0);
	choicePos = sp;
	parent[sp.y][sp.x] = choicePos;
	m_spt.push_back(choicePos);

	for (int i = 0; i < width * height; i++)
	{
		// extract min
		m_gameMap->setVisitInfo(choicePos.x, choicePos.y, true);
		m_spt.push_back(choicePos);

		if (choicePos.x == ds.x && choicePos.y == ds.y) // find destination
		{
			m_bFound = true;
			break;
		}
		for (int ty = -1; ty <= 1; ty++)
		{
			for (int tx = -1; tx <= 1; tx++)
			{
				int nx = choicePos.x + tx;
				int ny = choicePos.y + ty;
				int dist;
				if (nx <0 || nx > width - 1 || ny < 0 || ny > height - 1)
					continue;
				// relaxation of an Edge Algoritm
				if (m_gameMap->getVisitInfo(nx, ny) == false)
				{
					dist = (tx == 0 || ty == 0) ? 10 : 14;
					if (m_gameMap->getMapVal(choicePos.x, choicePos.y) + dist < m_gameMap->getMapVal(nx, ny))
					{
						int val = m_gameMap->getMapVal(choicePos.x, choicePos.y) + dist;
						m_gameMap->setMapVal(nx, ny, val);
						parent[ny][nx] = choicePos;

					}
				}
			}
		}
		choose(choicePos);
	}

	// TargetNode from StartNode to Push in Stack
	if (m_bFound)
	{
		point curPos = ds;
		m_path.push(curPos);
		while (curPos.x != sp.x || curPos.y != sp.y)
		{
			curPos = parent[curPos.y][curPos.x];
			m_path.push(curPos);
		}
		return true;
	}
	return false;
}

void Dijkstra::draw()
{
	m_gameMap->draw();
	if (m_bFound)
	{
		point curPos;
		do
		{
			curPos = m_path.top();
			cout << "(" << curPos.x << "," << curPos.y << ")";
			m_path.pop();
			if (!m_path.empty())
				cout << " ==> ";
		} while (!m_path.empty());
		cout << endl;
	}
}
