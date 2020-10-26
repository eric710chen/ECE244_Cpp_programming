#ifndef DBentry_H
#define DBentry_H
using namespace std;
typedef string treeType;

class DBentry {
    private:
    string name;
    int IPaddress;
    public:
    DBentry();
    DBentry(string name, int IPaddress);
    string getName();
    int getIPaddress();
    void setName(string newname);
    void setIPaddress(int newIPaddress);
};
#endif // DBentry_H
