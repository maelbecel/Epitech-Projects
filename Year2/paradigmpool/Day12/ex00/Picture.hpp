/*
** EPITECH PROJECT, 2023
** p
** File description:
** p
*/

#ifndef PICTURE_CPP_
    #define PICTURE_CPP_

    #include <iostream>

    class Picture {
        public:
            Picture();
            Picture(const std :: string & file);
            ~Picture();
            std::string data;
            bool getPictureFromFile ( const std :: string & file ) ;

        protected:
        private:
    };

#endif /* !PICTURE_CPP8 */

