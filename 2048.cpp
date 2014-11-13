//2048 :D

#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<conio.h>
#include<cstdio>
#include<cstdlib>
#include <time.h>
#define ARROW_UP 72
#define pb push_back
#define mp make_pair
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
typedef long long ll;
typedef long double ld;
using namespace std;

int board[10][10],n;

 pair<int,int>  getRandomEmptyCell() {
    int i,j,randvalue;
    //vector < pair<int,int> > p;
    vector < pair<int,int> > emptycells;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if( board[i][j] == 0)
                emptycells.pb( mp(i,j));

            if(emptycells.size() == 0){ //board is full
                emptycells.pb( mp(-1,-1));
            }

    randvalue = rand()%emptycells.size();
    return emptycells[randvalue];
}


int main() {
	int  t,tc,i,j,k,k1,k2,arr[100],randrow,randcol;
	int dir;
    char cInput;
     pair<int,int>  p;
	//cin>>t;

	tc=0;
	n =  4;
	 srand (time(NULL)); //Initialize the seed




	while(true) {
		//cin>>n>>dir;

		  p =   getRandomEmptyCell();
    if( p.first == -1 && p.second == -1){
        cout<<"Game Over"<<endl;
        break;
    }
  board[p.first][p.second] = 2; //Adding a new 2 to the board

for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				cout<<board[i][j]<<"\t";
			cout<<endl;
			}


cInput = getch();
cInput = getch();




		if( cInput == ARROW_UP) { //up
            cout<<"Up Arrow Key"<<endl<<endl;
			for(j=0;j<n;j++){    //check column wise
				k=0;

				for(i=0;i<n;i++)
					if( board[i][j]!=0)
						arr[k++]=board[i][j];

					//	cout<<"k is: "<<k<<endl;

				for(k1=0;k1<k-1;k1++){
					if(arr[k1] == 0) continue; //skip if the number is 0.
					if( arr[k1] == arr[k1+1] )
						arr[k1] += arr[k1], arr[k1+1] = 0;
				}
				//	cout<<"k1 is: "<<k1<<endl;


				k2 = 0;
				for(k1=0;k1<k;k1++)
					if( arr[k1] !=0)
						board[k2++][j] = arr[k1];
				for(;k2<n;k2++)
					board[k2][j] = 0;

			}

		}


		else if(cInput == ARROW_DOWN) { //down
         cout<<"Down Arrow Key"<<endl<<endl;
		for(j=0;j<n;j++){    //check column wise
				k=0;

				for(i=0;i<n;i++)
					if( board[i][j]!=0)
						arr[k++]=board[i][j];

					//	cout<<"k is: "<<k<<endl;

				for(k1=k-1;k1>0;k1--){
					if(arr[k1] == 0) continue; //skip if the number is 0.
					if( arr[k1] == arr[k1-1] )
						arr[k1] += arr[k1], arr[k1-1] = 0;
				}
					//cout<<"k1 is: "<<k1<<endl;


				k2 = n-1;
				for(k1=k-1;k1>=0;k1--)
					if( arr[k1] !=0)
						board[k2--][j] = arr[k1];

				//cout<<"k2 is: "<<k2<<endl;


				for(;k2>=0;k2--)
					board[k2][j] = 0;

			}
		}


		else if(cInput == ARROW_LEFT){ //left
		     cout<<"Left Arrow Key"<<endl<<endl;
			for(i=0;i<n;i++){

				k = 0;
				for(j=0;j<n;j++)
					if( board[i][j]!=0)
						arr[k++]=board[i][j];

				for(k1=0;k1<k;k1++){
					if(arr[k1] == 0) continue; //skip if the number is 0.
						if( arr[k1] == arr[k1+1] )
							arr[k1] += arr[k1], arr[k1+1] = 0;
					}

			k2 = 0;
				for(k1=0;k1<k;k1++)
					if( arr[k1] !=0)
						board[i][k2++] = arr[k1];
				for(;k2<n;k2++)
					board[i][k2] = 0;

			}// for:i


		}
		else if(cInput == ARROW_RIGHT){ //right
                 cout<<"Right Arrow Key"<<endl<<endl;

		for(i=0;i<n;i++){

				k = 0;
				for(j=0;j<n;j++)
					if( board[i][j]!=0)
						arr[k++]=board[i][j];

				for(k1=k-1;k1>0;k1--){
					if(arr[k1] == 0) continue; //skip if the number is 0.
						if( arr[k1] == arr[k1-1] )
							arr[k1] += arr[k1], arr[k1-1] = 0;
					}

			k2 = n-1;
				for(k1=k-1;k1>=0;k1--)
					if( arr[k1] !=0)
						board[i][k2--] = arr[k1];
				for(;k2>=0;k2--)
					board[i][k2] = 0;


		}



	}//right


	}//t




	return 0;
} //main
