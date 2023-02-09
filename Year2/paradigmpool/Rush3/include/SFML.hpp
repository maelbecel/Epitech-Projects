/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** SFML
*/

#ifndef SFML_HPP_
    #define SFML_HPP_
    #include "IMonitorDisplay.hpp"
    #include "Info.hpp"
    #include "Cpu.hpp"
    #include "Memory.hpp"

    typedef struct window_sm_s {
        sf::Vector2i size;
        sf::Vector2i pos;
        const char *title;
        IMonitorDisplay::scene type;
        IMonitorModule *info;
    } window_sfml_t;

    class SFML : public IMonitorDisplay {
        private:
            sf::RenderWindow window;
            sf::Event event;
            sf::Clock _clock;
            sf::Font font;
            sf::Text text[NB_SCENES][50];
            sf::Texture _texture[2];
            sf::Sprite _sprite[NB_SCENES];
            window_sfml_t windows[NB_SCENES];
            int WIDTH {1920};
            int HEIGHT {1080};
            // int save[10] = {0};

        public:
            SFML();
            ~SFML();

            void init_scenes() override;
            void init_window() override;

            void draw_load(int at, int on, sf::Vector2i pos);
            void draw_text(int i, int j, std::string str, sf::Vector2f pos);
            void draw_info(window_sfml_t info);
            void draw_cpu(window_sfml_t cpu);
            void draw_ram(window_sfml_t ram);
            void draw_network(window_sfml_t net);
            void draw_weather(window_sfml_t weather);
            void draw_scenes() override;

            void check_events() override;
            void check_clocks() override;
            void game_loop() override;

        protected:
    };

#endif /* !SFML_HPP_ */
