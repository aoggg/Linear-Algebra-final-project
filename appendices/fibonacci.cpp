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

int main(){
    int64_t n;
    cin >> n;
    int64_t a = 1, b = 1, c;
    int64_t t = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    for(int64_t i = 3; i <= n; i ++){
    	c = (a+b)%prime;
    	a = b;
    	b = c;
    }
    cout << duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()-t << '\n';
    cout << c << '\n';
    
}
