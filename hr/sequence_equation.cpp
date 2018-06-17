vector<int> permutationEquation(vector<int> p) {
    vector<int> ans(p.size());
    for (int i = 1; i <= p.size(); i++) {
        for (int j = 1; j <= p.size(); j++) {
            if (p[j-1] == i) {
                ans[p[i-1]-1] = j;
                break;
            }
        }
    }
    return ans;
}
