/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** Network
*/

#ifndef NETWORK_HPP_
    #define NETWORK_HPP_

    #include <iostream>
    #include <string>
    #include <vector>
    #include "ANetwork.hpp"

    class Network : public ANetwork {
        public:
            Network();
            ~Network();

            void Update(void) override;
            std::map<std::string, std::string> getData(void) override;

            void updateIp();
            std::string getIp() const {return _ip;};
            void getNetworkInfo();
            void getNetworkValues(std::string &line);
            size_t getDownloadBytes(void) const {return _valueSec[0];};
            size_t getDownloadPackets(void) const {return _valueSec[1];};
            size_t getUploadBytes(void) const {return _valueSec[2];};
            size_t getUploadPackets(void) const {return _valueSec[3];};

        protected:
        private:
            std::string _ip;
            std::string _networkValues[4];
            size_t _valueSec[4];
    };

#endif /* !NETWORK_HPP_ */
