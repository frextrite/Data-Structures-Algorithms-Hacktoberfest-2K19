vector<int> countingSort(vector<int> arr) {
  int max = *max_element(arr.begin(), arr.end());
  vector<int> v(100);
  for (int i = 0; i < arr.size(); i++)
    v[arr[i]] += 1;
  return v;
  // for (auto i: v) cout<<i<<" ";
}