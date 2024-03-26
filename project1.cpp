#include <bits/stdc++.h>
using namespace std;

struct Recipe{
    string name;
    vector<string> ingredient;
    string category;
    string instruction;
};

class RecipeManager{
public:
    list<Recipe> L;
    unordered_map <string,Recipe> byName;
    unordered_map <string,vector<Recipe>> byIngredient;

public:
    void displayAllRecipe(){
        int i=1;
    
        if(L.empty()){
            cout << "\nNo reciepes in the record " << endl;
            return;
        }
    
        for(list<Recipe> :: iterator it = L.begin();it != L.end();it++){
            
            cout << "\nRecipe " << i << " is" << endl;

            cout << "Name : ";
            cout << it->name << endl;
    
            cout << "Ingredients : ";
            for(vector<string> :: iterator it2 = it->ingredient.begin(); it2 != it->ingredient.end();it2++){
                cout << *(it2) << " ";
            }

            cout << "Instruction : ";
            cout << it->instruction << endl;

            i++;
        }

    }

    void displayRecipeList(vector<Recipe> Rlist){
        cout << "Recipes found are" << endl;
        for(int i=0;i<Rlist.size();i++){
            cout<<Rlist[i].name<<endl;
        }
    }
    
    void diplay1Recipe(Recipe R){
        cout << "Name : ";
        cout << R.name << endl;

        cout << "Ingredients : ";
        for(vector<string> :: iterator it2 = R.ingredient.begin(); it2 != R.ingredient.end();it2++){
            cout << *(it2) << " ";
        }
        cout << endl;

        cout << "Category : ";
        cout << R.category << endl;

        cout << "Instruction : ";
        cout << R.instruction << endl;
    }
    
    void addRecipie(){
        Recipe temp;
    
        cout << "\nEnter name" << endl;
        cin >> temp.name;

        string ing;
        while(1){
            cout << "Enter ingredients(Press 1 to stop adding ingredients)" << endl;
            cin >> ing;
            if(ing == "1"){
                break;
            }
            temp.ingredient.push_back(ing);
        }

        cout << "Enter category" << endl;
        cin >> temp.category;

        cout << "Enter instruction" << endl;
        cin >> temp.instruction;

        L.push_back(temp);
        addToByName(temp);
        addToByIngredient(temp);
    }

    void deleteRecipe(){
        string n;
        cout << "\nEnter name of reciepe you want to delete " << endl;
        cin >> n;
        list<Recipe> :: iterator it = L.begin();
        while(it->name != n ){
           it++;
        }

        L.erase(it);
    }

    void addToByName(Recipe pntr){
        pair<string, Recipe> pairToAdd(pntr.name, pntr);
        byName.insert(pairToAdd);
    }

    void addToByIngredient(Recipe pntr){
    for(int i = 0; i < pntr.ingredient.size(); i++){
        // Check if the ingredient exists in the map
        auto it = byIngredient.find(pntr.ingredient[i]);
        if(it == byIngredient.end()){
            // If the ingredient doesn't exist, initialize a new vector and insert it into the map
            vector<Recipe> thisIng;
            thisIng.push_back(pntr);
            // Construct the pair and insert it into the map
            std::pair<std::string, vector<Recipe> > pairToAdd(pntr.ingredient[i], thisIng);
            byIngredient.insert(pairToAdd);

        }
        else{
            // If the ingredient exists, push the pointer to the recipe into its associated vector
            byIngredient.at(pntr.ingredient[i]).push_back(pntr);
        }
    }
}

    Recipe searchByName(){
        string nameOfRec;
        cout << "\nEnter Recipe Name you want to search for " << endl;
        cin >> nameOfRec;

        return byName.at(nameOfRec);
    }

    vector<Recipe> searchByIngredient(){
        string nameOfIng;
        cout << "\nEnter Name of Ingredient by which you want to search recipe by" << endl;
        cin >> nameOfIng;
        return byIngredient.at(nameOfIng);
    }

};

int main(){

RecipeManager M;
int con=1;

while(con != 0){
    cout << "\nPress the following keys for the given functions " << endl;
    cout << "1 for adding receipe " << endl;
    cout << "2 for viewing all current recepies " << endl;
    cout << "3 for deleting recepie " << endl;
    cout << "4 for searching by name " << endl;
    cout << "5 for searching by ingredient " << endl;
    cout << "0 for exit " << endl;

    cin >> con;

    switch(con){
        case 1:
            M.addRecipie();
            break;
        case 2:
            M.displayAllRecipe();
            break;
        case 3:
            M.deleteRecipe();
            break;
        case 4:{
            Recipe temp;
            temp = M.searchByName();
            M.diplay1Recipe(temp);
            break;
        }
        case 5:{
            vector<Recipe> t;
            t = M.searchByIngredient();
            M.displayRecipeList(t);
            break;
        }
        case 0:
            break;
        default:
            break;
    }
}

return 0;
}