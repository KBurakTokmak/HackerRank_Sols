/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
vector<int> absolutePermutation(int n, int k) {
    vector<int> result(n,0);
    
    for(int i=1;i<=n;i++){
        if(i-k>0 && result[i-k-1]==0){
            result[i-k-1]=i;
        }
        else if(i+k<n && result[i+k-1]==0){
            result[i+k-1]=i;
        }
        else{
            vector<int> failed_result;
            failed_result.push_back(-1);
            //cout<<"failed at "<<i<<endl;
            return failed_result;
            
        }
    }
    
    for(int i=0;i<result.size();i++){
        if(abs(result[i]-(i+1))!=k || result[i]==0 ){
            vector<int> failed_result;
            failed_result.push_back(-1);
            //cout<<"failed at "<<i<<endl;
            return failed_result;
            
        }
    }
    
    
    return result;
}

int main(){
    vector<int> result=absolutePermutation(30 ,10);
    for(auto i:result){
        cout<<i<<" ";
    }
    return 0;
}