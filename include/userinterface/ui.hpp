#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
using std::cin;
using std::stoi;

#include <string>
using std::string;

#include <sstream>
using std::stringstream;
using std::istringstream;

#include <iomanip>
using std::setw;
using std::setfill;
using std::ios;
using std::right;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <vector>
using std::vector;

#include <algorithm>
using std::find;
#include <chrono>
#include <thread>

#include "../client/client.hpp"
#include "../client/user/user.hpp"
#include "../client/artist/artist.hpp"

#include "../media/playlist/playlist.hpp"
#include "../media/album/album.hpp"

#include "../media/track/track.hpp"
#include "../media/track/music/music.hpp"
#include "../media/track/podcast/podcast.hpp"


class UserInterface
{

    private:
        Artist artist;
        typedef const vector<string> VPATH;
        typedef const string PATH;
        VPATH PATHS{"../../CSV/clients.csv","../../CSV/tracks.csv","../../CSV/playlists.csv","../../CSV/albuns.csv"};
        vector<string> track_atributes_;
        vector<string> client_atributes_;
        vector<string> album_atributes_;
        vector<string> playlist_atributes_;
        vector<string> promo_codes_ = {"123abc", "cba321", "1qaz2wsx","xmusic"};
    public:
        UserInterface();
        ~UserInterface() = default;
        void UiStartMenu();
        void UiClientRegister();
        void UiClientLogin();
        void interfaceLogado();
        void interfacePesquisar();
        void interfacePlaylist();
        void adicionarMusicaPlaylist();

        void UiPressToGo(void);
        void UiLogo(void);
        void UiLayer(string);
        void UiClearScreen(void);
        double CheckNumber(char *);
        char * CharInput(void);
        string StringInput(void);
        int IntInput(void);
        double DoubleInput(void);
        void AddLine(string, PATH);
        string ReadColumn(string, int);
        void UiSetUserPremium(void);
        void UiVipLogo(string);

        Client* PushClient(bool);
        bool UiInputValidation(vector<string>, string);


        vector<string> ClientAtributes();
        vector<string> TrackAtributes();
        vector<string> AlbumAtributes();
        vector<string> PlaylistAtributes();
};

#endif
