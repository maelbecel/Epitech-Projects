/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** Ram
*/

#ifndef RAM_HPP_
    #define RAM_HPP_

    #include <iostream>
    #include "ARam.hpp"

    class InfoMemory {
        public:
            InfoMemory() {};
            ~InfoMemory() {};
            InfoMemory(const std::string name);
            size_t GetValue(void) const;
            void SetValue(const size_t &value);
        protected:
        private:
            std::string _name;
            size_t _value;
    };

    class RAM : public ARam {
        public:
            RAM() {Update();};
            ~RAM() {};

            void Update(void) override;
            std::map<std::string, std::string> getData(void) override;

            InfoMemory GetMemTotal(void) const;
            InfoMemory GetMemCurrent(void) const;
            InfoMemory GetSwapTotal(void) const;
            InfoMemory GetSwapCurrent(void) const;

        protected:
        private:
            InfoMemory _memTotal;
            InfoMemory _memCurrent;
            InfoMemory _swapTotal;
            InfoMemory _swapCurrent;
    };

#endif /* !RAM_HPP_ */

