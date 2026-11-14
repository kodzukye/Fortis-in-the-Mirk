#include "window.h"
#include "animated_sprite.h"

int main() {
    Window window{};
    window.open();

    Texture2D playerIdle{LoadTexture("assets/images/sprites/player/Idle.png")};

    AnimatedSprite sprite{};
    sprite.addAnimation("idle",
        Animation{
        playerIdle,
        Size{96, 84},
        7,
        10.0f,
        true
    });
    sprite.playAnimation("idle");

    while (!WindowShouldClose()) {
        sprite.updateAnimation(GetFrameTime());

        BeginDrawing();
        ClearBackground(BLACK);
        sprite.draw(Vector2(200.0f, 200.0f));
        EndDrawing();
    }

    UnloadTexture(playerIdle);
    window.close();

    return 0;
}