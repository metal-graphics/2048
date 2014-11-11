//2048 :D

#include<iostream>
#include<algorithm>
#include<stack>
#include<cmath>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() { 
	int board[100][100] , t,tc,i,j,k,k1,k2,arr[100],n;
	string dir;
	
	cin>>t;
	
	tc=0;
	
	while(t--) {
		cin>>n>>dir;
		
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin>>board[i][j];
				
		if( dir[0] == 'u') { //up
			
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
		
		
		else if(dir[0] == 'd') { //down
		
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
		
		
		else if(dir[0] == 'l'){ //left
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
		else { //right
		
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
	
	cout<<"Case #"<<++tc<<":"<<endl;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				cout<<board[i][j]<<" ";
			cout<<endl;
			}
	
	
	}//t




	return 0;
} //main