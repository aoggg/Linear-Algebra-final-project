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
    FILE *f1, *f2;
    f1 = fopen("num.txt","w");
    f2 = fopen("time.txt","w");
    for(n=0;n<=40000;n += 400){
        int64_t a = 1, b = 1, c;
        fprintf(f1,"%ld\n",n);
        int64_t t = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        for(int64_t i = 3; i <= n; i ++){
            c = (a+b)%prime;
            a = b;
            b = c;
        }
        fprintf(f2,"%ld\n",duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()-t);
        cout << "Time Cost: " << duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()-t << "ms\n";
        cout << "Value: " << c << '\n';
    }
    fclose(f1);
    fclose(f2);
}
