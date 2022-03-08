#include "../../../include/media/playlist/playlist.hpp"

/******************************
********* Construtores ********
*******************************/
Playlist::Playlist()
{
    Clean();
}

Playlist::Playlist(string istreamfile)
{
    string temp;
    Music m;
    istringstream strg(istreamfile);
    getline(strg, title_, ';');
    getline(strg, playlist_duration_, ';');
    getline(strg, creation_date_, ';');
    getline(strg, user_id_, ';');
    getline(strg, track_type_, ';');

    if(track_type_ == "Music")
    {
        Music music_;
        playlist_tracks_.push_back(new Music(music_));
    }
    if(track_type_ == "Podcast")
    {
        Podcast podcast_;
        playlist_tracks_.push_back(new Podcast(podcast_));
    }
    SetTrackCount();
}

/******************************
********* Métodos SET *********
*******************************/
void Playlist::SetPlaylistTitle(string title)
{
    title_ = title;
}
void Playlist::SetCreationDate(string creation_date)
{
    creation_date_ = creation_date ;
}
void Playlist::SetPlaylistUserID(string user_id)
{
    user_id_ = user_id ;
}
void Playlist::SetTrackType(string track_type)
{
    track_type_ = track_type;
}
void Playlist::SetTrackCount(void)
{
    track_count_ = playlist_tracks_.size();
}

void Playlist::SetPlaylistDuration(string duration)
{
    playlist_duration_ = duration;
}

/******************************
********* Métodos GET *********
*******************************/
string Playlist::GetPlaylistTitle(void)
{
    return title_;
}
string Playlist::GetPlaylistDuration(void)
{
    return playlist_duration_;
}
string Playlist::GetCreationDate(void)
{
    return creation_date_;
}
string Playlist::GetPlaylistUserID(void)
{
    return user_id_;
}
string Playlist::GetTrackType(void)
{
    return track_type_;
}
int Playlist::GetTrackCount(void)
{
    return track_count_;
}

/******************************
****** Métodos Adicionais *****
*******************************/
void Playlist::Clean()
{
    title_ = "";
    playlist_duration_ = "";
    creation_date_ = "";
    user_id_ = "";
    playlist_tracks_.clear();
}

void Playlist::DeleteAllTracks(void)
{
    playlist_tracks_.erase(playlist_tracks_.begin(), playlist_tracks_.end());
    delete this;
}

void Playlist::DeletePlaylistTrack(int id)
{
    playlist_tracks_.erase(playlist_tracks_.begin()+id);
}


void Playlist::AddMusic(Music& m)
{
    playlist_tracks_.push_back(new Music(m));
}

void Playlist::AddPodcast(Podcast& p)
{
    playlist_tracks_.push_back(new Podcast(p));
}


string Playlist::ReadCSVPlaylistInfo(void)
{
    stringstream input;
    Music m;
    Podcast p;

    input << title_ << ";";
    input << playlist_duration_ << ";";
    input << creation_date_ << ";";
    input << user_id_ << ";";
    input << track_type_ << ";";

    if(track_type_ == "Music")
        AddMusic(m);
    if(track_type_ == "Podcast")
        AddPodcast(p);
    return input.str();
}
