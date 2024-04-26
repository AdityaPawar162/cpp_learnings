#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<std::string> playlist{"Song A", "Song B", "Song C", "Song D", "Song E", "Song F", "Song G", "Song H", "Song I", "Song J", "Song K", "Song L"};
    std::rotate(playlist.rbegin(), playlist.rbegin() + 10, playlist.rend());
    std::cout << "Year in Review playlist: ";
    for (const auto &s : playlist)
        std::cout << s << " ";
    std::cout << '\n';
    std::reverse(playlist.begin(), playlist.end());
    std::cout << "Rediscovery playlist: ";
    for (const auto &s : playlist)
        std::cout << s << " ";
    std::cout << '\n';
    std::vector<std::string> newPlaylist{"New 1", "New 2", "New 3"};
    playlist.insert(playlist.begin() + playlist.size() / 2, newPlaylist.begin(), newPlaylist.end());
    std::cout << "After new album playlist: ";
    for (const auto &s : playlist)
        std::cout << s << " ";
    std::cout << '\n';
    std::vector<std::string> SpringPlaylist{"Spring 1", "Spring 2", "Spring 3"};
    std::fill(playlist.begin(), playlist.begin() + SpringPlaylist.size(), "Spring Song");
    std::cout << "Spring playlist: ";
    for (const auto &s : playlist)
        std::cout << s << " ";
    std::cout << '\n';

    return 0;
}

/*#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
    std::vector<std::string> playlist = {
        "Song A", "Song B", "Song C", "Song D",
        "Song E", "Song F", "Song G", "Song H",
        "Song I", "Song J", "Song K", "Song L"};
    std::rotate(playlist.rbegin(), playlist.rbegin() + 10,
                playlist.rend());
    std::cout << "Year in Review playlist: ";
    for (const auto &song : playlist)
    {
        std::cout << song << ", ";
    }
    std::cout << "\n";
    std::reverse(playlist.begin(), playlist.end());
    std::cout << "Rediscovery playlist: ";
    for (const auto &song : playlist)
    {
        std::cout << song << ", ";
    }
    std::cout << "\n";
    std::vector<std::string> newAlbum = {
        "New Song 1", "New Song 2", "New Song 3"};
    playlist.insert(playlist.begin() + playlist.size() / 2,
                    newAlbum.begin(), newAlbum.end());
    std::rotate(playlist.begin() + playlist.size() / 2,
                playlist.end() - newAlbum.size(),
                playlist.end());
    std::cout << "After new album purchase: ";
    for (const auto &song : playlist)
    {
        std::cout << song << ", ";
    }
    std::cout << "\n";
    std::vector<std::string> springSongs = {
        "Spring 1", "Spring 2", "Spring 3", "Spring 4"};
    if (playlist.size() < springSongs.size())
    {
        playlist.resize(springSongs.size());
    }
    std::fill(playlist.begin(),
              playlist.begin() + springSongs.size(),
              "Spring Song");
    std::cout << "Spring Refresh: ";
    for (const auto &song : playlist)
    {
        std::cout << song << ", ";
    }
    std::cout << "\n";
    return 0;
}
*/