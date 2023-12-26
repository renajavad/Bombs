#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

double distance(int x1, int y1, int x2, int y2) 
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int maxDetonatedBombs(std::vector<std::vector<int>>& bombs) 
{
    int maxBombsDetonated = 0;
    int n = bombs.size();

    for (int i = 0; i < n; i++) 
    {
        int x1 = bombs[i][0];
        int y1 = bombs[i][1];
        int r1 = bombs[i][2];
        int bombsDetonated = 0;
        
        for (int j = 0; j < n; j++)  // the range of current bomb with other bombs
        { 
            if (j != i) {
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                int r2 = bombs[j][2];
                
                double dist = distance(x1, y1, x2, y2); // the distance between the centers of the two bombs

                if (dist <= r1 + r2) 
                {
                    bombsDetonated++;
                }
            }
        }
        
        maxBombsDetonated = std::max(maxBombsDetonated, bombsDetonated); // the maximum number of bombs that can be detonated
    }
    
    return maxBombsDetonated + 1;
}

/*int main() 
{
    std::vector<std::vector<int>> bombs1 = {{2, 1, 3}, {6, 1, 4}};
    std::cout << maxDetonatedBombs(bombs1) << "\n"; 
    
    std::vector<std::vector<int>> bombs2 = {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}};
    std::cout << maxDetonatedBombs(bombs2) << "\n";
    
    std::vector<std::vector<int>> bombs3 = {{1, 1, 5}, {10, 10, 5}};
    std::cout << maxDetonatedBombs(bombs3) << "\n"; 
    
    return 0;
}*/

