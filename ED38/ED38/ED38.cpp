#include <iostream>
#include <string>
#include <list>

#include "iPud.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema hacemos un programa que gestiona las canciones de un dispositivo de música.
*/

using song = std::string;

bool resuelveCaso() {
	std::string orden, artist;
	song s;
	int duration, n;

	std::cin >> orden;
	if (std::cin.fail()) return false;

	iPud p;

	while (orden != "FIN") {
		try {
			if (orden == "addSong"){
				std::cin >> s >> artist >> duration;
				p.addSong(s, artist, duration);
			}
			else if (orden == "addToPlaylist") {
				std::cin >> s;
				p.addToPlaylist(s);
			}
			else if (orden == "play") {
				try {
					s = p.current();
					std::cout << "Sonando " << s << '\n';
					p.play();
				}
				catch (std::domain_error& e) {
					std::cout << "No hay canciones en la lista\n";
				}
			}
			else if (orden == "totalTime") std::cout << "Tiempo total " << p.totalTime() << '\n';
			else if (orden == "current") p.current();
			else if (orden == "deleteSong") {
				std::cin >> s;
				p.deleteSong(s);
			}
			else if (orden == "recent") {
				std::cin >> n;
				try {
					std::list<song> l = p.recent(n);

					std::cout << "Las " << (n > l.size() ? l.size() : n) << " mas recientes\n";

					int i = 0;
					auto it = l.begin();
					while (it != l.end() && i++ < n) {
						std::cout << "    " << *it << '\n';
						++it;
					}
				}
				catch (std::domain_error& e) {
					std::cout << "No hay canciones recientes\n";
				}
			}
		}
		catch (std::domain_error e) {
			std::cout << "ERROR " << orden << '\n';
		}
		std::cin >> orden;
	}
	std::cout << "---\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}