#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter a decimal number"<<endl;
    cin>>n;
    int num=n,ans=0,i=0;


    if(num>=0){

    // NOTE that the following code will be constrained by the limits of integer data type i.e. 4bytes memory
    // it would have been better to store it as an array or string

        while(n!=0){
        int bit=n&1;    // using concept of bitwise operator // 1&1 = 1  1&0 = 0   
                        // for eg 5 = 101 => 101 & 1   see rightmost bit => 1&1 = 1   then store it in bit  

        ans = (bit * pow(10, i)) +ans;
        n=n>>1;        // right shifting the bits // 101 >>1 => 10 >>1  => 1
        i++;
        }

        cout<<"Binary representation of "<<num<<" is :"<<ans<<endl;
        }
        
        else if(num<0){
            n=abs(n);
            while(n!=0){
            int bit=n&1;
            bit=!bit;  // exchanging bits to find 1's complement
            ans = (bit * pow(10, i)) +ans;
            n=n>>1;
            i++;
            }

            // Now ans contains the 1's complement of the number.
                // To find the 2's complement, add 1 to it.
            int carry = 1;
            i = 0;
            while(carry != 0){
                int bit = (ans / (int)pow(10, i)) % 10; // Extract the i-th bit from ans
                if(bit == carry){
                    ans -= carry * pow(10, i); // If the bit is 1, make it 0 and keep the carry as 1
                    carry=1;
                } else {
                    ans += carry * pow(10, i); // If the bit is 0, make it 1 and set the carry to 0
                    carry = 0;
                }
                i++;
            }
            n=abs(num);
            while(n!=0){
            int bit=n&1;
            ans = (bit * pow(10, i)) +ans;
            n=n>>1;
            i++;
            }
            cout<<"Binary representation of "<<num<<" is :"<<ans<<endl;
            cout<<"\n[Please note that an extra 1 is displayed on the MSB as it denotes the negative sign]\n";
        }
    return 0;
}