#include "../include/core.h"
#include <raylib.h>
#include <stdio.h>

#define _COIN -111
#define _DEATH 420

// Transforms the position of the entity from
// the 20x20 array card to a position on the 
// screen.
#define NORMALISE(A) A * CELL_SIZE

void init_card (GameState* currGameState) {
    currGameState->remainingLife = 3;
    currGameState->coinsCollected = 0;
    currGameState->playerMoving = 0;
    currGameState->direction = RIGHT;

    currGameState->framesSpeed = 8;

    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            currGameState->card[i][j] = NOTHING;
            currGameState->collisionMap[i][j] = NOTHING;
        }
    }

    currGameState->card[10][8] = E_PLATFORM_W4;
    currGameState->collisionMap[8][11] = 69;
    currGameState->collisionMap[8][12] = 69;
    currGameState->collisionMap[8][13] = 69;
    currGameState->collisionMap[8][10] = 69;
    
    currGameState->card[17][4] = E_SMALL_TREE;
    currGameState->card[15][8] = E_PLATFORM_W6;

    currGameState->collisionMap[8][15] = 69;
    currGameState->collisionMap[8][16] = 69;
    currGameState->collisionMap[8][17] = 69;
    currGameState->collisionMap[8][18] = 69;
    currGameState->collisionMap[8][19] = 69;

    currGameState->card[0][2] = E_PLATFORM_W6;
    currGameState->card[4][1] = E_COIN;
    currGameState->card[5][1] = E_COIN;
    currGameState->collisionMap[1][4] = _COIN;
    currGameState->collisionMap[1][5] = _COIN;
    currGameState->card[10][8] = E_PLATFORM_W4;
    currGameState->collisionMap[8][11] = 69;
    currGameState->collisionMap[8][12] = 69;
    currGameState->collisionMap[8][13] = 69;
    currGameState->collisionMap[8][10] = 69;

    currGameState->card[17][4] = E_SMALL_TREE;
    currGameState->card[15][8] = E_PLATFORM_W6;

    currGameState->collisionMap[8][15] = 69;
    currGameState->collisionMap[8][16] = 69;
    currGameState->collisionMap[8][17] = 69;
    currGameState->collisionMap[8][18] = 69;
    currGameState->collisionMap[8][19] = 69;

    currGameState->card[0][2] = E_PLATFORM_W6;
    currGameState->card[4][1] = E_COIN;
    currGameState->card[5][1] = E_COIN;
    currGameState->collisionMap[1][4] = _COIN;
    currGameState->collisionMap[1][5] = _COIN;
    currGameState->collisionMap[2][0] = 69;
    currGameState->collisionMap[2][1] = 69;
    currGameState->collisionMap[2][2] = 69;
    currGameState->collisionMap[2][3] = 69;
    currGameState->collisionMap[2][4] = 69;
    currGameState->collisionMap[2][5] = 69;

    currGameState->card[9][2] = E_COIN;
    currGameState->card[10][2] = E_COIN;
    currGameState->collisionMap[2][9] = _COIN;
    currGameState->collisionMap[2][10] = _COIN;
    currGameState->card[8][3] = E_PLATFORM_W4;
    currGameState->collisionMap[3][8] = 69;
    currGameState->collisionMap[3][9] = 69;
    currGameState->collisionMap[3][10] = 69;
    currGameState->collisionMap[3][11] = 69;

    currGameState->card[0][19] = E_ORANGE_TILES;
    currGameState->collisionMap[19][0] = 69;
    currGameState->collisionMap[19][1] = 69;
    currGameState->collisionMap[19][2] = 69;
    currGameState->collisionMap[19][3] = 69;

    currGameState->card[3][19] = E_ORANGE_TILES;
    currGameState->collisionMap[19][3] = 69;
    currGameState->collisionMap[19][4] = 69;
    currGameState->collisionMap[19][5] = 69;
    currGameState->collisionMap[19][6] = 69;

    currGameState->card[5][17] = E_LAMP;
    currGameState->card[0][11] = E_BIG_TREE; 

    currGameState->card[6][19] = E_PLATFORM_W6;
    currGameState->collisionMap[19][6] = 69;
    currGameState->collisionMap[19][7] = 69;
    currGameState->collisionMap[19][8] = 69;
    currGameState->collisionMap[19][9] = 69;
    currGameState->collisionMap[19][10] = 69;
    currGameState->collisionMap[19][11] = 69;

    currGameState->card[13][17] = E_PLATFORM_W4;
    currGameState->collisionMap[17][13] = 69;
    currGameState->collisionMap[17][14] = 69;
    currGameState->collisionMap[17][15] = 69;
    currGameState->collisionMap[17][16] = 69;

    currGameState->card[16][15] = E_PLATFORM_W4;
    currGameState->card[17][14] = E_COIN;
    currGameState->card[18][14] = E_COIN;
    currGameState->collisionMap[14][17] = _COIN;
    currGameState->collisionMap[14][18] = _COIN;
    currGameState->collisionMap[15][16] = 69;
    currGameState->collisionMap[15][17] = 69;
    currGameState->collisionMap[15][18] = 69;
    currGameState->collisionMap[15][19] = 69;

    currGameState->card[8][14] = E_PLATFORM_W6;
    currGameState->collisionMap[14][8] = 69;
    currGameState->collisionMap[14][9] = 69;
    currGameState->collisionMap[14][10] = 69;
    currGameState->collisionMap[14][11] = 69;
    currGameState->collisionMap[14][12] = 69;
    currGameState->collisionMap[14][13] = 69;

    currGameState->card[16][7] = E_COIN;
    currGameState->card[17][7] = E_COIN;
    currGameState->collisionMap[7][16] = _COIN;
    currGameState->collisionMap[7][17] = _COIN;


    currGameState->card[3][5] = E_SPIKES;
    currGameState->collisionMap[5][3] = _DEATH;
    currGameState->collisionMap[5][4] = _DEATH;
    currGameState->collisionMap[5][5] = _DEATH;

    currGameState->card[6][5] = E_SPIKES;
    currGameState->collisionMap[5][6] = _DEATH;
    currGameState->collisionMap[5][7] = _DEATH;
    currGameState->collisionMap[5][8] = _DEATH;
    
    currGameState->card[12][9] = E_SPIKES;
    currGameState->collisionMap[9][12] = _DEATH;
    currGameState->collisionMap[9][13] = _DEATH;
    currGameState->collisionMap[9][14] = _DEATH;

    currGameState->card[15][9] = E_SPIKES;
    currGameState->collisionMap[9][15] = _DEATH;
    currGameState->collisionMap[9][16] = _DEATH;
    currGameState->collisionMap[9][17] = _DEATH;

    currGameState->card[13][5] = E_PLATFORM_W4;
    currGameState->collisionMap[5][14] = 69;
    currGameState->collisionMap[5][15] = 69;
    currGameState->collisionMap[5][16] = 69;
    currGameState->collisionMap[5][13] = 69;

    currGameState->card[0][12] = E_PLATFORM_W4;
    currGameState->collisionMap[12][0] = 69;
    currGameState->collisionMap[12][1] = 69;
    currGameState->collisionMap[12][2] = 69;
    currGameState->collisionMap[12][3] = 69;

    currGameState->card[1][11] = E_COIN;
    currGameState->card[2][11] = E_COIN;
    currGameState->collisionMap[11][1] = _COIN;
    currGameState->collisionMap[11][2] = _COIN;



    currGameState->card[5][10] = E_PLATFORM_W4;
    currGameState->collisionMap[10][6] = 69;
    currGameState->collisionMap[10][7] = 69;
    currGameState->collisionMap[10][8] = 69;
    currGameState->collisionMap[10][5] = 69;

    currGameState->card[3][11] = E_ROCK;
    currGameState->card[3][10] = E_ROCK;
    currGameState->card[15][4] = E_ROCK;

    currGameState->card[8][12] = E_SKELLY;
    currGameState->card[0][0] = E_SKELLY;

    // Initialising player position
    currGameState->playerPos[0] = INITIAL_PLAYER_X;
    currGameState->playerPos[1] = INITIAL_PLAYER_Y;
}

void display_card (GameState* currGameState) {
    DrawTexture(currGameState->bg1, 0, 0, WHITE); 
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            DrawTexture(
                currGameState->tilset[currGameState->card[i][j]],
                NORMALISE(i), NORMALISE(j), WHITE
            );
        }
    }

    int flip = (currGameState->direction == RIGHT) ? 1 : -1;

    if (currGameState->playerMoving) {
        DrawTexturePro(
            currGameState->scarfy,
            (Rectangle) {
                .x = currGameState->frameRec.x,
                .y = currGameState->frameRec.y,
                .width = currGameState->frameRec.width * flip,
                .height = currGameState->frameRec.height
            },
            (Rectangle) {
                .x = currGameState->playerPos[0], 
                .y = currGameState->playerPos[1] + 10, 
                .width = CELL_SIZE, .height = CELL_SIZE
            },
            (Vector2) {.x = 10, .y = 10},
            0.0f,
            WHITE
        );
    } else {
        DrawTexturePro(
            currGameState->scarfy,
            (Rectangle) {
                .x = 660, .y = 0, 
                .width = 65 * flip, .height = 128
            },
            (Rectangle) {
                .x = currGameState->playerPos[0],
                .y = currGameState->playerPos[1] + 10,
                .width = CELL_SIZE, .height = CELL_SIZE
            },
            (Vector2) {.x = 10, .y = 10},
            0.0f,
            WHITE
        );
    }
}

int handle_player (GameState* currGameState) {
    currGameState->playerMoving = 0;
    int jumpVal = 0;

    int playerPosGridX = currGameState->playerPos[0] / CELL_SIZE;
    int playerPosGridY = currGameState->playerPos[1] / CELL_SIZE;

    if (
        currGameState->playerPos[0] > WINDOW_WIDTH 
        || currGameState->playerPos[0] < 0
        || currGameState->playerPos[1] > WINDOW_HEIGHT
    ) {
        currGameState->playerPos[0] = INITIAL_PLAYER_X;
        currGameState->playerPos[1] = INITIAL_PLAYER_Y;
        currGameState->remainingLife -= 1;
        return 1;
    }

    if (playerPosGridY < 19) {
        if (currGameState->collisionMap[playerPosGridY + 1][playerPosGridX] == NOTHING) {
            currGameState->playerPos[1] += 10;
        } else if (currGameState->collisionMap[playerPosGridY][playerPosGridX] == _COIN) {
            PlaySound(currGameState->sounds[S_COIN]);
            currGameState->coinsCollected += 1;
            currGameState->card[playerPosGridX][playerPosGridY] = NOTHING;
            currGameState->collisionMap[playerPosGridY][playerPosGridX] = NOTHING;
        } 
        if (
            currGameState->collisionMap[playerPosGridY][playerPosGridX] == _DEATH
            || currGameState->collisionMap[playerPosGridY + 1][playerPosGridX] == _DEATH
        ) {
            PlaySound(currGameState->sounds[S_DEATH]);
            currGameState->playerPos[0] = INITIAL_PLAYER_X;
            currGameState->playerPos[1] = INITIAL_PLAYER_Y;
            currGameState->remainingLife -= 1;
        }
    } else {
        PlaySound(currGameState->sounds[S_DEATH]);
        currGameState->playerPos[0] = INITIAL_PLAYER_X;
        currGameState->playerPos[1] = INITIAL_PLAYER_Y;
        currGameState->remainingLife -= 1;
    }

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        currGameState->playerMoving = 1;
        currGameState->direction = RIGHT;
        currGameState->playerPos[0] += PLAYER_SPEED;
    }

    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        currGameState->playerMoving = 1;
        currGameState->direction = LEFT;
        currGameState->playerPos[0] -= PLAYER_SPEED;
    } 

    if (IsKeyDown(KEY_SPACE)) {
        while (jumpVal < 30) {
            currGameState->playerPos[1] -= 8;
            jumpVal += 10;
        }
    }

    return 0;
}
