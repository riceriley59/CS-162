#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "room.h"
#include <vector>

using namespace std;

class Game{
    private:
        Player player;
        vector<vector<Room>> grid;
    public:

};

#endif