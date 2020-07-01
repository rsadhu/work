#ifndef GRAPHS_H
#define GRAPHS_H
#include <vector>
#include <set>
#include <stack>

template<typename DS, typename EL>
bool  find(const DS &rhs, const EL &el )
{
    for(auto it: rhs)
    {
        if (el == it)
            return true;
    }
    return false;
}

void bfs(std::vector<std::vector<int>> adjMat, int startNode) {
    std::cout<<"\n";
    std::vector<int> list;
    list.emplace_back(startNode-1);
    for (int i = 0 ;i < list.size();i++ ) {
        std::cout<<" "<<list[i]+1;
        for (int j = 0;j < adjMat.size();j++)
        {
            if (adjMat[list[i]][j]==1)
            {
                if (!find(list, j))
                {
                    list.emplace_back(j);
                }
            }
        }
    }
    std::cout<<"\n";
}


void dfs(std::vector<std::vector<int>> adjMatrix, int start) {
    std::cout<<"\n";
    std::stack<int> st;
    st.push(start-1);
    std::set<int> visited;
    int i = 0;
    while(!st.empty())
    {
        int i = st.top();

        if (visited.count(i)==0)
            std::cout<< i +1 <<" " ;

        visited.insert(i);

        bool f = false;

        for(int j = 0;j < adjMatrix.size();j++)
        {
            if (adjMatrix[i][j] == 1 &&  visited.count(j)==0)
            {
                st.push(j);
                f = true;
                break;
            }
        }

        if (!f)
        {
            st.pop();
        }
    }
    std::cout<<"\n";
}


#endif// grphs