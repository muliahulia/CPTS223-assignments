// list.h

#ifndef LIST_H
#define LIST_H

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

struct Command {
    string name;
    string description;

    Command(const string& cmd, const string& desc) : name(cmd), description(desc) {}
};

struct Node {
    Command command;
    Node* next;

    Node(const Command& cmd) : command(cmd), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    Node* getHead() const;
    void setHead(Node* newHead);


    int getCount() const ;
    void insertAtFront(const Command& command);
    bool removeNode(const string& commandName);
    bool contains(const string& commandName) const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
    

private:
    Node* head;
    int size;
};

#endif // LIST_H
