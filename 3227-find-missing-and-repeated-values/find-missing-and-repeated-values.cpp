class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map <int,int> mpp;
        for ( int i = 0 ; i < grid.size() ; i ++ ) {
            for ( int j = 0 ; j < grid[0].size() ; j ++ ) {
                mpp[grid[i][j]]++;
            }
        }
        int a , b;
        for ( auto &it : mpp ) {
            if ( it.second == 2 ) {
                a = it.first;
                break;
            }
        }
        int size = grid.size() * grid.size();
        for ( int i = 1 ; i <= size ; i ++ ) {
            if ( mpp.find(i) == mpp.end() ) {
                b = i;
                break;
            }
        }
        return {a,b};
    }
};