//
// Created by rsadhu on 01.10.20.
//

#include <vector>
#include "leetcode_headers.h"


using namespace std;

struct LinkNode
{
    LinkNode(int d): val(d){}
    int val;
    LinkNode *next =  nullptr;
};

void reverseSome(LinkNode *prev, LinkNode *tra, LinkNode *&head, int &k)
{
 if (tra->next)
 {
     prev = tra;
     tra = tra->next;
     reverseSome(prev, tra, head, k);
     k--;
     if ( k >= 0)
     {
        prev->next = nullptr;
        tra->next = head;
        head = tra;
     }
 }
}

bool test(std::vector<int> &A)
{
    int l_index =  1;
    int r_index =  A.size() - 2;
    int sum1 = 0, sum2=0, mid_sum=0;
    std::vector<int> sum_arr(A.size());
    sum_arr.push_back(A[0]);
    for (int i = 1; i <A.size(); i++)
    {
        sum_arr[i] = sum_arr[i-1] + A[i];
    }

    while(l_index < r_index)
    {
        sum1 = sum_arr[l_index] - A[l_index];
        mid_sum = sum_arr[r_index] - sum_arr[l_index]- A[r_index];
        sum2 = sum_arr[A.size()-1]- sum_arr[r_index];

        if (sum1 == mid_sum && mid_sum == sum2)
            return true;

        if ( sum1 < sum2)
            l_index++;
        else if (sum1 > sum2)
            r_index--;
        else{
            l_index++;
            r_index--;
        }
    }
}




void  tokenize(string str , char delim, vector<string> &out)
{
    int start = 0;
    int end = 0;
    while((start = str.find_first_not_of(delim, end))!= string::npos)
    {
        end  =  str.find(delim, start);
        out.push_back(str.substr(start, end-start));
    }
}



string mySolution(int N, string &S, string &T)
{
    //std::vector::vector<int> area (N);
    vector<vector<int>> area(N, vector<int> (N, 0));

    vector<string > hits;
    tokenize(T, ' ', hits);

    for (auto it :hits)
    {
        int x = it[0] -'0' -1;
        int y = it[1] - 'A';
        area[x][y]= 1;
    }


    int sum_sunk =0 , sum_hits = 0;


    vector<string > ships;
    tokenize(S, ',', ships);


    for (auto it: ships)
    {
        vector<string> ship;
        tokenize(it, ' ', ship);

        int x1 = ship[0][0] -'0'-1;
        int y1 = ship[0][1] - 'A';

        int x2 = ship[1][0]-'0'-1;
        int y2 = ship[1][1] - 'A';

        bool a(false), b(false);
        while(x1 <= x2)
        {
            int yy = y1;
            while(yy <= y2 )
            {
                if (area[x1][yy] == 1)
                    a = true;
                else
                {
                    b = true;
                }
                yy++;
            }
            if (b && a)
                break;

            x1++;
        }

        if (a && b)
            sum_hits++;
        else
        if(a)
        {
            sum_sunk++;
        }
    }

    std::string output;
    output = std::to_string(sum_sunk);
    output +=  std::to_string(sum_hits);
    return output;


}

string solution(int N, string &S, string &T) {
    // write your code in C++14 (g++ 6.2.0)

    return mySolution(N, S, T);
}

class TreeNode
{
public:
    TreeNode(int d):val(d){}
    int val;
    TreeNode *left =  nullptr, *right = nullptr;
};


TreeNode *LevelOrder(TreeNode *root , int data)
{
    if(root==NULL){
        root = new TreeNode(data);
        return root;
    }
    if(data <= root->val)
        root->left = LevelOrder(root->left, data);
    else
        root->right = LevelOrder(root->right, data);
    return root;
}

TreeNode* deserialize(string data) {

    TreeNode *root = nullptr;


    while(!data.empty())
    {
        int i = data.find_first_of('/');
        if (i == string::npos)
            break;
        auto num_s = data.substr(0, i);
        data = data.substr(i+1, data.length());

        root = LevelOrder(root, std::stoi(num_s));
    }
    return root;
}


bool buddyStrings(string A, string B) {

    if (A.length() == 0 || B.length() == 0 || A.length() != B.length())
        return false;

    int no_match_ind = -1, same = true;
    char ch = A[0];

    for(int i = 0 ; i < A.length(); i++)
    {
        if (ch != B[i])
        {
            same = false;
        }
        if (A[i] != B[i]) {
            no_match_ind =  i;

            break;
        }
    }

    if (same)
        return true;

    for (int  i = 0;  no_match_ind !=-1 && i < A.length(); i++)
    {
        if (A[i] == B[no_match_ind])
        {
            std::swap(A[i], A[no_match_ind]);
            std::cout<<A <<"   "<< B;
            if (A == B)
                return true;
            else
                return false;
        }
    }
    return false;
}
using ListNode = LinkNode;
ListNode *sort(ListNode *head)
{
    for(auto tra = head; tra; tra= tra->next)
    {
        auto tmp = head;
        auto cur = tra->next;
        if (!cur)
            break;
        for (; tmp != cur; tmp= tmp->next)
        {
            if (cur->val > tmp->val)
            {
                std::swap(cur->val, tmp->val);
            }
        }
    }
    return head;
}



int main(void) {
    LinkNode *head = new LinkNode(1);
    auto tra =  head;
    for (int x = 2; x <=10 ; x++)
    {
        head->next = new LinkNode(x);
        head = head->next;
    }
    auto disp = [](LinkNode *tra)
    {
        std::cout<<"\n";
        while(tra)
        {
            std::cout<<" "<< tra->val;
            tra =  tra->next;
        }
        std::cout<<"\n";
    };
    disp(tra);

    sort(tra);


//    int k = 1;
//    reverseSome(tra, tra->next, tra, k);
//    disp(tra);

    std::cout<<"\n1\n";
    {
        auto S = std::string("1B 2C,2D 4D");
        auto T = std::string("2B 2D 3D 4D 4A");
        auto str = solution(4, S, T);
        std::cout<<"\n"<<str<<"\n";
    }
    std::cout<<"\n2\n";

    {
        auto S =  std::string("1A 1B,2C 2C");
        auto T =  std::string("1B");
        auto str = solution(3, S,T);
        std::cout<<str<<"\n";
    }
    std::cout<<"\n3\n";
    {
        auto S =  std::string("1A 2A,12A 12A");
        auto T =  std::string("12A");
   //     auto str = solution(12, S,T);
//        std::cout<<str<<"\n";
    }



 //   deserialize("7/4/12/3/6/8/1/5/10/");


    std::string s1("abcd"), s2("badc");
    std::cout<<buddyStrings(s1, s2);

  return 0;
}