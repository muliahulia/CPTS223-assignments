// functions.cpp

#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>
#include "list.h"

using namespace std;
extern LinkedList commandList;


void loadProfilesFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    vector<Profile> tempProfiles; // Use a temporary vector to handle file input

    while (getline(file, line)) {
        istringstream iss(line);
        string name;
        int points;
        if (getline(iss, name, ',') && (iss >> points)) {
            // Remove leading and trailing spaces and quotes
            name.erase(0, name.find_first_not_of(" \t\""));
            name.erase(name.find_last_not_of(" \t\"") + 1);

            tempProfiles.insert(tempProfiles.begin(), {name, points});
        }
    }
    file.close();

    profiles = tempProfiles;

    // Display the loaded profiles and their scores
    cout << "Profiles loaded from file:" << endl;
    for (const auto& profile : profiles) {
        cout << "Name: " << profile.name << ", Score: " << profile.points << endl;
    }
}



void saveProfilesToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (const auto& profile : profiles) {
        file << profile.name << "," << profile.points << endl;
    }
    file.close();
}

void playGame() {
    string playerName;
    int numQuestions, score = 0;

    cout << "Enter your name: ";
    cin >> playerName;

    cout << "How many questions would you like to play (5-30)? ";
    cin >> numQuestions;

    if (numQuestions < 5 || numQuestions > 30) {
        cout << "Invalid number of questions. Exiting game." << endl;
        return;
    }

    // Collect all commands into a vector
    vector<Command> commands;
    Node* current = commandList.getHead(); // Assumes a getHead() method in LinkedList
    while (current != nullptr) {
        commands.push_back(current->command);
        current = current->next;
    }

    // Check if there are enough commands to generate options
    if (commands.size() < numQuestions) {
        cout << "Not enough commands to generate options. Exiting game." << endl;
        return;
    }

    random_device rd;
    default_random_engine rng(rd());
    shuffle(commands.begin(), commands.end(), rng); // Shuffle commands

    for (int i = 0; i < numQuestions; ++i) {
        // Pick a random command
        const Command& correctCommand = commands[i];

        // Create options (one correct, two incorrect)
        vector<Command> options = {correctCommand};
        while (options.size() < 3) {
            const Command& randomCommand = commands[rng() % commands.size()];
            if (randomCommand.name != correctCommand.name) {
                options.push_back(randomCommand);
            }
        }

        shuffle(options.begin(), options.end(), rng); // Shuffle options

        // Display question
        cout << "Q" << (i + 1) << ": What does the command '" << correctCommand.name << "' do?\n";
        for (size_t j = 0; j < options.size(); ++j) {
            cout << (j + 1) << ". " << options[j].description << endl;
        }

        int choice;
        cin >> choice;
        if (choice > 0 && choice <= options.size() && options[choice - 1].name == correctCommand.name) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Incorrect!\n";
            score--;
        }
    }

    cout << "Game Over! Your score is: " << score << endl;

    // Update or add the player's profile with the new score
    bool profileFound = false;
    for (auto& profile : profiles) {
        if (profile.name == playerName) {
            profile.points = score;
            profileFound = true;
            break;
        }
    }
    if (!profileFound) {
        profiles.insert(profiles.begin(), {playerName, score});
    }

    // Save updated profiles to file
    saveProfilesToFile("profile.csv");
}


void addCommandToList(const string& commandName, const string& description) {
    Command newCommandObj = {commandName, description};

    // Check if the command already exists
    bool exists = false;
    Node* current = commandList.getHead(); // Use Node* to traverse the list
    while (current != nullptr) {
        if (current->command.name == commandName) { // Access Command object inside Node
            exists = true;
            break;
        }
        current = current->next;
    }

    if (exists) {
        cout << "Command already exists.\n";
    } else {
        // Insert the Command object at the front of the linked list
        commandList.insertAtFront(newCommandObj);
        cout << "Command added successfully.\n";
    }
}