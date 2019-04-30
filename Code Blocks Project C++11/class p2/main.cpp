#include <iostream.h>

using namespace std;

class item{
public:
    void initialize(void);
    float large(void);
    float sum(void);
    void display_item(void);
private:
    int icode[3];
    float it_price[3];
    };
    void item::initialize(void)
    {
        for(int i=0;i<3;i++)
        {
            cout<<"\n Enter item code for item : "<<i+1<<"  :";
            cin>>icode[i];
            cout<<" \n Enter item price for item : "<<i+1<<"  :";
            cin>>it_price[i];
        }
    }
    float item::large(void)
    {
        float l=it_price[0];
        for(int i=0;i<3;)
            if(l<it_price[i])
            l=it_price[i];
        return l;
    }
    float item::sum(void)
    {
        float s=0;
        for(int i=0;i<5;i++)
        {
            s+=it_price[i];
           }
            return s;
    }
    void item::display_item(void)
    {
        cout<<"\n Code price"<<endl;
        for(int i=0;i<3;i++)
            cout<<"\n"<<icode[i]<<"\t"<<it_price[i]<<endl;
            system("pause");
    }

    int main()
    {
        item o;
        o.initialize();
        cout<<"Sum is"<<o.sum()<<endl;
        cout<<"Max Price is "<<o.large()<<endl;
        cout<<"\n---------------------\n";
        o.display_item();
        return 0;
    }
