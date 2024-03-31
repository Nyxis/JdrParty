#include "GameMaster.h"
#include <ctime>

int main()
{
    srand(time(0));
    GameMaster gameMaster;
    auto result = gameMaster.pleaseGiveMeACrit(60, 10, 5);
    return 0;
}