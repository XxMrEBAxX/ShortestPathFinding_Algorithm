#include <iostream>
#include "GameMap.h"
#include "Dijkstra.h"
#include "AStar.h"

int main()
{
    GameMap gameMap(10, 10);
    GameMap gameMap2(10, 10);
    Dijkstra spathD(&gameMap);
    AStar spathA(&gameMap2);

    point sp = { 0, 9 }; // startNode
    point dp = { 5, 2 }; // targetNode

    spathD.draw();

    bool bFound = spathD.findPath(sp, dp);
    spathD.draw();

    bool aFound = spathA.findPath(sp, dp);
    spathA.draw();

    return 0;
}