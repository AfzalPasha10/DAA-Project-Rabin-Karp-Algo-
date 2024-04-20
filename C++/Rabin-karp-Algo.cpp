#include <bits/stdc++.h>
#include <string>

using namespace std;

#define d 256
#define q 101

int rabin_karp(string txt, string pat) {
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j])
                    break;
            }

            if (j == M)
                return i;
        }

        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            if (t < 0)
                t = (t + q);
        }
    }

    return -1;
}

int main() {
    string txt, pat;

    cout << "Enter the text: ";
    getline(cin, txt);

    cout << "Enter the pattern: ";
    getline(cin, pat);

    int index = rabin_karp(txt, pat);

    if (index != -1)
        cout << "Pattern found at index " << index + 1 << endl;
    else
        cout << "Pattern not found" << endl;

    return 0;
}
