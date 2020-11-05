#ifndef OBJECT_H
#define OBJECT_H
#include <string>
using namespace std;


class object
{
    public:
        object(string name);
        virtual bool act() =0;
        void setObjectName(string n);
        string getObjectName();
        protected:
    string objectName;
    //
};

#endif // OBJECT_H
