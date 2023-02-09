/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** CPU
*/

#ifndef CPU_HPP_
    #define CPU_HPP_

    #include <iostream>
    #include "ACpu.hpp"

    class Core {
        public:
            Core() {};
            ~Core() {};
            void SetActivity(size_t activity) { _activity = activity; };
            size_t GetActivity(void) { return _activity; };
            size_t GetUsage(void) { return _usage; };
            void UpdateUsage(int core);

        protected:
        private:
            size_t _lastTotalUser = 0;
            size_t _lastTotalUserLow = 0;
            size_t _lastTotalSys = 0;
            size_t _lastTotalIdle = 0;
            size_t _usage = 0;
            size_t _activity = 0;
    };

    class CPU : public ACpu {
        public:
            CPU();
            ~CPU();

            void UpdateCore(void);
            void Update(void) override;
            std::map<std::string, std::string> getData(void) override;
            size_t GetUsage(void) const override { return _usage; };

            Core *GetCore(void) const override { return _core; } ;
            std::string GetModel(void) { return _model; };
            size_t GetFrequence(void) { return _frequence; };
            size_t GetMaxFrequence(void) { return _maxFrequence; };
            size_t GetNbCore(void) { return _nbCore; };
            size_t GetNbProcess(void) { return _nbProcess; };
            void UpdateUsage(void);

        protected:
        private:
            std::string _model;
            size_t _frequence;
            size_t _maxFrequence;
            size_t _nbProcess;
            size_t _nbCore;
            size_t _usage = 0;
            Core *_core;
            size_t _lastTotalUser = 0;
            size_t _lastTotalUserLow = 0;
            size_t _lastTotalSys = 0;
            size_t _lastTotalIdle = 0;
    };

#endif /* !CPU_HPP_ */

