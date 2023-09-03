#include "../include/utils.h"
#include "../include/globals.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

void _initGraphics () {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Cartesia");
    InitAudioDevice();
    SetTargetFPS(60);
}

Texture2D _processImage (const char* filepath, Rectangle src, Vector2 size) {
    Image tempImage = LoadImage(filepath);
    ImageCrop(&tempImage, src);

    if (size.x == -1) return LoadTextureFromImage(tempImage);

    ImageResize(&tempImage, size.x, size.y);
    UnloadImage(tempImage);
    
    return LoadTextureFromImage(tempImage);
}


void _loadResources (GameState* currGameState) {
    Image tempbg1 = LoadImage("../res/bg.png");
    ImageResize(&tempbg1, WINDOW_WIDTH, WINDOW_HEIGHT);
    currGameState->bg1 = LoadTextureFromImage(tempbg1);
    UnloadImage(tempbg1);

    currGameState->tilset[E_PLATFORM_W4] = _processImage(
        STRING_STARFIELDS_PATH,
        (Rectangle) {.x = 80, .y = 64, .width = 80, .height = 15},
        (Vector2) {.x = 4 * CELL_SIZE, .y = CELL_SIZE}
    );

    currGameState->tilset[E_PLATFORM_W6] = _processImage(
        STRING_STARFIELDS_PATH,
        (Rectangle) {.x = 80, .y = 64, .width = 80, .height = 15},
        (Vector2) {.x = 6 * CELL_SIZE, .y = CELL_SIZE}
    );

    currGameState->tilset[E_BIG_TREE] = _processImage(
        STRING_STARFIELDS_PATH,
        (Rectangle) {.x = 178, .y = 12, .width = 102, .height = 132},
        (Vector2) {.x = 7 * CELL_SIZE, .y = 8 * CELL_SIZE}
    );

    currGameState->tilset[E_SMALL_TREE] = _processImage(
        STRING_STARFIELDS_PATH,
        (Rectangle) {.x = 6, .y = 81, .width = 50, .height = 63},
        (Vector2) {.x = 3 * CELL_SIZE, .y = 4 * CELL_SIZE}
    );

    currGameState->tilset[E_ORANGE_TILES] = _processImage(
        OAK_WOODS_PATH,
        (Rectangle) {.x = 1, .y = 0, .width = 94, .height = 24},
        (Vector2) {.x = 3 * CELL_SIZE, .y = CELL_SIZE}
    );

    currGameState->tilset[E_LAMP] = _processImage(
        "../res/oak-woods/decorations/lamp.png",
        (Rectangle) {.x = 0, .y = 0, .width = 23, .height = 57},
        (Vector2) {.x = CELL_SIZE, .y = 2 * CELL_SIZE}
    );

    currGameState->tilset[E_DIRT_W3] = _processImage(
        OAK_WOODS_PATH,
        (Rectangle) {.x = 385, .y = 312, .width = 47, .height = 24},
        (Vector2) {.x = 3 * CELL_SIZE, .y = CELL_SIZE}
    );

    currGameState->tilset[E_STONE_TILES_W3] = _processImage(
        OAK_WOODS_PATH,
        (Rectangle) {.x = 288, .y = 240, .width = 48, .height = 24},
        (Vector2) {.x = 3 * CELL_SIZE, .y = CELL_SIZE}
    );

    currGameState->tilset[E_COIN] = _processImage(
        "../res/coin.png", 
        (Rectangle) {.x = 0, .y = 0, .width = 70, .height = 70}, 
        (Vector2) {.x = 15 , .y = 15}
    );

    currGameState->scarfy = LoadTexture("../res/scarfy.png");

    currGameState->frameRec = (Rectangle) { 0.0f, 0.0f, (float) 768/6, (float)128};

    currGameState->sounds[S_COIN] = LoadSound("../res/coin.mp3");
    currGameState->sounds[S_DEATH] = LoadSound("../res/death.mp3");
    currGameState->sounds[S_DAGGER] = LoadSound("../res/Dagger.mp3");

    Image spikeImg = LoadImage("../res/spikes.png");
    ImageRotateCW(&spikeImg);
    ImageResize(&spikeImg, 3 * CELL_SIZE, CELL_SIZE);
    currGameState->tilset[E_SPIKES] = LoadTextureFromImage(spikeImg);
    UnloadImage(spikeImg);

    currGameState->tilset[E_ROCK] = _processImage(
        "../res/oak-woods/decorations/rock_1.png",
        (Rectangle) {.x = 0, .y = 0, .width = 20, .height = 11},
        (Vector2) {.x = CELL_SIZE, .y = CELL_SIZE}
    );

    currGameState->tilset[E_SKELLY] = _processImage(
        "../res/Idle.png",
        (Rectangle) {.x = 59, .y = 51, .width = 46, .height = 50},
        (Vector2) {.x = 2 * CELL_SIZE, .y = 2 * CELL_SIZE}
    );

}

void _unloadResources (GameState* currGameState) {
    UnloadTexture(currGameState->bg1);
    for (int i = 0 ; i < NUM_OF_TEXTURES; i++) {
        UnloadTexture(currGameState->tilset[i]);
    }
    CloseAudioDevice();
    CloseWindow();
}

void _updateFrameInfo (GameState* currGameState) {
    currGameState->framesCounter++;
    if (currGameState->framesCounter >= (60 / currGameState->framesSpeed)) {
        currGameState->framesCounter = 0;
        currGameState->currentFrame++;
        if (currGameState->currentFrame > 5) currGameState->currentFrame = 0;
        currGameState->frameRec.x = (float)currGameState->currentFrame*(float) 768/6;
    }
}

void _initParticles (GameState* currGameState) {
    for (int i = 0; i < PARTICLES_COUNT; i++) {
        currGameState->particles[i].pos.x = rand() % WINDOW_WIDTH - 500;
        currGameState->particles[i].pos.y = rand() % WINDOW_HEIGHT - 500;
        currGameState->particles[i].vel.x = rand() % 5;
        currGameState->particles[i].vel.y = rand() % 5;
    }
}

void _updateParticles (GameState* currGameState) {
    for (int i = 0; i < PARTICLES_COUNT; i++) {
        currGameState->particles[i].pos.x += currGameState->particles[i].vel.x;
        currGameState->particles[i].pos.y += currGameState->particles[i].vel.y;

        if (currGameState->particles[i].pos.x > WINDOW_WIDTH) {
            currGameState->particles[i].pos.x = rand() % WINDOW_WIDTH - 500;
        }
        if (currGameState->particles[i].pos.y > WINDOW_HEIGHT) {
            currGameState->particles[i].pos.y = rand() % WINDOW_HEIGHT;
        }
    }
}

void _displayParticles (GameState* currGameState) {
    for (int i = 0; i < PARTICLES_COUNT; i++) {
        // DrawRectangle(int posX, int posY, int width, int height, Color color)
        DrawRectangle(
            currGameState->particles[i].pos.x,
            currGameState->particles[i].pos.y,
            2,
            2,
            WHITE
        );
    }
}

void _displayText (GameState* currGameState) {
    char* text;
    asprintf(
        &text, 
        "Coins: %d  Remaining Life: %d", 
        currGameState->coinsCollected,
        currGameState->remainingLife
    );

    DrawText(text, WINDOW_WIDTH - 180, 10, 12, WHITE);

    free(text);
}
