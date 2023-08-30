#include "lib/weather.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    config settings(std::string("C:\\Users\\snab4\\labwork-10-krbyhome\\bin\\config.txt"));
    WeatherApp app(settings);
    app.launch();

    return 0;
}