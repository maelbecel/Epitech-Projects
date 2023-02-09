/*
** EPITECH PROJECT, 2023
** ar
** File description:
** ar
*/

#ifndef ARRAY_CPP_
    #define ARRAY_CPP_

    #include <iostream>
    #include <functional>
    #include <exception>

    template <typename Type, size_t Size>
    class Array {
        public:

            class OutOfRange : public std::exception {
                public:
                    const char *what() const throw() { return ("Out of range"); }
            };

            Type &operator[](size_t x)
            {
                if (x >= Size)
                    throw OutOfRange();
                return (this->_array[x]);
            }

            Type operator[](size_t x) const
            {
                if (x >= Size)
                    throw OutOfRange();
                return (this->_array[x]);
            }

            std::size_t size() const
            {
                return (Size);
            }

            void forEach(const std::function<void (const Type&)>& task) const
            {
                for (size_t i = 0; i < Size; i++)
                    task(this->_array[i]);
            }

            template < typename U >
            Array <U , Size> convert ( const std :: function < U ( const Type &) >& converter ) const
            {
                Array <U , Size > result ;
                for ( size_t i = 0 ; i < Size ; i ++ )
                    result [ i ] = converter( this -> _array [ i ]);
                return result ;
            }

        protected:
        private:
            Type _array[Size];
    };

    template <typename Type, size_t Size>
    std::ostream &operator<<(std::ostream &os, const Array<Type, Size> &arr)
    {
        os << "[";
        for (size_t i = 0; i < Size; i++) {
            os << arr[i];
            if (i != Size - 1)
                os << ", ";
        }
        os << "]";
        return (os);
    }


#endif /* !ARRAY_CPP_ */
