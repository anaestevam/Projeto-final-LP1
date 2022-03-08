/* *
 * @file artist.hpp
 * @brief Arquivo de cabeçalhos das funções em presentes no arquivo user.cpp.
 * @autoras Ana Luisa, Karoline da Paz, Kelvin Coelho, Thina Silva
 * @data 30/10/2019
* */

#ifndef  ___ARTIST_HPP______
#define  ___ARTIST_HPP______

#include "../../media/album/album.hpp"
#include "../client.hpp"

class Artist : public Client
{
    private:
        ostream& PrintArtistInfo(ostream&) const;
    protected:
        int albuns_count_;
        vector<Album*> albuns_;
    public:
        /*******************************
        ** Construtores & Destrutores **
        ********************************/
        Artist();
        Artist(string);
        Artist(vector<string>);

        /******************************
        ********* Métodos SET *********
        *******************************/
        void SetAlbunsCount(int);
        /******************************
        ********* Métodos GET *********
        *******************************/
        int GetAlbunsCount(void);

        /******************************
        ****** Métodos Virtuais *******
        *******************************/
        void Clean(void);
        string GetCSV(void);

        /******************************
        ***** Métodos Adicionais ******
        *******************************/
        vector<Album*> AddAlbum();

};


#endif
