#include <iostream>
#include "LinkedList.h"
#include "PlantList.h"
#include <vector>
#include <cstdlib>
using namespace std;

void clearScreen();

void printMenu(bool paid);
void visitHouse(LinkedList& furniture, vector<string>& house, int houseCapacity);
void farming(LinkedList& seeds, LinkedList& plants, PlantList& farmPlants);
void fishing(int& bait, LinkedList& fish);
void DonCrook(bool& paid, LinkedList& seeds, LinkedList& plants, int& bait, LinkedList& fish, LinkedList& furniture, int& houseCapacity, int& chimes);
void explore(LinkedList& seeds, LinkedList& fish, int& chimes);

int main() {
    string player_name;
    string island_name;
    LinkedList fish;
    int bait = 1;
    LinkedList seeds;
    LinkedList plants;
    LinkedList furniture;
    vector<string> house;
    PlantList farmPlants;
    string choice;
    bool paid = false;
    bool quit = false;
    int dayNumber = 1;
    int activityCounter = 3;
    int houseCapacity = 5;
    int chimes = 0;



    cout << "Enter your name: " << endl;
    cin >> player_name;
    cout << "Enter your island's name: " << endl;
    cin >> island_name;
    cout << "Welcome to " << island_name << "!" << endl;
    cin.ignore();
    cout << "Press Enter to Continue";
    cin.ignore();
    clearScreen();
    //Don Crook Intro
    cout << "???: Hello and welcome to the island.";
    cin.ignore();
    cout << "???: My name is Don Crook.";
    cin.ignore();
    cout << "Don Crook: I'm the president and founder of Crook.Inc.";
    cin.ignore();
    cout << "Don Crook: Let me welcome you to your new house.";
    cin.ignore();
    cout << "Don Crook: Here's some furniture to furnish your house.";
    cin.ignore();
    cout << "You received: bed, lamp, and table.";
    cin.ignore();
    house.push_back("Bed");
    house.push_back("Lamp");
    house.push_back("Table");
    cout << "Don Crook: Of course, you'll need chimes to pay off these items!" << endl;
    cout << "   Type 1 for \"yeah I got chimes right here\"" << endl;
    cout << "   Type 2 for  \"chimes?\"" << endl;
    cout << "   Type anything else to say nothing" << endl;
    cin >> choice;
    if (choice == "1")
    {
        cout << "Don Crook: Great! Well let me just take those chimes and I'll be on my way!";
        cin.ignore();
        cin.ignore();
        cout << "Don Crook: .....";
        cin.ignore();
        cout << "Don Crook: Wait a minute! What is this green paper? No, no. I need chimes.";
    }
    else if (choice == "2")
    {
        cout << "Don Crook: Oh boy don't tell me...";
    }
    else
    {
        cout << "Don Crook: So you don't want to say anything eh?";
    }
    cin.ignore();

    cout << "Don Crook: Well let me tell you about our currency here, chimes!";
    cin.ignore();
    cout << "Don Crook: You can buy all sorts of things with them, including bait, seeds for farming, and even buy a new house!";
    cin.ignore();
    cout << "Don Crook: Since you got nothin on you, let me get you started with some seeds";
    cin.ignore();
    cout << "You received: 1 Sunflower Seed, 1 Watermelon Seed, 1 Carrot Seed";
    cin.ignore();
    seeds.push_back("SunflowerS", 1);
    seeds.push_back("CarrotS", 1);
    seeds.push_back("WatermelonS", 1);
    cout << "Don Crook: You see, there are different crops on this island that vary in value and time to grow.";
    cin.ignore();
    cout << "Don Crook: I'll let you go now and give you some time to earn some chimes";
    cin.ignore();
    cout << "It's been a long day for you and you decide to go to sleep";
    cin.ignore();
    clearScreen();

    //Intro Finished
    while (quit == false)
    {
        while (activityCounter != 0)
        {
            cout << "Day " << dayNumber << ": " << endl;
            cout << "Number of Activity Points: " << activityCounter << endl;
            printMenu(paid);
            cin >> choice;
            if (choice == "v")
            {
                clearScreen();
                visitHouse(furniture, house, houseCapacity);
            }
            else if (choice == "fr")
            {
                clearScreen();
                farming(seeds, plants, farmPlants);
            }
            else if (choice == "fi")
            {
                clearScreen();
                fishing(bait, fish);
            }
            else if (choice == "d")
            {
                clearScreen();
                DonCrook(paid, seeds, plants, bait, fish, furniture, houseCapacity, chimes);
            }
            else if (choice == "e")
            {
                clearScreen();
                explore(seeds, fish, chimes);
            }
            else if (choice == "q")
            {
                clearScreen();
                cout << "Are you sure you wanna quit? Type q again to quit." << endl;
                cin >> choice;
                if (choice == "q")
                {
                    cout << "Thanks for playing!" << endl;
                    return 0;
                }
                else
                {
                    cout << "Returning back to menu" << endl;
                }
            }
            activityCounter--;
            clearScreen();
        }
        dayNumber++;
        farmPlants.growPlants();
        activityCounter = 3;
        clearScreen();
    }
    return 0;
}

void clearScreen() {
    cout << "\033[2J\033[1;1H";
    return;
}

void printMenu(bool paid)
{//options needed visit house, farming, fishing, visiting Don Crook, going to different islands, talking to villagers
    cout << "v - Visit House" << endl;
    cout << "fr - Farming" << endl;
    cout << "fi - Fishing" << endl;
    cout << "d - Visit Don Crook" << endl;
    cout << "e - Explore the island" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option:" << endl;
}

void visitHouse(LinkedList& furniture, vector<string>& house, int houseCapacity)
{//see furniture in house, add furniture, remove furniture
    cout << "Visiting house" << endl;
    string input = "";
    while (input != "q")
    {
        cout << "f - see furniture currently in house" << endl;
        cout << "a - add furniture to house" << endl;
        cout << "r - remove furniture in house" << endl;
        cout << "q - leave house" << endl;
        cin >> input;
        if (input == "f")
        {
            cout << "Current Items in the house: " << endl;
            for (unsigned int i = 0; i < house.size(); i++)
            {
                cout << i + 1 << ". " << house.at(i) << endl;
            }
        }
        else if (input == "a")
        {
            furniture.printList();
            cout << endl;
            cout << "What furniture do you want to add to your house?" << endl;
            cin >> input;
            if (house.size() >= houseCapacity)
            {
                cout << "Unable to add furniture to house - max limit reached" << endl;
            }
            else
            {
                if (furniture.search(input)) {
                    furniture.set_quantity(input, 1, "out");
                    house.push_back(input);
                }
            }
        }
        else if (input == "r")
        {
            cout << "Current Items in the house: " << endl;
            for (unsigned int i = 0; i < house.size(); i++)
            {
                cout << i + 1 << ". " << house.at(i) << endl;
            }
            cout << "What furniture do you want to remove from the house?" << endl;
            cin >> input;
            for (unsigned int i = 0; i < house.size(); i++)
            {
                if (house.at(i) == input) {
                    house.erase(house.begin() + i);
                }
            }
            furniture.set_quantity(input, 1, "in");
        }
    }
    return;
}

void farming(LinkedList& seeds, LinkedList& plants, PlantList& farmPlants)
{
    cout << "Farming" << endl;
    string input = "";
    int harvestNum;
    while (input != "q")
    {//check seeds, check the plant growth, harvest plant
        cout << "s - Check Seeds" << endl;
        cout << "p - Plant the seeds" << endl;
        cout << "g - Check the growth of your plants" << endl;
        cout << "h - Harvest your Plants" << endl;
        cout << "q - leave the farm" << endl;
        cin >> input;
        if (input == "s")
        {
            cout << "Current Seeds: " << endl;
            seeds.printList();
            cout << endl;
        }
        else if (input == "p")
        {
            cout << "What seed do you want to plant?" << endl;
            cin >> input;
            if (input == "SunflowerS")
            {
                if (seeds.get_quantity(input) >= 1)
                {
                    farmPlants.push_back("Sunflower");
                    seeds.set_quantity(input, 1, "out");
                }
            }
            else if (input == "CarrotS")
            {
                if (seeds.get_quantity(input) >= 1)
                {
                    farmPlants.push_back("Carrot");
                    seeds.set_quantity(input, 1, "out");
                }
            }
            else if (input == "WatermelonS")
            {
                if (seeds.get_quantity(input) >= 1)
                {
                    farmPlants.push_back("Watermelon");
                    seeds.set_quantity(input, 1, "out");
                }
            }

        }
        else if (input == "g")
        {
            cout << "The growth caps for each plant: Sunflower(2), Carrot(3), Watermelon(4)" << endl;
            farmPlants.printList();
            cout << endl;
        }
        else if (input == "h")
        {
            PlantNode* temp = farmPlants.getHead();
            while (temp != nullptr)
            {
                if (temp->plantName == "Sunflower")
                {
                    if (temp->dayCount == 2)
                    {
                        harvestNum = farmPlants.remove("Sunflower", 2);
                        plants.set_quantity("Sunflower", harvestNum, "in");
                        temp = farmPlants.getHead();
                    }
                }
                else if (temp->plantName == "Carrot")
                {
                    if (temp->dayCount == 3)
                    {
                        harvestNum = farmPlants.remove("Carrot", 3);
                        plants.set_quantity("Carrot", harvestNum, "in");
                        temp = farmPlants.getHead();
                    }
                }
                else if (temp->plantName == "Watermelon")
                {
                    if (temp->dayCount == 4)
                    {
                        harvestNum = farmPlants.remove("Watermelon", 4);
                        plants.set_quantity("Watermelon", harvestNum, "in");
                        temp = farmPlants.getHead();
                    }
                } 
                else
                {
                    temp = temp->next;
                }
            }
        }
    }
    return;
}

void fishing(int& bait, LinkedList& fish)
{
    cout << "Going Fishing" << endl;
    string dummy;
    if (bait > 0)
    {
        srand((time(0) * 30));
        int event_number;
        bait--;
        event_number = (rand() % 100) + 1;
        if (event_number >= 1 && event_number <= 40)
        {
            cout << "You caught a Sea Bass! That’s’ at least a C+!" << endl;
            fish.set_quantity("SeaBass", 1, "in");
        }
        else if (event_number >= 41 && event_number <= 70)
        {
            cout << "You caught a Tuna! It’s a little off-key!" << endl;
            fish.set_quantity("Tuna", 1, "in");
        }
        else if (event_number >= 71 && event_number <= 90)
        {
            cout << "You caught a Salmon! Oh, that's slammin'!" << endl;
            fish.set_quantity("Salmon", 1, "in");
        }
        else if (event_number >= 91 && event_number <= 99)
        {
            cout << "You caught a Catfish! I caught a catfish! Who's meowing now?!" << endl;
            fish.set_quantity("Catfish", 1, "in");
        }
        else if (event_number == 100)
        {
            cout << "You caught a Pogfish! That's pretty pogchamp, bro!" << endl;
            fish.set_quantity("Pogfish", 1, "in");
        }
        cout << "Enter any key to continue: " << endl;
        cin >> dummy;
    }
    else
    {
        cout << "Sorry, but you got no game! Come back a little more al-lure-ing!" << endl;
        cout << "Enter any key to continue: " << endl;
        cin >> dummy;
    }
    return;
}

void DonCrook(bool& paid, LinkedList& seeds, LinkedList& plants, int& bait, LinkedList& fish, LinkedList& furniture, int& houseCapacity, int& chimes)
{//buying
    string input = "";
    int number;
    cout << "Visiting Don Crook" << endl;
    cout << "Don Crook: Hello my little friend, is there anything you need?" << endl;

    while (input != "q")
    {
        number = 0;
        clearScreen();
        cout << "You have " << chimes << " chimes" << endl;
        cout << "b - Buy items from Don Crook" << endl;
        cout << "s - Sell items to Don Crook" << endl;
        cout << "m - Pay off your House/Expand" << endl;
        cout << "q - Leave Don Crook" << endl;
        cin >> input;
        if (input == "b")
        {
            cout << "Don Crook: What would you like to buy?" << endl;
            cout << "~Don Crook's shop~" << endl;
            cout << "Bait:" << endl;
            cout << "1 - Bait $5" << endl;
            cout << "Seeds:" << endl;
            cout << "2 - Sunflower seed $5" << endl;
            cout << "3 - Carrot seed $7" << endl;
            cout << "4 - Watermelon seed $9" << endl;
            cout << "Furniture:" << endl;
            cout << "5 - Chair $15" << endl;
            cout << "6 - Bookshelf $30" << endl;
            cout << "7 - Bintendo Bit $40" << endl;
            cout << "8 - TV $50" << endl;
            cout << "9 - Piano $60" << endl;
            cin >> input;
            cout << "How much of that would you like?" << endl;
            cin >> number;
            if (input == "1")
            {
                if (chimes - 5 * number >= 0)
                {
                    chimes -= 5 * number;
                    bait = bait + number;
                }
                else
                {
                    cout << "Don Crook: You poor lol. Come back a little, mmm, richer!" << endl;
                }
            }
            else if (input == "2")
            {
                if (chimes - 5 * number >= 0)
                {
                    seeds.set_quantity("SunflowerS", number, "in");
                    chimes -= 5 * number;
                }
                else
                {
                    cout << "Don Crook: You poor lol. Come back a little, mmm, richer!" << endl;
                }
            }
            else if (input == "3")
            {
                if (chimes - 7 * number >= 0)
                {
                    seeds.set_quantity("CarrotS", number, "in");
                    chimes -= 7 * number;
                }
                else
                {
                    cout << "Don Crook: You poor lol. Come back a little, mmm, richer!" << endl;
                }

            }
            else if (input == "4")
            {
                if (chimes - 9 * number >= 0)
                {
                    seeds.set_quantity("WatermelonS", number, "in");
                    chimes -= 9 * number;
                }
                else
                {
                    cout << "Don Crook: You poor lol. Come back a little, mmm, richer!" << endl;
                }
            }
            else if (input == "5")
            {
                if (chimes - 15 * number >= 0)
                {
                    furniture.set_quantity("Chair", number, "in");
                    chimes -= 15 * number;
                }
                else
                {
                    cout << "Don Crook: You poor lol. Come back a little, mmm, richer!" << endl;
                }
            }
            else if (input == "6")
            {
                if (chimes - 30 * number >= 0)
                {
                    furniture.set_quantity("Bookshelf", number, "in");
                    chimes -= 30 * number;
                }
                else
                {
                    cout << "Don Crook: You poor lol. Come back a little, mmm, richer!" << endl;
                }
            }
            else if (input == "7")
            {
                if (chimes - 40 * number >= 0)
                {
                    furniture.set_quantity("BintendBit", number, "in");
                    chimes -= 40 * number;
                }
                else
                {
                    cout << "Don Crook: You poor lol. Come back a little, mmm, richer!" << endl;
                }
            }
            else if (input == "8")
            {
                if (chimes - 50 * number >= 0)
                {
                    furniture.set_quantity("TV", number, "in");
                    chimes -= 50 * number;
                }
                else
                {
                    cout << "Don Crook: You poor lol. Come back a little, mmm, richer!" << endl;
                }
            }
            else if (input == "9")
            {
                if (chimes - 60 * number >= 0)
                {
                    furniture.set_quantity("Piano", number, "in");
                    chimes -= 60 * number;
                }
                else
                {
                    cout << "Don Crook: You poor lol. Come back a little, mmm, richer!" << endl;
                }

            }
        }
        else if (input == "s")
        {
            cout << "Don Crook: So you wanna sell your stuff? What goodies do you have for me today?" << endl;
            cout << "~Sell List~" << endl;
            cout << "Plants:" << endl;
            cout << "1 - Sunflower $10" << endl;
            cout << "2 - Carrot $15" << endl;
            cout << "3 - Watermelon $20" << endl;
            cout << "Fish:" << endl;
            cout << "4 - Sea Bass $10" << endl;
            cout << "5 - Tuna $12" << endl;
            cout << "6 - Salmon $15" << endl;
            cout << "7 - Catfish $20" << endl;
            cout << "8 - Oarfish $75" << endl;
            cin >> input;
            cout << "How many do you want to sell?" << endl;
            cin >> number;
            if (input == "1")
            {
                if (plants.get_quantity("Sunflower") >= number)
                {
                    cout << "Alright! I'll give " << 10 * number << " that sound good? (type q for no, anything else for yes)" << endl;
                    cin >> input;
                    if (input == "q")
                    {
                        cout << "Ah alright. What else do you need?" << endl;
                    }
                    else
                    {
                        cout << "It's a deal then!" << endl;
                        chimes += 10 * number;
                        plants.set_quantity("Sunflower", number, "out");
                    }
                }
                else
                {
                    cout << "Sorry, you don't have " << number << " sunflowers you could sell me" << endl;
                }
            }
            else if (input == "2")
            {
                if (plants.get_quantity("Carrot") >= number)
                {
                    cout << "Alright! I'll give " << 15 * number << " that sound good? (type q for no, anything else for yes)" << endl;
                    cin >> input;
                    if (input == "q")
                    {
                        cout << "Ah alright. What else do you need?" << endl;
                    }
                    else
                    {
                        cout << "It's a deal then!" << endl;
                        chimes += 15 * number;
                        plants.set_quantity("Carrot", number, "out");
                    }
                }
                else
                {
                    cout << "Sorry, you don't have " << number << " carrots you could sell me" << endl;
                }
            }
            else if (input == "3")
            {
                if (plants.get_quantity("Watermelon") >= number)
                {
                    cout << "Alright! I'll give " << 20 * number << " that sound good? (type q for no, anything else for yes)" << endl;
                    cin >> input;
                    if (input == "q")
                    {
                        cout << "Ah alright. What else do you need?" << endl;
                    }
                    else
                    {
                        cout << "It's a deal then!" << endl;
                        chimes += 20 * number;
                        plants.set_quantity("Watermelon", number, "out");
                    }
                }
                else
                {
                    cout << "Sorry, you don't have " << number << " watermelons you could sell me" << endl;
                }
            }
            else if (input == "4")
            {
                if (fish.get_quantity("SeaBass") >= number)
                {
                    cout << "Alright! I'll give " << 10 * number << " that sound good? (type q for no, anything else for yes)" << endl;
                    cin >> input;
                    if (input == "q")
                    {
                        cout << "Ah alright. What else do you need?" << endl;
                    }
                    else
                    {
                        cout << "It's a deal then!" << endl;
                        chimes += 10 * number;
                        fish.set_quantity("SeaBass", number, "out");
                    }
                }
                else
                {
                    cout << "Sorry, you don't have " << number << " sea bass you could sell me" << endl;
                }
            }
            else if (input == "5")
            {
                if (fish.get_quantity("Tuna") >= number)
                {
                    cout << "Alright! I'll give " << 12 * number << " that sound good? (type q for no, anything else for yes)" << endl;
                    cin >> input;
                    if (input == "q")
                    {
                        cout << "Ah alright. What else do you need?" << endl;
                    }
                    else
                    {
                        cout << "It's a deal then!" << endl;
                        chimes += 12 * number;
                        fish.set_quantity("Tuna", number, "out");
                    }
                }
                else
                {
                    cout << "Sorry, you don't have " << number << " tuna you could sell me" << endl;
                }
            }
            else if (input == "6")
            {
                if (fish.get_quantity("Salmon") >= number)
                {
                    cout << "Alright! I'll give " << 15 * number << " that sound good? (type q for no, anything else for yes)" << endl;
                    cin >> input;
                    if (input == "q")
                    {
                        cout << "Ah alright. What else do you need?" << endl;
                    }
                    else
                    {
                        cout << "It's a deal then!" << endl;
                        chimes += 15 * number;
                        fish.set_quantity("Salmon", number, "out");
                    }
                }
                else
                {
                    cout << "Sorry, you don't have " << number << " salmon you could sell me" << endl;
                }
            }
            else if (input == "7")
            {
                if (fish.get_quantity("Catfish") >= number)
                {
                    cout << "Alright! I'll give " << 20 * number << " that sound good? (type q for no, anything else for yes)" << endl;
                    cin >> input;
                    if (input == "q")
                    {
                        cout << "Ah alright. What else do you need?" << endl;
                    }
                    else
                    {
                        cout << "It's a deal then!" << endl;
                        chimes += 20 * number;
                        fish.set_quantity("Catfish", number, "out");
                    }
                }
                else
                {
                    cout << "Sorry, you don't have " << number << " catfish you could sell me" << endl;
                }
            }
            else if (input == "8")
            {
                if (fish.get_quantity("Oarfish") >= number)
                {
                    cout << "Alright! I'll give " << 75 * number << " that sound good? (type q for no, anything else for yes)" << endl;
                    cin >> input;
                    if (input == "q")
                    {
                        cout << "Ah alright. What else do you need?" << endl;
                    }
                    else
                    {
                        cout << "It's a deal then!" << endl;
                        chimes += 75 * number;
                        fish.set_quantity("Oarfish", number, "out");
                    }
                }
                else
                {
                    cout << "Sorry, you don't have " << number << " oarfish you could sell me" << endl;
                }
            }
        }
        else if (input == "m")
        {
            if (houseCapacity == 5)
            {
                if (chimes >= 200)
                {
                    cout << "Don Crook: Do you want to pay off your house for 200 chimes? (Type y for yes, n for no)" << endl;
                    cin >> input;
                    if (input == "y")
                    {
                        chimes -= 200;
                        paid = true;
                        houseCapacity = 10;
                    }
                    else if (input == "n")
                    {
                        cout << "Don Crook: Well alright, come back later then!" << endl;
                    }
                }
                else
                {
                    cout << "Don Crook: Sorry, you don't have enough chimes yet to pay off the house." << endl;
                }
            }
            else if (houseCapacity == 10)
            {
                if (chimes >= 400)
                {
                    cout << "Don Crook: Do you want to expand your house for 400 chimes? (Type y for yes, n for no)" << endl;
                    cin >> input;
                    if (input == "y")
                    {
                        chimes -= 400;
                        houseCapacity = 15;
                    }
                    else if (input == "n")
                    {
                        cout << "Don Crook: Well alright, come back later then!" << endl;
                    }
                }
                else
                {
                    cout << "Don Crook: Sorry, you don't have enough chimes yet to expand the house." << endl;
                }
            }
        }
        else if (input == "q")
        {
            cout << "Don Crook: Are you finished? (Type q to leave)" << endl;
            cin >> input;
            if (input == "q")
            {
                cout << "Don Crook: Alright then! You know where to find me if you need anything else!" << endl;
                return;
            }
            else
            {
                cout << "What else do you need?" << endl;
            }
        }
    }
    return;
}

void explore(LinkedList& seeds, LinkedList& fish, int& chimes)
{
    cout << "Going exploring!" << endl;
    string dummy;
    srand((time(0) * 30));
    int event_number;
    event_number = (rand() % 100) + 1;
    if (event_number >= 1 && event_number <= 17)
    {
        cout << "You scourged around and got a Sunflower seed!" << endl;
        seeds.set_quantity("SunflowerS", 1, "in");
    }
    else if (event_number >= 18 && event_number <= 27)
    {
        cout << "You see a small orange seed and picked it up. You got a Carrot seed!" << endl;
        seeds.set_quantity("CarrotS", 1, "in");
    }
    else if (event_number >= 28 && event_number <= 33)
    {
        cout << "Nice! You got a Watermellon seed!" << endl;
        seeds.set_quantity("WatermelonS", 1, "in");
    }
    else if (event_number >= 34 && event_number <= 53)
    {
        cout << "You explore your island and notice a small glint in the distance. You got 5 chimes!" << endl;
        chimes += 5;
    }
    else if (event_number >= 54 && event_number <= 63)
    {
        cout << "You catch a decent glimmer in your eye walking around. You got 10 chimes!" << endl;
        chimes += 10;
    }
    else if (event_number >= 64 && event_number <= 67)
    {
        cout << "You walk around until something really bright shimmers. You got 15 chimes!" << endl;
        chimes += 15;
    }
    else if (event_number >= 68 && event_number <= 87)
    {
        cout << "You went swimming and caught a Sea Bass! That's pretty badass!" << endl;
        fish.set_quantity("SeaBass", 1, "in");
    }
    else if (event_number >= 88 && event_number <= 100)
    {
        cout << "You swim near the shore and caught a Tuna! What a great opportunaty!" << endl;
        fish.set_quantity("Tuna", 1, "in");
    }
    cout << "Enter any key to continue: " << endl;
    cin >> dummy;
}