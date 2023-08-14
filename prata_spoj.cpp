#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSolution(vector<int>cookRank, int nP, int mid){
    int countPratha = 0;
    for(int i=0; i<cookRank.size(); i++){
        int R = cookRank[i], j=1;
        int timeTaken = 0;
        while (true)
        {
            if(timeTaken +j * R <=mid){
                ++countPratha;
                timeTaken += j*R;
                ++j;
            }
            else{
                break;
            }
        }
        if(countPratha>=nP){
            return true;
        }
        
    }
    return false;
}

int minTimeToCompleteOrder(vector<int>cookRank, int nP){
    int start = 0;
    int highestRank = *max_element(cookRank.begin(), cookRank.end());
    int end = highestRank * (nP*(nP+1)/2);
    int ans = -1;
    while(start<=end){
        int mid = start +(end-start)/2;
        if(isPossibleSolution(cookRank, nP, mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    int T; // Test Case
    cin >> T;
    while(T--){
        // nP -> No. of pratha && nC-> no. of cook
        int nP , nC;
        cin >> nP >> nC;
        vector <int> cookRank;
        while(nC--){
            int R;
            cin >> R;
            cookRank.push_back(R);
        }
        cout << minTimeToCompleteOrder(cookRank, nP) << endl;
    }
    return 0;
}