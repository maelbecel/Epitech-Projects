/*
** EPITECH PROJECT, 2023
** PArts
** File description:
** parts
*/

#ifndef PARTS_CPP_
    #define PARTS_CPP_

    #include <iostream>
    #include <string>

    class Arms {
        public:
            Arms(std::string serial = "A-01", bool functionnal = true);
            bool isFunctionnal() const;
            std::string serial() const;
            void informations() const;
        private:
            std::string _serial;
            bool _functionnal;
    };

    class Legs {
        public:
            Legs(std::string serial = "L-01", bool functionnal = true);
            bool isFunctionnal() const;
            std::string serial() const;
            void informations() const;
        private:
            std::string _serial;
            bool _functionnal;
    };

    class Head {
        public:
            Head(std::string serial = "H-01", bool functionnal = true);
            bool isFunctionnal() const;
            std::string serial() const;
            void informations() const;
        private:
            std::string _serial;
            bool _functionnal;
    };

#endif /* !PARTS_CPP_ */
