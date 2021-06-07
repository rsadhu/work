#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    
    int getArea(int x, int y, vector<vector<int>>& list){
		if( x<0 || (x>=list.size()) || (y<0) || (y>=list[x].size()) ){
			return 0;
		}   
		if(list[x][y] == 1){
			list[x][y] = 0;
			return (1 + (getArea(x+1,y,list) + getArea(x-1,y,list) + getArea(x,y+1,list) + getArea(x,y-1,list))); 
		}
		return 0;
	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int max_value = 0;
		for(int i=0; i<grid.size(); i++){
			for(int j=0; j<grid[i].size(); j++){
				 if(grid[i][j]==1)
					max_value = max(max_value, getArea(i, j, grid));
			}
		}
		return max_value;
	}
   
};




int main(void)
{
    Solution s;
    std::vector<std::vector<int>> sea = {
                                        {0,0,1,0,0,0,0,1,0,0,0,0,0},
                                        {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                        {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                        {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                        {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                        {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                        {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                        {0,0,0,0,0,0,0,1,1,0,0,0,0}
                                        };
 
    std::cout<<"biggest island in sea is of size ->  "<< s.maxAreaOfIsland(sea);
    return 0;
}