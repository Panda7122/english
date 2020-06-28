#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string.h>
#include <vector>
#include <queue>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
int r[100000];
int r_wa[100000];
queue <int> round;
vector <int> wra;
int wr = 0, co = 0;
string UTF8ToGB(const char* str)
{
	string result;
	WCHAR *strSrc;
	LPSTR szRes;
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);
	result = szRes;
	delete[]strSrc;
	delete[]szRes;
	return result;
}
string field[10000][2];
int main(){
	string s;
	bool wa = 0;
    srand(time(NULL));
     ifstream inFile(".\\eng\\english.csv", ios::in);
    if (!inFile)
    {
        cout << "�}���ɮץ��ѡI" << endl;
        exit(1);
    }
    int len = 0;
    string line;

    while (getline(inFile, line)){
        istringstream sin(line); //�N���r��lineŪ�J��r��ysin��

        getline(sin, field[len][0], ','); //�N�r��ysin�����r��Ū�J��field�r�ꤤ�A�H�r�������j��
        getline(sin, field[len][1], ','); //�N�r��ysin�����r��Ū�J��field�r�ꤤ�A�H�r�������j��
        field[len][1] = UTF8ToGB(field[len][1].c_str()).c_str();
        len++;
    }
    inFile.close();
    cout << "�@Ū���F" << len << "�ӳ�r\n��rŪ������\n";
	system("pause");
    system("cls");
    for(int j = 0; j < len; j++){
        r[j] = (rand() % len) + 1;
        for(int k = 0; k < j; k++){
            if(r[j] == r[k]){
                j--;
                break;
            }
        }
    }
    for(int j = 0; j < len; j++) round.push(r[j]);
	int count = 0;
	int size_wa = 0;
	do{
		wra.clear();
	    while(!round.empty()){
	        cout << count+1 << " " << field[round.front() - 1][1] << ":";
	        cin >> s;
	        wa = 0;
	        for(int k = 0; field[round.front() - 1][0][k]!= 0x00; k++){
	        	if(s[k] != field[round.front() - 1][0][k]){
	        		wa = 1;
	        		break;
				}
			}
			if(s.size() != field[round.front() - 1][0].size()) wa = 1;
			if(wa){
				cout << "wrong!\n";
				cout << "���T���׬O:" << field[round.front() - 1][0] << "\n"; 
				wra.push_back(round.front()); 
				wr++;
			}else{
				cout << "correct!!!\n";
				co++;
			}
			round.pop();
			system("pause");
			system("cls");
			count++;
	    }
	    size_wa = wra.size();
	    if(size_wa)
		    cout << "���~�D��:"; 
		else
			cout << "���ƥ��T!!!���߹L��!\n";
	    for(int i = 0; i < size_wa; i++){
	        r_wa[i] = wra[(rand() % size_wa)];
	        for(int k = 0; k < i; k++){
	            if(r_wa[i] == r_wa[k]){
	                i--;
	                break;
	            }
	        }
		}
	    for(int i = 0; i < size_wa; i++)
	    	cout << field[wra[i]-1][1] << " ";
		cout << "\n";
		for(int j = 0; j < size_wa; j++) round.push(r_wa[j]);
		system("pause");
		system("cls");
	}while(!wra.empty());
	cout << "���T�D��:" << co << "\n";
	cout << "���~�D��:" << wr << "\n";
}
