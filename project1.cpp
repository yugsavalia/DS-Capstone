#include <bits/stdc++.h>
using namespace std;

struct Recipie{
    string name;
    vector<string> ingredient;
    string category;
    string instruction;
};

list<Recipie> L;

void display(){
    int i=1;
    
    for(list<Recipie> :: iterator it = L.begin();it != L.end();it++){
        
        cout << "\nRecipe " << i << " is" << endl;

        cout << "Name : ";
        cout << it->name << endl;
    
        cout << "Ingredients : ";
        for(vector<string> :: iterator it2 = it->ingredient.begin(); it2 != it->ingredient.end();it2++){
            cout << *(it2) << " ";
        }
        cout << endl;

        cout << "Category : ";
        cout << it->category << endl;

        cout << "Instruction : ";
        cout << it->instruction << endl;

        i++;
    }

}

void addRecipie(){
    Recipie temp;
    
    cout << "Enter name" << endl;
    cin >> temp.name;
    
    cout << "Enter ingredients" << endl;
    string ing;
    while(1){
        cout << "press 2 to stop adding ingredients" << endl;
        cin >> ing;
        if(ing == "2"){
            break;
        }
        temp.ingredient.push_back(ing);
    }

    cout << "Enter category" << endl;
    cin >> temp.category;

    cout << "Enter instruction" << endl;
    cin >> temp.instruction;

    L.push_back(temp);
}

void deleteRecipe(string n){
    list<Recipie> :: iterator it = L.begin();
    while(it->name != n ){
       it++;
    }

    L.erase(it);
}

int main(){

//adding recepie
int con=1;
while(con){
    cout << "\nEnter 1 to continue 0 to exit" << endl;
    cin >> con;
    if(con == 0){
        break;
    }
    
    addRecipie();
}
display();

//delteing recipe
int con2;
cout << "\nDo you want to delete recipe? (press 1 for yes and 0 for no)" << endl;
cin >> con2;

if(con2 == 1){
string dname;
cout << "Enter name of recepie you want to delete " << endl;
cin >> dname;
deleteRecipe(dname);
cout << "Recipe deleted" <<endl;
display();
}



return 0;
}