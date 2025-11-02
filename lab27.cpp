#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

// Type alias for villager data: (friendship level, species, catchphrase)
using VillagerData = tuple<int, string, string>;

// Map: villager name -> (friendship level, species, catchphrase)
map<string, VillagerData> villagers;
