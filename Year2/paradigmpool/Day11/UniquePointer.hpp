/*
** EPITECH PROJECT, 2023
** g
** File description:
** g
*/

#ifndef UNIQUEPOINTER_CPP_
    #define UNIQUEPOINTER_CPP_

    #include <iostream>
    #include "IObject.hpp"
    #include <memory>

    class UniquePointer : public IObject {
        public:
            UniquePointer();
            UniquePointer(IObject *obj);
            ~UniquePointer();
            void touch();
            void swap(UniquePointer &other);
            void reset(IObject *obj);
            void reset();
            UniquePointer &operator=(IObject *object);
            IObject *operator->();
            IObject &operator*();
        protected:
        private:
            std::unique_ptr <IObject> _obj;
    };

#endif /* !UNIQUEPOINTER_CPP_ */
