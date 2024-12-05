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

M solve_2(int64_t n){
    M tmp;

    if(n == 1) return tmp;


    M tmp_2 = solve_2(n/2);
    tmp_2 = tmp_2 * tmp_2;

    if(n%2){
        tmp_2 = tmp_2 * tmp;
    }

    return tmp_2;
}

int64_t solve(int64_t n){
    if(n == 0) return 1;
    if(n == 1) return 0;
    if(n == 2) return 1;

    M tmp = solve_2(n-2);
    return (tmp.arr[0][0]+tmp.arr[0][2])%prime;
}

int main(){
    int64_t n;
    FILE *f1, *f2;
    f1 = fopen("num.txt","w");
    f2 = fopen("time.txt","w");
    for(n=0;n<=40000;n += 400){
        //cout << '\n';
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
        fprintf(f1,"%ld\n",n);
        fprintf(f2,"%ld\n",duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()-t);
        cout << "Time Cost(O(N^2)): " << duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()-t << "ms\n";
        cout << "Value: " << dp[n] << "\n\n";
    }
    
    for(n = 0; n <= 40000000; n += 400000){
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
            //if(i % 100000000 == 0) cout << i << " " << dp2[2] << '\n';
        }
        fprintf(f1,"%ld\n",n);
        fprintf(f2,"%ld\n",duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()-t2);
        cout << "Time Cost(O(N)): " << duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()-t2 << "ms\n";
        cout << "Value: " << (dp2[2]+prime)%prime << "\n\n";  
    }
    //fclose(f1);
    //fclose(f2);
    for(n = 0; n <= 40000000; n+= 400000){
        int64_t t3 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        int64_t ans = solve(n);
        fprintf(f1,"%ld\n",n);
        fprintf(f2,"%ld\n",duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()-t3);
        cout << "Time Cost(Mat): " << duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()-t3 << '\n';
        cout << "Value: " << ans << '\n';
    }

    fclose(f1);
    fclose(f2);
}
