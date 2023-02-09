/*
** EPITECH PROJECT, 2021
** navy
** File description:
** navy
*/

#ifndef NAVY
    #define NAVY

    #define END "E9"
    #define CONNECT "C9"
    #define HIT "H9"
    #define MISSED "M9"
    #define FINISH "F9"

    typedef struct catcher {
        int signals;
        int l_or_i;
        int enemy_pid;
        char letter;
        char number;
        char last_letter;
        char last_number;
    }catcher_t;

    extern catcher_t GAME;

    typedef struct map {
        char **enemy_map;
        char **my_map;
    } map_t;

    typedef struct vector{
        int x;
        int y;
    } vector_t;

    int send(char *pos, int pid);
    int checkmap(char posx, char posy, char **map);
    int check_line(int i, char **map);
    int sink(char **map);
    int waitchoose(char *signal_a, char *signal_b);
    void wait(char *signal);
    void wait_for_connection(void);
    void printmap(char **map);
    int setposmap(map_t *Maps, char *filepath);
    void displaymaps(map_t *Maps);
    void attack_result(char *input, map_t *Maps);
    void defence_result(int pid, map_t *Maps);
    void signal_action(char letter, char number);
    void signal_handler(int sign, siginfo_t *siginfo, void *v);
    void register_signal(void);
    char *get_input(void);
    void initmap(map_t *Maps);

#endif
