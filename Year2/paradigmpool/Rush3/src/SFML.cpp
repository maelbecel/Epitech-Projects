/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** SFML
*/

#include "../include/ENGINE.hpp"
#include <string.h>

static const window_sfml_t SCENES_SFML[] =
{
    {
        .size   = (sf::Vector2i) {1920, 100},
        .pos    = (sf::Vector2i) {0, 0},
        .title  = "INFO",
        .type   = IMonitorDisplay::scene::S_INFO,
        .info   = nullptr
    },
    {
        .size   = (sf::Vector2i) {640, 980},
        .pos    = (sf::Vector2i) {0, 100},
        .title  = "CPU",
        .type   = IMonitorDisplay::scene::S_CPU,
        .info   = new CPU()
    },
    {
        .size   = (sf::Vector2i) {640, 490},
        .pos    = (sf::Vector2i) {1280, 590},
        .title  = "RAM",
        .type   = IMonitorDisplay::scene::S_RAM,
        .info   = new RAM()
    },
    {
        .size   = (sf::Vector2i) {640, 490},
        .pos    = (sf::Vector2i) {1280, 100},
        .title  = "NETWORK",
        .type   = IMonitorDisplay::scene::S_NETWORK,
        .info   = new Network()
    },
    {
        .size   = (sf::Vector2i) {640, 980},
        .pos    = (sf::Vector2i) {640, 100},
        .title  = "WEATHER",
        .type   = IMonitorDisplay::scene::S_WEATHER,
        .info   = new Weather()
    }
};

static const size_t NB_TEXTURES = 2;
static const char *TEXTURE_PATHS[] = {
    "assets/panel_bar.png",
    "assets/panel.png"
};

/**
 * It converts an unsigned long to a string
 *
 * @param x The number to convert to a string
 *
 * @return A string
 */
static std::string ULToS(size_t x)
{
    std::string s;
    std::stringstream ss;
    ss << x;
    s = ss.str();
    return s;
}


/**
 * It loads the font and the textures
 */
SFML::SFML() {
    if (!this->font.loadFromFile("assets/popins.ttf")) {
        std::cerr << "Error" << std::endl;
    }
    for (size_t i = 0; i < NB_TEXTURES; i++) {
        this->_texture[i].loadFromFile(TEXTURE_PATHS[i]);
    }
    this->init_scenes();
}

/**
 * Destructor for the SFML class.
 */
SFML::~SFML() {}


/* INIT */

/**
 * It creates a window with the given width, height and title
 */
void SFML::init_window() {
    this->window.create(sf::VideoMode(WIDTH, HEIGHT, 32), "MyGKrellM");
}

/**
 * It initializes the scenes
 */
void SFML::init_scenes() {
    for (size_t i = 0; i < NB_SCENES; i++) {
        this->windows[i] = SCENES_SFML[i];
        this->_sprite[i].setTexture(((SCENES_SFML[i].type == S_INFO)?this->_texture[0]:this->_texture[1]), true);
        this->_sprite[i].setPosition(SCENES_SFML[i].pos.x, SCENES_SFML[i].pos.y);
        this->_sprite[i].setScale(SCENES_SFML[i].size.x / this->_sprite[i].getLocalBounds().width, SCENES_SFML[i].size.y / this->_sprite[i].getLocalBounds().height);
    }
}


/* EVENT */

/**
 * It checks for events and closes the window if the user presses the escape key
 * or closes the window
 */
void SFML::check_events() {

    while (this->window.pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            this->window.close();
            EXIT = true;
        }
        if (this->event.type == sf::Event::KeyPressed) {
            if (this->event.key.code == sf::Keyboard::Key::Space) {
                this->window.close();
            }
        }
    }
}


/* DRAW */

/**
 * It sets the font, size, color, style, string, and position of the text
 *
 * @param i the row of the text
 * @param j the number of the text to be drawn
 * @param str The string to be displayed
 * @param pos The position of the text on the screen.
 */
void SFML::draw_text(int i, int j, std::string str, sf::Vector2f pos)
{
    text[i][j].setFont(this->font);
    text[i][j].setCharacterSize(26);
    text[i][j].setFillColor(sf::Color::Cyan);
    text[i][j].setStyle(sf::Text::Bold);
    text[i][j].setString(str);
    text[i][j].setPosition(pos);
    window.draw(text[i][j]);
}

/**
 * It initializes a rectangle shape with a size and position
 *
 * @param number the number that you want to display
 * @param pos The position of the bar.
 *
 * @return A sf::RectangleShape object.
 */
static sf::RectangleShape init_rect(float number, sf::Vector2i pos)
{
    sf::RectangleShape rect;
    rect.setPosition(pos.x, pos.y);
    rect.setSize(sf::Vector2f(300 * (number / 100), 30));
    return rect;
}

/**
 * It draws a loading bar
 *
 * @param at the current value
 * @param on the total number of files to load
 * @param pos The position of the loading bar
 */
void SFML::draw_load(int at, int on, sf::Vector2i pos)
{
    sf::RectangleShape rect = init_rect((float)(at + 1) / (on) * 100, pos);
    sf::RectangleShape rect2 = init_rect((float)(on + 1) / (on) * 100, pos);
    rect.setFillColor(sf::Color::Green);
    rect2.setFillColor(sf::Color::Red);
    window.draw(rect2);
    if (at > 0)
        window.draw(rect);
}

/**
 * It draws the info text on the screen
 *
 * @param info The window_sfml_t struct that contains the window and the
 * sf::Event.
 */
void SFML::draw_info(window_sfml_t info) {
    (void)info;
    text[S_INFO][0].setFont(this->font);
    text[S_INFO][0].setCharacterSize(26);
    text[S_INFO][0].setFillColor(sf::Color::Cyan);
    text[S_INFO][0].setStyle(sf::Text::Bold);
    text[S_INFO][0].setString(Info::getOsName() + " | " + Info::getKernelVersion() + " | " + Info::getUserName() + " | " + Info::getHostname() + " | " + Info::getDateTime());
    text[S_INFO][0].setPosition(560, 25);
    window.draw(text[S_INFO][0]);
}

/**
 * It draws the CPU information on the screen
 *
 * @param cpu The window_sfml_t structure that contains the CPU information.
 */
void SFML::draw_cpu(window_sfml_t cpu)
{
    CPU info;
    Core *cores = cpu.info->GetCore();
    cpu.info->Update();
    std::map<std::string, std::string> data = cpu.info->getData();

    draw_text(S_CPU, 0, "Model: " + data["model"], sf::Vector2f(50, 150));
    draw_text(S_CPU, 1, "Nb Core: " + data["nbCore"], sf::Vector2f(50, 220));
    draw_text(S_CPU, 2, "Usage: " + data["usage"] + "%", sf::Vector2f(50, 290));
    draw_text(S_CPU, 3, "Frequence: " + data["frequence"] + "Mhz", sf::Vector2f(50, 360));
    draw_load(stoi(data["usage"]), 100, sf::Vector2i(300, 290));
    draw_load(stoi(data["frequence"]), stoi(data["maxFrequence"]), sf::Vector2i(300, 360));
    for (size_t s = 0; s < info.GetNbCore(); s++) {
        draw_text(S_CPU, s, "Core " + std::to_string(s + 1) + "                                                              [" + ULToS((cores[s].GetUsage() > 100) ? 100 : cores[s].GetUsage()) + "%]", sf::Vector2f(50, 450 + (s * 70)));
        draw_load((cores[s].GetUsage() > 100) ? 100 : cores[s].GetUsage(), 100, sf::Vector2i(150, 450 + (s * 70)));
    }
}

/**
 * It draws the ram usage, swap usage, and battery usage
 *
 * @param ram The window_sfml_t struct that contains the information about the
 * window.
 */
void SFML::draw_ram(window_sfml_t ram) {
    ram.info->Update();
    std::map<std::string, std::string> data = ram.info->getData();

    draw_load(stoi(data["MemCurrent"]), stoi(data["MemTotal"]), sf::Vector2i(1580, 700));

    draw_load(stoi(data["SwapCurrent"]), stoi(data["SwapTotal"]), sf::Vector2i(1580, 820));

    draw_load(stoi(Battery::getPercent()), 100, sf::Vector2i(1580, 940));

    draw_text(S_RAM, 0, "Memory: " + data["MemCurrent"] + " MB", sf::Vector2f(1320, 700));
    draw_text(S_RAM, 1, "Swap: " + data["SwapCurrent"] + " MB", sf::Vector2f(1320, 820));
    draw_text(S_RAM, 2, "Battery: " + Battery::getPercent() + " %", sf::Vector2f(1320, 940));
}

/**
 * It draws the network information on the screen
 *
 * @param net The window_sfml_t object that was created in the main function.
 */
void SFML::draw_network(window_sfml_t net) {
    net.info->Update();
    std::map<std::string, std::string> data = net.info->getData();

    draw_text(S_NETWORK, 0, "IP: " + data["ip"], sf::Vector2f(1320, 190));
    draw_text(S_NETWORK, 1, "Download: " + data["downloadBytes"] + " Bytes (" + data["downloadPackets"] + " packets)", sf::Vector2f(1320, 290));
    draw_text(S_NETWORK, 2, "Upload: " + data["uploadBytes"] + " Bytes (" + data["uploadPackets"] + " packets)", sf::Vector2f(1320, 390));
}

/**
 * It draws the weather information on the screen
 *
 * @param weather The weather window object
 */
void SFML::draw_weather(window_sfml_t weather) {
    std::map<std::string, std::string> data = weather.info->getData();

    draw_text(S_WEATHER, 0, "City: " + data["city"], sf::Vector2f(690, 150));
    draw_text(S_WEATHER, 1, "Country: " + data["country"], sf::Vector2f(690, 150 + (1 * 50)));
    draw_text(S_WEATHER, 2, "Latitude: " + data["latitude"], sf::Vector2f(690, 150 + (2 * 50)));
    draw_text(S_WEATHER, 3, "Longitude: " + data["longitude"], sf::Vector2f(690, 150 + (3 * 50)));
    draw_text(S_WEATHER, 4, "Temperature: " + data["temperature"] + " *C (feels like " + data["feelslike"] + " *C)", sf::Vector2f(690, 150 + (4 * 50)));

    draw_text(S_WEATHER, 5, "Humidity: " + data["humidity"] + " %", sf::Vector2f(690, 150 + (5 * 50)));
    draw_load(stoi(data["humidity"]), 100, sf::Vector2i(690, 150 + (6 * 50)));

    draw_text(S_WEATHER, 6, "Wind speed : " + data["wind"] + " km/h", sf::Vector2f(690, 150 + (7 * 50)));
    draw_text(S_WEATHER, 7, "Cloudcover : " + data["cloud"] + " %", sf::Vector2f(690, 150 + (8 * 50)));
    draw_load(stoi(data["cloud"]), 100, sf::Vector2i(690, 150 + (9 * 50)));

    draw_text(S_WEATHER, 8, "Pressure : " + data["pressure"] + " hPa", sf::Vector2f(690, 150 + (10 * 50)));

    draw_text(S_WEATHER, 9, "Precipitation : " + data["precipitation"] + " mm", sf::Vector2f(690, 150 + (11 * 50)));
}



/**
 * It draws the background of the scene, then calls the appropriate function to
 * draw the content of the scene
 */
void SFML::draw_scenes() {
    for (size_t i = 0; i < NB_SCENES; i++) {
        this->window.draw(this->_sprite[i]);

        switch (this->windows[i].type) {
            case S_INFO:
                this->draw_info(this->windows[i]);
                break;
            case S_CPU:
                this->draw_cpu(this->windows[i]);
                break;
            case S_RAM:
                this->draw_ram(this->windows[i]);
                break;
            case S_NETWORK:
                this->draw_network(this->windows[i]);
                break;
            case S_WEATHER:
                this->draw_weather(this->windows[i]);
                break;
        default:
            break;
        }
    }
}


/* LOOP */

/**
 * If a second has passed, clear the window, draw the scenes, and display the
 * window.
 */
void SFML::check_clocks()
{
    static float clock = 0.0f;
    sf::Time time = _clock.getElapsedTime();
    float now = time.asSeconds();
    float diff = now - clock;

    while (diff >= 1.f) {
        diff -= 1.f;
        this->window.clear(sf::Color::Black);

        this->draw_scenes();

        this->window.display();
        clock = time.asSeconds();
    }
}

/**
 * It initializes the window, then it checks for events, checks the clocks, and
 * updates the window
 */
void SFML::game_loop() {
    this->init_window();

    while (this->window.isOpen()) {
        this->check_events();
        this->check_clocks();
        this->windows[4].info->Update();
    }
}
