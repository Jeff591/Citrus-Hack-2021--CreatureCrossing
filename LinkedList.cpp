#include <iostream>
#include <ostream>
#include "LinkedList.h"

using namespace std;

/*
  string itemName;
  int quantity;
  ItemNode *next;
*/

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}
LinkedList::~LinkedList()
{
    ItemNode* temp = head;
    while (head != nullptr) {
        head = head->next;
        delete temp;
        temp = head;
    }
    tail = nullptr;
}

void LinkedList::push_back(string itemName, int quantity)
{
    ItemNode* temp = new ItemNode(itemName, quantity);
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
void LinkedList::set_quantity(string itemName, int quantity, string inorout)
{
    ItemNode* temp = head;
    if (inorout == "in")
    {
        while (temp != nullptr)
        {
            if (temp->itemName == itemName)
            {
                temp->quantity += quantity;
                return;
            }
            temp = temp->next;
        }
        push_back(itemName, quantity);
        return;
    }
    else if (inorout == "out") {
        while (temp != nullptr)
        {
            if (temp->itemName == itemName)
            {
                if (temp->quantity - quantity < 0)
                {
                    cout << "Do not have enough items" << endl;
                    return;
                }
                else if (temp->quantity - quantity == 0)
                {
                    remove(itemName);
                    return;
                }
                else
                {
                    temp->quantity -= quantity;
                    return;
                }
            }
            temp = temp->next;
        }
        cout << "Do not have the item" << endl;
        return;
    }
}

int LinkedList::get_quantity(string itemName)
{
    ItemNode* temp = head;
    while (temp != nullptr)
    {
        if (temp->itemName == itemName)
        {
            return temp->quantity;
        }
        temp = temp->next;
    }
    cout << "Item could not be found" << endl;
    return 0;
}

void LinkedList::remove(string itemName)
{
    ItemNode* temp = nullptr;
    if (head->itemName == itemName)
    {
        temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        return;
    }
    temp = head->next;
    ItemNode* prev = head;
    while (temp != nullptr)
    {
        if (temp->itemName == itemName) {
            if (temp == tail) {
                prev->next = nullptr;
                delete temp;
                temp = nullptr;
                tail = prev;
                return;
            }
            else
            {
                prev->next = temp->next;
                delete temp;
                temp = nullptr;
                return;
            }
        }
        temp = temp->next;
        prev = prev->next;
    }
    cout << "Item could not be found" << endl;
    return;
}

void LinkedList::printList() {
    ItemNode* temp = head;
    while (temp != nullptr) {
        if (temp->next == nullptr) {
            cout << temp->itemName << "(" << temp->quantity << ")";
        }
        else {
            cout << temp->itemName << "(" << temp->quantity << ")" << " ";
        }
        temp = temp->next;
    }

    return;

}

bool LinkedList::search(string itemName) 
{
    ItemNode* temp = head;
    while (temp != nullptr)
    {
        if (temp->itemName == itemName)
        {
            return true;
        }
        temp = temp->next;
    }
    cout << "Item could not be found" << endl;
    return false;
}