/*
** EPITECH PROJECT, 2023
** dir
** File description:
** dir
*/

#ifndef IDIRECTORYLISTER_CPP_
    #define IDIRECTORYLISTER_CPP_

    #include <iostream>

    class IDirectoryLister {
        public:
            virtual ~IDirectoryLister() = default;
            virtual bool open(const std::string& path, bool hidden) = 0;
            virtual std::string get() = 0;

            class OpenFailureException : public std::exception {
                public:
                    const char *what() const noexcept override;
            };

            class NoMoreFileException : public std::exception {
                public:
                    const char *what() const noexcept override;
            };

        protected:
        private:
    };

#endif /* !IDIRECTORYLISTER_CPP_ */
