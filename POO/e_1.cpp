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

void add_element(vector<dog> &arr) {
    dog temp = {};
    cout << "\nIntroduceti rasa\n";
    cin >> temp.race;

    cout << "Introduceti numele\n";
    cin >> temp.name;

    cout << "Introduceti varsta\n";
    cin >> temp.age;

    arr.push_back(temp);
}

void delete_element(vector<dog> &arr) {
    int position;
    vector<dog> :: iterator it;
    cout << "Introduceti nr. cainelui care doriti sa il stergeti : ";
    cin >> position;
    it = arr.begin()+position;
    arr.erase(it);
}


void afisare(vector<dog> arr) {
    for (int i=0;i < arr.size();i++) {
        cout << "\nCainele nr." << i;
        cout << "\n" <<arr[i].race << endl;
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
    int error_input_found = 0;
menu_start: 
    system("CLS");
    cout << "\n\n1. Creare listei de caini.\n";
    cout << "2. Afisarea listei.\n";
    cout << "3. Adaugare element in lista\n";
    cout << "4. Stergere element din lista\n";
    cout << "5. Sortare.\n";
    cout << "6. Stergere lista.\n";
    cout << "0. Exit.\n";
    int command = 6;
    cin >> command;

     while(command>6 || command<0)
    {
      cout << "Command does not exist .\n";
      error_input_found = 1;
      _getch();
      goto menu_start;
    }
    return command;
}

main() {

   vector<dog> dogs;
    int command = 6;
    while(command != 0)
    {
    command = menu();
    if(command == 1)
    {
        if(dogs.empty() == false) {
            dogs.clear();
            dogs = creare();
        }
        else {
            dogs = creare();
        }

    }
    switch (command)
    {
    case 2:
        afisare(dogs);
        break;
    case 3:
        add_element(dogs);
        break;
    case 4:
        delete_element(dogs);
    case 5:
        sort_by_alph(dogs);
        break;
    case 6:
        dogs.clear();
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
