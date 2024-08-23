/* PATTERN : 
1234554321
1234**4321
123****321
12******21
1********1

*/

#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter number of rows"<<endl;
    cin>>n;

    int row=1;
    while(row<=n){
        
        // printing 1st triangle
        int col=1;
        while(col<=n-row+1){
            cout<<col;
            col++;
        }

        // printing stars pt 1
        int star=row-1;
        while(star){
            cout<<'*';
            star--;
        }

        // printing stars pt 2
        star=row-1;
        while(star){
            cout<<'*';
            star--;
        }

        // printing 2nd triangle 
        col=n-row+1;
        while(col){
            cout<<col;
            col--;
        }
        cout<<endl;
        row++;
    }

    return 0;
}