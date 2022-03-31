#include "core/Dice.h"
#include <time.h> 
#include <stdlib.h>
#include "core/Tile.h"
#include "core/Property.h"


int main() {
    
    Dice unDes;
    srand((unsigned int)time(NULL));
    unDes.regressionTestDice();

    Property p("test",1,99,99,99,99,99,99,99,99,99);
    p.testRegProperty();

    return 0;
}