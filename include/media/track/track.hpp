/* *
 * @file User.hpp
 * @brief Arquivo de cabeçalhos das funções em presentes no arquivo user.cpp.
 * @autoras Ana Luisa, Karoline da Paz, Kelvin Coelho, Thina Silva
 * @data 30/10/2019
* */

#ifndef TRACK_HPP
#define TRACK_HPP

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::ostream;
using std::to_string;

#include <string>
using std::string;

#include <sstream>
using std::stringstream;
using std::istringstream;

#include <vector>
using std::vector;

#include <algorithm>
using std::find;

#include <iomanip>
using std::setfill;
using std::setw;

#include <istream>
using std::istream;
using std::stoi;
#include <iterator>


class Track
{
    protected:
        string track_type_;     ///Tipo de faixa
        string title_;          ///Nome da faixa
        string artist_;         ///Nome do artista
        string album_;          ///Nome do album associado
        string duration_;       ///Duração da Faixa
    public:
        Track() = default;
        ~Track() = default;
        /******************************
        ********* Métodos SET *********
        *******************************/
        void SetTrackType (string);        ///Seta o Titulo da faixa
        void SetTrackTitle (string);        ///Seta o Titulo da faixa
        void SetTrackArtist (string);       ///Seta o Artista da faixa
        void SetTrackAlbum(string);         ///Seta o Album da faixa
        void SetTrackDuration (string);     ///Seta a Duração da faixa


        /******************************
        ********* Métodos GET *********
        *******************************/
        string GetTrackType (void);        ///Retorna o Titulo da faixa
        string GetTrackTitle (void);        ///Retorna o Titulo da faixa
        string GetTrackArtist (void);       ///Retorna o Artista da faixa
        string GetTrackAlbum(void);         ///Retorna o Album da faixa
        string GetTrackDuration (void);     ///Retorna a Duração da faixa

        /******************************
        ***** Métodos Adicionais ******
        *******************************/
        string DurationConverter(string);


        /******************************
        ****** Métodos Virtuais *******
        *******************************/
        virtual void Clean(void) = 0;
        virtual string ReadCSVTrackInfo(void) = 0;







};

#endif
