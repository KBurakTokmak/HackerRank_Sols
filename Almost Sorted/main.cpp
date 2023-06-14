#include <vector>
#include <iostream>
using namespace std;
/*
 * Complete the 'almostSorted' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void print_vector(vector<int> arr){
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
void almostSorted(vector<int> arr) {
    int temp;
    bool failed=false;
    if(is_sorted(arr.begin(),arr.end())){//check if already sorted
        cout<<"yes";
        return;
    }
    else{
        for(int i=0;i<arr.size();i++){
            if(arr[i]>arr[i+1]){
                for(int y=i+1;y<arr.size();y++){
                    if(arr[i]<arr[y]||y==arr.size()-1){
                        if(y==arr.size()-1) y++;//adjust pointer if last element
                        cout<<"array anamoly between "<<i<<" and "<<y-1<<endl;
                        temp=arr[i];
                        arr[i]=arr[y-1];
                        arr[y-1]=temp;
                        cout<<"array after swapping : ";
                        print_vector(arr);
                        if(is_sorted(arr.begin(),arr.end())){
                            cout<<"yes"<<endl;
                            cout<<"swap "<<i+1<<" "<<y;                     
                            return;
                        }
                        else{// remove back swap
                            temp=arr[i];
                            arr[i]=arr[y-1];
                            arr[y-1]=temp;
                        }
                        //now check reverse part
                        //cout<<"vector before checking for reverse: ";
                        //print_vector(arr);
                        int k=i;
                        if(arr.size()==y) y--;
                        int l=y-1;
                        while(k<l){//reverse
                            temp=arr[k];
                            arr[k]=arr[l];
                            arr[l]=temp;
                            k++;
                            l--;
                        }
                        //cout<<"vector after reverse:"<<endl;
                        //print_vector(arr);
                        if(is_sorted(arr.begin(),arr.end())){
                            cout<<"yes"<<endl;
                            cout<<"reverse "<<i+1<<" "<< y;
                            return;
                        }
                        else{
                            //
                        }
                    failed=true;
                    break; 
                    }
                }   
            }
            if(failed) break;
        }
        cout<<"no";
        return;
    }
}

int main(){
    vector<int> arr{ 1, 2, 3, 4, 5, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 18, 19, 20 };
    
    vector<int> arr2{ 1, 2, 3, 5, 4, 6 };
    almostSorted(arr);
    cout<<endl;
    almostSorted(arr2);
    return 0;
}
