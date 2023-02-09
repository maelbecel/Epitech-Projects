/*
** EPITECH PROJECT, 2023
** p
** File description:
** p
*/

#ifndef PRIEST_CPP_
#define PRIEST_CPP_

#include "Enchanter.hpp"

class Priest : public Enchanter {
    public:
        Priest(const std :: string & name , int power);
        virtual void rest();
        ~Priest();
    protected:
    private:
};

#endif /* !PRIEST_CPP_ */
