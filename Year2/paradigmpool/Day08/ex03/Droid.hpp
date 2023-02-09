/*
** EPITECH PROJECT, 2023
** droid
** File description:
** droid
*/

#ifndef DROID_CPP_
    #define DROID_CPP_

    #include <iostream>
    #include "DroidMemory.hpp"

    class Droid {
        public:
            Droid(std::string serial);
            Droid(const Droid &damaged);
            ~Droid();
            Droid &operator=(const Droid &old);
            bool operator==(const Droid &other) const;
            bool operator!=(const Droid &other) const;
            Droid &operator<<(size_t x);
            std::string getId() const;
            void setId(std::string serial);
            size_t getEnergy() const;
            void setEnergy(size_t energy);
            size_t getAttack(void) const;
            size_t getToughness(void) const;
            void setStatus(std::string *status);
            std::string *getStatus(void) const;
            bool operator()(const std::string *task, size_t required);
        protected:
        private:
            DroidMemory *BattleData;
            std::string Id;
            size_t Energy;
            const size_t Attack;
            const size_t Toughness;
            std::string *Status;
    };

    std::ostream &operator<<(std::ostream &str, const Droid &drd);

#endif /* !DROID_CPP_ */
