#ifndef USER_HPP_____
#define USER_HPP_____

#include "../../media/playlist/playlist.hpp"
#include "../client.hpp"

class User : public Client
{
    private:
        ostream& PrintUserInfo(ostream&) const;
    protected:
        string cpf_;
        string phone_;
        string email_;
        string premium_;
        vector<Playlist*> playlists_;
    public:
        /*******************************
        ** Construtores & Destrutores **
        ********************************/
        User();
        User(string);
        User(vector<string>);

        /******************************
        ********* Métodos SET *********
        *******************************/
        void SetUserCPF(string);
        void SetUserPhone(string);
        void SetUserEmail(string);
        void SetUserPremium(string);

        /******************************
        ********* Métodos GET *********
        *******************************/
        string GetUserCPF(void);
        string GetUserPhone(void);
        string GetUserEmail(void);
        string GetUserPremium(void);


        /******************************
        ****** Métodos Virtuais *******
        *******************************/
        void Clean(void);
        string GetCSV(void);
        /******************************
        ***** Métodos Adicionais ******
        *******************************/
        vector<Playlist*> AddPlaylist();



};


#endif
