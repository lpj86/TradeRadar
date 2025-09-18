
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
using namespace ftxui;

int main() {
    auto screen = ScreenInteractive::TerminalOutput();

    // Innholdet til hver tab:
    auto page1 = Renderer([] { return text("Dette er TAB 1") | border; });
    auto page2 = Renderer([] { return text("Dette er TAB 2") | border; });
    auto page3 = Renderer([] { return text("Dette er TAB 3") | border; });
    auto page4 = Renderer([] { return text("Dette er TAB 4") | border; });

    // Alle tabs i en vektor:
    std::vector<Component> pages = { page1, page2, page3, page4 };

    // Menyen for å velge tab:
    std::vector<std::string> tab_entries = { "Tab 1", "Tab 2", "Tab 3", "Tab 4" };
    int selected = 0;  // start med første tab
    auto menu = Menu(&tab_entries, &selected);

    // Container::Tab viser riktig "side" basert på `selected`
    auto tab_content = Container::Tab(pages, &selected);

    // Sett sammen layouten: meny øverst, innhold under
    auto layout = Container::Vertical({
        menu,
        tab_content,
    });

    // Legg til litt styling
    auto renderer = Renderer(layout, [&] {
        return vbox({
            text("Fire-tab UI med FTXUI") | bold | center,
            separator(),
            hbox({
                menu->Render() | border,
                separator(),
                tab_content->Render() | flex,
            }),
        });
    });

    // Start appen
    screen.Loop(renderer);
}