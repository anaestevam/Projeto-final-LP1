/* *
 * @file User.hpp
 * @brief Arquivo de cabeçalhos das funções em presentes no arquivo user.cpp.
 * @autoras Ana Luisa, Karoline da Paz, Kelvin Coelho, Thina Silva
 * @data 30/10/2019
* */

#include "../../../include/media/track/track.hpp"




/******************************
********* Métodos SET *********
*******************************/

/**
 *@brief            Método 'Set' para alterar o tipo da faixa
 *@param type      O tipo da faixa
**/
void Track::SetTrackType (string track_type)
{
  track_type_ = track_type;
}
/**
 *@brief            Método 'Set' para alterar o título da faixa
 *@param title      O título da faixa
**/
void Track::SetTrackTitle(string title)
{
    title_ = title;
}

/**
 *@brief            Método 'Set' para alterar o artista da faixa
 *@param artist     O artista da faixa
**/
void Track::SetTrackArtist(string artist)
{
    artist_ = artist;
}

/**
 *@brief            Método 'Set' para alterar o album da faixa
 *@param album      O Album da faixa
**/
void Track::SetTrackAlbum(string album)
{
    album_ = album_;
}

/**
 *@brief            Método 'Set' para alterar a duração da faixa
 *@param duration   A duração da faixa
**/
void Track::SetTrackDuration(string duration)
{
    duration_ = duration;
}



/******************************
********* Métodos GET *********
*******************************/

/**
 *@brief    Método 'Get' para retorno do tipo da faixa
 *@return   O tipo da faixa
**/
string Track::GetTrackType (void)
{
  return track_type_;
}
/**
 *@brief    Método 'Get' para retorno do título da faixa
 *@return   O título da faixa
**/
string Track::GetTrackTitle(void)
{
    return title_;
}

/**
 *@brief    Método 'Get' para retorno do artista da faixa
 *@return   O artista da faixa
**/
string Track::GetTrackArtist(void)
{
    return artist_;
}

/**
 *@brief    Método 'Get' para retorno do album da faixa
 *@return   O Album da faixa
**/
string Track::GetTrackAlbum(void)
{
    return album_;
}

/**
 *@brief    Método 'Get' para retorno da duração da faixa
 *@return   A duração da faixa
**/
string Track::GetTrackDuration(void)
{
    return duration_;
}
/**
 *@brief    Método Adicional para converter da duração da faixa
 *@return   A duração da faixa, em minutos e segundos
**/
string Track::DurationConverter(string duration)
{
    int sec, min;

    min = stoi(duration)/60;
    sec = stoi(duration)%60*60;

    return (to_string(min) + ":" + to_string(sec));
}
