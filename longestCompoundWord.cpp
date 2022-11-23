#include <bits/stdc++.h>
#include <ctime>
using namespace std;


class trie
{
public:
   trie *map[26] = {0};
   int worend = 0;
   int pre = 0;
};


bool comparator(string &s1, string &s2)
{
     return s1.size() > s2.size();
}


void create(trie **root, string word, int length, int index)
{
   if (index < length)
   {
   
       if (((*root)->map[word[index] - 97]) == 0)
       {
           ((*root)->map[word[index] - 97]) = new trie();
       }
       
       ((*root)->map[word[index] - 97])->pre += 1;
       
       create(&((*root)->map[word[index] - 97]), word, length, index + 1);
   }
   if(index == length)
   {
      (*root)->worend = 1;
    }
}


int longestCompoundWord(trie **root, string word, int index, int length1, int split)
{
   trie *newTrie = (*root);
   if (index < length1)
   {
      if ((newTrie->map[word[index] - 97]) == 0)
         return 0;
    }
    while (index < length1)
    {
      if ((newTrie->map[word[index] - 97])->worend == 1) && (index != length1 - 1))
      {
         int w = longestCompoundWord(root, word, index + 1, length, 1);
         if (w == 1)
         {
            return 1;
         }
      }
      newTrie = (newTrie->map[word[index] - 97]);
      index += 1;
      if (((newTrie->map[word[index] - 97]) == 0) && (index != length1))
           return 0;
   }
   if ((index == length1) && (split == 1))
      return 1;
   if ((split == 1) && ((newTrie->worend) == 1))
       return 1;
    return 0;
   }
   
   int main()
   {
   
   #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
   #endif
       clock_t start, end;
       start = clock();
       trie *root = new trie();
       int cases;
       vector<string> colour;
       cin >> cases;
       cin.ignore();
       for (int i = 0; i < cases; i++)
       {
           string s1;
           getline(cin, s1);
           colour.push_back(s1);
           create(&root, s1, s1.length(), 0);
       }
       
       sort(colour.begin(), colour.end(), compare);
       int absent = 1;
       int count = 0;
       
       for (int i = 0; i < cases; i++)
       {
          if(longestCompoundWord(&root, colour[i], 0, colour[i].length(), 0) == 1)
          {
              cout << colour[i] << endl;
              count+=1;
              if (count == 2)
              {
              absent = 0;
              break;
              }
           }
       }
       
       if (absent == 1)
          cout<<"No word found";
          end = clock();
          double duration_sec = double(end-start)/CLOCKS_PER_SEC;
          cout<<"time taken is " <<duration_sec<< " seconds";
          
    }
   
   
   
