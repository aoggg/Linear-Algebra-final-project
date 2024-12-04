#include <bits/stdc++.h>
#include <sys/time.h>
#include <chrono>
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;
using namespace std;

#define prime 1000000007

struct Num{
    int size = 1005;
    int arr[1005];

    Num(){
        for(int i = 0; i < size; i ++) arr[i] = 0;
    }

    Num(string str){
        for(int i = 0; i < size; i ++) arr[i] = 0;
        for(int i = 0; i < str.length(); i ++){
            arr[i] = str[str.length()-i-1] - '0';
        }
    }

    void tten(){
        for(int i = size-1; i >= 0; i --){
            arr[i] = arr[i-1];
        }
        arr[0] = 0;
    }

    Num dtwo(){
        Num ans;
        int tmp = 0;
        for(int i = size-1; i >= 0; i --){
            tmp = tmp*10 + arr[i];
            ans.tten();
            ans.arr[0] = tmp/2;
            tmp = tmp % 2;
        }
        return ans;
    }

    int ptwo(){
        return arr[0]%2;
    }

    void mtwo(){
        arr[0] -= 2;
        int n = 0;
        while(arr[n] < 0){
            arr[n] += 10;
            arr[n+1] --;
            n ++;
        }
    }

    bool is_two(){
        for(int i = size-1; i > 0; i --){
            if(arr[i] != 0) return false;
        }
        if(arr[0] != 2) return false;
        return true;
    }
    bool is_one(){
        for(int i = size-1; i > 0; i --){
            if(arr[i] != 0) return false;
        }
        if(arr[0] != 1) return false;
        return true;
    }
    bool is_zero(){
        for(int i = size-1; i >= 0; i --){
            if(arr[i] != 0) return false;
        }
        return true;
    }

    void print(){
        bool start = false;
        for(int i = size-1; i >= 0; i --){
            if(start){
                cout << arr[i];
            }
            else{
                if(arr[i] != 0){
                    cout << arr[i];
                    start = true;
                }
            }
        }
    }
};

struct M{
    int64_t arr[3][3];

    M(){
        arr[0][0] = 2;
        arr[0][1] = 0;
        arr[0][2] = 1;
        arr[1][0] = 1;
        arr[1][1] = 0;
        arr[1][2] = 0;
        arr[2][0] = 0;
        arr[2][1] = 1;
        arr[2][2] = 0;
    }


    M operator * (const M &b) const {
        M tmp;
        for(int64_t i = 0; i < 3; i ++){
            for(int64_t j = 0; j < 3; j ++){

                int64_t s = 0;
                for(int64_t k = 0; k < 3; k ++){
                    s += arr[i][k] * b.arr[k][j];
                    s %= prime;
                }
                tmp.arr[i][j] = s;
            }
        }
        return tmp;
    }
};

M solve_2(Num &n){
    M tmp;

    vector<bool> v;

    while(!n.is_one()){
        v.emplace_back(n.ptwo());
        n = n.dtwo();
    }

    M tmp_2;
    for(int i = v.size()-1; i >= 0; i --){
        tmp_2 = tmp_2*tmp_2;
        if(v[i]) tmp_2 = tmp_2*tmp;

    }

    return tmp_2;
}

int64_t solve(Num n){
    if(n.is_zero()) return 1;
    if(n.is_one()) return 0;
    if(n.is_two()) return 1;
    n.mtwo();
    M tmp = solve_2(n);
    return (tmp.arr[0][0]+tmp.arr[0][2])%prime;
}

int main(){
    string str;
    cin >> str;
    Num n(str);
    int64_t t3 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    int64_t ans = solve(n);
    cout << duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()-t3 << '\n';
    cout << ans << '\n';
    
}
