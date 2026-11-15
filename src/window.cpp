#include "window.h"
using namespace std;
#include <cmath>

Window::Window(std::string_view title, int width, int height)
    : m_title{title}, m_size{width, height}
{
}

Window::Window()
    : Window{WindowDefault::game_title, WindowDefault::window_default_width, WindowDefault::window_default_height}
{
}

void Window::open() {
    InitWindow(m_size.width, m_size.height, m_title.c_str());
    m_game_screen = LoadRenderTexture(WindowDefault::game_width, WindowDefault::game_height);
    SetTextureFilter(m_game_screen.texture, TEXTURE_FILTER_POINT);
    SetTargetFPS(60);
}

void Window::close() {
    UnloadRenderTexture(m_game_screen);
    CloseWindow();
}

void Window::beginGameDrawing() {
    BeginTextureMode(m_game_screen);
}

void Window::endGameDrawing() {

    const Rectangle source{
        0.0f,
        0.0f,
        static_cast<float>(m_game_screen.texture.width),
        -static_cast<float>(m_game_screen.texture.height)
    };
    DrawTextureRec(m_game_screen.texture, source, Vector2{0.0f, 0.0f}, WHITE);

    const float scaleX{static_cast<float>(GetScreenWidth()) / WindowDefault::game_width};
    const float scaleY{static_cast<float>(GetScreenHeight()) / WindowDefault::game_height};
    float scale{std::min(scaleX, scaleY)};
    scale = std::max(1.0f, std::floor(scale));

    const float width{WindowDefault::game_width * scale};
    const float height{WindowDefault::game_height * scale};
    const Rectangle destination{
        (static_cast<float>(GetScreenWidth()) - width) / 2.0f,
        (static_cast<float>(GetScreenHeight()) - height) / 2.0f,
        width,
        height
    };

    EndTextureMode();

    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexturePro(m_game_screen.texture, source, destination, Vector2{0.0f, 0.0f}, 0.0f, WHITE);
    EndDrawing();
}
