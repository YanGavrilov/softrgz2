#include <iostream>
#include <bitset>
#include<cmath>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void print_num(int32_t value)
{
    cout  << bitset<8>(value) << " = " << int32_t(value)<<endl;
}
void print_alphabet(vector <string> alphabet,vector <string> alphabet_code)
{
	for(int i=0;i<alphabet.size();i++)
	cout  << alphabet_code[i] << " = " << alphabet[i]<<endl;
}
void input_arr(vector <int>& arr) {
    cout << "Please enter numbers:" << endl;
    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];
}
void output_to_file(vector <int>& arr) {
    string patch = "num.txt";
    fstream number;
    number.open(patch, fstream::in | fstream::out | fstream::binary | fstream::trunc);
    if (!number.is_open())
    {
        cout << "Open error!  " << endl;
    }
    else
    {
        cout << "File num is open " << endl;
        for (int i = 0; i < arr.size(); i++)
        {
            number << bitset<8>(arr[i]) << endl;

        }
        number.close();
        cout << "File num is saved!\n";
    }
}
void read_alphabet(vector <string>& arr) {
    string line;
    ifstream in("letters.txt");
    if (in.is_open())
    {
        cout << "Letters file was opened!\n";
        while (getline(in, line))
        {
            arr.push_back(line);
        }
        cout << "Letters file was saved!\n";
    }
    else {
        cout << "Error";
    }
    in.close();
}
void read_nums(vector <string>& arr) {
    string line;
    ifstream in("num.txt");
    if (in.is_open())
    {
        cout << "Num file was opened!\n";
        while (getline(in, line))
        {
            arr.push_back(line);
        }
        cout << "Num file was saved!\n";
    }
    else {
        cout << "Error";
    }
    in.close();
}
void read_values(vector <string>& arr) {
    string line;
    ifstream in("values.txt");
    if (in.is_open())
    {
        cout << "Values file was opened!\n";
        while (getline(in, line))
        {
            arr.push_back(line);
        }
        cout << "Values file was saved!\n";
    }  
    else {
        cout << "Error";
    }
    in.close();  
}
void swap_line(vector<vector<string>>& arr, int first, int second) {
    for (int i = 0; i < arr.size(); ++i) {
        swap(arr[first][i], arr[second][i]);
    }
}
void swap_column(vector<vector<string>>& arr, int first, int second) {
    for (int i = 0; i < arr[0].size(); ++i) {
        swap(arr[i][first], arr[i][second]);
    }
} 
void gibrid_sort(vector<vector<string>>& arr) {
    for (int i = 1; i < arr[0].size() - 1; ++i)
    {
        for (int j = 0; j < arr[0].size() - 1; ++j)
            if (arr[0][j + 1] < arr[0][j])
                swap_column(arr, j, j + 1);
    }
    for (int i = 1; i < arr.size() - 1; ++i)
    {
        for (int j = 0; j < arr.size() - 1; ++j)
            if (arr[j + 1][0] < arr[j][0])
                swap_line(arr, j, j + 1);
    }
}
int main()
{
    int size;
    int q = 0, z = 0;
    int counter = 0;
    string** Mas;
    vector<vector<string>> FinalMas;
    cout << "Size is: ";
    cin >> size;
    Mas = new string* [size];
    for (int i = 0; i < size; ++i)
    Mas[i] = new string[size];
    vector <int> arr(pow(size,2));
    input_arr(arr);
    output_to_file(arr);
    cout << "Print numbers in binary system:  " << endl;
    for (int i = 0; i < arr.size(); i++)
    print_num(arr[i]);
    vector <string> horizontal(size);
    vector <string> vertical(size);
    vector <string> alphabet;
    vector <string> alphabet_code;
    vector <string> string_arr;
    read_alphabet(alphabet);
    read_nums(string_arr);
    read_values(alphabet_code);
    print_alphabet(alphabet,alphabet_code);
    for (int i = 0; i < string_arr.size(); ++i)
    {
        for (int q = 0; q < alphabet_code.size(); ++q)
        {
            if (string_arr[i] == alphabet_code[q]) {
                string_arr[i] = alphabet[q];
            }
        }
    }
    for (int i = 0; i < string_arr.size(); ++i) {
        for (int k = 0; k < size; ++k) {
            for (int j = 0; j < size; ++j) {
                Mas[k][j] = string_arr[counter];
                counter++;
                i++;
            }
        }
    }
    cout << "Enter the first word(by letter): " << endl;
    for (int i = 0; i < size; ++i) {
        cin >> horizontal[i];
    }
    cout << "Enter the second word(by letter): " << endl;
    for (int i = 0; i < size; ++i) {
        cin >> vertical[i];
    }
    for (int i = 0; i < size; ++i)   
    {
        if (i == 0) {
            cout << "  " << horizontal[i];
       } else
            cout << " " << horizontal[i];
    }
    cout << endl;
    for (int i = 0; i < size; ++i) {
        cout << vertical[i];
        for (int j = 0; j < size; ++j) {
            cout << ' ' << Mas[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < size+1; ++i) {
        vector <string> temp;
        for (int j = 0; j < size+1; ++j) {
            if (i == 0 && j == 0) {
                temp.push_back("  ");
            }
            else if (i == 0) {
                temp.push_back(horizontal[j - 1]);
            }
            if (i != 0 && j == 0) {
                temp.push_back(vertical[i - 1]);
            }
            if (i != 0 && j != 0) {
                temp.push_back(Mas[q][z]);
                z++;
            }
        }
        if (i != 0) {
            q++;
            z = 0;
        }
        FinalMas.push_back(temp);
    }
    gibrid_sort(FinalMas);
    cout<<endl;
    for (int i = 0; i < size+1; i++) {
        for (int j = 0; j < size+1; j++) {
            if (i == 0 && j == 0)
                cout << FinalMas[i][j];
            else
                cout << FinalMas[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
