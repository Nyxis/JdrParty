#include <iostream>
#include "Gamemaster.h"
#include "Logger.h"
#include <string>
using namespace std;
int main(int argnb, char *args[]) {
    GameMaster gm = GameMaster({1, 2, 3, 4, 5, 6, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, {6, 10}, 2, {3, 4}, {18, 13});
    string str = "";
    //for(int i = 0; i < 100; i++) {
    //string str2 = args[0];
        //Logger::Log(str2);
    //Logger::Log(args[2]);
        str = gm.pleaseGiveMeACrit(atof(args[1]) , atof(args[2]), atof(args[3]));
        Logger::Log("GameMaster utilise "+gm.getObjetNom()+" et le résultat donne : "+to_string(gm.getResultat())+"\n"+str+"\n");
    //}
    Logger::Log("   Echec: "+to_string(gm.getEchec())+"Succes: "+to_string(gm.getSuccess())+"   Crit: "+to_string(gm.getCritique()));
    return gm.getResultatState();
}
