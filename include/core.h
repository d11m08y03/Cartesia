#ifndef CORE_H_
#define CORE_H_

#include "./globals.h"
#include "definitions.h"

void init_card (GameState* currGameState);
void display_card (GameState* currGameState);
int handle_player (GameState* currGameState);

#endif
