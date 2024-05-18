int findMedian(vector<int> arr) {
int n = arr.size();
int l = 0;
int r = n-1;
sort(arr.begin(), arr.end());
int m = l+(r-l)/2;

return arr[m];

}