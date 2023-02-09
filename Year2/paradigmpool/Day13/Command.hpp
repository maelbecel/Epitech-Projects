/*
** EPITECH PROJECT, 2023
** command
** File description:
** co
*/

#ifndef COMMAND_CPP_
    #define COMMAND_CPP_

    #include <iostream>
    #include <map>
    #include <functional>

    class Command {
        public:
            class Error : public std::exception {
                public:
                    Error(const char *msg) : _msg(msg) {}
                    const char *what() const throw() { return (_msg.c_str());}
                private:
                    std::string _msg;
            };
            Command();
            ~Command();
            void registerCommand ( const std :: string & name , const std :: function < void () >&function ) ;
            void executeCommand ( const std :: string & name ) ;

        protected:
        private:
            std::map<std::string, std::function<void()>> _commands;
    };

#endif /* !COMMAND_CPP_ */
