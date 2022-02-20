/*
1. sort by ending.
2 . keep track of previous end
3. if the next start > previous end, remove element

example:
arr : [[1,2],[2,3],[3,4],[1,3]]
sorted by end: [[1, 2], [2, 3], [1, 3], [3, 4]]

intervals with lowest end will allow us to fit more intervals
if the previous end is more than the next start, remove it.
because this means that the interval has a smaller start than previous, but a bigger end which means that its interval is bigger and hence we should remove it

*/



//custom comperator
bool mycomperator(vector<int> &a,vector<int> &b) {
	return a[1]<b[1];
}

class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
		if(intervals.size()==0) 
			return 0;       

		sort(intervals.begin(),intervals.end(),mycomperator); 

		int prev = 0;
        	int erase = 0;
        
		for (int i = 1; i < intervals.size(); ++i) {

			if (intervals[prev][1] > intervals[i][0])
				erase++;
			else 
				prev = i;
		}
        
		return erase;
	}
};
