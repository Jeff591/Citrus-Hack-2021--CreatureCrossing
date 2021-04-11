#include "PlantList.h"
#include <iostream>

using namespace std;


PlantList::PlantList()
{
    head = nullptr;
    tail = nullptr;
}
PlantList::~PlantList()
{
    PlantNode* temp = head;
    while (head != nullptr) {
        head = head->next;
        delete temp;
        temp = head;
    }
    tail = nullptr;
}
void PlantList::push_back(string plantName)
{
    PlantNode* temp = new PlantNode(plantName);
    if (head == nullptr)
    {
        this->head = temp;
        this->tail = temp;
    }
    else
    {
        this->tail->next = temp;
        this->tail = temp;
    }
}
int PlantList::remove(string plantName, int harvestNum)
{
    PlantNode* temp = nullptr;
    int removed_counter = 0;
    if (head->plantName == plantName)
    {
        if (head->dayCount == harvestNum)
        {
            temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
            removed_counter++;
        }
    }
    else
    {
        temp = head->next;
        PlantNode* prev = head;
        while (temp != nullptr)
        {
            if (temp->plantName == plantName) {
                if (temp->dayCount == harvestNum)
                {
                    if (temp == tail) {
                        prev->next = nullptr;
                        delete temp;
                        temp = nullptr;
                        tail = prev;
                        removed_counter++;
                    }
                    else
                    {
                        prev->next = temp->next;
                        delete temp;
                        temp = nullptr;
                        removed_counter++;
                    }
                }
            }
            else
            {
                temp = temp->next;
                prev = prev->next;
            }
        }
        if (removed_counter == 0)
        {
            cout << "Item could not be found" << endl;
        }
    }
    return removed_counter;
}
void PlantList::printList()
{
    PlantNode* temp = head;
    while (temp != nullptr) {
        if (temp->next == nullptr) {
            cout << temp->plantName << "(" << temp->dayCount << ")";
        }
        else {
            cout << temp->plantName << "(" << temp->dayCount << ")" << " ";
        }
        temp = temp->next;
    }

    return;

}
void PlantList::growPlants() //growth cap sunflower: 2, carrot: 3, watermelon: 4
{
    PlantNode* temp = head;
    while (temp != nullptr) {
        if (temp->plantName == "Sunflower")
        {
            if (temp->dayCount != 2)
            {
                temp->dayCount += 1;
            }
        }
        else if (temp->plantName == "Carrot")
        {
            if (temp->dayCount != 3)
            {
                temp->dayCount += 1;
            }
        }
        else if (temp->plantName == "Watermelon")
        {
            if (temp->dayCount != 4)
            {
                temp->dayCount += 1;
            }
        }
        temp = temp->next;
    }

    return;
}

PlantNode* PlantList::getHead()
{
    return head;
}