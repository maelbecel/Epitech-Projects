/*
** EPITECH PROJECT, 2023
** s
** File description:
** s
*/

#ifndef SAFEDIRECTORYLISTER_CPP_
    #define SAFEDIRECTORYLISTER_CPP_

    #include "DirectoryLister.hpp"

    class SafeDirectoryLister : public IDirectoryLister {
        public:
            SafeDirectoryLister() {};
            ~SafeDirectoryLister() {(_dir) ? closedir(_dir) : 0;};

            SafeDirectoryLister(std::string path, bool hidden) {open(path, hidden);}

            bool open(const std::string& path, bool hidden);
            std::string get();

        protected:
        private:
            DIR *_dir = nullptr;
            bool _hidden;
    };

#endif /* !SAFEDIRECTORYLISTER_CPP_ */
