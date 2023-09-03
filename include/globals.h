#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <raylib.h>
#include "./definitions.h"

enum TextureType {
    NOTHING = -1,
    E_PLATFORM_W4 = 0, 
    E_PLATFORM_W6 = 1, 
    E_BIG_TREE = 2,
    E_SMALL_TREE = 3,
    E_ORANGE_TILES = 4,
    E_LAMP = 5,
    E_DIRT_W3 = 6,
    E_STONE_TILES_W3 = 7,
    E_COIN = 8,
    E_SPIKES = 9,
    E_ROCK = 10,
    E_SKELLY = 11
};

enum SoundType {
    S_COIN = 0,
    S_DEATH = 1,
    S_DAGGER = 2
};

typedef enum {
    RIGHT, LEFT 
} Direction;

typedef struct {
    Vector2 pos;
    Vector2 vel;
} Particle;

typedef struct {
    Texture2D tilset[NUM_OF_TEXTURES];
    Texture2D bg1;
    Particle particles[PARTICLES_COUNT];
    int card[MAP_SIZE][MAP_SIZE];
    int collisionMap[MAP_SIZE][MAP_SIZE];
    int playerPos[2];

    int coinsCollected;
    int remainingLife; 

    Sound sounds[3];

    Direction direction;
    int playerMoving;
    Texture2D scarfy;
    int framesCounter;
    int framesSpeed;
    int currentFrame;
    Rectangle frameRec;
} GameState;

#endif
