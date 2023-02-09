/*
** EPITECH PROJECT, 2023
** l
** File description:
** l
*/

#ifndef LIST_CPP_
    #define LIST_CPP_

    #include "IObject.hpp"
    #include <iostream>
    #include <list>

    class List {
        public:
            List();
            ~List();
            bool empty() const;
            std::size_t size() const;
            IObject*& front();
            IObject *front() const;
            IObject*& back();
            IObject *back() const;
            void pushBack(IObject* obj);
            void popFront();
            void pushFront(IObject* obj);
            void popBack();
            void clear();
            void forEach(void(*function)(IObject*));

            class InvalidOperationException : public std::exception {
                public:
                    InvalidOperationException() {};
                private:
            };
        protected:
        private:
            std::list <IObject *> _obj;
    };

#endif /* !LIST_CPP_ */
