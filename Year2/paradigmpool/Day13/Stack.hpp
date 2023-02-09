/*
** EPITECH PROJECT, 2023
** st
** File description:
** stack
*/

#ifndef STACK_CPP_
    #define STACK_CPP_

    #include <stack>
    #include <iostream>


    class Stack {
        public:
            class Error : public std::exception {
                public:
                    Error(const char *msg) : _msg(msg) {}
                    const char *what() const throw() { return (_msg.c_str());}
                private:
                    std::string _msg;
            };
            Stack();
            ~Stack();
            void push(double value);
            double pop();
            double top();
            void add();
            void sub();
            void mul();
            void div();

        protected:
        private:
            std::stack<double> _stack;
    };

#endif /* !STACK_CPP_ */
