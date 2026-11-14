#ifndef FORTIS_IN_THE_MIRK_ANIMATION_H
#define FORTIS_IN_THE_MIRK_ANIMATION_H

#include "raylib.h"
#include "types.h"

struct Animation {
    Texture2D texture{};
    Size frame_size{0, 0};
    int frame_number{0};
    float frames_per_second{10.0f};
    bool loop{true};
};

#endif //FORTIS_IN_THE_MIRK_ANIMATION_H
