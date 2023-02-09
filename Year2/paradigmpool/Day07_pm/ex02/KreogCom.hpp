/*
** EPITECH PROJECT, 2023
** kreog
** File description:
** kreog
*/

#ifndef KREOGCOM_CPP_
#define KREOGCOM_CPP_
#include <iostream>

class KreogCom {
    public :
        KreogCom (int x , int y , int serial ) ;
        ~KreogCom();
        void addCom (int x , int y , int serial ) ;
        void removeCom () ;
        KreogCom *getCom () ;
        void ping () ;
        void locateSquad () const;
    private :
        int _x;
        int _y;
        const int m_serial;
        KreogCom *_next;
};
#endif /* !KREOGCOM_CPP_ */
