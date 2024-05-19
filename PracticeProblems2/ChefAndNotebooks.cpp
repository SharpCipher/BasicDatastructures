/*
Chef likes to write poetry. Today, he has decided to write a X pages long poetry, 
but unfortunately his notebook has only Y pages left in it. Thus he decided to buy a new CHEFMATE notebook 
and went to the stationary shop. Shopkeeper showed him some N notebooks, where the number of pages and 
price of the ith one are Pi pages and Ci rubles respectively. Chef has spent some money preparing for Ksen's birthday, 
and then he has only K rubles left for now.Chef wants to buy a single notebook such that the price of the notebook 
should not exceed his budget and he is able to complete his poetry.

Help Chef accomplishing this task. You just need to tell him whether he can buy such a notebook or not. 
Note that Chef can use all of the Y pages in the current notebook, and Chef can buy only one notebook because 
Chef doesn't want to use many notebooks.

Input
3
3 1 2 2
3 4
2 2    
3 1 2 2
2 3
2 3    
3 1 2 2
1 1
1 2

Output
LuckyChef
UnluckyChef
UnluckyChef

Explanation

Example case 1. In this case, Chef wants to write X = 3 pages long poetry, but his notebook has only Y = 1 page. 
And his budget is K = 2 rubles, and there are N = 2 notebooks in the shop. The first notebook has P1 = 3 pages, 
but Chef cannot buy it, because its price is C1 = 4 rubles. The second notebook has P2 = 2 pages, 
and its price is C2 = 2 rubles. Thus Chef can select the second notebook to accomplish the task. 
He will write 1 page of poetry in the old notebook, and 2 page of poetry in the new notebook.

Example case 2. Chef cannot buy any notebook, because the prices exceed the Chef's budget.

Example case 3. No notebook contains sufficient number of pages required to write poetry.

@Codechef
*/
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int x,y,k,n;
	    cin>>x>>y>>k>>n;
	    int t = x-y;
	    int flag = 0;
	    int arr[n][2];
	    for(int i=0; i<n; i++){
	        for(int j=0; j<2; j++){
	            cin>>arr[i][j];
	        }
	    }
	    for(int i=0; i<n; i++){
	        if(arr[i][0] >= t && arr[i][1] <= k){
	            flag = 1;
	            cout<<"LuckyChef"<<endl;
	            break;
	        }
	    }
	    if(flag == 0)
	        cout<<"UnluckyChef"<<endl;
	}
	return 0;
}
