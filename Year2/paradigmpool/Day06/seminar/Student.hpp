/*
** EPITECH PROJECT, 2023
** Student
** File description:
** paradigm
*/

#ifndef STUDENT
    #define STUDENT

    #include <iostream>
    #include <string>
    #include <fstream>

    #define FILL(nrg, wth) ((nrg + wth) > 100) ? 100 : (nrg + wth)

    class Student {
        public:
            Student(std::string name);
            ~Student();
            bool learn(std::string name);
            void drink(std::string drink);
            std::string getName(void);
        protected:
        private:
            std::string _name;
            size_t _energy;
    };

#endif /* !STUDENT */
