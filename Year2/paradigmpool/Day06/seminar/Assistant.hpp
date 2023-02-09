/*
** EPITECH PROJECT, 2023
** Assistant
** File description:
** Assistant
*/

#ifndef ASSISTANT_HPP_
    #define ASSISTANT_HPP_

    #include <iostream>
    #include <string>
    #include <fstream>
    #include <iomanip>
    #include <iostream>
    #include <cstdio>
    #include "Student.hpp"

    class Assistant {
        public:
            Assistant(int id);
            ~Assistant();
            void giveDrink(Student *student, std::string drink);
            void helpStudent(Student *student);
            std::string readDrink(std::string student);
            void timeCheck(void);
            int getId(void);
        protected:
        private:
            bool _isWorking;
            int _id;
    };

#endif /* !ASSISTANT_HPP_ */
