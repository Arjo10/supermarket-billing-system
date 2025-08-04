#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>

using namespace std;

class Receipt{
private:
    string ITEM;
    float RATE;
    int NUMBER;
public:
    Receipt():ITEM(""),RATE(0.0),NUMBER(0){}

    void setitem(string item){
    ITEM=item;
    }

    void setrate(float rate){
    RATE=rate;
    }

    void setnumber(int number){
    NUMBER=number;
    }

    string getitem(){
    return ITEM;
    }

    float getrate(){
    return RATE;
    }

    int getnumber(){
    return NUMBER;
    }
};

void additem(Receipt b){
bool close=false;
while(!close){
    system("cls");
    int choice;
    cout<<"\t1.Add"<<endl;
    cout<<"\t2.Close"<<endl;
    cout<<"Enter Your Choice"<<endl;
    cin>>choice;
    if(choice==1){
        string item;
        float rate;
        int number;
        cout<<"Enter name of item"<<endl;
        cin>>item;
        b.setitem(item);

        cout<<"Enter rate of item"<<endl;
        cin>>rate;
        b.setrate(rate);

        cout<<"Enter number of item"<<endl;
        cin>>number;
        b.setnumber(number);

        ofstream out("C:\\Users\\USER\\OneDrive\\Documents\\C++\\Receipt.txt", ios::app);

        if(!out){
            cout<<"File Not Opening"<<endl;
        }
        else{
            out<<b.getitem()<<"\t"<<b.getrate()<<"\t"<<b.getnumber()<<endl;
        }
        out.close();
        cout<<"\t Item added successfully"<<endl;
        Sleep(3000);
    }
    else if(choice==2){
        system("cls");
        close=true;
        cout<<"Back to main menu"<<endl;
        Sleep(3000);
    }
}
}

void printbill(){
    system("cls");
    int count=0;
    bool close=false;
    while(!close){
        system("cls");
        int choice;
        cout<<"1.Add Bill"<<endl;
        cout<<"2.Close Session"<<endl;
        cout<<"Enter Your Choice"<<endl;
        cin>>choice;
        if(choice==1){
            string item;
            int quantity;
            cout<<"Enter Item"<<endl;
            cin>>item;
            cout<<"Enter quantity"<<endl;
            cin>>quantity;
            ifstream in("C:\\Users\\USER\\OneDrive\\Documents\\C++\\Receipt.txt");
            ofstream out("C:\\Users\\USER\\OneDrive\\Documents\\C++\\ReceiptTemp.txt");

            string line;
            bool found=false;
            while(getline(in,line)){
            stringstream s;
            s<<line;
            string itemname;
            float itemrate;
            int itemquantity;
            s>>itemname>>itemrate>>itemquantity;

            if(item==itemname){
                found=true;;
                if(quantity<=itemquantity){
                    int amount=quantity*itemrate;
                    cout<<"\tItem | Rate |Quantity | Amount"<<endl;
                    cout<<"\t"<<itemname<<"\t"<<itemrate<<"\t"<<quantity<<"\t"<<amount<<endl;
                    itemquantity=itemquantity-quantity;
                    count=count+amount;

                    out<<itemname<<"\t"<<itemrate<<"\t"<<itemquantity<<endl;
                }
                else{
                    cout<<"Quantity not available"<<endl;
                }
            }
            else{
                out<<line<<endl;
            }
            }
            if(!found){
                cout<<"Item Not Available"<<endl;
            }
            in.close();
            out.close();
            remove("C:\\Users\\USER\\OneDrive\\Documents\\C++\\Receipt.txt");
            rename("C:\\Users\\USER\\OneDrive\\Documents\\C++\\ReceiptTemp.txt","C:\\Users\\USER\\OneDrive\\Documents\\C++\\Receipt.txt");
        }
        else if(choice==2){
            close=true;
            cout<<"Counting total bill"<<endl;
    Sleep(3000);
    system("cls");
    cout<<endl;
    cout<<"TOTAL BILL IS--->"<<count<<endl;
    Sleep(4000);
        }
        Sleep(3000);
    }
    /*system("cls");
    cout<<endl;
    cout<<"TOTAL BILL IS--->"<<count<<endl;
    Sleep(4000);*/
}



int main(){
 Receipt b;
 bool exit=false;
 while(!exit){
 system("cls");
 int val;
 cout<<"\tWELCOME TO SUPER MARKET BILLING SYSTEM"<<endl;
 cout<<"\t**************************************"<<endl;
 cout<<"\t\t1.Add Item"<<endl;
 cout<<"\t\t2.Print Bill"<<endl;
 cout<<"\t\t3.Exit"<<endl;
 cout<<"\t\tEnter Your Choice"<<endl;
 cin>>val;

 if(val==1){
  system("cls");
  additem(b);
 Sleep(3000);
 }
 else if(val==2){
    printbill();
 }
 else if(val==3){
system("cls");
exit=true;
cout<<"GOOD BYE"<<endl;
Sleep(3000);
}
}
}
