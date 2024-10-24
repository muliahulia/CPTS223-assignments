#include <map>
#include "generateUsers.hpp"
using namespace std;


map<string, User> buildMapByUserName(vector<User> users) {
    map<string, User> usersMap;
    
    // cout << "TODO" << endl;
    for (const auto& user : users){
        usersMap[user.userName] = user;
        }
    return usersMap;
}


map<string, User> buildMapByEmail(vector<User> users) {
    map<string, User> usersMap;
    
    // cout << "TODO" << endl;

    for (const auto& user : users){
        usersMap[user.email] = user;
    }

    return usersMap;
}


void printMap(map<string, User> aMap) {
    //cout << "TODO" << endl;

    for (const auto& entry : aMap){
        cout << "Key: " << entry.first 
        << ", User: " << entry.second.userName 
        << ", Email: " <<entry.second.email << endl;
    }
}


bool isMapSorted(map<string, User> aMap) {
    if ( aMap.empty() )
        return true;
    
    //cout << "TODO" << endl;
    
    auto prevKey = aMap.begin()->first;
    for(auto it = next(aMap.begin()); it != aMap.end(); ++it){
        if(it->first < prevKey){
            return false;
        }
        prevKey = it->first;
    }
    return true;
}


bool testSearchByKey(map<string, User> aMap, string keyToSearch) {
   // cout << "TODO" << endl;
   return aMap.find(keyToSearch) != aMap.end();
}


bool testDeleteByKey(map<string, User> aMap, string keyToDelete) {
    //cout << "TODO" << endl;
    if (aMap.erase(keyToDelete)>0){
        cout << "sucess" << keyToDelete << endl;
        return true;
    }
    return false;
}


void printActiveUsers(map<string, User> aMap) {
    int activeThreshold = 800;
    //cout << "TODO" << endl;
    for (const auto& entry : aMap){
        if (entry.second.numPosts > activeThreshold){
            cout << entry.second.userName << " has " << entry.second.numPosts << " posts. "<<endl;
        }
    }
}


void printMostPopularCategory(map<string, User> aMap) {    
    // cout << "TODO" << endl;
    map<string, int> categoyCount;
    for (const auto& entry : aMap){
        categoyCount[entry.second.mostViewedCategory]++;
    }

    string printMostPopularCategory;
    int maxCount = 0;
    for(const auto& category : categoyCount){
        if (category.second > maxCount){
            maxCount = category.second;
            printMostPopularCategory = category.first;
        }
    }

    cout << "Most pop Category: " 
    << printMostPopularCategory 
    << " with" << maxCount
     << " users. " << endl;

}    



int main()
{


    int numUsers = 10;
    vector<User> users = generateUsers(numUsers);

    cout << "Build map with username as key" << endl;
    map<string, User> mapByUserName = buildMapByUserName(users);
    if ( mapByUserName.size() == numUsers )
        cout << "  Built successfully." << endl << endl;
    else
        cout << "  Built unsuccessfully." << endl << endl;


    cout << "Print \"mapByUserName\" map:" << endl;
    printMap(mapByUserName);
    cout << endl;


    string keyToSearch = "smith55";
    cout << "Search by key: mapByUserName[\"" << keyToSearch << "\"]" << endl;
    if ( testSearchByKey(mapByUserName, keyToSearch) )
        cout << "  Search successfully." << endl << endl;
    else
        cout << "  Search unsuccessfully." << endl << endl;


    string keyToDelete = "smith55";
    cout << "Delete by key: \"" << keyToDelete << "\"" << endl;
    if ( testDeleteByKey(mapByUserName, keyToDelete) )
        cout << "  Delete successfully." << endl << endl;
    else
        cout << "  Delete unsuccessfully." << endl << endl;


    cout << "Test if map's key is sorted" << endl;
    if ( isMapSorted(mapByUserName) )
        cout << "  Order test passed!" << endl << endl;
    else
        cout << "  Order test failed!" << endl << endl;


    cout << "Print usernames with more than 800 tweets:" << endl;
    printActiveUsers(mapByUserName);
    cout << endl;

    cout << "Print the most popular category" << endl;
    printMostPopularCategory(mapByUserName);
    cout << endl;


    cout << " ============================================================================== " << endl << endl;


    cout << "Build map with username as key" << endl;
    map<string, User> mapByEmail = buildMapByEmail(users);
    if ( mapByEmail.size() == numUsers )
        cout << "  Built successfully." << endl << endl;
    else
        cout << "  Built unsuccessfully." << endl << endl;
    

    keyToSearch = "kat@gmail.com";
    cout << "Search by key: mapByEmail[\"" << keyToSearch << "\"]" << endl;
    if ( testSearchByKey(mapByEmail, keyToSearch) )
        cout << "  Search successfully." << endl << endl;
    else
        cout << "  Search unsuccessfully." << endl << endl;


    keyToDelete = "kat@gmail.com";
    cout << "Delete by key: \"" << keyToDelete << "\"" << endl;
    if ( testDeleteByKey(mapByEmail, keyToDelete) )
        cout << "  Delete successfully." << endl << endl;
    else
        cout << "  Delete unsuccessfully." << endl << endl;


    return 0;
}
