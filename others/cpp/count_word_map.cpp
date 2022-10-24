#include<iostream>
#include <unordered_map>
#include <fstream>
using namespace std;

// get rid of characters that are not letters in a word
string GetWord(string inputWord); 

int main(int argc, char const *argv[])
{
    int count = 0;
    string word;
    unordered_map<string, int> map1; //count the number of words
    unordered_map<string, int> map2; //count the total words
    unordered_map<string, int>::iterator itr;

    string file = "test_countWord_Map.txt";
    fstream myfile;

    myfile.open(file);

    while (!myfile.eof())
    {
        myfile >> word;
        string str = "";
        if (!word.empty())
            str = GetWord(word);

        if (!str.empty())
        {
            itr = map1.find(str);
            if (itr != map1.end())
            {
                itr = map2.find(str);
                if (itr == map2.end())
                    map2[str] += 1;

                count++;    
            }   
            else
            {
                map1[str] += 1;
                count++;
            }   
        }   
    }
    cout << "There are " << map2.size() << " duplicates in the text" << endl;
    cout << "There are " << count << " words in the text" << endl;

    return 0;
}

string GetWord(string inputWord) 
{ 
    int i, j;       i = j = 0; 
 
    bool check = false; 
 
    while (i < inputWord.size()) 
    { 
        if (!(isalpha(inputWord[i])) && !(isdigit(inputWord[i]))) 
        { 
            j = i; 
            inputWord.erase(inputWord.begin() + i); 
            check = true; 
        } 
 
        if (check == true) 
        { 
            i = j; 
            check = false; 
        } 
        else 
        { 
            i++; 
        } 
    } 
 
    return inputWord; 
}
