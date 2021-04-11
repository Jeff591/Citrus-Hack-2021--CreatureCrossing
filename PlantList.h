#pragma once
#ifndef PLANTLIST_H
#define PLANTLIST_H

#include <iostream>
#include <string>
using namespace std;

struct PlantNode {
    string plantName;
    int dayCount;
    PlantNode* next;
    PlantNode(string plantName) : plantName(plantName), dayCount(0), next(nullptr) {}
};

class PlantList
{
private:
    PlantNode* head;
    PlantNode* tail;
public:
    PlantList();
    ~PlantList();
    void push_back(string plantName);
    int remove(string plantName, int harvestNum);
    void growPlants();
    void printList();
    PlantNode* getHead();
};

#endif