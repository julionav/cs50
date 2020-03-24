#include <cs50.h>
#include <stdio.h>
#include <math.h>

int calculate_coins(int change, int coin_count) {
    if (change == 0) {
        return coin_count;
    }
    
    int new_change;
    if (change >= 25) {
        new_change = change - 25;
    } else if (change >= 10) {
        new_change = change - 10;
    } else if (change >= 5) {
        new_change = change - 5;
    } else {
        new_change = change - 1;
    }
    return calculate_coins(new_change, coin_count + 1);
}

float get_positive_float(string message)
{
    float val;
    do {
        val = get_float("%s", message);
    } while (val < 0);
    return val;
}

int main(void)
{
    float change = get_positive_float("Change owed: ");
    int change_int = round(change * 100);
    int coins = calculate_coins(change_int, 0);
    printf("%i\n", coins);
}
