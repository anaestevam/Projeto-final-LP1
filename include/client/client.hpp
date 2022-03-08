#ifndef CLIENT_HPP___
#define CLIENT_HPP___
/**
 * @file	user.hpp
 * @brief	Arquivo de cabeçalhos das funções em presentes no arquivo user.cpp.
 * @authors	Ana Luisa, Karoline da Paz, Kelvin Coelho, Thina Silva
 * @date	24/10/2019
**/


#include "../media/track/track.hpp"

class Client
{
    protected:
        string name_;
        string id_;
        string password_;
        int step_count_;
    public:
        Client() = default;
        ~Client() = default;

        void ListClients(void);

        /******************************
        ********* Métodos SET *********
        *******************************/
        void SetClientName(string);
        void SetClientID(string);
        void SetClientPassword(string);
        void SetStepCount(int);

        /******************************
        ********* Métodos GET *********
        *******************************/
        string GetClientName(void);
        string GetClientID(void);
        string GetClientPassword(void);
        int    GetStepCount(void);


        /******************************
        ****** Métodos Virtuais *******
        *******************************/
        virtual void Clean() = 0;
        virtual string GetCSV(void) = 0;

        // virtual vector<Client> ClientList() = 0;

};
#endif
