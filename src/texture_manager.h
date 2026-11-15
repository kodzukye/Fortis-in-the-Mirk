#ifndef FORTIS_IN_THE_MIRK_TEXTUREMANAGER_H
#define FORTIS_IN_THE_MIRK_TEXTUREMANAGER_H
#include <map>
#include <string>
#include <string_view>

#include "raylib.h"

class TextureManager {
    public:
        TextureManager() = default;
        TextureManager(const TextureManager&) = delete;
        TextureManager& operator=(const TextureManager&) = delete;
        Texture2D get(std::string_view path);
        void unloadAll();
    private:
        std::map<std::string,Texture2D> m_textures{};
};

#endif //FORTIS_IN_THE_MIRK_TEXTUREMANAGER_H
