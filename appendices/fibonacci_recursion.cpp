#include <iostream>
#include <sys/time.h>
#include <chrono>
#include <ctime>
#include <time.h>
using namespace std;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

const int MOD = 1e9 + 7;

int64_t cal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return (cal(n - 1) + cal(n - 2)) % MOD;
}

int main() {
    int n;
    cin >> n;
    int64_t ans = 0;
    int64_t t = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    ans = cal(n);
    cout << "cost time: " << duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - t << '\n';
    cout << "ans: " << ans << '\n';
    return 0;
}