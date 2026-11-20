#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

int W;
int L[4];

// lugar del casillero (i, w, c0, c1, c2, c3) dentro del arreglo
int pos(int i, int w, int c0, int c1, int c2, int c3) {
    return ((((i * (W + 1) + w) * (L[0] + 1) + c0) * (L[1] + 1) + c1) * (L[2] + 1) + c2) * (L[3] + 1) + c3;
}

// dp[i][w][c0][c1][c2][c3]: mejor satisfaccion usando los primeros i productos,
// con w kilos y a lo sumo c0 achuras, c1 cortes, c2 bebidas y c3 vegetales
int resolver(int N, int* peso, int* sat, int* cat) {
    int total = (N + 1) * (W + 1) * (L[0] + 1) * (L[1] + 1) * (L[2] + 1) * (L[3] + 1);
    int* dp = new int[total]();   // todo en 0, la fila 0 ya queda lista

    for (int i = 1; i <= N; i++) {
        int p = peso[i - 1];
        int s = sat[i - 1];
        int k = cat[i - 1];

        for (int w = 0; w <= W; w++)
        for (int c0 = 0; c0 <= L[0]; c0++)
        for (int c1 = 0; c1 <= L[1]; c1++)
        for (int c2 = 0; c2 <= L[2]; c2++)
        for (int c3 = 0; c3 <= L[3]; c3++) {
            int c[4] = {c0, c1, c2, c3};

            // no me meto
            int mejor = dp[pos(i - 1, w, c0, c1, c2, c3)];

            // me meto
            if (p <= w && c[k] >= 1) {
                int resto[4] = {c0, c1, c2, c3};
                resto[k]--;
                int valor = s + dp[pos(i - 1, w - p, resto[0], resto[1], resto[2], resto[3])];
                if (valor > mejor) mejor = valor;
            }

            dp[pos(i, w, c0, c1, c2, c3)] = mejor;
        }
    }

    int res = dp[pos(N, W, L[0], L[1], L[2], L[3])];
    delete[] dp;
    return res;
}

int main() {
    int N;
    cin >> N >> W;
    for (int k = 0; k < 4; k++) cin >> L[k];

    int* peso = new int[N];
    int* sat = new int[N];
    int* cat = new int[N];
    for (int i = 0; i < N; i++) cin >> peso[i] >> sat[i] >> cat[i];

    cout << resolver(N, peso, sat, cat) << endl;

    delete[] peso;
    delete[] sat;
    delete[] cat;
    return 0;
}