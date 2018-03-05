/* 
 * Design a C++ sructure to store a diary product name, portion weight, calories, protein, fat, and carbohydrates,
 *
 * 25 grams of American cheese have:
 * 375 Calories
 * 5 grams of protein
 * 8 grams of fat
 * 0 carbohydrates
 *
 * show how to assign these values to the member variables of your structure.
 * Write a function that given a variable of type struct dairy and a weight in grams (protion size) returns the number of calories for that weight.
 */

#include <iostream>
#include <string>
using namespace std;

struct dairy
{
  char name[60];
  int weight;
  int calories;
  int protein;
  int fat;
  int carbs;
  //void init(char iName[], int iWeight, int iCalories, int iProtein, int iFat, int iCarbs) { strcpy(name, iName); weight = iWeight; calories = iCalories; protein = iProtein; fat = iFat; carbs = iCarbs;};
};

double getWeight(dairy cheese, int weight) {
  double weight1 = weight;
  double cheeseWeight = cheese.weight;
  double weightProtion = weight1 / cheeseWeight;
  return cheese.calories * weightProtion;

}

int main()
{
  dairy american;
  char cheeseName[60] = "American";
  
  strcpy(american.name, cheeseName);
  american.weight = 25;
  american.calories = 375;
  american.protein = 5;
  american.fat = 8;
  american.carbs = 0;

  //american.init( cheeseName, 25, 375, 5, 8, 0);

  int tenGrams =  getWeight(american, 10);

  cout << tenGrams << endl;


  return 0;
}
