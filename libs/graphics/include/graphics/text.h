//
// Created by volodya on 15.04.2021.
//

#ifndef VOYAGER_I_TEXT_H
#define VOYAGER_I_TEXT_H

#include <string>
#include <filesystem>
#include "font.h"
#include "pos_drawable.h"
namespace graphics {
    class Text: public PosDrawable{
    private:
        std::string _string;
        std::shared_ptr<Font> _font;
    public:
        virtual Font &get_font();

        virtual void set_font(std::shared_ptr<Font> font);

        virtual const std::string &get_string();

        virtual void set_string(const std::string &string);

        virtual int get_width() = 0;

        ~Text() override = default;
    };
}


#endif //VOYAGER_I_TEXT_H