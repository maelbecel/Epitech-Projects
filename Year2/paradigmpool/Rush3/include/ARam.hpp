/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** ARam
*/

#ifndef ARAM_HPP_
    #define ARAM_HPP_
    #include "IMonitorModule.hpp"

class ARam : public IMonitorModule {
    public:
        ARam() {};
        virtual ~ARam() = default;
        virtual void Update(void) = 0;
        virtual std::map<std::string, std::string> getData(void) = 0;
        Core *GetCore(void) const {return nullptr;};
        size_t GetUsage(void) const {return -1;};

    protected:
    private:
};

#endif /* !ARAM_HPP_ */
