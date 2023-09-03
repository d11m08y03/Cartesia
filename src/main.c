#include <stdio.h>
#include <raylib.h>
#include <stdbool.h>

#include "../include/definitions.h"
#include "../include/globals.h"
#include "../include/utils.h"
#include "../include/core.h"

int main () {
    GameState currGameState;
    _initGraphics();
    _loadResources(&currGameState);
    _initParticles(&currGameState);

    init_card(&currGameState);

    PlaySound(currGameState.sounds[S_DAGGER]);
    
    while (!WindowShouldClose()) {
        _updateFrameInfo(&currGameState);

        handle_player(&currGameState);

        if (currGameState.remainingLife < 1 || currGameState.coinsCollected > 69) {
            break;
        }

        BeginDrawing();

        display_card(&currGameState);

        _displayParticles(&currGameState);
        _updateParticles(&currGameState);
        _displayText(&currGameState);

        EndDrawing();
    }

    _unloadResources(&currGameState);

    return 0;
}
