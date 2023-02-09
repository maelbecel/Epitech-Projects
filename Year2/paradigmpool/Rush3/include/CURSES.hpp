/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** CURSE
*/

#ifndef CURSES_HPP_
    #define CURSES_HPP_
    #include <ncurses.h>
    #include "IMonitorDisplay.hpp"

    typedef struct window_s {
        sf::Vector2i size;
        sf::Vector2i pos;
        const char *title;
        IMonitorDisplay::scene type;
        IMonitorModule *info;
        WINDOW *win;
    } window_crs_t;

    class Curses : public IMonitorDisplay {
        private:
            const int exit_key{27};
            int current_key{0};
            window_crs_t windows[NB_SCENES];
            WINDOW *win;

        public:
            Curses();
            ~Curses();

            void init_scenes() override;
            void init_window() override;

            void draw_info(window_crs_t win);
            void draw_cpu(window_crs_t win);
            void draw_ram(window_crs_t win);
            void draw_network(window_crs_t net);
            void draw_weather(window_crs_t weather);
            void draw_scenes() override;

            void check_events() override;
            void check_clocks() override;
            void game_loop() override;

        protected:
    };

#endif /* !CURSES_HPP_ */
