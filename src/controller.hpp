#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include <string>

using json = nlohmann::json;

class Controller {

    public:
        Controller();
    private:
        void readSettings();
        void writeSettings();
        void readParameter(std::string key);
        std::string settingsFile = "settings.json";
        json config;

        

};