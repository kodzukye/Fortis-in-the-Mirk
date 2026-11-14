#include "animated_sprite.h"

#include <chrono>
using namespace std;


void AnimatedSprite::addAnimation(string_view name, const Animation& animation) {
    m_animations[string{name}] = animation;
}

void AnimatedSprite::playAnimation(string_view name) {
    if (m_animations.contains(string{name}))
        {
            if (m_current_animation != name)
                {
                    m_current_animation = string{name};
                    m_current_frame = 0;
                    m_frame_timer = 0.0f;
                }
        }
}

void AnimatedSprite::updateAnimation(float delta_time) {
    if (m_current_animation.empty()) {  return;  }

    const Animation& animation{m_animations.at(m_current_animation)};
    if (animation.frames_per_second <= 0.0f) {  return;  }

    float duration{1.0f / animation.frames_per_second};
    m_frame_timer += delta_time;

    while (m_frame_timer >= duration)
    {
        m_frame_timer -= duration;
        m_current_frame++;
        if (m_current_frame >= animation.frame_number)
        {
            if (animation.loop) {
                m_current_frame = 0;
            }
            else {
                m_current_frame = animation.frame_number - 1;
                break;
            }
        }
    }
}

void AnimatedSprite::draw(Vector2 position) const {
    if (m_current_animation.empty()) {  return;  }

    const Animation& animation{m_animations.at(m_current_animation)};

    Rectangle source{
        static_cast<float>(m_current_frame * animation.frame_size.width),
        0.0f,
        static_cast<float>(animation.frame_size.width),
        static_cast<float>(animation.frame_size.height)
    };

    if (m_horizontal_flip) {
        source.width = -source.width;
    }

    DrawTextureRec(
        animation.texture,
        source,
        position,
        WHITE
    );
}

void AnimatedSprite::setHorizontalFlip(bool horizontalFlip) {
    m_horizontal_flip = horizontalFlip;
}
