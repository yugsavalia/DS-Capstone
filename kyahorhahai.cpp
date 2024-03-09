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
        : name(n), ingredients(ing), instructions(ins), category(cat), noOfIng(numing){}
};
class RecipeManager{
    public:
    vector<Recipe> list;
    unordered_map <string,Recipe> byName;
    unordered_map <string,vector<Recipe> > byIngredient;

    void addRecipe(Recipe recipe){
        list.push_back(recipe);
        addToByName(recipe);
        addToByIngredient(recipe);
    }

    void addToByName(Recipe pntr){
        std::pair<std::string, Recipe> pairToAdd(pntr.name, pntr);
        byName.insert(pairToAdd);
    }

    void addToByIngredient(Recipe pntr){
    for(int i = 0; i < pntr.noOfIng; i++){
        // Check if the ingredient exists in the map
        auto it = byIngredient.find(pntr.ingredients[i]);
        if(it == byIngredient.end()){
            // If the ingredient doesn't exist, initialize a new vector and insert it into the map
            vector<Recipe> thisIng;
            thisIng.push_back(pntr);
            // Construct the pair and insert it into the map
            std::pair<std::string, vector<Recipe> > pairToAdd(pntr.ingredients[i], thisIng);
            byIngredient.insert(pairToAdd);

        }
        else{
            // If the ingredient exists, push the pointer to the recipe into its associated vector
            byIngredient.at(pntr.ingredients[i]).push_back(pntr);
        }
    }
}


    Recipe searchByName(string nameOfRec){
        return byName.at(nameOfRec);
    }
    
    vector <Recipe> searchByIngredient(string nameOfIng){
        return byIngredient.at(nameOfIng);
    }

    void displayRecipesByIngredients(vector <Recipe> allRecs){

        for(int i=0;i<allRecs.size();i++){
            cout<<allRecs[i].name<<endl;
        }

    }


};

int main() {
    RecipeManager recipeManager;

   // Sample recipes
    vector<string> ingredients1;
    ingredients1.push_back("pasta");
    ingredients1.push_back("tomato sauce");
    ingredients1.push_back("cheese");
    Recipe recipe1("Pasta", ingredients1, "Cook pasta, add sauce, sprinkle cheese, bake", "Italian", 3);

    vector<string> ingredients2;
    ingredients2.push_back("dough");
    ingredients2.push_back("tomato sauce");
    ingredients2.push_back("cheese");
    ingredients2.push_back("toppings");
    Recipe recipe2("Pizza", ingredients2, "Roll out dough, add sauce and toppings, bake", "Italian", 4);

    vector<string> ingredients3;
    ingredients3.push_back("lettuce");
    ingredients3.push_back("tomato");
    ingredients3.push_back("cucumber");
    ingredients3.push_back("olive oil");
    ingredients3.push_back("vinegar");
    Recipe recipe3("Salad", ingredients3, "Chop vegetables, toss with oil and vinegar", "Healthy", 5);

    // Add recipes to RecipeManager
    recipeManager.addRecipe(recipe1);
    recipeManager.addRecipe(recipe2);
    recipeManager.addRecipe(recipe3);

    // Ask user for search method
    char choice;
    do {
        cout << "Do you want to search by (N)ame or by (I)ngredient? (N/I): ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        if (choice == 'N' || choice == 'n') {
            // Search by name
            string name;
            cout << "Enter the name of the recipe: ";
            cin>>name;

            // Perform the search and display the results
            try {
                Recipe foundRecipe = recipeManager.searchByName(name);
                cout << "Recipe found: " << foundRecipe.name << endl;
                // Display additional details if needed
            } catch (const out_of_range& e) {
                cout << "Recipe not found." << endl;
            }
        } else if (choice == 'I' || choice == 'i') {
            // Search by ingredient
            string ingredient;
            cout << "Enter the name of the ingredient: ";
            cin>>ingredient;

            // Perform the search and display the results
            try {
                vector<Recipe> foundRecipes = recipeManager.searchByIngredient(ingredient);
                cout << "Recipes containing " << ingredient << ":" << endl;
                recipeManager.displayRecipesByIngredients(foundRecipes);
            } catch (const out_of_range& e) {
                cout << "No recipes found containing " << ingredient << "." << endl;
            }
        } else {
            cout << "Invalid choice. Please enter 'N' or 'I'." << endl;
        }

        // Ask if the user wants to continue searching
        cout << "Do you want to search again? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');



    return 0;
}
