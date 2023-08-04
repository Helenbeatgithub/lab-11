#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int minCoins(int coins[], int coin, int target){
    
    //initialize the table for bookkeeping
    int table[target+1];
    table[0] = 0;
    
    for(int i=1; i<=target; i++){
       table[i] = SIZE;
    }
    
    //Fill the table
    for(int i=1; i<=target; i++){
        for(int j=0; j<coin; j++){
            if(coins[j] <=i){
                int sub_res = table[i - coins[j]];
                if(sub_res != SIZE && sub_res + 1 < table[i])
                    table[i] = sub_res + 1;
            }
            
        }
    }
   if(table[target] == SIZE) {
       return -1;
    }
    return table[target];
}




int main()
{
    int n;
    printf("Number of values of coins:");
    scanf("%d",&n);
    
    int coins[n];
    
    printf("Enter the coin values:\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &coins[i]);
    }
    
    int target;
    printf("Enter the amount:\n");
    scanf("%d", &target);
    
    int res = minCoins(coins, n, target);
    printf("The minimum number of coins required is %d.\n", res);

    return 0;

}

