#ifndef __USER__
#define __USER__

#include <string>
#include <vector>

#include "../Song/Song.hpp"
#include "../main/Exceptions.hpp"
#include "../main/functions.hpp"

class User {
   public:
    User(std::string username_, std::string email_, std::string password_);
    User(){};
    bool is_username(std::string username_);
    bool is_email(std::string email_);
    bool is_password(std::string password_);
    void like_song(Song* song);
    void show_likes();
    void remove_liked_song(int song_id);
    std::string get_username();
    bool compare_by_name_with(User* second);
    bool do_likes(Song* song);

   private:
    std::string username;
    std::string email;
    std::string password;
    std::vector<Song*> liked_songs;
};

#endif
