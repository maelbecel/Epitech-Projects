/*
** EPITECH PROJECT, 2023
** h
** File description:
** h
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Algorithm.hpp"
#include "../Array.hpp"
#include "../Matrix.hpp"
#include "../Stack.hpp"
#include "../Command.hpp"

Test(Command_cpp, command)
{
    Command command ;
    Stack stack ;

    try {
        command.registerCommand ("push", [& stack ]() { stack . push (4.2) ; }) ;
        command.registerCommand ("display", [& stack ]() { std :: cout << stack . top () <<
        std :: endl ; }) ;
        command.registerCommand ("add", [& stack ]() { stack . add () ; }) ;
        command.registerCommand ("sub", [& stack ]() { stack . sub () ; }) ;
        command.registerCommand ("mul", [& stack ]() { stack . mul () ; }) ;
        command.registerCommand ("div", [& stack ]() { stack . div () ; }) ;
        command.registerCommand ("display", []() {}) ;
    }
    catch ( const std :: exception & e ) {
        std :: cout << e . what () << std :: endl ;
    }
    try {
        command . executeCommand ("push") ;
        command . executeCommand ("push") ;
        command . executeCommand ("push") ;
        command . executeCommand ("add") ;
        command . executeCommand ("div") ;
        command . executeCommand ("display") ;
        command . executeCommand ("jej") ;
    }
    catch ( const std :: exception & e ) {
        std :: cout << e . what () << std :: endl ;
    }
}

Test(Algorithm_hpp, algorithm)
{
    int *x = new int();
    int *y = new int();
    *x = 1;
    *y = 2;
    swap(*x, *y);
    cr_assert_eq(*x, 2);
    cr_assert_eq(*y, 1);
    cr_assert_eq(min(1, 2), 1);
    cr_assert_eq(min(2, 1), 1);
    cr_assert_eq(max(1, 2), 2);
    cr_assert_eq(max(2, 1), 2);
    cr_assert_eq(clamp(1, 2, 3), 2);
    cr_assert_eq(clamp(4, 2, 3), 3);
    cr_assert_eq(clamp(2, 2, 3), 2);
    delete x;
    delete y;
}

Test(Stack_cpp, stack)
{
    Stack stack;
    std::cout << "========== Push ===========" << std::endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cr_assert_eq(stack.top(), 3);
    stack.pop();
    cr_assert_eq(stack.top(), 2);
    stack.pop();
    cr_assert_eq(stack.top(), 1);
    stack.pop();
    std::cout << "============Mul==========" << std::endl;
    stack.push(5);
    stack.push(6);
    stack.mul();
    cr_assert_eq(stack.top(), 30);
    std::cout << "==========Add============" << std::endl;
    stack.pop();
    stack.push(5);
    stack.push(6);
    stack.add();
    cr_assert_eq(stack.top(), 11);
    std::cout << "==========Sub============" << std::endl;
    stack.pop();
    stack.push(5);
    stack.push(6);
    stack.sub();
    cr_assert_eq(stack.top(), 1);
    std::cout << "==========Div============" << std::endl;
    stack.pop();
    stack.push(2);
    stack.push(2);
    stack.div();
    cr_assert_eq(stack.top(), 1);
    std::cout << "==========Div by 0==========" << std::endl;
    stack.pop();
    stack.push(0);
    stack.push(6);
    try {
        stack.div();
    } catch (const std::exception &e) {
        std::cout << "error = " << e.what() << std::endl;
    }
    try {
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();
    } catch (const std::exception &e) {
        std::cout << "error = " << e.what() << std::endl;
    }
    try {
        stack.top();
    } catch (const std::exception &e) {
        std::cout << "error = " << e.what() << std::endl;
    }
    try {
        stack.push(1);
        stack.add();
    } catch (const std::exception &e) {
        std::cout << "error = " << e.what() << std::endl;
    }
    try {
        stack.sub();
    } catch (const std::exception &e) {
        std::cout << "error = " << e.what() << std::endl;
    }
    try {
        stack.mul();
    } catch (const std::exception &e) {
        std::cout << "error = " << e.what() << std::endl;
    }
    try {
        stack.div();
    } catch (const std::exception &e) {
        std::cout << "error = " << e.what() << std::endl;
    }
}

