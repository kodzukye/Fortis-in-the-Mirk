#ifndef FORTIS_IN_THE_MIRK_ANIMATED_SPRITE_H
#define FORTIS_IN_THE_MIRK_ANIMATED_SPRITE_H

#include <string>
#include <string_view>
#include <map>
#include "animation.h"

class AnimatedSprite {
    public:
        void addAnimation(std::string_view name, const Animation& animation);
        void playAnimation(std::string_view name);
        void updateAnimation(float deltaTime);
        void draw(Vector2 position) const;
        void setHorizontalFlip(bool horizontalFlip);

    private:
        std::map<std::string, Animation> m_animations{};
        std::string m_current_animation{};
        int m_current_frame{0};
        float m_frame_timer{0.0f};
        bool m_horizontal_flip{false};
};

#endif //FORTIS_IN_THE_MIRK_ANIMATED_SPRITE_H
