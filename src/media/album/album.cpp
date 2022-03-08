#include "../../../include/media/album/album.hpp"

/*******************************
** Construtores e Destrutores **
********************************/

Album::Album(void)
{
    Clean();
}



Album::Album(string istreamfile)
{
    string temp;

    istringstream strg(istreamfile);
    getline(strg, title_, ';');
    getline(strg, album_duration_, ';');
    getline(strg, year_, ';');
    getline(strg, artist_id_, ';');
    getline(strg, track_type_, ';');

    if(track_type_ == "Music")
    {
        Music music_;
        album_tracks_.push_back(new Music(music_));
    }
    if(track_type_ == "Podcast")
    {
        Podcast podcast_;
        album_tracks_.push_back(new Podcast(podcast_));
    }
    SetTrackCount();
}


/******************************
********* Métodos SET *********
*******************************/

/**
 *@brief       Método 'Set' para definir o título do álbum
 *@param title Título do álbum
**/
void Album::SetAlbumTitle(string title)
{
    title_ = title;
}

/**
 *@brief       Método 'Set' para definir a quantidade de faixas no álbum
**/
void Album::SetTrackCount(void)
{
    track_count_ = album_tracks_.size();
}

/**
 *@brief       Método 'Set' para definir o ano de lançamento do álbum
 *@param year  Ano de lançamento
**/
void Album::SetAlbumYear(string year)
{
    year_ = year;
}

/**
 *@brief                Método 'Set' para definir a duração total do album
 *@param album_duration Duração total das faixas do álbum
**/
void Album::SetAlbumDuration(string album_duration)
{
    album_duration_ = album_duration;
}

void Album::SetAlbumArtistID(string artist_id)
{
    artist_id_ = artist_id;
}
void Album::SetTrackType(string track_type)
{
    track_type_ = track_type;
}

/******************************
********* Métodos GET *********
*******************************/

/**
*@brief     Método 'Get' para retornar o título do álbum
*@return    Título do álbum
**/
string Album::GetAlbumTitle(void)
{
    return title_;
}

/**
 *@brief    Método 'Get' para retornar a quantidade de faixas do álbum
 *@return   Quantidade de faixas do álbum
**/
int Album::GetTrackCount(void)
{
    return track_count_;
}

/**
 *@brief    Método 'Get' para retornar o ano de lançamento
 *@return   Ano de lançamento do álbum
**/
string Album::GetAlbumYear(void)
{
    return year_;
}

/**
 *@brief    Método 'Get' para retornar a duração total do álbum
 *@return   Duração total do álbum
**/
string Album::GetAlbumDuration(void)
{
    return album_duration_;
}


string Album::GetAlbumArtistID(void)
{
    return artist_id_;
}

string Album::GetTrackType(void)
{
    return track_type_;
}

/******************************
****** Métodos Adicionais *****
*******************************/
void Album::Clean()
{
    album_tracks_.clear();
    title_ = "";
    album_duration_ = "";
    year_ = "";
    artist_id_ = "";
    track_type_ = "";
    track_count_ = album_tracks_.size();
}

void Album::DeleteAllTracks(void)
{
    album_tracks_.erase(album_tracks_.begin(), album_tracks_.end());
    delete this;
}

void Album::DeleteAlbumTrack(int id)
{
    album_tracks_.erase(album_tracks_.begin()+id);
}


void Album::AddMusic(Music& m)
{
    album_tracks_.push_back(new Music(m));
}

void Album::AddPodcast(Podcast& p)
{
    album_tracks_.push_back(new Podcast(p));

}

string Album::ReadCSVAlbumInfo(void)
{
    stringstream input;
    Music m;
    Podcast p;

    input << title_ << ";";
    input << album_duration_ << ";";
    input << year_ << ";";
    input << artist_id_ << ";";
    input << track_type_ << ";";

    if(track_type_ == "Music")
        AddMusic(m);
    if(track_type_ == "Podcast")
        AddPodcast(p);
    return input.str();
}
