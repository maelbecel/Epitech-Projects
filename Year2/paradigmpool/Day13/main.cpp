
// #include <iostream>
// #include "Shell.hpp"
// #include "Stack.hpp"
// #include "Command.hpp"
// #include "Matrix.hpp"
// #include <math.h>

// int main ( void )
// {
//     Matrix <3 , 1 > point ;
//     Matrix <3 , 3 > translation ;
//     Matrix <3 , 3 > rotation ;
//     point (0 , 0) = 3;
//     point (1 , 0) = 2;
//     point (2 , 0) = 1;
//     std :: cout << "P: " << point << std :: endl ;
//     translation (0 , 0) = translation (1 , 1) = translation (2 , 2) = 1.0;
//     translation (0 , 2) = 4;
//     translation (1 , 2) = 2;
//     point = translation * point ;
//     std :: cout << "T: " << translation << std :: endl ;
//     std :: cout << "P: " << point << std :: endl ;
//     rotation (0 , 0) = + std :: cos ( M_PI / 2) ;
//     rotation (0 , 1) = - std :: sin ( M_PI / 2) ;
//     rotation (1 , 0) = + std :: sin ( M_PI / 2) ;
//     rotation (1 , 1) = + std :: cos ( M_PI / 2) ;
//     rotation (2 , 2) = 1;
//     point = rotation * point ;
//     std :: cout << "R: " << rotation << std :: endl ;
//     std :: cout << "P: " << point << std :: endl ;
//     return 0;
// }

// #include "Shell.hpp"
// #include "Stack.hpp"
// #include "Command.hpp"
// #include <iostream>

// int main ( void )
// {
// Shell shell ( std :: cin ) ;
// Stack stack ;
// Command command ;
// command . registerCommand ("push", [& shell , & stack ]() { stack . push ( shell . extract <
// double >() ) ; }) ;
// command . registerCommand ("display", [& stack ]() { std :: cout << stack . top () << std ::
// endl ; }) ;
// command . registerCommand ("add", [& stack ]() { stack . add () ; }) ;
// command . registerCommand ("sub", [& stack ]() { stack . sub () ; }) ;
// command . registerCommand ("mul", [& stack ]() { stack . mul () ; }) ;
// command . registerCommand ("div", [& stack ]() { stack . div () ; }) ;
// while ( true ) {
// try {
// std :: cout << "> " << std :: flush ;
// shell . next () ;
// command . executeCommand ( shell . extract < std :: string >() ) ;
// }
// catch ( const Shell :: Error & e ) {
// std :: cout << e . what () << std :: endl ;
// break ;
// }
// catch ( const std :: exception & e ) {
// std :: cout << e . what () << std :: endl ;
// continue ;
// }
// }
// return 0;
// }

#include <iostream>
#include "SharedPointer.hpp"
#include <memory>

class Example
{
private :
    int _id ;
public :
    Example (int id ) : _id ( id ) { std :: cout << "#" << _id << " construction " << std ::
    endl ; }
    ~ Example () { std :: cout << "#" << _id << " destruction " << std :: endl ; }
    void method () const { std :: cout << "#" << _id << " method " << std :: endl ; }
};

void my(void)
{
    SharedPointer <Example> ptr1 (new Example (1));
    SharedPointer <Example> ptr2 (ptr1);
    SharedPointer <Example> ptr3;

    ptr2.get();
    ptr1.reset ();
    ptr3 = ptr2;
    ptr2.get()->method();
    ptr3->method();
}

void reel(void)
{
    std::shared_ptr <Example> rptr1 (new Example (1));
    std::shared_ptr <Example> rptr2 (rptr1);
    std::shared_ptr <Example> rptr3;

    rptr2.get();
    rptr1.reset ();
    rptr3 = rptr2;
    rptr2.get()->method();
    rptr3->method();
}

int main ( void )
{
    my();
    std::cout << "------------------" << std::endl;
    reel();
}