/*
** EPITECH PROJECT, 2023
** u
** File description:
** u
*/

#ifndef UNIQUEPOINTER_CPP_
    #define UNIQUEPOINTER_CPP_

    #include <iostream>

    template <typename Type>
    class UniquePointer {
        public:
            UniquePointer() : _ptr(nullptr) {};
            UniquePointer(Type *ptr) : _ptr(ptr) {};
            ~UniquePointer()
            {
                if (_ptr != nullptr)
                    delete _ptr;
            };

            void reset()
            {
                if (_ptr != nullptr)
                    delete _ptr;
                _ptr = nullptr;
            };

            Type *get() {return (_ptr);};

            UniquePointer &operator=(Type *ptr)
            {
                if (_ptr != nullptr)
                    delete _ptr;
                _ptr = ptr;
                return (*this);
            }

            Type *operator->()
            {
                return (_ptr);
            }

        protected:
        private:
            Type *_ptr;
    };

#endif /* !UNIQUEPOINTER_CPP_ */
