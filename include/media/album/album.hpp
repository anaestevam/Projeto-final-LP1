#ifndef ALBUM_HPP
#define ALBUM_HPP

#include "../track/music/music.hpp"
#include "../track/podcast/podcast.hpp"

class Album
{
    private:
        ostream& PrintAlbumInfo(ostream&) const;
    protected:
        string title_;
        string album_duration_;
        string year_;
        string artist_id_;
        string track_type_;
        int track_count_;
        vector<Track*> album_tracks_;
    public:
        /******************************
        ********* Construtores ********
        *******************************/
        Album(void);
        Album(string);
        ~Album() = default;

        /******************************
        ********* Métodos SET *********
        *******************************/
        void SetAlbumTitle(string);
        void SetAlbumDuration(string);
        void SetAlbumYear(string);
        void SetAlbumArtistID(string);
        void SetTrackType(string);
        void SetTrackCount(void);

        /******************************
        ********* Métodos GET *********
        *******************************/
        string GetAlbumTitle(void);
        string GetAlbumDuration(void);
        string GetAlbumYear(void);
        string GetAlbumArtistID(void);
        string GetTrackType(void);
        int GetTrackCount(void);


        /*******************************
         ****** Métodos Adicionais *****
         *******************************/
         void Clean(void);
         void DeleteAllTracks(void);
         void DeleteAlbumTrack(int);
         void AddMusic(Music& m);
         void AddPodcast(Podcast& p);

         string ReadCSVAlbumInfo(void);

         friend istream& operator>> (istream &, Album &);

};

#endif
