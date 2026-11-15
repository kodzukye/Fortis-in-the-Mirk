#ifndef FORTIS_IN_THE_MIRK_WINDOW_H
#define FORTIS_IN_THE_MIRK_WINDOW_H

#include "raylib.h"
#include "types.h"
#include <string_view>
#include <string>

namespace WindowDefault {
    constexpr std::string_view game_title{"Fortis in the Mirk"};

    // Window size
    constexpr int window_default_width{1280};
    constexpr int window_default_height{720};

    // Game Size
    constexpr int game_width{640};
    constexpr int game_height{360};
}

class Window {
    public:
        Window(std::string_view title, int width, int height);
        Window();

        void open();
        void close();

        void beginGameDrawing();
        void endGameDrawing();

    private:
        std::string m_title{};
        Size m_size{0, 0};
        RenderTexture2D m_game_screen{};
};

#endif //FORTIS_IN_THE_MIRK_WINDOW_H
