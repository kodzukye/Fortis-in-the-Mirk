#include "window.h"
using namespace std;

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
    SetTargetFPS(60);
}

void Window::close() {
    CloseWindow();
}