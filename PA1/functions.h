// functions.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include "list.h"

#include <string>

using namespace std;

struct Profile {
    string name;
    int points;
};

extern vector<Profile> profiles;
void loadCommands(const std::string& filename, LinkedList& list);
void loadProfilesFromFile(const string& filename);
void saveProfilesToFile(const string& filename);
void addCommandToList(const string& commandName, const string& description);
void playGame();

#endif // FUNCTIONS_H
