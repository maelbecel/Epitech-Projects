/*
** EPITECH PROJECT, 2023
** dir
** File description:
** dir
*/

#ifndef DIRECTORYLISTER_CPP_
    #define DIRECTORYLISTER_CPP_

    #include "IDirectoryLister.hpp"
    #include <dirent.h>
    #include <string.h>

    class DirectoryLister : public IDirectoryLister {
        public:
            DirectoryLister();
            DirectoryLister(const std::string& path, bool hidden);
            ~DirectoryLister();
            bool open(const std::string& path, bool hidden);
            std::string get();
        protected:
        private:
            bool _hidden;
            DIR *_dir = nullptr;
    };

#endif /* !DIRECTORYLISTER_CPP_ */
