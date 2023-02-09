/*
** EPITECH PROJECT, 2023
** Car
** File description:
** car
*/

#ifndef CARRIER_CPP_
    #define CARRIER_CPP_

    #include "Droid.hpp"

    class Carrier {
        public:
            Carrier(std::string id);
            ~Carrier();
            Carrier &operator<<(Droid *&droid);
            Droid *&operator[](size_t i);
            Carrier &operator>>(Droid *&droid);
            Carrier &operator~();
            bool operator()(int x, int y);
            void setSpeed(size_t x);
            size_t getSpeed() const;
            void setEnergy(size_t x);
            size_t getEnergy() const;
            std::string getId(void) const;
            Droid *getDroid(int i) const;
            size_t GetLength(void) const;
        protected:
        private:
            std::string Id;
            size_t Energy;
            const size_t Attack;
            const size_t Toughness;
            size_t Speed;
            Droid *Droids[5];
    };

    std::ostream &operator<<(std::ostream &str, const Carrier &carrier);

#endif /* !CARRIER_CPP_ */
