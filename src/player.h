#ifndef FORTIS_IN_THE_MIRK_PLAYER_H
#define FORTIS_IN_THE_MIRK_PLAYER_H
#include "animated_sprite.h"
#include "texture_manager.h"
#include "types.h"
#include "input_manager.h"
#include "raylib.h"

#include <string_view>


namespace DefaultPlayer {
    // Idle Animation
    constexpr std::string_view idle_path{"assets/images/sprites/player/Idle.png"};
    constexpr Size idle_size{96, 84};
    constexpr int idle_frame_count{7};
    constexpr float idle_fps{10.0f};

    // Run Animation
    constexpr std::string_view run_path{"assets/images/sprites/player/Run.png"};
    constexpr Size run_size{96, 84};
    constexpr int run_frame_count{8};
    constexpr float run_fps{10.0f};

    // Player Default Variables
    constexpr float default_speed{150.0f};
}

class Player {
    public:
        Player(TextureManager& textures, Vector2 startPosition);
        void update(float deltaTime, const InputManager& input);
        void draw() const;
    private:
        // Variables
        AnimatedSprite m_sprite{};
        Vector2 m_position{};
        float m_speed{DefaultPlayer::default_speed};

        // Functions
        void initializeAnimations(TextureManager& textures);
        float getDirection(const InputManager& input) const;
};

#endif //FORTIS_IN_THE_MIRK_PLAYER_H
