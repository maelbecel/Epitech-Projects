/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
    #define IMONITORDISPLAY_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <iostream>
    #include "IMonitorModule.hpp"

    class IMonitorDisplay {
        public:
            virtual ~IMonitorDisplay() = default;

            typedef enum {
                S_INFO,
                S_RAM,
                S_CPU,
                S_NETWORK,
                S_WEATHER,
                NB_SCENES
            } scene;

            typedef enum {
                PANEL_BAR, PANEL
            } texture;

            virtual void init_scenes() = 0;
            virtual void init_window() = 0;
            virtual void draw_scenes() = 0;
            virtual void check_events() = 0;
            virtual void check_clocks() = 0;
            virtual void game_loop() = 0;

        protected:
        private:
    };

#endif /* !IMONITORDISPLAY_HPP_ */
