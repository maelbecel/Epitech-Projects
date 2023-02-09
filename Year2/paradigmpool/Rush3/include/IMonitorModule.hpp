/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
    #define IMONITORMODULE_HPP_

    #include <map>

    class Core;

    class IMonitorModule {
        public:
            virtual ~IMonitorModule() = default;

            virtual void Update(void) = 0;
            virtual std::map<std::string, std::string> getData(void) = 0;
            virtual Core *GetCore(void) const = 0;
            virtual size_t GetUsage(void) const = 0;

        protected:
        private:
    };

#endif /* !IMONITORMODULE_HPP_ */
