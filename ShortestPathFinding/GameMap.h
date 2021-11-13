#pragma once
// Tile Map
class GameMap
{
	int** m_map;
	bool** m_visitInfo;
	int m_width;
	int m_height;
public:
	GameMap(int w, int h) : m_width(w), m_height(h)
	{
		m_map = new int* [h];
		m_visitInfo = new bool* [h];
		for (int i = 0; i < h; i++)
		{
			m_map[i] = new int[w];
			m_visitInfo[i] = new bool[w];
		}

		initMap();
	}
	~GameMap() {}
	void initMap(); // Map initialization
	
	// getters
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	int getMapVal(int x, int y) { return m_map[y][x]; }
	bool getVisitInfo(int x, int y) { return m_visitInfo[y][x]; }

	// setters
	void setMapVal(int x, int y, int val) { m_map[y][x] = val; }
	void setVisitInfo(int x, int y, bool val) { m_visitInfo[y][x] = val; }

	// draw
	void draw();
};

