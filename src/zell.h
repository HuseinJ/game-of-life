
#include "globals.h"
#include <cstdlib>

class Zell {
    bool alive = rand() % 2 >= 1;
    bool futureAliveState;
    size_t posCol = 0;
    size_t posRow = 0;

    u_int64_t countNeighbours(Zell** world);
    bool inBounds(int row, int col);

    public:
        void update(Zell** world);
        void updateIteration();
        bool isAlive();
        void setPosition(size_t posCol, size_t posRow);
};