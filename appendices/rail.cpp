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
    int64_t dp[n+1];
    dp[0] = 1;
    dp[1] = 0;
    int64_t t = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    for(int i = 2; i <= n; i ++){
        dp[i] = 0;
        for(int j = 0; j <= i-2; j ++){
            dp[i] += (2*(i-j)-3)*dp[j];
            dp[i] %= prime;
        }
    }
    cout << duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()-t << '\n';
    cout << dp[n] << "\n\n";

    int64_t dp2[3], a[3], b[3];
    dp2[0] = 1;
    dp2[1] = 0;
    a[0] = 1;
    a[1] = 1;
    b[0] = 0;
    b[1] = 0;
    int64_t t2 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    for(int64_t i = 2; i <= n; i ++){
        dp2[2] = ((( (2*i-3)%prime * a[0] - 2*b[0] % prime ) % prime)+prime)%prime;
        a[2] = ((a[1] + dp2[2]) % prime + prime) % prime;
        b[2] = ((b[1] + i*dp2[2] % prime) % prime + prime) % prime;
        dp2[0] = dp2[1];
        dp2[1] = dp2[2];
        a[0] = a[1];
        a[1] = a[2];
        b[0] = b[1];
        b[1] = b[2];
    }
    cout << duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()-t2 << '\n';
    cout << (dp2[2]+prime)%prime << "\n\n";
    
}
