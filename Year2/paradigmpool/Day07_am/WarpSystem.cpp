/*
** EPITECH PROJECT, 2023
** WarpSystem
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

namespace WarpSystem {
    // ========================================================================
    //                     WarpSystem::QuatumReactor
    // ========================================================================
    QuantumReactor::QuantumReactor()
    {
        this->_stability = true;
    }

    bool QuantumReactor::isStable()
    {
        return this->_stability;
    }

    void QuantumReactor::setStability(bool stability)
    {
        this->_stability = stability;
    }

    // ========================================================================
    //                     WarpSystem::Core
    // ========================================================================
    Core::Core(QuantumReactor *coreReactor)
    {
        this->_coreReactor = coreReactor;
    }

    QuantumReactor *Core::checkReactor()
    {
        return this->_coreReactor;
    }
}
