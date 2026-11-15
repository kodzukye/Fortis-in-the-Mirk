#include "input_manager.h"

InputManager::InputManager() {
    m_bindings[Action::MoveLeft] = {KEY_A, KEY_LEFT};
    m_bindings[Action::MoveRight] = {KEY_D, KEY_RIGHT};
}

bool InputManager::isDown(Action action) const {
    if (!m_bindings.contains(action)) {
        return false;
    }
    for (KeyboardKey key : m_bindings.at(action)) {
        if (IsKeyDown(key)) {
            return true;
        }
    }
    return false;
}

bool InputManager::isPressed(Action action) const {
    if (!m_bindings.contains(action)) {
        return false;
    }
    for (KeyboardKey key : m_bindings.at(action)) {
        if (IsKeyPressed(key)) {
            return true;
        }
    }
    return false;
}