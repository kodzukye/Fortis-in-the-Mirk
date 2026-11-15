#include "window.h"
#include "input_manager.h"
#include "player.h"
#include "texture_manager.h"

int main() {
    Window window{};
    window.open();

    TextureManager textures{};
    InputManager input{};

    Player player{textures, Vector2(200.0f, 200.0f)};

    while (!WindowShouldClose()) {
        player.update(GetFrameTime(), input);

        BeginDrawing();
        ClearBackground(BLACK);
        player.draw();
        EndDrawing();
    }

    textures.unloadAll();
    window.close();

    return 0;
}