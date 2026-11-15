#include "player.h"
using namespace std;

Player::Player(TextureManager& textures, Vector2 startPosition)
    : m_position{startPosition}
{
    initializeAnimations(textures);
}

void Player::initializeAnimations(TextureManager& textures) {
    m_sprite.addAnimation("idle",
        Animation{
        textures.get(DefaultPlayer::idle_path),
        DefaultPlayer::idle_size,
        DefaultPlayer::idle_frame_count,
        DefaultPlayer::idle_fps,
        true
    });

    m_sprite.addAnimation("run",
        Animation{
        textures.get(DefaultPlayer::run_path),
        DefaultPlayer::run_size,
        DefaultPlayer::run_frame_count,
        DefaultPlayer::run_fps,
        true
    });

    m_sprite.playAnimation("idle");
}

void Player::update(float deltaTime, const InputManager& input) {
    float direction{getDirection(input)};
    m_position.x += direction * m_speed * deltaTime;

    if (direction != 0.0f)
    {
        m_sprite.playAnimation("run");
    }

    else
    {
        m_sprite.playAnimation("idle");
    }

    if (direction < 0.0f ) {
        m_sprite.setHorizontalFlip(true);
    }
    if (direction > 0.0f ) {
        m_sprite.setHorizontalFlip(false);
    }

    m_sprite.updateAnimation(deltaTime);
}

void Player::draw() const {
    m_sprite.draw(m_position);
}

float Player::getDirection(const InputManager& input) const {
    float left{0.0f};
    float right{0.0f};

    if (input.isDown(Action::MoveLeft)) {
        left = 1.0f;
    }
    if (input.isDown(Action::MoveRight)) {
        right = 1.0f;
    }
    return right - left;
}
