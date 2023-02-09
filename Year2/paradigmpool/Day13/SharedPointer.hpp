/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGD13-mael1.becel
** File description:
** SharedPointer
*/

#ifndef SHAREDPOINTER_CPP_
    #define SHAREDPOINTER_CPP_

    template <typename Type>
    class SharedPointer {
        public:
            SharedPointer() : _ptr(nullptr) {};
            SharedPointer(Type *ptr) : _ptr(ptr) {};
            SharedPointer(const SharedPointer &ptr)
            {
                _ptr = ptr._ptr;
            };
            ~SharedPointer()
            {
                if (_ptr)
                    delete _ptr;
            };

            void reset()
            {
                _ptr = nullptr;
            };

            Type *get() {return (_ptr);};

            SharedPointer &operator=(Type *ptr)
            {
                _ptr = ptr;
                return (*this);
            }

            SharedPointer &operator=(const SharedPointer &ptr)
            {
                _ptr = ptr._ptr;
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

#endif /* !SHAREDPOINTER_CPP_ */
