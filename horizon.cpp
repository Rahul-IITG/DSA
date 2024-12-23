#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;



int main() {
    unordered_map<string,unordered_map<string,string>> umap;
    unordered_map<string,vector<string>> instance;
    vector<string> dataset={
        "INSERT INTO \"MDI\".\"MDIPROD\" (API_NAME, API_RESPONSE, MDI_RESOURCE, INSTANCE, RECORD_DATE, SSDI$CREATED_DATE, SSDI$CREATED_BY) VALUES ('Create Dataset', 'Success', 'Dataset', ",
        ", TO_DATE('2024-12-",
        " 17:03:06', 'YYYY-MM-DD HH24:MI:SS'), TO_TIMESTAMP('2024-12-",
        " 17:03:13.803268000', 'YYYY-MM-DD HH24:MI:SS.FF'), 'DWADMIN');"
    };
    vector<string> dsat={
        "INSERT INTO \"MDI\".\"MDIPROD\" (ACTION_TYPE, API_NAME, API_RESPONSE, MDI_RESOURCE, INSTANCE, RECORD_DATE, SSDI$CREATED_DATE, SSDI$CREATED_BY) VALUES ('",
        "', 'Create Dataset Action Task', 'Success', 'Dataset Action Task', '",
        "', TO_DATE('2024-11-",
        "15:56:35', 'YYYY-MM-DD HH24:MI:SS'), TO_TIMESTAMP('2024-11-",
        " 15:56:42.700753000', 'YYYY-MM-DD HH24:MI:SS.FF'), 'DWADMIN');"
    };

    vector<vector<string>> script={{"3","COLLECT", "evalserviceinstance", "09"}, {"11", "MIGRATE", "cdaadi", "10"}};

    for (int i=0;i<script.size();i++) {
        int t=stoi(script[i][0]);
        string action=script[i][1];
        string instance=script[i][2];
        string day=script[i][3];

        for (int j=0;j<t;j++) {
            cout<<dsat[0]+action+dsat[1]+instance+dsat[2]+day+dsat[3]+day+dsat[4]<<endl;
        }
    }
}