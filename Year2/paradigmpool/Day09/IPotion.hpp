/*
** EPITECH PROJECT, 2023
** popo
** File description:
** popo
*/

#ifndef IPOTION_CPP_
    #define IPOTION_CPP_

    class IPotion {
        public:
            IPotion() = default;
            virtual ~IPotion() = default;
            virtual int getHealth() const = 0;
            virtual int getPower() const = 0;
    };

#endif /* !IPOTION_CPP_ */
