#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include "../track/music/music.hpp"
#include "../track/podcast/podcast.hpp"

class Playlist
{
    private:
        ostream& PrintPlaylistInfo(ostream&) const;
    protected:
        string title_;
        string playlist_duration_;
        string creation_date_;
        string user_id_;
        string track_type_;
        int track_count_;
        vector<Track*> playlist_tracks_;
    public:
        /******************************
        ********* Construtores ********
        *******************************/
        Playlist(void);
        Playlist(string);
        ~Playlist() = default;

        /******************************
        ********* Métodos SET *********
        *******************************/
        void SetPlaylistTitle(string);
        void SetPlaylistDuration(string);
        void SetCreationDate(string);
        void SetPlaylistUserID(string);
        void SetTrackType(string);
        void SetTrackCount(void);

        /******************************
        ********* Métodos GET *********
        *******************************/
        string GetPlaylistTitle(void);
        string GetPlaylistDuration(void);
        string GetCreationDate(void);
        string GetPlaylistUserID(void);
        string GetTrackType(void);
        int GetTrackCount(void);

        /******************************
        ****** Métodos Adicionais *****
        *******************************/
        void Clean(void);
        void DeleteAllTracks(void);
        void DeletePlaylistTrack(int);
        void AddMusic(Music& m);
        void AddPodcast(Podcast& p);

        string ReadCSVPlaylistInfo(void);

        friend istream& operator>> (istream &, Playlist &);

};

#endif
