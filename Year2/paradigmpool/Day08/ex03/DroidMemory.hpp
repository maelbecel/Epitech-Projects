/*
** EPITECH PROJECT, 2023
** droid
** File description:
** droid
*/

#ifndef DROIDMEMORY_CPP_
    #define DROIDMEMORY_CPP_

    #include <iostream>

    class DroidMemory {
        public:
            DroidMemory();
            ~DroidMemory();
            size_t getFingerprint() const;
            size_t getExp() const;
            void setFingerprint(size_t fingerprint);
            void setExp(size_t exp);
            DroidMemory &operator<<(const DroidMemory &other);
            DroidMemory &operator>>(DroidMemory &other);
            DroidMemory &operator+=(size_t exp);
            DroidMemory &operator+=(const DroidMemory &other);
            DroidMemory operator+(const DroidMemory &other) const;
            DroidMemory operator+(size_t exp) const;
            bool operator==(const DroidMemory &other) const;
            bool operator!=(const DroidMemory &other) const;
            bool operator<(const DroidMemory &other) const;
            bool operator>(const DroidMemory &other) const;
            bool operator<=(const DroidMemory &other) const;
            bool operator>=(const DroidMemory &other) const;
            bool operator==(size_t x) const;
            bool operator!=(size_t x) const;
            bool operator<(size_t x) const;
            bool operator>(size_t x) const;
            bool operator<=(size_t x) const;
            bool operator>=(size_t x) const;
        protected:
        private:
            size_t Fingerprint;
            size_t Exp;
    };

    std::ostream &operator<<(std::ostream &str, const DroidMemory &drd);

#endif /* !Droid */
