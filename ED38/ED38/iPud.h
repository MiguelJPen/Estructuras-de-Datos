#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>

using song = std::string;
using artist = std::string;

class iPud {
private:
	std::unordered_map<song, int> dur;
	std::unordered_map<song, std::list<song>::iterator> inPlaylist;
	std::list<song> playlist;
	std::unordered_map<song, std::list<song>::iterator> inRecent;
	std::list<song> recents;
	int totalTimeP;
public:
	iPud() {
		totalTimeP = 0;
	}

	void addSong(song const& s, artist const& a, int d) { // O(1)
		if (dur.count(s) > 0) throw std::domain_error("");
		dur.insert({ s, d });
	}
	void addToPlaylist(song const& s) { // O(1)
		if (dur.count(s) == 0) throw std::domain_error("");

		if (inPlaylist.count(s) == 0) {
			playlist.push_front(s);
			inPlaylist[s] = playlist.begin();
			totalTimeP += dur[s];
		}
	}
	song current() { // O(1)
		if (playlist.empty()) throw std::domain_error("");

		return playlist.back();
	}
	void play() { // O(1)
		song s = current();
		totalTimeP -= dur[s];

		if (inRecent.count(s) > 0)
			recents.erase(inRecent[s]);
		recents.push_front(s);
		inRecent[s] = recents.begin();

		inPlaylist.erase(s);
		playlist.pop_back();
	}
	int totalTime() { // O(1)
		return totalTimeP;
	}
	std::list<song> recent(int n) { // O(min(n, NR)) siendo NR el número de canciones recientes. (Contamos con la función mostrar de resuelveCaso()).
		if (recents.size() == 0) throw std::domain_error("");

		return recents;
	}
	void deleteSong(song const& s) { // O(1)
		if (dur.count(s) > 0) {
			if (inRecent.count(s) > 0) {
				recents.erase(inRecent[s]);
				inRecent.erase(s);
			}
			if (inPlaylist.count(s) > 0) {
				playlist.erase(inPlaylist[s]);
				inPlaylist.erase(s);
				totalTimeP -= dur[s];
			}
			dur.erase(s);
		}
	}
};