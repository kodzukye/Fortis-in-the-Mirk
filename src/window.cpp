#include "window.h"
using namespace std;

Window::Window(std::string_view title, int width, int height)
    : m_title{title}, m_width{width}, m_height{height}
{
}

Window::Window()
    : Window{WindowDefault::gameTitle, WindowDefault::windowDefaultWidth, WindowDefault::windowDefaultHeight}
{
}

void Window::open() {
    InitWindow(m_width, m_height, m_title.c_str());
    SetTargetFPS(60);
}

void Window::close() {
    CloseWindow();
}