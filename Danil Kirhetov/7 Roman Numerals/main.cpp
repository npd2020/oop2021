#include <iostream>
#include <string>
#include <map>

using namespace std;

int rom2arab(string a) {
    int res;
    map <char, int> rmn;
    rmn['M'] = 1000;
    rmn['D'] = 500;
    rmn['C'] = 100;
    rmn['L'] = 50;
    rmn['X'] = 10;
    rmn['V'] = 5;
    rmn['I'] = 1;
    for (int i = 0; i < a.size(); i++){
        if(rmn[a[i]] < rmn[a[i+1]]){res -= rmn[a[i]];}
        else{res += rmn[a[i]];}
    }
    return res;
}

string a2r(int num){
    string rtrn;
    for(int i = 1000; i > 9; i /= 10){
        int now = num / i;
        num -= now * i;
        switch(i){
            case 10:
                switch (now){
                    case 4:
                        rtrn.append("XL");
                        break;
                    case 5:
                        rtrn.append("L");
                        break;
                    case 6:
                    case 7:
                    case 8:
                        rtrn.append("L");
                        now -= 5;
                    case 1:
                    case 2:
                    case 3:
                        for (int j = 0; j < now; j++){rtrn.append("X");}
                        break;
                    case 9:
                        rtrn.append("XC");
                        break;
                }
                break;

            case 100:
                switch (now){
                    case 4:
                        rtrn.append("CD");
                        break;
                    case 5:
                        rtrn.append("D");
                        break;
                    case 6:
                    case 7:
                    case 8:
                        rtrn.append("D");
                        now -= 5;
                    case 1:
                    case 2:
                    case 3:
                        for (int j = 0; j < now; j++){rtrn.append("C");}
                        break;
                    case 9:
                        rtrn.append("CM");
                        break;
                }
                break;

            case 1000:
                for( int j = 0; j < now; j++){rtrn.append("M");}
                break;

        }
    }
    switch (num){
        case 4:
            rtrn.append("IV");
            break;
        case 5:
            rtrn.append("V");
            break;
        case 6:
        case 7:
        case 8:
            rtrn.append("V");
            num -= 5;
        case 1:
        case 2:
        case 3:
            for (int j = 0; j < num; j++){rtrn.append("I");}
            break;
        case 9:
            rtrn.append("IX");
            break;
    }
    return rtrn;
}

int main() {
    int un, deux, sum;
    string input;
    cin >> input;
    string frst = input.substr(0, input.find("+"));
    string scnd = input.substr(input.find("+")+1);

    un = rom2arab(frst);
    deux = rom2arab(scnd);
    sum = un + deux;
    cout << a2r(sum);

    return 0;
}