#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Structure to represent a recipe
struct Recipe {

    string name;
    vector<string> ingredients;
    string instructions;
    string category;
    int noOfIng;

    // Constructor to initialize the recipe
    Recipe(string n, vector<string> ing, string ins, string cat,int numing) 
        : name(n), ingredients(ing), instructions(ins), category(cat),noOfIng(numing) {}
};
class RecipeManager{
    public:
    vector<Recipe> list;
    unordered_map <string,Recipe*> byName;
    unordered_map <string,vector<Recipe*> > byIngredient;

    void addRecipe(Recipe& recipe){
        list.push_back(recipe);
    }

    void addToByName(Recipe* pntr){
        byName.insert({pntr->name,pntr});
    }

    void addToByIngredient(Recipe* pntr){
        
        for(int i=0;i<pntr->noOfIng;i++){
            if(byIngredient.find(pntr->ingredients[i])==byIngredient.end()){
                vector <Recipe*> thisIng;
                thisIng.push_back(pntr);
                byIngredient.insert({pntr->ingredients[i],thisIng});

            }
            else{
                byIngredient.at(pntr->ingredients[i]).push_back(pntr);
            }
        }
    }

    Recipe* searchByName(string nameOfRec){
        return byName.at(nameOfRec);
    }
    
    vector <Recipe*> searchByIngredient(string nameOfIng){
        return byIngredient.at(nameOfIng);
    }

    void displayRecipesByIngredients(vector <Recipe*> allRecs){

        for(int i=0;i<allRecs.size();i++){
            cout<<allRecs[i]->name<<endl;
        }

    }

    
};
