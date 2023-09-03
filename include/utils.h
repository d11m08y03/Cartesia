#ifndef UTILS_H_
#define UTILS_H_

#include <raylib.h>
#include "../include/globals.h"

void _initGraphics ();
Texture2D _processImage (const char* filepath, Rectangle src, Vector2 size);
void _loadResources(GameState* currGameState);
void _unloadResources(GameState* currGameState);

void _updateFrameInfo(GameState* currGameState);
void _initParticles(GameState* currGameState);
void _displayParticles(GameState* currGameState);
void _updateParticles(GameState* currGameState);
void _displayText (GameState* currGameState);
#endif // UTILS_H_
