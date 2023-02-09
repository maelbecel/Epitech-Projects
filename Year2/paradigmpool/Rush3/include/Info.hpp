/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** Info
*/

#ifndef INFO_HPP_
    #define INFO_HPP_

    #include <iostream>

    class Info {
        public:
            Info();
            ~Info();
            static std::string getOsName();
            static std::string getHostname();
            static std::string getUserName();
            static std::string getKernelVersion();
            static std::string getDateTime();

        protected:
        private:
            std::string dateTime;
    };

#endif /* !INFO_HPP_ */
