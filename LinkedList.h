#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

struct ItemNode {
    string itemName;
    int quantity;
    ItemNode* next;
    ItemNode(string itemName, int quantity) : itemName(itemName), quantity(quantity), next(nullptr) {}
};

class LinkedList
{
private:
    ItemNode* head;
    ItemNode* tail;
public:
    LinkedList();
    ~LinkedList();
    void push_back(string itemName, int quantity);
    void set_quantity(string itemName, int quantity, string inorout);
    int get_quantity(string itemName);
    void remove(string itemName);
    void printList();
    bool search(string itemName);
};

#endif

#pragma once
