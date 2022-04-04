#ifndef _GAMETXT
#define _GAMETXT

#include "../core/Game.h"

Game txtInit(int nb_player, std::string filename);

void txtLoop(Game & game);

void txtEnd();

void lineBreak();

#endif