#include "core/Dice.h"
#include <time.h> 
#include <stdlib.h>
#include "core/Tile.h"
#include "core/Property.h"
#include "core/Inventory.h"


int main() {
    
    Dice unDes;
    srand((unsigned int)time(NULL));
    unDes.testRegDice();

    Property p("test",1,99,99,99,99,99,99,99,99,99);
    p.testRegProperty();

    Inventory i;
    i.testRegInventory();

    return 0;
}