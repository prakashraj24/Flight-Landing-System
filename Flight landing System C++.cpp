#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

class Hangar
{
public:
    int DepTime;
    int flightNo;
    Hangar *next;
    Hangar()
    {
        flightNo=(rand()%3000)+212;     // Default Constructor will generate random Flight number every time called
    }
};

class runway
{
private:
    Hangar *front,*rear;
    int MAX,rearPos;
public:
    runway()
    {
        front=rear=NULL;
        MAX=6;                          // Maximum capacity of hanger is 6
        rearPos=0;                      // At start front and rear both will be equal to NULL;
    }
    int getrearPos()
    {
        return rearPos;                 // Initially rear is zero so it return 0;
    }
    int full()                          // Checks queue is full or not
    {
        if(rearPos==MAX)
            return 1;
        else
            return 0;
    }
    int empty()                              // Checks queue is empty or not
    {
        if(rear==NULL)
            return 1;                       // First time it returns 1 because rear is NULL initially
        else
            return 0;
    }
    void land()                             // This function will generate random time every time it is called
    {
        int TempDeptime=(rand()%1000)+79;   // Random Departure time (We assumed that time is in minutes)
        Hangar *temp=new Hangar;
        temp->DepTime=TempDeptime;          // Departure time is set randomly (that we earlier assumed)
        temp->next=NULL;
        if(front==NULL)                     // When hanger is empty it will initialize front and rear to random departure time
        {
            front=temp;
            rear=front;
        }
        else
        {
            rear->next=temp;                // When some aeroplanes had landed in hanger then it will shift aeroplane in next location
            rear=temp;
        }
        rearPos++;                          //Increment rear position (initially 0 in second turn 1,...,6 and finally full)
    }
    void draw()                             // It will draw hanger (Code from Internet)
    {
        int HangarNum=1;
        for(int i=1;i<=25;i++)
        {
            cout<<"#";
        }
        cout<<endl;
        for(int j=1;j<=7;j++)
        {
            cout<<"#";
            cout<<"   ";
        }
        cout<<endl;
        for(int k=0;k<6;k++)
        {
            cout<<"#";
            if(HangarNum<=rearPos)
            {
                cout<<" # ";
            }
            else
            {
                cout<<"   ";
            }
            HangarNum++;
        }
        cout<<"#"<<endl;
        for(int j=1;j<=6;j++)
        {
            cout<<"#";
            cout<<"   ";
        }
        cout<<"#"<<endl;
        for(int i=1;i<=25;i++)
        {
            cout<<"#";
        }
    }
    void printdata()                     // It will print departure time and flight number when hanger is not empty nor full
    {
        Hangar *temp=front;
        while(temp!=rear)
        {
            cout<<endl<<endl;
            cout<<"Flight number "<<temp->flightNo<<endl;
            cout<<"Departure in "<<temp->DepTime<<"mins "<<endl;
            temp=temp->next;
        }
        cout<<endl<<endl;
        cout<<"Flight number "<<temp->flightNo<<endl;
        cout<<"Departure in "<<temp->DepTime<<"mins "<<endl;
    }
};

int main()
{
    char land;
    runway obj;
    for(int i=1;i<=7;i++)
    {
        obj.draw();
        cout<<endl;
        cout<<obj.getrearPos()<<" of 6 Hangars are full"<<endl;  // Initially Hangers are empty so 0 is returned
        if(obj.empty())
            cout<<"All hangars are empty "<<endl;
        else
        {
            obj.printdata();                                     // Initially this code does not execute
        }
        Sleep(rand()%10000);                                     // It delays output for some seconds
        cout<<"A flight wants to land here enter(Y/N)"<<endl;
        cin>>land;
        if(land=='N'||land=='n')
        {
            hangarfull:    cout<<"Permission not granted "<<endl;    // hangerfull is label of goto statement
                           cout<<"Please try later after "<<rand()%20<<" mins"<<endl;
                           system("pause");
        }
        else
        {
            if(obj.full())
            {
                goto hangarfull;            // if all hanger are full then it will goto hangerfull label
            }
            else
            {
                cout<<"You are clear to land"<<endl;
                obj.land();                 // Initially first aeroplane landed and given random departure time
                system("pause");
            }
        }
        system("cls");
    }
    obj.draw();                             // It will draw hanger (Code from internet)
    obj.printdata();                        // It will print flight number and departure time
    return 0;
}
