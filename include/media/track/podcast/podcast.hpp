#ifndef PODCAST_HPP
#define PODCAST_HPP

#include "../track.hpp"

class Podcast : public Track                      ///Class Podcast que recebe os atributos público da Class Track
{
    private:
        ostream& PrintTrackInfo(ostream&) const;
    protected:
        string category_;                         ///Categoria de Podcast
        string release_date_;                     ///Data de lançamento de Podcast
    public:
        /******************************
        ********* Construtores ********
        *******************************/
        Podcast();
        Podcast(string);

        /******************************
        ********* Métodos SET *********
        *******************************/
        void SetCategory(string);
        void SetReleaseDate(string);

        /******************************
        ********* Métodos GET *********
        *******************************/
        string GetCategory(void);
        string GetReleaseDate(void);

        /******************************
        ****** Métodos Virtuais *******
        *******************************/
        void Clean(void);
        string ReadCSVTrackInfo(void);
        /******************************
        ********** Operadores *********
        *******************************/
        friend istream& operator>> (istream &, Podcast &);


};

#endif
