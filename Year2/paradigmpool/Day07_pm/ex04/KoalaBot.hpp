/*
** EPITECH PROJECT, 2023
** Koala
** File description:
** koala
*/

#ifndef KOALABOT_CPP_
    #define KOALABOT_CPP_

    #include "Parts.hpp"
    #include <iostream>

    class KoalaBot {
        public:
            KoalaBot(std::string serial = "Bob-01");
            ~KoalaBot();
            void setParts(const Arms &arms);
            void setParts(const Legs &legs);
            void setParts(const Head &head);
            void swapParts(Arms &arms);
            void swapParts(Legs &legs);
            void swapParts(Head &head);
            void informations();
            bool status(void);
        protected:
        private:
            Arms _arms;
            Legs _legs;
            Head _head;
            std::string _serial;
    };

#endif /* !KOALABOT_CPP_ */
