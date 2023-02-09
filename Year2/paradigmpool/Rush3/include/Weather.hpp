/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** Weather
*/

#ifndef WEATHER_HPP_
    #define WEATHER_HPP_

    #include <iostream>
    #include <string>
    #include <fstream>
    #include <sstream>
    #include "IMonitorModule.hpp"

    class Weather : public IMonitorModule {
        public:
            Weather();
            ~Weather();

            void Update(void) override;
            std::map<std::string, std::string> getData(void) override;
            Core *GetCore(void) const {return nullptr;};
            size_t GetUsage(void) const {return -1;};

            std::string GetCity(void) { return _city; };
            std::string GetCountry(void) { return _country; };
            double GetLatitude(void) { return _latitude; };
            double GetLongitude(void) { return _longitude; };
            double GetTemperature(void) { return _temperature; };
            size_t GetHumidity(void) { return _humidity; };
            size_t GetWind(void) { return _wind; };
            size_t GetCloud(void) { return _cloud; };
            size_t GetPressure(void) { return _pressure; };
            size_t GetPrecipitation(void) { return _precipitation; };
            size_t GetFeelslike(void) { return _feelslike; };

        protected:
        private:
            std::string _city = "";
            std::string _country = "";
            double _latitude = 0;
            double _longitude = 0;
            double _temperature = 0;
            size_t _humidity = 0;
            size_t _wind = 0;
            size_t _cloud = 0;
            size_t _pressure = 0;
            size_t _precipitation = 0;
            double _feelslike = 0;
    };

#endif /* !WEATHER_HPP_ */
