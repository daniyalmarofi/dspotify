#ifndef __SONG__
#define __SONG__

#include <iostream>
#include <string>
#include <vector>

struct comment{
    int time;
    std::string username;
    std::string text;
};

class Song {
   public:
    Song(int id_, std::string title_, std::string artist_, int release_year_,
         std::string link_);
    Song(){};
    bool compare_by_id_with(Song* second);
    void print_short_info();
    bool is_id(int id_);
    bool is_the_same(Song* second);
    void print_full_info();
    void like();
    void add_comment(int time, std::string username, std::string text);

   private:
    int id;
    std::string title;
    std::string artist;
    int release_year;
    std::string link;
    int num_of_likes;
    int num_of_playlists;
    std::vector<comment> comments;
};

#endif