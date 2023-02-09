/*
** EPITECH PROJECT, 2023
** frui
** File description:
** frui
*/

#ifndef AFRUIT_CPP_
    #define AFRUIT_CPP_

    #include "IFruit.hpp"

    class AFruit : public IFruit {
        public:
            AFruit();
            AFruit(IFruit &fruit);
            AFruit(std::string name, unsigned int vitamins);
            AFruit(std::string name, unsigned int vitamins, bool peeled);
            virtual ~AFruit() = default;
            unsigned int getVitamins() const;
            std::string getName() const;
            bool isPeeled() const;
            void peel();
            void setVitamins(unsigned int vitamins);
            void setName(const std::string &name);
            IFruit *clone() const;
        protected:
        private:
            bool _isPeeled = false;
            unsigned int _vitamins;
            std::string _name;
    };

#endif /* !AFRUIT_CPP_ */
