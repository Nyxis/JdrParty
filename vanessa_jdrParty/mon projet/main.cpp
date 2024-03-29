#include "game_master.hpp"
#include "logger.hpp"

int main() {
    GameMaster gameMaster;
    RandomResult result = gameMaster.pleaseGiveMeAResult(20, 10, 5);
    Logger::log("Result: " + result.getTypeString());
    return 0;
}
