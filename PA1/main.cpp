/*
<<<<<<< HEAD:PA1/main.cpp
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
=======
Inserting the randomly generated integers into a BST generally gives a height in the order of:

Your answer: O(log n)


*/

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <chrono>
#include <cmath>
#include <random>
#include "BST.h"

double log2(double d)
{
    return log(d) / log(2); // log() use e as base
}

void insertRandomIntegers(BST<int>* root, int numIntegers)
{
    // The range of random integers
    const int minValue = -1000000000;
    const int maxValue =  1000000000;
    int randomInteger;

    // Generate a uniform distribution to generate random integers
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist(minValue, maxValue); 

    // Generate random integers (without duplicates) from the specified range
    for (int i = 0; i < numIntegers; ++i) {
        randomInteger = dist(rng);
        while ( root->contains(randomInteger) == true )
        {
            randomInteger = dist(rng);
        }
        root->insert(randomInteger);
    }
}

int main()
{
    // Seed the random number generator with the current time
    srand(static_cast<unsigned>(time(0)));

    // (i) test member functions with simple 6 inputs
    BST<int> *bst = new BST<int>();
    bst->insert(11);
    bst->insert(1);
    bst->insert(6);
    bst->insert(-1);
    bst->insert(-10);
    bst->insert(100);

    // a demo for findMin and findMax if "insert" is successfully implemented
    // cout << "(0) findMin = " << bst->findMin() << endl;
    // cout << "    findMax = " << bst->findMax() << endl;

    cout << "(1.1) Print BST (in-order traversal): " << endl << " ";
    bst->printInOrder();
    cout << endl;

    cout << "(1.2) Print BST in level order: " << endl;
    bst->printLevels();

    cout << "(1.3) Is 100 in BST? true (1) or false (0): " << bst->contains(100) << endl;

    cout << "(1.4) Is 9 in BST? true (1) or false (0): " << bst->contains(9) << endl;
    
    cout << "(1.5) BST size: " << bst->treeSize() << endl;

    cout << "(1.6) Height of BST: " << bst->treeHeight() << endl;
    
    cout << "(1.7) Print max path: " << endl << " ";
    bst->printMaxPath();
    cout << endl;

    bst->remove(11);
    cout << "(1.8) Removing 11, print BST (in-order traversal): " << endl << " ";
    bst->printInOrder();
    cout << endl;

    cout << "(1.9) Print BST in level order: " << endl;
    bst->printLevels();

    cout << "(1.10) BST size: " << bst->treeSize() << endl;

    // Delete this bst
    delete bst;

    return 0;
}
>>>>>>> ee3882b (Change):Documents/CPTS223-Assignmets/MA2/main.cpp
