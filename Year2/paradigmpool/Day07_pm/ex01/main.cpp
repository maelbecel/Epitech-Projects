#include "KoalaBot.hpp"
#include <iostream>
#include "Parts.hpp"

int main ()
{
    const KoalaBot kb ;
    std :: cout << std :: boolalpha << kb . status () << std :: endl ;
    kb . informations () ;
    return 0;
}