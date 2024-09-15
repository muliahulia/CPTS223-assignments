/*
ADVANTAGES/DISADVANTAGES LINKED LIST:
Advantage: A linked list allows dynamic memory allocation, which means you can efficiently add and remove commands without resizing or shifting elements. This is useful for storing Linux commands in this assignment since the number of commands can change frequently.
Disadvantage: Linked lists have a higher memory overhead because they require additional pointers, and accessing an element by index takes linear time (O(n)), which can make them less efficient when searching for specific commands.

ADVANTAGES/DISADVANTAGES ARRAY:
Advantage: Arrays allow direct access to elements by index in constant time (O(1)), which makes accessing user profiles very fast. This is useful when retrieving and updating player profiles during the game.
Disadvantage: Arrays have a fixed size, so when the number of profiles exceeds the array size, you must reallocate memory and copy elements, which can be inefficient compared to a dynamic structure like a linked list.
*/

#include <iostream>
#include <limits>
#include <string>
#include "functions.h"
#include "list.h"

using namespace std;

// Assuming global variables
LinkedList commandList;
vector<Profile> profiles;

int main() {
    string userName;
    int selection;

    // Load commands and profiles from files at startup
    commandList.loadFromFile("command.csv");
    loadProfilesFromFile("profile.csv");

    while (true) {
        cout << "Please select an option listed below:\n";
        cout << "1. Game Rules\n2. Play Game\n3. Load Previous Game\n4. Add Command\n5. Remove Command\n6. Exit\n";
        cout << "Your selection: ";
        cin >> selection;

        if (cin.fail()) {
            cout << "Invalid selection. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Continue the loop to prompt for selection again
        }

        switch (selection) {
            case 1: {
                cout << "=================== Game Rules ===================\n";
                cout << "Match the Linux commands with their descriptions. You gain a point for each correct match and lose a point for incorrect ones.\n";
                cout << "=================================================\n";
                break;
            }

            case 2:
                playGame(); // Start the game
                break;

            case 3: {
                cout << "Please enter your profile name: ";
                cin >> userName;
                // Check if profile exists and display the stored points
                auto it = find_if(profiles.begin(), profiles.end(), [&](const Profile& p) {
                    return p.name == userName;
                });

                if (it != profiles.end()) {
                    cout << "Profile found. Points: " << it->points << endl;
                    playGame(); // Start the game with the existing profile
                } else {
                    cout << "Profile not found. Exiting.\n";
                }
                break;
            }

            case 4: {
                string newCommand, newDescription;
                cout << "Enter the new command: ";
                cin >> newCommand;
                cout << "Enter the description: ";
                cin.ignore(); // Clear the newline character from the buffer
                getline(cin, newDescription);
                addCommandToList(newCommand, newDescription);
                break;
            }

            case 5: {
                string commandToRemove;
                cout << "Enter the command to remove: ";
                cin >> commandToRemove;

                if (commandList.removeNode(commandToRemove)) {
                    cout << "Command removed successfully.\n";
                } else {
                    cout << "Command not found.\n";
                }
                break;
            }

            case 6: {
                // Save commands and profiles before exiting
                commandList.saveToFile("command.csv");
                saveProfilesToFile("profile.csv");

                // Deallocate linked list memory
                Node* current = commandList.getHead(); // Traverse the linked list
                while (current != nullptr) {
                    Node* toDelete = current;
                    current = current->next;
                    delete toDelete; // Free the memory for each node
                }

                // Reset the head of the list to nullptr
                commandList.setHead(nullptr);

                // Exit the program
                return 0;
            }

            default:
                cout << "Invalid selection. Please try again.\n";
                break;
        }
    }
}
