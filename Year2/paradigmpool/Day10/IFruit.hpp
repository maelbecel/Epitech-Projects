/*
** EPITECH PROJECT, 2023
** fruit
** File description:
** druit
*/

#ifndef IFRUIT_CPP_
    #define IFRUIT_CPP_

    #include <iostream>

    class IFruit {
        public:
            virtual ~IFruit() = default;
            virtual unsigned int getVitamins() const = 0;
            virtual std::string getName() const = 0;
            virtual bool isPeeled() const = 0;
            virtual void peel() = 0;
            virtual IFruit *clone () const = 0;
        protected:
        private:
    };

    std::ostream &operator<<(std::ostream &s, const IFruit &fruit);

#endif /* !IFRUIT_CPP_ */
