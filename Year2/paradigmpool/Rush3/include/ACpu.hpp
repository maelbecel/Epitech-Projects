/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** ACpu
*/

#ifndef ACPU_HPP_
    #define ACPU_HPP_
    #include "IMonitorModule.hpp"

class ACpu : public IMonitorModule {
    public:
        ACpu() {};
        virtual ~ACpu() = default;

        virtual void Update(void) = 0;
        virtual std::map<std::string, std::string> getData(void) = 0;
        virtual Core *GetCore(void) const = 0;
        virtual size_t GetUsage(void) const = 0;

    protected:
    private:
};

#endif /* !ACPU_HPP_ */
