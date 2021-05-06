//
// Created by volodya on 06.05.2021.
//

#ifndef VOYAGER_SF_GRAPHICS_FACTORY_H
#define VOYAGER_SF_GRAPHICS_FACTORY_H

#include "i_graphics_factory.h"
namespace graphics::sf {
    class SfGraphicsFactory: public IGraphicsFactory{
    public:
        std::unique_ptr<ITexture> create_texture(const std::string &filename) override;

        std::unique_ptr<Sprite> create_sprite(const SpriteInfo &info, TextureStorage &storage) override;

        std::shared_ptr<Font> create_font() override;

        std::unique_ptr<Text> create_text() override;

        std::unique_ptr<ICanvas> create_canvas() override;

        std::unique_ptr<ICanvas> create_canvas(int width, int height, bool is_full) override;
    };
}

#endif //VOYAGER_SF_GRAPHICS_FACTORY_H
