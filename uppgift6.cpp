//Johan Fröderberg

#include <iostream>
using namespace std;

int main(){
    int price,payed,change;

    // ställ frågor och ta emot input
    cout << "hur mycket kostar den?"<< "\n" << "svar: ";
    cin >> price;
    cout << "vad betalade du?" << "\n" <<"Svar: ";
    cin >> payed;

    //beräkna växel vi arbetar med
    change = payed - price; 
    
    //presentation och beräkning 
    cout << "Du skall ha detta tillbaka i växel:"<< "\n";
    cout << "\t" << change / 100 << " st " << "Hundrakronorssedlar, " << "\n";
        change = change % 100;
    cout << "\t" << change / 50 <<" st " << "Femtiokronorssedel," << "\n";
        change = change % 50;
    cout << "\t" << change / 20 <<" st " << "Tjugokronerssedel," << "\n";
        change = change % 20;
    cout << "\t" << change / 10 <<" st " << "Tiokronorsmynt,"<< "\n";
        change = change % 10;
    cout << "\t" << change / 5 <<" st " << "Femkronorsmynt," << "\n";
        change = change % 5;
    cout << "\t" << change <<" st "<< "Enkronorsmynt." << endl;
    
}