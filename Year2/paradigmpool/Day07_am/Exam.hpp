/*
** EPITECH PROJECT, 2023
** exam
** File description:
** exam
*/

#ifndef EXAM_CPP_
#define EXAM_CPP_

class Exam {
    public:
        static bool cheat;
        Exam(bool *ptr);
        bool isCheating(void);
        ~Exam();
        void start(int x);
        void (Exam::*kobayashiMaru)(int x);
    protected:
    private:
};

#endif /* !EXAM_CPP_ */
