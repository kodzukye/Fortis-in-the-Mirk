#ifndef FORTIS_IN_THE_MIRK_WINDOW_H
#define FORTIS_IN_THE_MIRK_WINDOW_H

#include "raylib.h"
#include <string_view>
#include <string>

namespace WindowDefault {
    constexpr std::string_view gameTitle{"Fortis in the Mirk"};

    // Window size
    constexpr int windowDefaultWidth{1280};
    constexpr int windowDefaultHeight{720};
}

class Window {
public:
    Window(std::string_view title, int width, int height);
    Window();

    void open();
    void close();

private:
    std::string m_title{};
    int m_width{};
    int m_height{};
};

#endif //FORTIS_IN_THE_MIRK_WINDOW_H
