#include <iostream>
#include <vector>
vector<int> absolutePermutation(int n, int k) {
    vector<int> result;
    bool failed=false;
    for(int i=1;i<=n;i++){
        if(k+i<=n && k+i>0 && (std::find(result.begin(), result.end(), i+k) == result.end()) ){
            result.push_back(k+i);
        }
        else if(i-k<=n && i-k>0 && (std::find(result.begin(), result.end(), i-k) == result.end())){
            result.push_back(i-k);
        }
        else{
            failed=true;
            break;
        }
    }
    
    
    
    if(failed){
        result.clear();
        result.push_back(-1);
    }
    return result;
}