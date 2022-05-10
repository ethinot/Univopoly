#include "core/Dice.h"
#include <time.h> 
#include <stdlib.h>
#include "core/Tile.h"
#include "core/Property.h"
#include "core/Inventory.h"
#include "core/Player.h"

int main() {
    
    Dice unDes;
    srand((unsigned int)time(NULL));
    unDes.testRegDice();

    Property prop("test","blue",1,99,99,99,99,99,99,99,99,99);
    prop.testRegProperty();

    Inventory i;
    i.testRegInventory();

    std::cout<<std::endl;
    std::cout<<std::endl;

    Player player;
    player.testRegPlayer();

    return 0;
}