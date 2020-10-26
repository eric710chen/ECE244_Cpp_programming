#ifndef DBentry_H
#define DBentry_H
using namespace std;
typedef string treeType;

class DBentry {
    private:
    string name;
    int IPaddress;
    bool active;
    public:
    DBentry();
    DBentry(string name, int IPaddress, bool active);
    string getName();
    int getIPaddress();
    bool getActive ();
    string printactive (bool ifactive);
    void setName(string newname);
    void setIPaddress(int newIPaddress);
    void setactive (bool newactive);
};
#endif // DBentry_H
