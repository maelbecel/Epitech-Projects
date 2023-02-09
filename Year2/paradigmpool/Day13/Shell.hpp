/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGD13-mael1.becel
** File description:
** Shell
*/

#ifndef SHELL_CPP_
    #define SHELL_CPP_

    #include <iostream>
    #include <sstream>
    #include <string>
    #include <fstream>

    class Shell {
        public:
            class Error : public std::exception {
                public:
                    Error(const char *msg) : _msg(msg) {}
                    const char *what() const noexcept override { return (_msg.c_str());}
                private:
                    std::string _msg;
            };
            class Warning : public std::exception {
                public:
                    Warning(const char *msg) : _msg(msg) {}
                    const char *what() const noexcept override { return (_msg.c_str());}
                private:
                    std::string _msg;
            };

            Shell(std::istream &stream);
            ~Shell();
            void next();

            template <typename Type>
            Type extract()
            {
                Type value;
                _buffer >> value;
                if (_buffer.fail())
                    throw Warning("Invalid conversion");
                return (value);
            }

        protected:
        private:
            std::istream &_stream;
            std::stringstream _buffer;
    };

#endif /* !SHELL_CPP_ */
