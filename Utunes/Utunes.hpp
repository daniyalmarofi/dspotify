#ifndef __UTUNES__
#define __UTUNES__

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "../Filters/ArtistFilter.hpp"
#include "../Filters/Filter.hpp"
#include "../Filters/LikeFilter.hpp"
#include "../Filters/YearFilter.hpp"
#include "../Playlist/Playlist.hpp"
#include "../Song/Song.hpp"
#include "../User/User.hpp"
#include "../main/Exceptions.hpp"
#include "../main/functions.hpp"

using namespace std;

class Utunes {
   public:
    Utunes();
    ~Utunes();
    void read_songs(string file_path);
    void read_liked_songs(string file_path);
    void handle_input();

   private:
    void import_user(string username, string email, string password,
                     int liked_song);
    void handle_post_commands(string rest_of_command);
    void handle_get_commands(string rest_of_command);
    void handle_delete_commands(string rest_of_command);
    void handle_signup_command(string rest_of_command);
    void signup_user(string username, string email, string password);
    string hash_text(string password);
    void handle_login_command(string rest_of_command);
    void login_user(string email, string password);
    void handle_logout_command();
    void needs_login();
    void logout_user();
    void handle_get_songs_command(string rest_of_command);
    void handle_get_song_command(string rest_of_command);
    void handle_like_a_song_command(string rest_of_command);
    void handle_get_likes_command();
    void handle_delete_likes_command(string rest_of_command);
    void handle_create_playlist_command(string rest_of_command);
    void create_playlist(string name, string privacy);
    void handle_get_playlists_command(string rest_of_command);
    bool show_all_playlists_of_user(string ownername);
    bool show_public_playlists_of_user(string ownername);
    void handle_add_song_to_playlist_command(string rest_of_command);
    void add_song_to_playlist(int playlist_id, int song_id);
    void handle_get_playlist_songs_command(string rest_of_command);
    void handle_remove_song_from_list_command(string rest_of_command);
    void handle_get_users_command(string rest_of_command);
    void handle_add_comment_command(string rest_of_command);
    void handle_get_comments_command(string rest_of_command);
    void handle_set_filter_command(string rest_of_command);
    vector<Song*> get_filtered_songs();
    void reset_filters();
    Song* find_song(int id);
    void create_likes_matrix();
    void change_likes_matrix_cell(User* user, Song* song, int do_likes);
    void calculate_similarity_matrix();
    double calculate_similarity_of(User* first_user, User* second_user);
    double calculate_confidence(User* user, Song* song);
    void handle_get_similar_users_command(string rest_of_command);
    int find_user_id(User* user);
    vector<pair<string, double>> get_similar_users_of(User* user);

    vector<Song*> songs;
    vector<User*> users;
    User* loggedin_user;
    vector<Playlist*> playlists;
    map<string, Filter*> filters;
    vector<vector<int>> likes_matrix;
    vector<vector<double>> similarity_matrix;
};

#endif