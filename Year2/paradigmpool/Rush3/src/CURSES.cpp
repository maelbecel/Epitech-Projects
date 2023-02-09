/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** CURSES
*/

#include "../include/ENGINE.hpp"

static const window_crs_t SCENES_CURSES[] =
{
    {
        .size   = (sf::Vector2i) {210, 2},
        .pos    = (sf::Vector2i) {0, 0},
        .title  = "INFO",
        .type   = IMonitorDisplay::scene::S_INFO,
        .info   = nullptr,
        .win    = NULL
    },
    {
        .size   = (sf::Vector2i) {210, 25},
        .pos    = (sf::Vector2i) {2, 0},
        .title  = "CPU",
        .type   = IMonitorDisplay::scene::S_CPU,
        .info   = new CPU(),
        .win    = NULL
    },
    {
        .size   = (sf::Vector2i) {104, 10},
        .pos    = (sf::Vector2i) {29, 0},
        .title  = "RAM",
        .type   = IMonitorDisplay::scene::S_RAM,
        .info   = new RAM(),
        .win    = NULL
    },
    {
        .size   = (sf::Vector2i) {104, 10},
        .pos    = (sf::Vector2i) {29, 106},
        .title  = "NETWORK",
        .type   = IMonitorDisplay::scene::S_NETWORK,
        .info   = new Network(),
        .win    = NULL
    },
    {
        .size   = (sf::Vector2i) {104, 13},
        .pos    = (sf::Vector2i) {41, 0},
        .title  = "WEATHER",
        .type   = IMonitorDisplay::scene::S_WEATHER,
        .info   = new Weather(),
        .win    = NULL
    }
};

/**
 * It converts an unsigned long to a string
 *
 * @param x The number to convert to a string
 *
 * @return A string
 */
static std::string ULToString(size_t x)
{
    std::string s;
    std::stringstream ss;
    ss << x;
    s = ss.str();
    return s;
}

/**
 * It converts a string to an unsigned long
 *
 * @param x The string to convert to a size_t
 *
 * @return The size_t value of the string.
 */
static size_t ULFromString(std::string x)
{
    size_t s;
    std::stringstream ss;
    ss << x;
    ss >> s;
    return s;
}

/**
 * A constructor for the class Curses.
 */
Curses::Curses() {}

/**
 * It calls the endwin() function from the ncurses library
 */
Curses::~Curses() {
    endwin();
}


/* INIT */

/**
 * It creates a new window for each scene
 */
void Curses::init_scenes() {
    for (int i = 0; i < NB_SCENES; i++) {
        this->windows[i] = SCENES_CURSES[i];
        this->windows[i].win = newwin (
            this->windows[i].size.y, this->windows[i].size.x,
            this->windows[i].pos.x, this->windows[i].pos.y
        );
    }
}

/**
 * It initializes the ncurses library, sets up the color pairs, and calls the
 * init_scenes function.
 * 
 * @return A pointer to the window.
 */
void Curses::init_window() {
    this->win = initscr();
    this->current_key = 0;
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();
    if (!has_colors())
        return;
    init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(GREEN, COLOR_WHITE, COLOR_GREEN);
    init_pair(YELLOW, COLOR_WHITE, COLOR_YELLOW);
    init_pair(RED, COLOR_WHITE, COLOR_RED);
    init_pair(GREY, COLOR_WHITE, COLOR_WHITE);
    init_scenes();
}


/* EVENT */

/**
 * If the current key is not null, then check the events.
 */
void Curses::check_events() {
    // if (this->current_key);
}


/* DRAW */

/**
 * It draws a loading bar
 *
 * @param win The window to draw the bar in.
 * @param current The current value of the bar
 * @param max The maximum value of the bar.
 * @param size The size of the bar in characters.
 * @param position The position of the bar in the window.
 */
static void drawLoadBar(window_crs_t win, size_t current, size_t max, sf::Vector2i size, sf::Vector2i position)
{
    float percent = (float) current / (float) max;
    int barSize = (int) (size.x * percent);

    for (int i = 0; i < size.y; i++) {
        if (percent * 100 < 33)
            wattron(win.win, COLOR_PAIR(GREEN));
        else if (percent * 100 < 66)
            wattron(win.win, COLOR_PAIR(YELLOW));
        else
            wattron(win.win, COLOR_PAIR(RED));
        for (int j = 0; j < size.x; j++) {
            if (j >= barSize)
                wattron(win.win, COLOR_PAIR(GREY));
            mvwprintw(win.win, position.y + i, position.x + j, " ");
        }
    }
    wattron(win.win, COLOR_PAIR(WHITE));
}


/**
 * It draws the info window
 *
 * @param win The window to draw the info in.
 */
void Curses::draw_info(window_crs_t win)
{
    wborder(win.win, ' ',' ',' ',0,' ',' ', ACS_HLINE, ACS_HLINE);
    std::string str = "User: " + Info::getUserName() + "    |    Hostname: " + Info::getHostname() + "    |    OS: " + Info::getOsName() + "    |    Kernel: " + Info::getKernelVersion() + "    |    Battery: " + Battery::getPercent() + "%     |     Date: " + Info::getDateTime();
    mvwprintw(win.win, 0, 1, "INFO |");
    mvwprintw(win.win, 0, (win.size.x / 2) - (str.length() / 2), str.c_str());
}

/**
 * It draws the CPU window
 *
 * @param win The window to draw on
 */
void Curses::draw_cpu(window_crs_t win)
{
    CPU cpu;
    win.info->Update();
    Core *cores = win.info->GetCore();
    size_t i = 0;
    std::string tmp = "";

    wborder(win.win, 0,0,0,0,0,0,0,0);
    mvwprintw(win.win, 0, 4, "CPU");
    for (; i < cpu.GetNbCore() && i < 4; i++) {
        mvwprintw(win.win, 2 + (i * 5), 2, "Core %d", i);
        drawLoadBar(win, cores[i].GetUsage(), 100, (sf::Vector2i) {50, 1}, (sf::Vector2i) {10, 2 + (int(i) * 5)});
        tmp = "[" + ULToString(cores[i].GetUsage()) + "%]\t" + ULToString(cores[i].GetActivity()) + " MHz";
        mvwprintw(win.win, 2 + (i * 5), 65, tmp.c_str());
    }
    for (; i < cpu.GetNbCore(); i++) {
        mvwprintw(win.win, 2 + ((i - 4)* 5), 110, "Core %d", i);
        drawLoadBar(win, cores[i].GetUsage(), 100, (sf::Vector2i) {50, 1}, (sf::Vector2i) {120, 2 + ((int(i) - 4) * 5)});
        tmp = "[" + ULToString(cores[i].GetUsage()) + "%]\t" + ULToString(cores[i].GetActivity()) + " MHz";
        mvwprintw(win.win, 2 + ((i - 4) * 5), 175, tmp.c_str());
    }
    mvwprintw(win.win, 22, 2, "CPU   ");
    drawLoadBar(win, win.info->GetUsage(), 100, (sf::Vector2i) {50, 1}, (sf::Vector2i) {10, 22});
    tmp = "[" + ULToString(win.info->GetUsage()) + "%]\t" + ULToString(cpu.GetFrequence()) + " MHz";
    mvwprintw(win.win, 22, 65, tmp.c_str());
}

/**
 * It draws the RAM window
 *
 * @param win The window to draw in
 */
void Curses::draw_ram(window_crs_t win)
{
    win.info->Update();
    std::map<std::string, std::string> data = win.info->getData();
    wborder(win.win, 0,0,0,0,0,0,0,0);
    mvwprintw(win.win, 0, 4, "RAM");
    mvwprintw(win.win, 3, 2, "Memory : ");
    drawLoadBar(win, ULFromString(data["MemCurrent"]), ULFromString(data["MemTotal"]), (sf::Vector2i) {50, 1}, (sf::Vector2i) {10, 3});
    std::string tmp = "[" + ULToString(ULFromString(data["MemCurrent"]) * 100 / ULFromString(data["MemTotal"])) + "%]\t" + ULToString(ULFromString(data["MemCurrent"]) / 1024) + " MB";
    mvwprintw(win.win, 3, 65, tmp.c_str());
    mvwprintw(win.win, 6, 2, "Swap : ");
    drawLoadBar(win, ULFromString(data["SwapCurrent"]), ULFromString(data["SwapTotal"]), (sf::Vector2i) {50, 1}, (sf::Vector2i) {10, 6});
    tmp = "[" + ULToString(ULFromString(data["SwapCurrent"]) * 100 / ULFromString(data["SwapTotal"])) + "%]\t" + ULToString(ULFromString(data["SwapCurrent"]) / 1024) + " MB";
    mvwprintw(win.win, 6, 65, tmp.c_str());
}

/**
 * It draws the network window
 *
 * @param win The window to draw on.
 */
void Curses::draw_network(window_crs_t win)
{
    win.info->Update();
    std::map<std::string, std::string> data = win.info->getData();
    std::string tmp = "";
    wborder(win.win, 0,0,0,0,0,0,0,0);
    mvwprintw(win.win, 0, 4, "Network");
    tmp = "Download : " + data["downloadBytes"] + " bytes (" + data["downloadPackets"] + " packets)";
    mvwprintw(win.win, 3, 2, tmp.c_str());
    tmp = "Upload : " + data["uploadBytes"] + " bytes (" + data["uploadPackets"] + " packets)";
    mvwprintw(win.win, 6, 2, tmp.c_str());
}

/**
 * It draws the weather window
 *
 * @param win The window to draw in
 */
void Curses::draw_weather(window_crs_t win)
{
    win.info->Update();
    std::map<std::string, std::string> data = win.info->getData();
    wborder(win.win, 0,0,0,0,0,0,0,0);
    mvwprintw(win.win, 0, 4, "Weather");
    mvwprintw(win.win, 2, 2, "City : %s", data["city"].c_str());
    mvwprintw(win.win, 4, 2, "Country : %s", data["country"].c_str());
    mvwprintw(win.win, 6, 2, "Latitude : %s°", data["latitude"].c_str());
    mvwprintw(win.win, 8, 2, "Longitude : %s°", data["longitude"].c_str());
    mvwprintw(win.win, 2, 52, "Temperature : %s °C (feels like %s°C)", data["temperature"].c_str(), data["feelslike"].c_str());
    mvwprintw(win.win, 4, 52, "Pressure : %s hPa", data["pressure"].c_str());
    mvwprintw(win.win, 6, 52, "Wind speed : %s km/h", data["wind"].c_str());
    mvwprintw(win.win, 8, 52, "Precipitation : %smm", data["precipitation"].c_str());

    mvwprintw(win.win, 10, 2, "Cloudcover : ");
    drawLoadBar(win, ULFromString(data["cloud"]), 100, (sf::Vector2i) {25, 1}, (sf::Vector2i) {16, 10});
    mvwprintw(win.win, 10, 42, "[%s%]", data["cloud"].c_str());
    mvwprintw(win.win, 10, 52, "Humidity : ");
    drawLoadBar(win, ULFromString(data["humidity"]), 100, (sf::Vector2i) {25, 1}, (sf::Vector2i) {64, 10});
    mvwprintw(win.win, 10, 90, "[%s%]", data["humidity"].c_str());
}


/**
 * It clears the window, then calls the appropriate function to draw the scene
 */
void Curses::draw_scenes() {
    for (size_t i = 0; i < NB_SCENES; i++) {
        wclear(this->windows[i].win);
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
        wrefresh(this->windows[i].win);
    }
}


/* LOOP */

/**
 * It's a function that checks the clock and draws the scenes if the clock has
 * changed
 */
void Curses::check_clocks()
{
    clock_t start = clock() / CLOCKS_PER_SEC;
    static int test = 0;

    if (start != test) {
        test++;
        this->draw_scenes();
        refresh();
    }
}

/**
 * It initializes the window, then it waits for the user to press a key, and if
 * the key is the exit key, it exits the game
 */
void Curses::game_loop()
{
    this->init_window();

    while (this->current_key != this->exit_key && this->current_key != ' ') {
        this->current_key = getch();
        this->check_events();
        this->check_clocks();
    }
    if (this->current_key == this->exit_key)
        EXIT = true;
    endwin();
}
