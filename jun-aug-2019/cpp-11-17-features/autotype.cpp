#include<iostream>

#ifdef RAKESH

template<typename T>
class ListNode {
public:
    ListNode(T rhs): value(rhs){}
    ListNode *next = nullptr;
    T value ;
};

ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
    std::stack<int> s1, s2, s3;
    size_t width = 0;
    for(auto it = a; it;it = it->next)
    {
        s1.push(it->value);
        auto str = std::to_string(it->value);
        if(width < str.length())
            width = str.length();
    }

    for(auto it = b; it;it = it->next)
    {
        s2.push(it->value);
        auto str = std::to_string(it->value);
        if(width < str.length())
            width = str.length();
    }

    int c = 0;
    while(!s1.empty() && !s2.empty())
    {
        auto sum = s1.top() + s2.top() + c;
        c = 0;

        auto str = std::to_string(sum);
        if( str.length() <=  width)
        {
            s3.push(sum);
        }
        else
        {
            auto delta = str.length() - width;
            c =  std::stoi(str.substr(0, delta));
            s3.push(std::stoi(str.substr(delta, str.length())));
        }

        s1.pop();
        s2.pop();
    }

    while(!s1.empty())
    {
        auto sum = s1.top() + c;
        s1.pop();
        auto str = std::to_string(sum);
        if( str.length() <=  width)
        {
            s3.push(sum);
        }
        else
        {
            auto delta = str.length() - width;
            c =  std::stoi(str.substr(0, delta));
            s3.push(std::stoi(str.substr(delta, str.length())));
        }
    }


    while(!s2.empty())
    {
        auto sum = s2.top() + c;
        s2.pop();

        c = 0;

        auto str = std::to_string(sum);
        if( str.length() <=  width)
        {
            s3.push(sum);
        }
        else
        {
            auto delta = str.length() - width;
            c =  std::stoi(str.substr(0, delta));
            s3.push(std::stoi(str.substr(delta, str.length())));
        }
    }

    ListNode<int> *tmp  = nullptr;
    if(c!=0)
        tmp = new ListNode<int> (c);



    ListNode<int> *head = new ListNode<int> (0);
    auto tt = head;


    while(!s3.empty())
    {
        std::string fin = std::to_string(s3.top());

        int i = 0, j = fin.length()-1;

        int flag = 0;
        while(i<j)
        {
            flag = 0;
            if( fin[i] == '0') {
                flag = 1;
                i++;
            }

            if(fin[j] == '0') {
                flag = 1;
                j--;
            }

            if(flag == 0)
                break;
        }

        if(flag != 0) {
            if(i!=j)
                tt->value =  std::stoi(fin.substr(i,j));
            else {
                tt->value = std::abs('0' - fin[i]);
            }
        }
        else {
            tt->value = std::stoi(fin);
        }
        s3.pop();

        if(s3.empty())
            break;

        tt->next = new  ListNode<int>(0);
        tt = tt->next;
    }

    if(tmp){
        tmp->next =  head;
        head = tmp;
    }


    return head;
}


ListNode<int > * generateSll(const std::initializer_list<int > &list)
{
    ListNode<int > *head =  nullptr, *tra;

    for(auto it:list)
    {
        if(!head) {
            head = new ListNode<int>(it);
        }
        else {
            for(tra =  head; tra->next; tra=tra->next);
            tra->next =  new ListNode<int>(it);
        }
    }
    return head;

}


void display(ListNode<int> *head)
{
    while(head)
    {
        std::cout<< head->value <<" ";
        head = head->next;
    }
}

void TEST()
{
    ListNode<int> *l1, *l2, *l3;;

    //    l3 = addTwoHugeNumbers(generateSll({1}), generateSll({9999, 9999, 9999}));
    //    display(l3);

    //    l3 = addTwoHugeNumbers(generateSll({123, 4, 5}), generateSll({100, 100, 100}));
    //    display(l3);

    l3 = addTwoHugeNumbers(generateSll({1}), generateSll({9999, 9999, 9999, 9999, 9999, 9999, 9999}));
    display(l3);


    //    l3 = addTwoHugeNumbers(generateSll({626, 6726, 9980, 9738, 4562, 6376, 8940, 6921, 1676, 1107, 8959, 4623, 4324, 9083, 7716, 7800, 8042, 4337, 3616, 7983, 9701, 3275, 5680, 802, 2485, 4473, 7661, 9235, 5797, 5042, 7365, 3106, 7361, 2724, 5328, 8525, 7103, 755, 947, 7898}),
    //                           generateSll({9651, 8173, 5384, 7798, 8467, 2360, 3375, 9054, 1161, 9880, 1427, 6573, 5907, 9061, 7900, 6516, 6546, 293, 3877, 9453, 4289, 4829, 7563, 4308, 7845, 4840, 3279, 7186, 9917, 25, 4220, 9052, 6867, 8567, 8308, 5917, 7251, 7236, 2581, 8901, 8372}));
    //    display(l3);


    l3 = addTwoHugeNumbers(generateSll({9665}), generateSll({6933, 8443, 5132, 6809, 8519, 9096}));
    display(l3);
}



std::string correctDirectoryPath(std::string path)
{
    std::vector<std::string> ret;
    std::string tmp;
    for(int i = 0;i<path.length();i++)
    {
        bool split = false;

        while(path[i]!='\0' && path[i]=='/') {
            split = true;
            i++;
        }


        if(split && !tmp.empty())
        {
            i--;
            ret.push_back(tmp);
            tmp.clear();
        }
        else
        {
            tmp += path[i];
        }
    }

    if(!tmp.empty()) {
        ret.push_back(tmp);
        tmp.clear();
    }

    std::vector<std::string> st;
    for (auto it: ret) {
        if(it == ".." )
        {
            if(!st.empty())
                st.pop_back();
        }
        else
        {
            st.push_back(it);
        }
    }

    for( auto it: st)
        tmp += "//" + it;

    return tmp;
}



void ingredientListing(std::vector<std::vector<std::string>> list)
{
    std::map<std::string, std::vector<std::string>> lookup;
    for(auto it: list) {
        std::vector<std::string> d;
        for(int i = 1; i< it.size();i++)
        {
            d.clear();
            auto key = it.at(i);
            auto val  = lookup[key];
            if(val.size()>0)
            {
                d.swap(val);
            }
            d.push_back(it.at(0));
            lookup[key] = d;
        }
    }


    std::vector<std::vector<std::string>> res;

    std::vector<std::string> d;
    for(auto it: lookup)
    {
        d.push_back(it.first);
        for(auto it1: it.second)
        {
            d.push_back(it1);
        }
        res.push_back(d);
    }
    //return res;
}

void
test()
{
    std::vector<std::vector<std::string>> list = {
        {"Salad", "Tomato", "Cucumber", "Salad", "Sauce"},
        {"Pizza", "Tomato", "Sausage", "Sauce", "Dough"},
        {"Quesadilla", "Chicken", "Cheese", "Sauce"},
        {"Sandwich", "Salad", "Bread", "Tomato", "Cheese"}
    };

    ingredientListing(list);
    bool ok = false;;

    // std::string path = "This is my home I am part of this system";
    //path = correctDirectoryPath(path,ok);

}


int firstDuplicate(std::vector<int> arr)
{
    int i=0;
    std::map<int, int> lookup, indl;
    for(auto it: arr)
    {
        if(lookup[it]==0){
            lookup[it]=1;
        }else{
            indl[i]=it;
        }
        i++;
    }
    if(indl.size()>0)
        return indl.begin()->second;

    return -1;
}

char firstNotRepeatingCharacter(std::string s) {

    std::map<char , int> lookup;

    for(auto it: s)
    {
        lookup[it]+=1;
    }

    for(auto it: s)
    {
        if (lookup[it]==1)
            return it;
    }
    return '_';
}

void rotateMatrixby90()
{
    std::vector<std::vector<int>> a =  { {1, 2, 3},
                                         {4, 5, 6} ,
                                         {7, 8, 9}
                                       };
    std::vector<std::vector<int>> result;
    int row =  a.size();
    int col =  a.at(0).size();
    for (int i = 0; i < row  ; i++)
    {
        std::vector<int> r;
        for(int j = 0;j < col; j++)
        {
            r.push_back(a[row-j-1][i]);
        }
        result.push_back(r);
    }
    //       return result;

}

std::vector<std::string> tokenizer(std::string str)
{
    std::vector<std::string> ret;
    std::string tempStr;
    for(auto it: str)
    {
        bool isSlash  = false;
        while(it =='/'){
            it++;
            isSlash= true;
        }

        if(isSlash)
        {
            ret.push_back(tempStr);
            tempStr.clear();
            continue;
        }

        tempStr+=it;
    }
    return ret;
}


std::string  detectDirectoryUnixPath(std::string path, bool &ok)
{
    std::stack<std::string> allStrings;
    std::string newPath;
    auto tokenizedStrings =  tokenizer(path);

    for(auto it: tokenizedStrings)
    {
        if(it.empty() || it == ".")
            continue;

        if(it==".." && !allStrings.empty()) {
            allStrings.pop();
            continue;
        }

        allStrings.push(it);
    }

    while(!allStrings.empty())
    {
        auto d =  allStrings.top();
        newPath =  "//" + newPath + d;
        allStrings.pop();
    }

    std::string p;
    for(auto it = newPath.rbegin() ;it != newPath.rend();it++)
    {
        //p+=it;
    }
}


template<typename T, typename U, typename V>
void  callback( T a, U b , V c)
{
    std::cout<<" \n callback ::>> "<<a << "  "<< b << " " << c<< "\n";
}

template<typename Type>
class Test {
public:
    Test(Type  d):data (d){}
    void display() { std::cout<< "\n Templated ::class"<< data <<"\n";}

    template<typename U>
    void anotherFunction(U b)
    {
        std::cout<< "\n another functon :: "<< b<<"\n";
    }

    Type data;

    //    template<typename AnotherType>
    //    class NestedTest
    //    {
    //        AnotherType mdata;
    //    public:
    //        NestedTest(AnotherType rhs):mdata(rhs){}
    //        void display() { std::cout<< "\n  AnotherType:: display :: "<<mdata; }
    //    };

    //    template<typename AnotherType>
    //    NestedTest<AnotherType> priv() { NestedTest<AnotherType> nData; return std::move(nData); }
};



std::string integerToStringOfFixedWidth(int number, int width) {

    std::string ret;
    while(number && width)
    {
        auto d = std::to_string(number % 10 );
        ret.insert(0,d);
        number /= 10;
        width--;
    }

    while(width--)
    {
        ret.insert(0,std::to_string(0));
    }

    return ret;
}

std::string removeDuplicateCharacters(std::string str) {
    std::map<char, int> lk;

    for(char it: str)
    {
        lk[it]+=1;
    }

    std::string ret;
    for(auto it: str)
    {
        if(lk[it] == 1)
            ret+=it;
        else
            if(lk[it] == 2) {
                lk.erase(it);
                ret+=it;
            }
    }
    return ret;
}

// programming Question from codingFights
std::vector<std::string> repeatedDNASequences(std::string s) {
    std::vector<std::string> res;

    for(int i  = 0; i < s.length(); i++)
    {
        for(int j =  i + 10; j < s.length() - 10 ;j+=10)
        {
            if(s.substr(i, 10) == s.substr(j , 10))
            {
                res.push_back(s.substr(i, 10));
                break;
            }
        }
    }

    return res;
}

bool sudoku2(std::vector<std::vector<char>> grid) {



    std::set<int> lrow, lcol;
    for(int col = 0 ; col < 9 ; col++)
    {
        for(int row = 0 ; row < 9;row++)
        {
            auto d =  grid.at(row).at(col);
            if(d!='.') {
                if( !lcol.insert(d).second )
                    return false;
            }
        }

        lcol.clear();


        auto d =  grid.at(0).at(col);
        if(d!= '.') {
            if( !lrow.insert(d).second )
                return false;
        }
    }

    return true;
}

void test11()
{
    std::map<std::string , int> registers;

    for(int i = 0;i<43;i++)
    {
        std::string str;
        char ch = (i + '0');
        std::string chS(1, ch);
        if( i < 10 ) {
            str = "R0" + chS;
        } else {
            str = "R" + chS;
        }
        registers[str] = 0;
    }
}


int sumOfDivisors(int n) {
    int sum  = 0;
    for(int i = 1; i<=n; i++) {
        if(n % i == 0)
            sum += i;
    }

    return sum;
}

#endif

using namespace std;
//int x = 100;

auto getObject(){
// int & rv =  x;
 //return rv;
}


int main(void)
{
 //auto x = 10;
 return 0;
}
