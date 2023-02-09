/*
** EPITECH PROJECT, 2023
** SystemWarp
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_CPP_
    #define WARPSYSTEM_CPP_

    namespace WarpSystem {
        class QuantumReactor {
            public:
                QuantumReactor();
                bool isStable () ;
                void setStability(bool stability);
            protected:
            private:
                bool _stability;
        };
        class Core {
            public:
                Core(QuantumReactor *coreReactor);
                QuantumReactor *checkReactor();
            protected:
            private:
                QuantumReactor *_coreReactor;
        };
    }

#endif /* !WARPSYSTEM_CPP_ */
