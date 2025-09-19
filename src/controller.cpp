#include "controller.hpp"
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include <string>

using json = nlohmann::json;

Controller::Controller(){
    readSettings();
    writeSettings();
}

void Controller::readSettings()
{
    std::ifstream file(settingsFile);
    if(!file)
    {
        std::cerr << "Kunne ikke åpne settings.json\n";
    }

}

void Controller::writeSettings()
{

    
    config["log_level"] = "debug";
    config["max_queue_size"] = 1000;
    config["websockets"] = {
        {
            {"url", "wss://example.com/socket1"},
            {"filter", "BTC/USD"}
        },
        {
            {"url", "wss://example.com/socket2"},
            {"filter", "ETH/USD"}
        }
    };

    // 2. Åpne fil for skriving
    std::ofstream file("settings.json");
    if (!file) {
        std::cerr << "Kunne ikke åpne config.json for skriving\n";
        //return 1;
    }
    
    file << config.dump(4);  // dump(4) = pretty print med 4 spaces

    std::cout << "JSON lagret til config.json\n";

}

int main()
{
    Controller c;
    return 0;
}