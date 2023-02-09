/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** ANetwork
*/

#ifndef ANETWORK_HPP_
    #define ANETWORK_HPP_
    #include "IMonitorModule.hpp"

class ANetwork : public IMonitorModule {
    public:
        ANetwork() {};
        virtual ~ANetwork() = default;
        virtual void Update(void) = 0;
        virtual std::map<std::string, std::string> getData(void) = 0;
        Core *GetCore(void) const {return nullptr;};
        size_t GetUsage(void) const {return -1;};

    protected:
    private:
};

#endif /* !ANETWORK_HPP_ */
