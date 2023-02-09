/*
** EPITECH PROJECT, 2022
** shell.c
** File description:
** shell
*/

#ifndef SHELL
    #define SHELL
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <fcntl.h>
    #include <stddef.h>
    #include <signal.h>
    #include <string.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <errno.h>

    ////////////////////////////////////////////////////////////
    /// \brief Execute basic commands
    //
    /// \param parsed parsed arguments
    /// \param env environnement
    ///
    ////////////////////////////////////////////////////////////
    void basic(char **parsed, char **env);

    ////////////////////////////////////////////////////////////
    /// \brief Execute setenv command
    //
    /// \param parsed parsed arguments
    /// \param env environnement
    ///
    ////////////////////////////////////////////////////////////
    void set_env(char **parsed, char **env);

    ////////////////////////////////////////////////////////////
    /// \brief Execute unsetenv command
    //
    /// \param parsed parsed arguments
    /// \param env environnement
    ///
    ////////////////////////////////////////////////////////////
    void unset_env(char **parsed, char **env);

    ////////////////////////////////////////////////////////////
    /// \brief Execute cd command
    //
    /// \param parsed parsed arguments
    /// \param env environnement
    ///
    ////////////////////////////////////////////////////////////
    void changedir(char **parsed, char **env);

    ////////////////////////////////////////////////////////////
    /// \brief Display a string array in the standard output
    //
    /// \param arg string array who should be print
    ///
    ////////////////////////////////////////////////////////////
    void print_arg(char **arg);

    ////////////////////////////////////////////////////////////
    /// \brief Handle basic commands not in binary
    //
    /// \param parsed parsed arguments
    /// \param env environnement
    ///
    ////////////////////////////////////////////////////////////
    void action(char **parsed, char **env);

    ////////////////////////////////////////////////////////////
    /// \brief Display an error if exit had bad arguments
    //
    /// \param arg string array who should be print
    ///
    ////////////////////////////////////////////////////////////
    void bad_exit(char **arg);

    ////////////////////////////////////////////////////////////
    /// \brief Display a string in the error output
    //
    /// \param string string to be display
    ///
    ////////////////////////////////////////////////////////////
    void my_puterror(char *string);

    ////////////////////////////////////////////////////////////
    /// \brief Display exit in the standard output
    //
    /// \param arg arguments list to take exit
    ///
    /// \return The number of the exit
    ///
    ////////////////////////////////////////////////////////////
    int my_exit (char **arg);

    ////////////////////////////////////////////////////////////
    /// \brief Check if a string contain only alphanumeric characters
    //
    /// \param string string to check
    ///
    /// \return 1 if string contain only alphanumeric characters, 0 otherwise
    ///
    ////////////////////////////////////////////////////////////
    int is_alpha_num(char *string);

    ////////////////////////////////////////////////////////////
    /// \brief Check if a char contain only is an alphanumeric
    /// characterscontain only
    //
    /// \param c char to check
    ///
    /// \return 1 if char is an alphanumeric character, 0 otherwise
    ///
    ////////////////////////////////////////////////////////////
    int char_alpha(char c);

    ////////////////////////////////////////////////////////////
    /// \brief Get the value of a certain variable in the environnement
    //
    /// \param parsed parsed arguments
    /// \param env    environnement
    ///
    /// \return The value of the variable in the environnement
    ///
    ////////////////////////////////////////////////////////////
    char *getvalue(char **env, char *var);

    ////////////////////////////////////////////////////////////
    /// \brief Create a string for the environnement
    //
    /// \param name  name of the variable
    /// \param value value of the variable
    ///
    /// \return The concatenation of name and value with an '=' between them
    ///
    ////////////////////////////////////////////////////////////
    char *create_var(char *name, char *value);

    ////////////////////////////////////////////////////////////
    /// \brief Get the name of the variable with an environnement string
    //
    /// \param string string to find the variable name
    ///
    /// \return The name of the variable in the string
    ///
    ////////////////////////////////////////////////////////////
    char *getname(char *string);

    ////////////////////////////////////////////////////////////
    /// \brief Read the input
    ///
    /// \return A string of the input read
    ///
    ////////////////////////////////////////////////////////////
    char *read_input(void);

    ////////////////////////////////////////////////////////////
    /// \brief Parse a string into a string array
    //
    /// \param input     string to cut
    /// \param separator list of separators where string must be cut
    ///
    /// \return The string array of the string cut on separators given in
    ///         arguments
    ///
    ////////////////////////////////////////////////////////////
    char **parse(char *input, char *separator);

    ////////////////////////////////////////////////////////////
    /// \brief Display or not the prompt
    //
    /// \param env     environnement
    ///
    ////////////////////////////////////////////////////////////
    void show_prompt(char **env);

    ////////////////////////////////////////////////////////////
    /// \brief Get a value for en env variable
    ///
    /// \param env     environnement
    /// \param var     variable to check
    ///
    /// \return The value of \a var in the environnement
    ///
    ////////////////////////////////////////////////////////////
    char *getvalue(char **env, char *var);

    ////////////////////////////////////////////////////////////
    /// \brief Get the name of the variable
    ///
    /// \param string    line to check
    ///
    /// \return The name of \a var in the line
    ///
    ////////////////////////////////////////////////////////////
    char *getname(char *string);

    ////////////////////////////////////////////////////////////
    /// \brief Get the prompt
    ///
    /// \param env    environnement
    ///
    /// \return Return the prompt
    ///
    ////////////////////////////////////////////////////////////
    char *getprompt(char **env);

#endif
