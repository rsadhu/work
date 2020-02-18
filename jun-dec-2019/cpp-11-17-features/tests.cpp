#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <functional>
#include <memory>
#include <iterator>
#include <algorithm>
//#include "catch.hpp"

template<typename T>
class ListNode
{
public:
    ListNode(T rhs):value(rhs), next(nullptr){}
    int value = 0;
    ListNode<T> *next =  nullptr;

};

ListNode<int> *node(int d) {
    return new ListNode<int> (d);
}



//l = [1, 2, 3, 4, 5] and k = 2 , [2, 1, 4, 3, 5];
ListNode<int> * reverseNodesInKGroups(ListNode<int> * l, int k) {

    std::stack<ListNode<int>*> st;
    int i = 0;
    ListNode<int> *tra = new ListNode<int> (0);

    auto res =  tra;

    while(l)
    {
        i++;
        if(i <=k )
        {
            st.push(l);
        }
        else
        {
            i = 0;
            while(!st.empty())
            {
                tra->next = st.top();
                st.pop();
                tra = tra->next;
            }
            continue;
        }

        l = l->next;
    }

    while(!st.empty()) {
        tra->next = st.top();
        st.pop();
        tra =  tra->next;
    }


    auto tmp = res;
    res =  res->next;
    delete tmp;

    return res;
}



void creaateLinkList(ListNode<int> **l, std::vector<int> input)
{

    auto tra =  *l;
    for(auto it: input) {
        tra->next = new ListNode<int>(it);
        tra =  tra->next;
    }
}

/*a = [9876, 5432, 1999] and b = [1, 8001]*/
void createLists(){
    std::vector<int> input =  {1, 2, 3, 4, 5};
    //    ListNode<int> *l1 = new ListNode<int>(9876);
    //    l1->next =  node(5432);
    //    l1->next->next = node(1999);
    //    l1->next->next->next  = node(1);
    //    l1->next->next->next->next  = node(12);

    ListNode<int> *l1 = new ListNode<int>(-99);
    creaateLinkList(&l1, input);
    auto tmp =  l1;
    delete tmp;
    reverseNodesInKGroups(l1->next, 2);


    ListNode<int> *l2 =  node(1);
    l2->next  =  node(8001);



    std::stack<int> s1, s2, s3;
    int carry = 0;

    while(l1)
    {
        s1.push(l1->value);
        l1 =  l1->next;
    }


    while(l2)
    {
        s2.push(l2->value);
        l2 =  l2->next;
    }

    while(!s1.empty() && !s2.empty())
    {
        auto sum = s1.top() + s2.top() + carry;
        auto stringSum = std::to_string(sum);

        if(stringSum.length()> 4){
            auto tmpStr = stringSum.substr(1);
            s3.push(std::stoi(tmpStr));
            carry = std::stoi(stringSum.substr(0,1));
        }else{
            s3.push(sum);
            carry = 0;
        }
        s1.pop();
        s2.pop();
    }



    while(!s1.empty())
    {
        auto sum = s1.top() + carry;
        auto stringSum = std::to_string(sum);

        if(stringSum.length()> 4){
            auto tmpStr = stringSum.substr(1);
            s3.push(std::stoi(tmpStr));
            carry = std::stoi(stringSum.substr(0,1));
        }else{
            s3.push(sum);
            carry =0;
        }
        s1.pop();
    }


    while(!s2.empty())
    {
        auto sum = s2.top() + carry;
        auto stringSum = std::to_string(sum);

        if(stringSum.length()> 4){
            auto tmpStr = stringSum.substr(1);
            s3.push(std::stoi(tmpStr));
            carry = std::stoi(stringSum.substr(0,1));
        }else{
            carry =0;
            s3.push(sum);
        }
        s2.pop();
    }


    if(carry!=0)
    {
        s3.push(carry);
    }

    ListNode<int> *head  = nullptr;
    if(!s3.empty()) {
        head = node(s3.top());
        s3.pop();
    }

    auto tra = head;
    while(!s3.empty())
    {
        auto tmp = node(s3.top());
        tra->next  =  tmp;
        tra = tra->next;
        s3.pop();
    }


    // return head;
}




void sortColors(std::vector<int>& nums)
{
    int arr[3]= {0};
    for(const auto &it: nums)
    {
        arr[it]+=1;
    }

    for(int i = 0, j=0, k =0;i<3;i++)
    {
        j = 0;
        while((arr[i]-j++)>0)
        {
            nums[k++] = i;
        }
    }
}


void competitiveQuestions()
{
    std::vector<int> r =  {2,0,2,1,1,0};
    sortColors(r);

    for(auto o: r)
        std::cout<< o <<" ";

}


std::vector<int> digitalSumSort(std::vector<int> a)
{
    std::multimap<int, int> lookup;
    for(auto it: a)
    {
        int sum = 0, b = it;
        while(it)
        {
            sum += it%10;
            it/=10;
        }
        lookup.insert(std::pair<int,int>(sum,b));
    }

    std::vector<int> res;
    for(auto it: lookup)
    {
        res.push_back(it.second);
    }

    return res;
}

void addIntsFromLists()
{
    std::vector<int> n1 =  { 9, 0, 0, 1};
    std::vector<int> n2 =  {1};
}

std::vector<std::vector<std::string>> groupingDishes(std::vector<std::vector<std::string>> dishes)
{
    std::vector<std::vector<std::string>> res;
    std::multimap<std::string , std::string> lookup;

    for(auto it: dishes)
    {
        std::string item="";
        for(auto subit : it)
        {
            if(item=="")
                item =  subit;
            else
            {
                lookup.insert(std::pair<std::string, std::string> (subit, item));
            }
        }
    }
    return res;
}


int candles(int candlesNumber, int makeNew) {

    int sum  = candlesNumber;
    int remainder = 0;

    while(candlesNumber > 1)
    {
        sum += candlesNumber / makeNew;

        remainder =  candlesNumber % makeNew;

        candlesNumber = candlesNumber / makeNew  + remainder ;
    }

    return sum;
}


std::string decipher(std::string cipher) {
    std::string res;
    size_t cnt = 0;

    for(size_t i = 0;i < cipher.size();) {
        char ch = cipher[i];
        int sb = 0;
        if(ch != '9') {
            cnt = 3;
        }
        else {
            cnt = 2;
        }

        sb = std::stoi(cipher.substr(i, cnt));
        i+=cnt;
        res+= static_cast<char>(sb);
    }

    return res;
}

bool robotWalk(std::vector<int> a) {
    std::pair<int, int> pos(0,0);
    int d = 0 , i =0;
    for(auto it: a)
    {
        if(d == 0) {
            pos.second += it;
        }
        else if(d == 1) {
            pos.first += it;
        }
        else if(d == 2) {
            pos.second -= it;
        }
        else if(d == 3) {
            pos.first -= it;
        }

        d = ++i %4;
    }

    if(pos.first < 0 || pos.second < 0)
        return false;
    return true;
}

bool checkEqualFrequency(std::vector<int> inputArray) {

    std::map<int, int> lu;

    for(auto it: inputArray)
    {
        lu[it] +=1;
    }

    auto tmp = lu.begin();

    for(auto it =  lu.begin();it!=lu.end();it++)
    {
        if(it->second != tmp->second)
        {
            return false;
        }
    }
    return true;

}

int cal(int n)
{
    int sum = 0;
    if(n > 0)
    {
        std::vector<int> l;
        for(int i =2; i <= n;)
        {
            if(n%i==0) {
                l.push_back(i);
                sum+=i;
                n/=i;
            }
            else {
                i++;
            }
        }
    }
    return sum;
}

int deleteDigit(int n) {
    std::string str = std::to_string(n);

    std::string str1;

    int min = 10, i=0,j=0;
    for(auto it: str)
    {
        if(it - '0' < min)
        {
            min = it - '0';
            j =  i;
        }
        i++;
    }

    i = 0;
    for(auto it: str)
    {
        if(i==j)
        {
            i++;
            continue;
        }
        str1+=it;
        i++;

    }

    return std::stoi(str1);
}


//foo(bar(baz))blim  => foo(barzab)blim => foobazrabblim >> foobazrabblim
std::string reverseInParentheses(std::string inputString)
{
    std::stack<char> st1;
    std::vector<char> arrayVal;
    std::string res;
    bool bracket =  false;

    for(size_t i = 0; i < inputString.size(); i++)
    {
        if(inputString[i] == ')')
        {
            bracket =  false;
            while(!st1.empty())
            {
                if( st1.top()=='(') {
                    st1.pop();
                    if(st1.empty()) {
                        break;
                    }
                    for(auto it: arrayVal)
                    {
                        st1.push(it);
                    }
                    arrayVal.clear();
                }
                else {
                    arrayVal.push_back(st1.top());
                    st1.pop();
                }
            }

            for(auto it: arrayVal)
            {
                res.push_back(it);
            }
            arrayVal.clear();
        }
        else if(bracket==true || inputString[i]=='(')
        {
            st1.push(inputString[i]);
            bracket =  true;
        }
        else {
            bracket =  false;
            res+=inputString[i];
        }
    }

    return res;
}

std::string reduceString(std::string inputString) {

    int i=0,  j = inputString.size()-1;
    while(i<j && inputString[i]==inputString[j])
    {
        i++;
        j--;
    }

    return inputString.substr(i, j+1);
}


void rotateArray(){
    int k = 3;
    std::vector<int> arr =  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    for(auto it: arr)
    {
        std::cout<<it<<" ";
    }
    std::cout<<"\n";
    for(int i = 0;i< k;i++){
        auto tmp = arr[0];
        for(uint16_t j = 0;j <arr.size()-1;j++)
        {
            arr[j] = arr[j+1];
        }
        arr[arr.size()-1] = tmp;
    }

    std::cout<<"\n";
    for(auto it: arr)
    {
        std::cout<<it<<" ";
    }
}

void rotateArrayOptimized()
{
    std::cout<<"\n";
    int k = 3;
    std::vector<int> arr =  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    for(auto it: arr)
    {
        std::cout<<it<<" ";
    }

    std::reverse(arr.begin() , arr.begin()+k);
    std::reverse(arr.begin()+ k , arr.end());
    std::reverse(arr.begin() , arr.end());

    for(auto it: arr)
    {
        std::cout<<it<<" ";
    }
}


int parkingCost(std::string timeIn, std::string timeOut) {

    int hourDiff, minDiff;
    hourDiff = std::stoi(timeOut.substr(0,2))  - std::stoi(timeIn.substr(0,2)) ;
    minDiff =  std::stoi(timeOut.substr(3,4))  - std::stoi(timeIn.substr(3,4)) ;

    auto totalMins =  hourDiff * 60 + minDiff;
    auto totalPrice = 0;

    while( totalMins > 30 ) {
        if(totalMins > 120) {
            auto tmp = totalMins -  120;
            totalPrice += (tmp/10) * 2;
            if(tmp % 10 != 0){
                totalPrice+=2;
            }

            totalMins = 120;
        }
        else
            if(totalMins > 30){
                auto tmp = totalMins- 30;
                totalPrice += tmp/10 ;
                if(tmp % 10 !=0 )
                    totalPrice+=1;

                totalMins = 30;
            }
    }

    return totalPrice;
}


std::string htmlEndTagByStartTag(std::string startTag) {

    std::string retString("</") ;
    bool tagBegan = false;
    for(ulong i = 0; i < startTag.length(); ++i)
    {
        if (startTag[i]=='<') {
            tagBegan = true;
            continue;
        }
        if (startTag[i] == ' ')
            tagBegan = false;
        if (tagBegan) {
            retString+=startTag[i];

        }
        else {
            retString+=">";
            break;
        }
    }
    return retString;
}

std::vector<int> processArray(std::vector<int> arr, int k)
{
    std::vector<int> res;
    size_t i = k;
    for(;i < arr.size(); i+=k)
    {
        for(size_t j = i ; j > i-k; --j) {
            res.push_back(arr.at(j-1));
        }
    }
    return res;
}


std::vector<std::string> tokenize(std::string str, std::string token)
{
    std::vector<std::string> res;
    auto index = 0;
    while((index = str.find(token))!= -1)
    {
        std::string str1 = str.substr(0, index);
        if ( str1 == "..") {
            if( !res.empty() )
                res.pop_back();
        }
        else
            if( str1 != ""  && !str1.empty() && str1 != ".")
                res.push_back(str1);

        str = str.substr(index + 1, str.length()-1);
    }
    return res;
}

std::vector<std::string> splitAddress(std::string address) {
    auto protocol =  address.substr(0, address.find("//"));
    address =  address.substr(address.find("//")+2);

    auto domain =  address.substr(0, address.find("."));
    address =  address.substr(address.find(".")+1);

    auto ind =  address.find("/");
    if ( ind!=std::string::npos) {
        auto context =  address.substr(ind+1);
        return {protocol.substr(0, protocol.find(":")), domain, context};
    }
    else{
        return {protocol.substr(0, protocol.find(":")), domain};
    }
}

int giftSafety(std::string gift) {
    int sum = 0;
    for(size_t i = 0 ; i <=gift.length()-3; i++)
    {
        auto substr  = gift.substr(i, 3);
        for(size_t j =0 ;j < 3; j++)
        {
            if( substr[j%3] == substr[(j+1) % 3])
                sum++;
        }
    }
    return sum;
}

bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {
    std::map<char, int> lu ;
    for(uint i = 0; i < solution.size(); i++)
    {
        lu[solution[i][0]] = solution[i][1] - '0';
    }

    std::string first, second, third;

    for ( auto it: crypt[0])
    {
        first+= std::to_string((char)lu[it]);
    }

    if ( first[0] == '0')
        return false;

    for ( auto it: crypt[1])
    {
        second+= std::to_string((char)lu[it]);
    }

    if ( second[0] == '0')
        return false;

    for ( auto it: crypt[2])
    {
        third += std::to_string((char)lu[it]);
    }

    if ( third[0] == '0')
        return false;

    auto tmp = std::stoi(first) + std::stoi(second);
    if ( std::to_string(tmp) == third)
        return true;
    else {
        return false;
    }
}



std::vector<std::vector<int>> spiralNumbers(uint n) {

    std::vector<int> output;

    int nRow = 0, nCol = 0, row=0, col=0;

    int i = 0;

    while( output.size() <= n)
    {
        // go right
        while(  col < n - nCol )
        {
            output.push_back(++i);
            col++;
        }

        row++;
        col--;

        // go down
        while(  row < n - nRow )
        {
            output.push_back(++i);
            row++;
        }

        col--;
        row--;

        // go left
        while(  col >= nCol )
        {
            output.push_back(++i);
            col--;
        }


        row--;
        col++;
        // go up
        while( row > nRow )
        {
            output.push_back(++i);
            row--;
        }

        col++;
        row++;

        nCol++;
        nRow++;
    }
    output.push_back(++i);

    std::vector<std::vector<int>> matrix (n, std::vector<int> (n, 0));

    int line = 0, j = 0, k = 0;

    for(auto it: output)
    {
        matrix[j][k++] = it;
        if (++line % n == 0)
        {
            k = 0;
            j++;
        }
    }

    return matrix;
}


void convert(std::vector<int> &res, std::string ver)
{
    uint i = 0;
    std::string tmp;
    while (i < ver.size())
    {
        if (ver[i] == '.')
        {
            res.push_back(std::stoi(tmp));
            tmp = "";
        }
        else {
            tmp+=ver[i];
        }
        i++;
    }
    res.push_back(std::stoi(tmp));
}

int higherVersion2(std::string ver1, std::string ver2) {
    int ret (0);

    std::vector<int> res1;
    std::vector<int>  res2;

    convert (res1, ver1);
    convert (res2, ver2);

    for(int i = 0;i < res1.size(); i++)
    {
        if ( res1[i] > res2[i] )
        {
            ret =  1;
        }
        else
            if (res1[i] == res2[i]) {
                continue;
            }
            else {
                return -1;
            }
    }
    return ret;
}


std::vector<std::vector<int>> spiralNumbersFromN(int n) {

    std::vector<std::vector<int>> output(n , std::vector<int>(n, 0));

    int nRow = 0, nCol = 0, row=0, col=0;

    int i = 1;

    while( i <= n)
    {
        // go right
        while(  col < n - nCol )
        {
            output[row][col] = i++;
            col++;
        }

        row++;
        col--;

        // go down
        while(  row < n - nRow )
        {
            output[row][col] = i++;
            row++;
        }

        col--;
        row--;

        // go left
        while(  col >= nCol )
        {
            output[row][col] = i++;
            col--;
        }


        row--;
        col++;
        // go up
        while( row > nRow )
        {
            output[row][col] = i++;
            row--;
        }

        col++;
        row++;

        nCol++;
        nRow++;
    }
    return output;
}



int main(void)
{
    auto ret = spiralNumbersFromN(3);
    return 0;
}
