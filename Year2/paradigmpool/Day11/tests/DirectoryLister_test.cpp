/*
** EPITECH PROJECT, 2023
** h
** File description:
** h
*/

#include <criterion/criterion.h>
#include "../IDirectoryLister.hpp"
#include "../DirectoryLister.hpp"
#include "../SafeDirectoryLister.hpp"

Test(Directory_create, dir_create)
{
    DirectoryLister dl;
    DirectoryLister dldeux = DirectoryLister(".", true);
    DirectoryLister dltrois = DirectoryLister("jej", false);
    dl.get();
    dldeux.get();
    dldeux.get();
    dldeux.get();
    dldeux.get();
    dldeux.get();
    dltrois.get();
    dltrois.get();
    dltrois.open("..", true);
    dltrois.open("/home", false);
    dltrois.get();
    dltrois.get();
}

void myLs ( const std :: string & directory )
{
    try {
        SafeDirectoryLister dl ( directory , false ) ;
        std :: cout << directory << ":" << std :: endl ;
        for ( std :: string file = dl . get () ; true ; file = dl . get () )
            std :: cout << file << std :: endl ;
        dl.get();
    } catch ( const IDirectoryLister :: NoMoreFileException & e ) {
        return ;
    }
    throw std :: runtime_error (" should not happen ") ;
}

Test(IDirectory_create, idirectory_create)
{
    try {
        myLs ("..") ;
        myLs ("jej") ;
        myLs ("/") ;
    } catch ( const IDirectoryLister :: OpenFailureException & e ) {
        std :: cerr << " failure : " << e . what () << std :: endl ;
    } catch ( const IDirectoryLister :: NoMoreFileException & e ) {
        std :: cerr << " unexpected error : " << e . what () << std :: endl ;
    } catch ( const std :: exception & e ) {
        std :: cerr << " unexpected error : " << e . what () << std :: endl ;
    }
    try {
        SafeDirectoryLister dl;
        dl.open(".", false);
    } catch ( const IDirectoryLister::OpenFailureException & e ) {
        std :: cerr << " failure : " << e . what () << std :: endl ;
    }
    try {
        SafeDirectoryLister dl;
        dl.get();
    } catch ( const IDirectoryLister::OpenFailureException & e ) {
        std :: cerr << " failure : " << e . what () << std :: endl ;
    }
    try {
        SafeDirectoryLister dld("/", false);
        dld.open("..", true);
    } catch ( const IDirectoryLister::OpenFailureException & e ) {
        std :: cerr << " failure : " << e . what () << std :: endl ;
    }
    IDirectoryLister :: NoMoreFileException x;
    x.what();
}
