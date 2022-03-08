#ifndef MUSIC_HPP
#define MUSIC_HPP

#include "../track.hpp"

class Music : public Track                          ///Class Music que vai receber os atributos public da Class Track
{
    private:
        ostream& PrintTrackInfo(ostream&) const;
    protected:
        string gender_;                           ///Gênero de music
        string year_;                             ///Ano de music
    public:
        /******************************
        ********* Construtores ********
        *******************************/
        Music();
        Music(string);

        /******************************
        ********* Métodos SET *********
        *******************************/
        void SetGender(string);
        void SetYear(string);

        /******************************
        ********* Métodos GET *********
        *******************************/
        string GetGender(void);
        string GetYear(void);

        /******************************
        ****** Métodos Virtuais *******
        *******************************/

        void Clean(void);
        string ReadCSVTrackInfo(void);

        /******************************
        ********** Operadores *********
        *******************************/
        friend istream& operator>> (istream &, Music &);

};

#endif
