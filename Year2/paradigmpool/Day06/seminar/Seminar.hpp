/*
** EPITECH PROJECT, 2023
** Seminar
** File description:
** Seminar
*/

#ifndef SEMINAR
    #define SEMINAR

    #include <iostream>
    #include <string>
    #include <fstream>
    #include <iomanip>
    #include <iostream>
    #include <cstdio>
    #include "Student.hpp"
    #include "Assistant.hpp"
    #include "Dean.hpp"
    #include "vector"

    class Seminar {
        public:
            Seminar();
            ~Seminar();
            void run(void);
            void addDean(Dean *dean);
            void addStudent(Student *student);
            void addAssistant(Assistant *assistant);
        protected:
        private:
            void showSeminar(void);
            std::vector<Dean *> _deans;
            std::vector<Student *> _students;
            std::vector<Assistant *> _assistants;
    };

#endif /* !SEMINAR */
