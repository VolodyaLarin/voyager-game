//
// Created by volodya on 15.04.2021.
//

#include <graphics/json_sprite_sheet_loader.h>
#include <create_standart_menu_button.h>
#include <loaders/locale_loader.h>
#include "menu/command_button.h"
#include "menu/main_menu.h"
#include "game_manager/commands.hpp"
#include "event_controller/event/fps_event.h"

menu::MainMenu::~MainMenu() = default;

menu::MainMenu::MainMenu(graphics::ICanvas &canvas, event_controller::IController &controller, graphics::IGraphicsFactory &factory,
                         graphics::ISpiteLoader &loader) : BackgroundMenuDecorator(canvas, controller, 0, factory, loader),
                                                           _factory(factory),  _loader(loader) {

    LocaleLoader locale;
    _button_creator = std::make_unique<CreateStandartMenuButton>();

    set_gap(10);
    set_buttons_height(50);
    set_buttons_width(200);

    auto font = factory.create_font();

    auto cur_dir = std::filesystem::path(__FILE__).parent_path();
    font->set_path(cur_dir / "../../graphics/test/tests/fonts/Roboto-Medium.ttf");

    auto start_command = std::make_unique<game_manager::command::RunLevelMenu>();

    buttons().push_back(
            _button_creator->create(factory, font, std::move(start_command), locale.get("start_game"))
    );
    auto other_command = std::make_unique<game_manager::command::RunGameInfo>();
    buttons().push_back(
            _button_creator->create(factory, font, std::move(other_command), locale.get("game_info"))
    );

    auto exit_command = std::make_unique<game_manager::command::Exit>();
    buttons().push_back(
            _button_creator->create(factory, font, std::move(exit_command), locale.get("exit"))
    );

    set_active_id(0);
}
