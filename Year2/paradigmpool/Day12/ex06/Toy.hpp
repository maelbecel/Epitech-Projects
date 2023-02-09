/*
** EPITECH PROJECT, 2023
** TOY_CPP_
** File description:
** d
*/

#ifndef TOY_CPP_
    #define TOY_CPP_

    #include "Picture.hpp"
    #include <iostream>

    class Toy {
        public:
            enum ToyType {
                BASIC_TOY,
                ALIEN,
                BUZZ,
                WOODY
            };
            Toy();
            Toy(Toy const &toy);
            ~Toy();
            Toy(ToyType type, const std::string name, const std::string filename);
            ToyType getType() const;
            std::string getName() const;
            void setName(std::string name);
            bool setAscii(std::string file);
            std::string getAscii() const;
            Toy &operator=(Toy const &toy);
            Toy &operator<<(const std::string &str);
            virtual bool speak(const std::string text);
            virtual bool speak_es(const std ::string text);
            class Error {
                public :
                    enum ErrorType {
                        UNKNOWN,
                        PICTURE,
                        SPEAK
                    };
                    Error() {};
                    Error(Toy::Error::ErrorType err);
                    ~Error();
                    const char *what() const noexcept;
                    const char *where() const noexcept;
                    ErrorType type;
            };
            Error getLastError();
            Error _error;
        protected:
        private:
            ToyType _type;
            std::string _name;
            Picture _ascii;
    };
    std::ostream &operator<<(std::ostream &os, Toy &toy);

#endif /* !TOY_CPP_ */
