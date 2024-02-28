#include <stdio.h>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int num[100];
char in[100], f[400];
map <char, string> morse;
map <string, char> remorse;

void initmap() {
    morse['A'] = ".-";
    morse['B'] = "-...";
    morse['C'] = "-.-.";
    morse['D'] = "-..";
    morse['E'] = ".";
    morse['F'] = "..-.";
    morse['G'] = "--.";
    morse['H'] = "....";
    morse['I'] = "..";
    morse['J'] = ".---";
    morse['K'] = "-.-";
    morse['L'] = ".-..";
    morse['M'] = "--";
    morse['N'] = "-.";
    morse['O'] = "---";
    morse['P'] = ".--.";
    morse['Q'] = "--.-";
    morse['R'] = ".-.";
    morse['S'] = "...";
    morse['T'] = "-";
    morse['U'] = "..-";
    morse['V'] = "...-";
    morse['W'] = ".--";
    morse['X'] = "-..-";
    morse['Y'] = "-.--";
    morse['Z'] = "--..";
    morse['_'] = "..--";
    morse['.'] = "---.";
    morse[','] = ".-.-";
    morse['?'] = "----";

    remorse[".-"] = 'A';
    remorse["-..."] = 'B';
    remorse["-.-."] = 'C';
    remorse["-.."] = 'D';
    remorse["."] = 'E';
    remorse["..-."] = 'F';
    remorse["--."] = 'G';
    remorse["...."] = 'H';
    remorse[".."] = 'I';
    remorse[".---"] = 'J';
    remorse["-.-"] = 'K';
    remorse[".-.."] = 'L';
    remorse["--"] = 'M';
    remorse["-."] = 'N';
    remorse["---"] = 'O';
    remorse[".--."] = 'P';
    remorse["--.-"] = 'Q';
    remorse[".-."] = 'R';
    remorse["..."] = 'S';
    remorse["-"] = 'T';
    remorse["..-"] = 'U';
    remorse["...-"] = 'V';
    remorse[".--"] = 'W';
    remorse["-..-"] = 'X';
    remorse["-.--"] = 'Y';
    remorse["--.."] = 'Z';
    remorse["..--"] = '_';
    remorse["---."] = '.';
    remorse[".-.-"] = ',';
    remorse["----"] = '?';
}

void solve() {
    int t = 0, d = 0;
    string a = "";
    for (int i=0; i<strlen(in); ++i) {
        for (int j=t; j<t+morse[in[i]].length(); ++j) f[j] = morse[in[i]][j-t]; 
        t += morse[in[i]].length();
        num[i] = morse[in[i]].length();
    }
    for (int i=0; i<strlen(in); ++i) {
        a = "";
        for (int j=d; j<d+num[strlen(in)-i-1]; ++j) a += f[j];
        d += num[strlen(in)-i-1];
        printf("%c", remorse[a]);            
    }
    printf("\n"); 
}

int main() {
    int n;
    scanf("%d", &n);
    initmap();
    for (int i=0; i<5; ++i) {
        scanf("%s", in);
        printf("%d: ", i+1);
        solve();     
    }
}



