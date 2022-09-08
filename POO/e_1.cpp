#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <algorithm>
using namespace std;

struct dog
{
    string race;
    string name;
    int age;
};

vector<dog> creare() {
    int num,aged;
    string named,raced;
    cout << "\nIntroduceti numarul de caini : ";
    cin >> num;
    vector<dog> created(num);

    for (int i=0;i<num;i++) {
    cout << "\nCainele nr." << i;
    
    cout << "\nIntroduceti rasa\n";
    cin >> created[i].race;

    cout << "Introduceti numele\n";
    cin >> created[i].name;

    cout << "Introduceti varsta\n";
    cin >> created[i].age;
}
return created;
}


void afisare(vector<dog> arr) {
    for (int i=0;i < arr.size();i++) {
        cout << arr[i].race << endl;
        cout << arr[i].name << endl;
        cout << arr[i].age << endl;
        cout << "\n";
    }
}

bool my_comp(dog a, dog b){
	return a.age < b.age;
}

void swap(dog *a, dog *b) {
    dog temp = *a;
    *a=*b;
    *b=temp;
}


void sort_by_alph(vector<dog> &arr) {
    sort(arr.begin(),arr.end(),my_comp);
    for(int i=0;i<arr.size();i++) {
        for(int j=i+1;j<arr.size();j++){ 
            if(arr[i].age == arr[j].age){
                if(arr[i].name > arr[j].name){
                    cout << "hello";
                    swap(arr[i],arr[j]);
                }
                
            }
        }
    }
}


int menu() {
    system("CLS");
    cout << "\n\n1. Creare listei de caini.\n";
    cout << "2. Afisarea listei.\n";
    cout << "3. Sortare.\n";
    cout << "0. Exit.\n";
    int command = 3;
    cin >> command;
    return command;
}

main() {

   vector<dog> dogs;
    int command = 3;
    while(command != 0)
    {
    command = menu();
    if(command == 1)
    {
    dogs = creare();
    }
    switch (command)
    {
    case 2:
        afisare(dogs);
        break;
    case 3:
        sort_by_alph(dogs);
        break;
    case 0:
        exit(0);
        break;
    default:
        break;
    }
     printf("\nPress any Key to continue!\n");
	_getch();
    }


    
}
