/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** Battery
*/

#ifndef BATTERY_HPP_
    #define BATTERY_HPP_

    #include <iostream>
    #include <string>

    class Battery {
        public:
            Battery();
            ~Battery();

            static std::string getPercent();

        protected:
        private:
    };

#endif /* !BATTERY_HPP_ */
