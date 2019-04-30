#include <iostream.h>
#include <stdio.h>

using namespace std;

class stu{
int rno;
char name[20];
public:
    void getdata()
    {
        cout<<" Enter rno and name "<<endl;
        cin>>rno;
        gets(name);
        }
        void display();
        };
        void stu::display()
        {
            cout<<" R no : "<<rno<<endl;
            cout<<" Name : "<<name<<endl;
        }
void main()

{
    stu s;
    s.getdata();
    s.display();
}
