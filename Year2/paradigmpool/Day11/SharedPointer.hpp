/*
** EPITECH PROJECT, 2023
** h
** File description:
** h
*/

#ifndef SHAREDPOINTER_CPP_
    #define SHAREDPOINTER_CPP_

    #include "IObject.hpp"
    #include <memory>

    class SharedPointer : public IObject {
        public:
            SharedPointer();
            SharedPointer(IObject *obj);
            SharedPointer(SharedPointer &obj);
            ~SharedPointer();
            void touch();
            void swap(SharedPointer &other);
            void reset(IObject *obj);
            void reset();
            int use_count();
            SharedPointer &operator=(SharedPointer &object);
            SharedPointer &operator=(IObject *object);
            IObject *operator->();
            IObject &operator*();
        protected:
        private:
            std::shared_ptr <IObject> _obj;
    };

#endif /* !SHAREDPOINTER_CPP_ */
