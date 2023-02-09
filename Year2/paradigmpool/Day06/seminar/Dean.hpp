/*
** EPITECH PROJECT, 2023
** Dean
** File description:
** dean
*/

#ifndef DEAN
    #define DEAN

    #include <iostream>
    #include <string>
    #include <fstream>
    #include <iomanip>
    #include <iostream>
    #include <cstdio>
    #include <algorithm>
    #include <iterator>
    #include <array>
    #include "Student.hpp"
    #include "Assistant.hpp"


    class Dean {
        public:
            Dean(std::string name);
            ~Dean();
            void teachStudent(Student *student, std::string lesson);
            void timeCheck(void);
            std::string getName(void);
        protected:
        private:
            bool _isWorking;
            std::string _name;
    };

#endif /* !DEAN */
