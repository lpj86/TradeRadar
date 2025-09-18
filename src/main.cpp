#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
using namespace ftxui;

int main() {
    auto screen = ScreenInteractive::TerminalOutput();

    int counter = 0;
    auto button = Button("Trykk meg", [&] { counter++; });

    auto renderer = Renderer(button, [&] {
        return vbox({
            text("Antall trykk: " + std::to_string(counter)),
            separator(),
            button->Render(),
        }) | border;
    });

    screen.Loop(renderer);
}