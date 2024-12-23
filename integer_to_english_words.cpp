#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string reverseWordsInString(string str) {
    int s=str.size();

    string curr="";
    string sol="";
    vector<string> lst;

    for (int i=0;i<s;i++) {
        if (str[i]==' ') {
            if (curr!="") {
                lst.push_back(curr);
                curr="";
            }
        }
        else {
            curr.push_back(str[i]);
        }
    }

    if (curr!="") {
        lst.push_back(curr);
        curr="";
    }

    s=lst.size();

    for (int i=0;i<s;i++) {
        sol=sol+" "+lst[i];
    }

    return sol.substr(1);
}

string numberToWords(int num) {
    unordered_map<char,string> ones;
    ones['1']="One";
    ones['2']="Two";
    ones['3']="Three";
    ones['4']="Four";
    ones['5']="Five";
    ones['6']="Six";
    ones['7']="Seven";
    ones['8']="Eight";
    ones['9']="Nine";
    unordered_map<char,string> tens;
    tens['1']="Ten";
    tens['2']="Twenty";
    tens['3']="Thirty";
    tens['4']="Forty";
    tens['5']="Fifty";
    tens['6']="Sixty";
    tens['7']="Seventy";
    tens['8']="Eighty";
    tens['9']="Ninety";
    unordered_map<char,string> hundreds;
    hundreds['1']="One Hundred";
    hundreds['2']="Two Hundred";
    hundreds['3']="Three Hundred";
    hundreds['4']="Four Hundred";
    hundreds['5']="Five Hundred";
    hundreds['6']="Six Hundred";
    hundreds['7']="Seven Hundred";
    hundreds['8']="Eight Hundred";
    hundreds['9']="Nine Hundred";

    unordered_map<string,string> teens;
    teens["10"]="Ten";
    teens["11"]="Eleven";
    teens["12"]="Twelve";
    teens["13"]="Thirteen";
    teens["14"]="Fourteen";
    teens["15"]="Fifteen";
    teens["16"]="Sixteen";
    teens["17"]="Seventeen";
    teens["18"]="Eighteen";
    teens["19"]="Ninteen";

    vector<string> places;
    string str=to_string(num);
    int s=str.size();
    int i=s-1;

    while (i>=0) {
        int j=i;
        string curr="";

        while (j>=0&&j>i-3) {
            curr.push_back(str[j]);
            j--;
        }

        places.push_back(curr);
        i=i-3;
    }

    s=places.size();
    vector<string> values;

    for (int i=0;i<s;i++) {
        string value="";

        if (places[i].size()==3&&places[i][2]!='0') {
            value=value+hundreds[places[i][2]]+" ";
        }
        if (places[i].size()>=2&&places[i][1]!='0') {
            if (places[i][1]=='1') {
                value=value+" "+teens[places[i].substr(1)];
                continue;
            }

            value=value+tens[places[i][1]]+" ";
        }
        if (places[i].size()>=1&&places[i][0]!='0') {
            value=value+ones[places[i][0]];
        }

        values.push_back(value);
    }

    s=values.size();
    string sol="";

    if (s==4) {
        sol=sol+values[3]+" "+"Billion ";
    }
    if (s>=3) {
        sol=sol+values[2]+" "+"Million ";
    }
    if (s>=2) {
        sol=sol+values[1]+" "+"Thousand ";
    }
    if (s>=1) {
        sol=sol+values[0];
    }

    s=sol.size();

    if (sol[0]==' ') {
        sol=sol.substr(1);
    }
    if (sol[s-1]==' ') {
        sol=sol.substr(0,s-1);
    }

    return reverseWordsInString(sol);
}