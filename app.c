#include <stdio.h>

#define DAYS 2
#define MEALS 2

typedef struct {
    char name[50];
    float price;
} Meal;

int main() {
    Meal meals[] = {
        {"Pasta", 3.5},
        {"Sandwich", 2.0},
        {"Salad", 1.5},
        {"Soup", 2.5},
        {"Rice and Curry", 4.0}
    };
    int mealCount = sizeof(meals) / sizeof(meals[0]);
    
    float weeklyBudget, totalCost = 0;
    int day, mealChoice;
    
    printf("Enter your weekly budget: $");
    scanf("%f", &weeklyBudget);
    
    printf("\nAvailable meals:\n");
    for (int i = 0; i < mealCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, meals[i].name, meals[i].price);
    }
    
    printf("\nPlan your meals (Choose from the list above):\n");
    for (day = 1; day <= DAYS; day++) {
        printf("Day %d:\n", day);
        for (int meal = 1; meal <= MEALS; meal++) {
            printf("  Meal %d (Enter choice number): ", meal);
            scanf("%d", &mealChoice);
            
            if (mealChoice >= 1 && mealChoice <= mealCount) {
                totalCost += meals[mealChoice - 1].price;
            } else {
                printf("Invalid choice! Try again.\n");
                meal--;
            }
        }
    }
    
    printf("\nTotal Cost: $%.2f\n", totalCost);
    if (totalCost <= weeklyBudget) {
        printf("Your meal plan is within budget!\n");
    } else {
        printf("Your meal plan exceeds the budget! Adjust your plan.\n");
    }
    
    return 0;
}
