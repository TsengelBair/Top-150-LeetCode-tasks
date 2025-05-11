#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;

vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    vector<string> res;
    /// книга рецептов
    unordered_map<string, vector<string>> recipeBook;
    for (int i = 0; i < recipes.size(); ++i) {
        recipeBook[recipes[i]] = ingredients[i];
    }

    /// всевозможные ингридиенты - те что есть изначально и те, которые приготовим
    unordered_set<string> allPossibleSupplies;
    for (int i = 0 ; i < supplies.size(); ++i) {
        allPossibleSupplies.insert(supplies[i]);
    }

    /// если нашли новый рецепт (блюдо) в allPossibleSupplies, значит нужно перепроверить, можем ли еще приготовить что то
    /// т.к. вставленный рецепт (блюдо) может быть ингридиентом другого рецепта (блюда)
    bool newDishFound = true;
    while (newDishFound) {
        newDishFound = false;

        for (const auto& recipe : recipeBook) {
            const string& _recipe = recipe.first;
            const vector<string>& neededSupplies = recipe.second;

            /// проверяем можем ли приготовить блюдо из книги рецептов
            bool canCook = true;
            for (int i = 0; i < neededSupplies.size(); ++i) {
                if (allPossibleSupplies.find(neededSupplies[i]) == allPossibleSupplies.end()) {
                    canCook = false;
                }
            }

            /// проверяем не был ли ранее добавлен рецепт, чтобы не зациклиться
            if (canCook && allPossibleSupplies.find(_recipe) == allPossibleSupplies.end()) {
                res.push_back(_recipe);
                allPossibleSupplies.insert(_recipe);
                newDishFound = true;
            }
        }
    }

    return res;
}


int main(int argc, char *argv[])
{
    vector<string> recipes = {"bread", "sandwich", "burger"};
    vector<vector<string>> ingredients = {{"yeast", "flour"},{"bread", "meat"},{"sandwich", "meat", "bread"}};
    vector<string> supplies = {"yeast", "flour", "meat"};

    vector<string> res = findAllRecipes(recipes, ingredients, supplies);
    for (const string& elem : res) {
        std::cout << elem << " ";
    }

    std::cout << std::endl;
    return 0;
}
