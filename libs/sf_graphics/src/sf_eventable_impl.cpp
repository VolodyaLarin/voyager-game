// Владимир Ларин
// Created by volodya on 08.05.2021.
//

#include <SFML/Window/Event.hpp>

#include "sf_graphics/sf_eventable_impl.h"

#include "event_controller/event/keyboard_event.h"
#include "event_controller/event/fps_event.h"

namespace event_controller {

    std::unique_ptr<Event> SfEventableImpl::get_event(sf::RenderWindow &window) {
        ::sf::Event sf_event = {};
        while (window.pollEvent(sf_event))
        {
            switch (sf_event.type)
            {
                case ::sf::Event::KeyPressed: {
                    auto key = static_cast<Key>(sf_event.key.code);
                    return std::make_unique<KeyboardEvent>(key);
                }
                default:
                    continue;
            }
        }
        return std::make_unique<FPSEvent>();
    }
}