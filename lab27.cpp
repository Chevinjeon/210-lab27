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
    
    while (again) {
        int choice = main_menu();
        switch(choice) {
            case 1:
                add_villager();
                break;
            case 2:
                delete_villager();
                break;
            case 3:
                increase_friendship();
                break;
            case 4:
                decrease_friendship();
                break;
            case 5:
                search_villager();
                break;
            case 6:
                again = false;
                cout << "\nGoodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
        
        if (again && choice != 5 && choice != 6) {
            display_villagers();
        }
    }
    
    return 0;
}

// Display main menu and get user choice
int main_menu() {
    cout << "\n=== Villager Manager ===\n";
    cout << "[1] Add Villager\n";
    cout << "[2] Delete Villager\n";
    cout << "[3] Increase Friendship\n";
    cout << "[4] Decrease Friendship\n";
    cout << "[5] Search for Villager\n";
    cout << "[6] Exit\n";
    cout << "Enter choice: ";
    int choice;
    cin >> choice;
    return choice;
}

// Display all villagers in the map
void display_villagers() {
    cout << "\nVillager details:\n";
    for (const auto& pair : villagers) {
        int friendship = get<0>(pair.second);
        string species = get<1>(pair.second);
        string catchphrase = get<2>(pair.second);
        cout << pair.first << " [" << friendship << ", " << species 
             << ", " << catchphrase << "]\n";
    }
}

// Add a new villager
void add_villager() {
    string name, species, catchphrase;
    int friendship;
    
    cout << "\nVillager name: ";
    cin >> name;
    cout << "Friendship level: ";
    cin >> friendship;
    cin.ignore(); // Clear newline from buffer
    cout << "Species: ";
    getline(cin, species);
    cout << "Catchphrase: ";
    getline(cin, catchphrase);
    
    villagers[name] = make_tuple(friendship, species, catchphrase);
    cout << name << " added.\n";
}

// Delete a villager
void delete_villager() {
    if (villagers.empty()) {
        cout << "\nNo villagers to delete.\n";
        return;
    }
    
    cout << "\nEnter villager name to delete: ";
    string name;
    cin >> name;
    
    if (villagers.find(name) != villagers.end()) {
        villagers.erase(name);
        cout << name << " deleted.\n";
    } else {
        cout << "Villager \"" << name << "\" not found.\n";
    }
}
