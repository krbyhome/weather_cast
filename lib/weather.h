#pragma once

#include <cpr/cpr.h>
#include "fort.hpp"
#include <nlohmann/json.hpp>

#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <windows.h>

const std::vector<std::string> kDayTime = {"Ночь", "Утро", "День", "Вечер"};
const std::vector<std::string> kWeekdays = {"Вс. ", "Пн. ", "Вт. ", "Ср. ", "Чт. ", "Пт. ", "Сб. "};
const std::vector<std::string> kMonth = {" Декабря", " Февраля", " Марта", " Апреля", " Мая",
                                         " Июня", " Июля", " Августа", " Сентября", " Октября",
                                         " Ноября", " Декабря", " Января"};
constexpr size_t kForecastDays = 14;
constexpr char kEsc = 27;
constexpr size_t kPicRows = 5;

const std::vector<std::string> kCodeUnknown = {
        "    .-.      ",
        "     )     ",
        "    (        ",
        "     `-'     ",
        "      •      "
};

const std::vector<std::string> kCodeCloudy = {
        "             ",
        "     .--.    ",
        "  .-(    ).  ",
        " (___.)) ",
        "             "
};

const std::vector<std::string> kCodeFog = {
        "             ",
        " _ - _ - _ - ",
        "  _ - _ - _  ",
        " _ - _ - _ - ",
        "             "
};

const std::vector<std::string> kCodeHeavyRain = {
        "     .-.     ",
        "    (   ).   ",
        "   (___()  ",
        "  ,',',','   ",
        "  ,',',','   "
};

const std::vector<std::string> kCodeHeavyShowers = {
        " _`/\"\".-.    ",
        "  ,\\_(   ).  ",
        "   /(___() ",
        "   ,',',','  ",
        "   ,',',','  "
};

const std::vector<std::string> kCodeHeavySnow = {
        "     .-.     ",
        "    (   ).   ",
        "   (___()  ",
        "   * * * *   ",
        "  * * * *    "
};

const std::vector<std::string> kCodeHeavySnowShowers = {
        " _`/\"\".-.    ",
        "  ,\\_(   ).  ",
        "   /(___() ",
        "    * * * *  ",
        "   * * * *   "
};

const std::vector<std::string> kCodeLightRain = {
        "     .-.     ",
        "    (   ).   ",
        "   (___()  ",
        "    ' ' ' '  ",
        "   ' ' ' '   "
};

const std::vector<std::string> kCodeLightSleet = {
        "     .-.     ",
        "    (   ).   ",
        "   (___()  ",
        "    ' * ' *  ",
        "   * ' * '   "
};

const std::vector<std::string> kCodeLightSnow = {
        "     .-.     ",
        "    (   ).   ",
        "   (___()  ",
        "    *  *  *  ",
        "   *  *  *   "
};

const std::vector<std::string> kCodePartlyCloudy = {
        "   \\         ",
        " _ /\"\".-.    ",
        "   \\_(   ).  ",
        "   /(___() ",
        "             "
};

const std::vector<std::string> kCodeSunny = {
        "    \\   /    ",
        "     .-.     ",
        "  - (   ) -  ",
        "     `-'     ",
        "    /   \\    "
};

const std::vector<std::string> kCodeThunderyHeavyRain = {
        "     .-.     ",
        "    (   ).   ",
        "   (___()  ",
        "  ,'7',7,'   ",
        "  ,','7','   "
};

const std::vector<std::string> kCodeVeryCloudy = {
        "             ",
        "     .--.    ",
        "  .-(    ).  ",
        " (___.)__) ",
        "             "
}; //pics

const std::vector<std::string>& get_pic(int weather_code) {
    switch(weather_code) {
        case 0:
            return kCodeSunny;
        case 1:
            return kCodeSunny;
        case 2:
            return kCodePartlyCloudy;
        case 3:
            return kCodeVeryCloudy;
        case 45:
            return kCodeFog;
        case 48:
            return kCodeLightSleet;
        case 51:
            return kCodeLightSleet;
        case 53:
            return kCodeLightSleet;
        case 55:
            return kCodeLightSleet;
        case 56:
            return kCodeLightSleet;
        case 57:
            return kCodeLightSleet;
        case 61:
            return kCodeLightRain;
        case 63:
            return kCodeLightRain;
        case 65:
            return kCodeHeavyRain;
        case 66:
            return kCodeHeavySnowShowers;
        case 67:
            return kCodeHeavySnowShowers;
        case 71:
            return kCodeLightSnow;
        case 73:
            return kCodeHeavySnow;
        case 75:
            return kCodeHeavySnow;
        case 77:
            return kCodeHeavySnow;
        case 80:
            return kCodeHeavyRain;
        case 81:
            return kCodeHeavyRain;
        case 82:
            return kCodeHeavyRain;
        case 85 ...86:
            return kCodeHeavySnow;
        case 95:
            return kCodeThunderyHeavyRain;
    }

    return kCodeUnknown;
}

std::string get_weather_type(int weather_code) {
    switch(weather_code) {
        case 0:
            return "Ясно";
        case 1:
            return "В основном ясно";
        case 2:
            return "Местами облачно";
        case 3:
            return "Пасмурно";
        case 45:
            return "Туман";
        case 48:
            return "Заморозки";
        case 51:
            return "Слегка моросит";
        case 53:
            return "Моросит";
        case 55:
            return "Сильно моросит";
        case 56:
            return "Гололед";
        case 57:
            return "Сильный гололед";
        case 61:
            return "Грибной дождь";
        case 63:
            return "Дождь";
        case 65:
            return "Ливень";
        case 66:
            return "Град";
        case 67:
            return "Сильный град";
        case 71:
            return "Редкий снегопад";
        case 73:
            return "Снегопад";
        case 75:
            return "Сильный снегопад";
        case 77:
            return "Снегопад";
        case 80:
            return "Ливень";
        case 81:
            return "Ливень";
        case 82:
            return "Ливень";
        case 85:
            return "Снегопад";
        case 86:
            return "Сильный снегопад";
        case 95:
            return "Гроза";
    }

    return "Приятная погода";
}

class config {
public:
    std::vector<std::string>& get_cities() {
        return cities;
    }

    [[nodiscard]] size_t get_days() const {
        return days;
    }

    [[nodiscard]] size_t get_freq() const {
        return freq;
    }

    std::string& get_path() {
        return path;
    }

    void set_path(const std::string& path_) {
        path = path_;
    }

    config() {
        cities = {"Kemerovo"};
        days = 1;
        freq = 60;
    }

    explicit config(const std::string& path_) {
        path = path_;
        process();
    }

    friend class WeatherApp;

private:
    std::vector<std::string> cities;
    size_t days;
    size_t freq;
    std::string path;

    void process() {
        std::string config_name;
        config_name = get_path();
        std::ifstream input(config_name);
        nlohmann::json cfg;
        if (input.is_open()) {
            input >> cfg;
        } else {
            std::cout << config_name << "\n";
            std::cerr << "couldn't open config file\n";

            return;
        }

        cities = std::vector<std::string>(cfg["cities"]);
        days = cfg["days"];
        freq = cfg["freq"];
    }

    void process(const std::string& config_name) {
        set_path(config_name);
        process();
    }
};

//struct to absorb daily weather info
struct day_prediction {
    std::vector<std::string> weather_type;
    std::vector<std::string> temperature;
    std::vector<std::string> wind;
    std::vector<std::string> humidity;
    std::vector<std::string> date;
    std::vector<int> weather_codes;
    std::vector<std::string> out_of_idx = {""};

    std::vector<std::string>& operator[](size_t idx) {
        switch (idx) {
            case 1:
                return weather_type;
            case 2:
                return temperature;
            case 3:
                return wind;
            case 4:
                return humidity;
        }

        return out_of_idx;
    }
};

class WeatherApp {
private:
    config settings;
    day_prediction daily;
    int city_idx;
    std::string cur_city;
    size_t cur_days;

    nlohmann::json catch_errors() {
        std::ifstream log("log.txt");
        if (!log.is_open()) {
            std::cerr << "something went wrong\n";

            return -1;
        }

        nlohmann::json logs;
        std::cout << 1;
        log >> logs;

        return logs;
    }

    std::string process_cord(double cord) {
        std::string cord_ = std::to_string(cord);
        std::replace(cord_.begin(), cord_.end(), ',', '.');

        return cord_;
    }

    void get_cords(const std::string& city, cpr::Response& coordinates) {
        std::string coordinates_URL = "https://api.api-ninjas.com/v1/city?name=" + city;
        coordinates = cpr::Get(cpr::Url{coordinates_URL},
                               cpr::Header{{"X-Api-Key", "X7xa1yelRNuebwHZGIDMoGnFwuunB3JRaiqCM4ZF"}},
                               cpr::Authentication{"sufiyarov2000@gmail.com", "lab10pass", cpr::AuthMode::BASIC});

        if (coordinates.error) {
            catch_errors();
        }
    }

    void get_weather(const std::string& longitude, const std::string& latitude, cpr::Response& weather) {
        std::string weather_url = "https://api.open-meteo.com/v1/forecast";
        weather = cpr::Get(cpr::Url{weather_url},
                           cpr::Parameters{{"latitude",      latitude},
                                           {"longitude",     longitude},
                                           {"hourly",        "temperature_2m,windspeed_10m,relativehumidity_2m,apparent_temperature,rain,weathercode"},
                                           {"forecast_days", "16"}});

        if (weather.error) {
            catch_errors();
        }
    }

    nlohmann::json get_response(const std::string& city) {
        cpr::Response coordinates;
        get_cords(city, coordinates);

        nlohmann::json coordinates_json;
        coordinates_json = nlohmann::json::parse(coordinates.text);

        std::string latitude_ = process_cord(coordinates_json[0]["latitude"]);
        std::string longitude_ = process_cord(coordinates_json[0]["longitude"]);

        cpr::Response weather;
        get_weather(longitude_, latitude_, weather);

        nlohmann::json weather_json;
        weather_json = nlohmann::json::parse(weather.text);

        std::ofstream log("log.txt", std::ofstream::trunc);
        log << weather_json << "\n";

        return weather_json;
    }

    void ClickEvent(char click, nlohmann::json& weather_response) {
        if (click == '+' || click == '-') {
            if (click == '+') {
                ++cur_days;
                cur_days = std::min(cur_days, kForecastDays);
            } else {
                --cur_days;
                cur_days = std::max(cur_days, 1ULL);
            }
            print(cur_days);
        } else if (click == 'n' || click == 'p') {
            if (click == 'n') {
                ++city_idx;
                city_idx %= static_cast<int>(settings.cities.size());
            } else {
                --city_idx;
                if (city_idx < 0) {
                    city_idx = static_cast<int>(settings.cities.size()) - 1;
                }
            }
            cur_city = settings.cities[city_idx];
            weather_response = get_response(cur_city);
            process_weather(weather_response, cur_days);
        }
    }

    void clear_daily() {
        daily.humidity.clear();
        daily.temperature.clear();
        daily.wind.clear();
        daily.weather_type.clear();
        daily.date.clear();
    }

    void process_weather(nlohmann::json& weather_response, size_t days) {
        clear_daily();
        for (size_t day = 0; day < kForecastDays; ++day) {
            std::string time = weather_response["hourly"]["time"][day * 24];
            time_to_date(time);
            daily.date.push_back(time);

            size_t day_hours = 24;
            size_t hour_freq = 6;
            long double temperature_sum = 0;
            for (size_t k = 0; k < day_hours / hour_freq; ++k) {
                //getting weather type
                std::string weather_type;
                weather_type = get_weather_type(int(weather_response["hourly"]["weathercode"][day * day_hours + k * hour_freq]));
                daily.weather_type.push_back(weather_type);
                daily.weather_codes.push_back(int(weather_response["hourly"]["weathercode"][day * day_hours + k * hour_freq]));

                //getting temperature
                for (size_t i = k * hour_freq + 0; i < k * hour_freq + hour_freq; ++i) {
                    temperature_sum += static_cast<long double>(weather_response["hourly"]["temperature_2m"][i + day * day_hours]);
                }
                long double average_t;
                average_t = temperature_sum / day_hours;

                std::string temperature;
                if (average_t >= 0) {
                    temperature = "+";
                }
                temperature += std::to_string(average_t);
                temperature = temperature.substr(0, temperature.find('.') + 2) + " °C";

                daily.temperature.push_back(temperature);

                //getting windspeed
                size_t windspeed_lowerbound;
                size_t windspeed_upperbound;
                windspeed_lowerbound = static_cast<size_t>(weather_response["hourly"]["windspeed_10m"][day * day_hours + k * hour_freq]);
                windspeed_upperbound = static_cast<size_t>(weather_response["hourly"]["windspeed_10m"][day * day_hours + k * hour_freq]);
                for (size_t i = k * hour_freq + 0; i < k * hour_freq + hour_freq; ++i) {
                    windspeed_lowerbound = std::min(windspeed_lowerbound, static_cast<size_t>(weather_response["hourly"]["windspeed_10m"][i + day * day_hours]));
                    windspeed_upperbound = std::max(windspeed_upperbound, static_cast<size_t>(weather_response["hourly"]["windspeed_10m"][i + day * day_hours]));
                }
                std::string windspeed;
                if (windspeed_lowerbound == windspeed_upperbound) {
                    windspeed = std::to_string(windspeed_lowerbound) + " км/ч";
                } else {
                    windspeed = std::to_string(windspeed_lowerbound) + "-" + std::to_string(windspeed_upperbound) + " км/ч";
                }
                daily.wind.push_back(windspeed);

                //getting humidity
                long double rain_height = 0;
                for (size_t i = k * hour_freq + 0; i < k * hour_freq + hour_freq; ++i) {
                    rain_height += static_cast<long double>(weather_response["hourly"]["rain"][i + day * day_hours]);
                }
                size_t relative_humidity = 0;
                for (size_t i = k * hour_freq + 0; i < k * hour_freq + hour_freq; ++i) {
                    relative_humidity += static_cast<size_t>(weather_response["hourly"]["relativehumidity_2m"][i + day * day_hours]);
                }
                relative_humidity = relative_humidity / hour_freq;
                std::string humidity;
                humidity = std::to_string(rain_height);
                humidity = humidity.substr(0, humidity.find('.') + 2) + " мм | " + std::to_string(relative_humidity) + "%";
                daily.humidity.push_back(humidity);
            }
        }
        print(days);
    }

    void time_to_date(std::string& time) {
        std::string parsed_date;
        std::tm time_tm = {};
        std::istringstream ss(time);
        ss >> std::get_time(&time_tm, "%Y-%m-%dT%H:%M");
        std::mktime(&time_tm);
        time = kWeekdays[time_tm.tm_wday];
        time += std::to_string(time_tm.tm_mday) + kMonth[time_tm.tm_mon];
    }

    void print_daily(size_t cell) {
        const std::vector<std::string>& picture = get_pic(daily.weather_codes[cell]);
        size_t idx = 0;
        for (const auto& layer : picture) {
            std::cout << layer << "\t";
            std::cout << daily[idx][cell] << "\n";
            ++idx;
        }
        std::cout << "\n";
    }

    void print(size_t days) {
        system("cls");
        std::cout << "Прогноз погоды в " << cur_city << "\n";
        print_daily(0);
        for (size_t day = 0; day < days; ++day) {
            std::cout << daily.date[day] << "\n";
            fort::utf8_table daily_table;
            daily_table.set_border_style(FT_SOLID_ROUND_STYLE);
            daily_table << fort::header << kDayTime[0] << kDayTime[1] << kDayTime[2] << kDayTime[3] << fort::endr;

            for (size_t row = 0; row < kPicRows; ++row) {
                for (size_t t = 0; t < kDayTime.size(); ++t) {
                    const std::vector<std::string> &picture = get_pic(daily.weather_codes[day * 4 + t]);
                    daily_table << picture[row] + " " + daily[row][(day * kDayTime.size() + t) % daily[row].size()];
                }
                daily_table << fort::endr;
            }

            std::cout << daily_table.to_string() << "\n";
        }
    }

public:
    explicit WeatherApp(const config& settings_) {
        settings = settings_;
        city_idx = 0;
        cur_days = 0;
    }

    ~WeatherApp() = default;

    void launch() {
        city_idx = 0;
        cur_city = settings.cities[city_idx];
        cur_days = settings.get_days();

        auto start_time = std::chrono::system_clock::now();

        nlohmann::json weather_response;
        weather_response = get_response(cur_city);
        process_weather(weather_response, cur_days);
        print(cur_days);

        while (true) {
            auto cur_time = std::chrono::system_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::seconds>(cur_time - start_time);

            if (duration.count() >= settings.freq) {
                weather_response = get_response(cur_city);
                process_weather(weather_response, cur_days);
                start_time = std::chrono::system_clock::now();
            }

            if (_kbhit()) {
                char click = _getch();
                if (click == kEsc || click == 'q') {
                    std::cout << "Exit...\n";

                    break;
                }
                ClickEvent(click, weather_response);
                start_time = std::chrono::system_clock::now();
            }
        }
    }
};
