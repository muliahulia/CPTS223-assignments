// list.cpp

#include "list.h"
#include <sstream> 
#include <iostream>

using namespace std;
LinkedList::LinkedList() : head(nullptr), size(0) {}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insertAtFront(const Command& command) {
    
    Node* newNode = new Node(command);
    newNode->next = head;
    head = newNode;
    size++;
}
Node* LinkedList::getHead() const { return head; }

void LinkedList::setHead(Node* newHead) {
    head = newHead;
}

bool LinkedList::removeNode(const string& commandName) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->command.name != commandName) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        return false; // Command not found
    }

    if (previous == nullptr) {
        head = current->next; // Removing the head node
    } else {
        previous->next = current->next;
    }

    delete current;
    size--;
    return true;
}

bool LinkedList::contains(const string& commandName) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->command.name == commandName) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void LinkedList::saveToFile(const string& filename) const {
    ofstream file(filename);
    Node* current = head;
    while (current != nullptr) {
        file << current->command.name << "," << current->command.description << "\n";
        current = current->next;
    }
    file.close();
}


void LinkedList::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Find the position of the comma
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos) {
            continue; // Skip lines that don't contain a comma
        }

        // Extract the command name and description
        std::string name = line.substr(0, commaPos);
        std::string description = line.substr(commaPos + 1);

        // Create a Command object and insert it at the front of the list
        Command cmd{name, description};
        insertAtFront(cmd);
    }

    file.close();
}


