int hourSum(vector<vector<int>> &m, int r_start, int c_start) {
    int sum = 0;
    for (int r = r_start; r < r_start + 3; r++) {
        for (int c = c_start; c < c_start +3; c++) {
            sum += m[r][c];
        }
    }
    sum -= m[r_start+1][c_start];
    sum -= m[r_start+1][c_start+2];
    return sum;
}

int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    int max_sum;
    for (int c = 0; c < arr[0].size()-2; c++) {
        for (int r = 0; r < arr.size()-2; r++) {
            int new_sum = hourSum(arr, r, c);
            if (r == 0 && c == 0){
                max_sum = new_sum;
            }
            if (new_sum > max_sum) {
                max_sum = new_sum;
            }
        }
    }
    cout << max_sum;
    return 0;
}
