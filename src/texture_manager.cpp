#include "texture_manager.h"

using namespace std;

Texture2D TextureManager::get(string_view path) {
    string key{path};
    if (!m_textures.contains(key)) {
        m_textures[key] = LoadTexture(key.c_str());
    }
    return m_textures.at(key);
}

void TextureManager::unloadAll() {
    for (const auto& [path, texture] : m_textures) {
        UnloadTexture(texture);
    }
    m_textures.clear();
}