#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

// Type alias for villager data: (friendship level, species, catchphrase)
using VillagerData = tuple<int, string, string>;

// Map: villager name -> (friendship level, species, catchphrase)
map<string, VillagerData> villagers;

// Function declarations
int main_menu();
void display_villagers();
void increase_friendship();
void decrease_friendship();
void search_villager();
void add_villager();
void delete_villager();

int main() {
    // Initialize with some sample villagers for Milestone 1/2
    villagers["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
    villagers["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagers["Raymond"] = make_tuple(8, "Cat", "Nice fit");
    
    bool again = true;
