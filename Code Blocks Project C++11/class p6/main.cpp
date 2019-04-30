#include <iostream>

using namespace std;

class set{
int m,n;
int largest(void);
public:
    void input(void);
    void display(void);
};
int set :: largest(void)
{
    if(m>n)
        return m;
        else
            return n;

}
void set :: input(void)
{
    cout<<"Input value of m and n : \n";
    cin>>m>>n;
}
void set :: display(void)
{
    cout<<"Largest value is:"<<largest()<<endl;}

    int main()
    {
        set A;
        A.input();
        A.display();
        return 0;
    }
