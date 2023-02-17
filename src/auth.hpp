#include <iostream>
#include <string>
#include <map>
using namespace std;

class User {
  public:
    string name;
    string netId;
    int spCode;
};

class Handler {
  public:
    bool New_Data (const string &id, int code, const string &Name);
    bool Find (const string &id, int code);
    unsigned int Hash (const string &id);
    ~Handler();
  private:
    map <string, User *> Data;
};

bool Handler::Find (const string &id, int code) {
  /* If id doesn't exist or the code passed in doesn't match the id, returns false */
    if (Data.find(id) == Data.end()) return false;
    if (Data.find(id)->second != code) return false;

    return true;
}

bool Handler::New_Data(const string &id, int code, const string &Name) {
    /* If id is already in the map, we return false */
    if (Data.find(id) != Data.end()) return false;

    /* Creating a pointer to the User class, allocating mem, and setting its values */
    User *user;
    user = new User;

    user->name = Name;
    user->netId = id;
    user->spCode = code;

    /* Inserting the User instance with key (id) into the Data map */
    Data.insert(make_pair(id, user));

    return true;
}

unsigned int Handler::Hash(const string &id) {
    /* DJB hash function from the internet */
    size_t i;
    unsigned int h;

    h = 5381;

    for (i = 0; i < id.size(); i++) {
      h = (h << 5) + h + id[i];
    }

    return h;
}

Handler::~Handler() {
	map <string, User *>::const_iterator dit;
	/* Running through all of the Data and deleting the User pointer in the map */
	for (dit = Data.begin(); dit != Data.end(); ++dit) delete dit->second;
}