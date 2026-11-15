#ifndef FORTIS_IN_THE_MIRK_INPUT_MANAGER_H
#define FORTIS_IN_THE_MIRK_INPUT_MANAGER_H
#include <map>
#include <vector>

#include "raylib.h"

enum class Action {
    MoveLeft,
    MoveRight
};

class InputManager {
    public:
        InputManager();
        bool isDown(Action action) const;
        bool isPressed(Action action) const;
private:
    std::map<Action, std::vector<KeyboardKey>> m_bindings{};
};

#endif //FORTIS_IN_THE_MIRK_INPUT_MANAGER_H
