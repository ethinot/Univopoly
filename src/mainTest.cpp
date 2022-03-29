#include "Dice.h"
#include <time.h> 
#include <stdlib.h>
#include "Board.h"

int main() {
    
    Dice unDes;
    srand((unsigned int)time(NULL));
    unDes.regressionTestDice();
    return 0;
}