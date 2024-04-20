#include <iostream>
#include <string>

using namespace std;

int rabin_karp(string text, string pattern, int prime) {
    int text_length = text.length();
    int pattern_length = pattern.length();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < pattern_length - 1; i++)
        h = (h * 256) % prime;

    for (i = 0; i < pattern_length; i++) {
        p = (256 * p + pattern[i]) % prime;
        t = (256 * t + text[i]) % prime;
    }

    for (i = 0; i <= text_length - pattern_length; i++) {
        if (p == t) {
            for (j = 0; j < pattern_length; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == pattern_length)
                return i;
        }

        if (i < text_length - pattern_length) {
            t = (256 * (t - text[i] * h) + text[i + pattern_length]) % prime;

            if (t < 0)
                t += prime;
        }
    }

    return -1;
}

int main() {
    string text = "abcdefghijkhrt";
    string pattern = "hrt";
    int prime = 101;

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    int index = rabin_karp(text, pattern, prime);

    if (index != -1)
        cout << "Pattern found at index: " << index << endl;
    else
        cout << "Pattern not found" << endl;

    return 0;
}
