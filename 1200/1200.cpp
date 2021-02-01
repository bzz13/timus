#include <cmath>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;


double f(double x, double y, double A, double B) {
    return x*A + y*B - x*x - y*y;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    double A, B, K;
    cin >> A >> B >> K;
    cout << setprecision(2) << fixed;

    double result = 0;
    long xAnsw = 0, yAnsw = 0;

    if (A < 0 && B < 0) {
        cout << result << endl << xAnsw << " " << yAnsw;
        return 0;
    } else if (A < 0) {
        double yOpt = B/2.0;

        if (yOpt > K) {
            yOpt = std::min(yOpt, K);
        }
        long yOptL = std::max(trunc(yOpt), 0.0);

        for (long yd = -2; yd < 3; yd++) {
            if (yOptL + yd < 0) {
                continue;
            }
            if (yOptL + yd <= K) {
                double tmp = f(0, yOptL + yd, A, B);
                if (result < tmp) {
                    result = tmp;
                    yAnsw = yOptL + yd;
                }
            }
        }
        cout << result << endl << xAnsw << " " << yAnsw;

        return 0;
    } else if (B < 0) {
        double xOpt = A/2.0;

        if (xOpt > K) {
            xOpt = std::min(xOpt, K);
        }
        long xOptL = std::max(trunc(xOpt), 0.0);

        for (long xd = -2; xd < 3; xd++) {
            if (xOptL + xd < 0) {
                continue;
            }
            if (xOptL + xd <= K) {
                double tmp = f(xOptL + xd, 0, A, B);
                if (result < tmp) {
                    result = tmp;
                    xAnsw = xOptL + xd;
                }
            }
        }
        cout << result << endl << xAnsw << " " << yAnsw;
        return 0;
    } else {
        double xOpt = A/2.0;
        double yOpt = B/2.0;

        if (xOpt + yOpt >= K) {
            xOpt = K/2.0 - (B - A)/4.0;
            yOpt = K/2.0 + (B - A)/4.0;
        }

        long xOptL = std::max(trunc(xOpt), 0.0);
        long yOptL = std::max(trunc(yOpt), 0.0);

        for (long xd = -2; xd < 3; xd++) {
            for (long yd = -2; yd < 3; yd++) {
                if (xOptL + xd < 0) {
                    continue;
                }
                if (yOptL + yd < 0) {
                    continue;
                }
                if (xOptL + xd + yOptL + yd <= K) {
                    double tmp = f(xOptL + xd, yOptL + yd, A, B);
                    if (result < tmp) {
                        result = tmp;
                        xAnsw = xOptL + xd;
                        yAnsw = yOptL + yd;
                    }
                }
            }
        }
        cout << result << endl << xAnsw << " " << yAnsw;
    }

    return 0;
}
