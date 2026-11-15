#include "window.h"
#include "animated_sprite.h"
#include "texture_manager.h"

int main() {
    Window window{};
    window.open();

    TextureManager textures{};

    AnimatedSprite sprite{};
    sprite.addAnimation("idle",
        Animation{
        textures.get("assets/images/sprites/player/Idle.png"),
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

    textures.unloadAll();
    window.close();

    return 0;
}