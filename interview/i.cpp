if (hist[str[i]].count == 0) {
  ans.push_back(str[i]);
} else {
  if (hist[str[i]] <= i - history_size - skip_count) {
    ans.push_back(str[i]);
  }
}
hist[str[i]] = i;


if (hist[str[i]].count == 0) {
  ans.push_back(str[i]);
  hist[str[i]] = ans.length();
} else {
  if (hist[str[i]] <= ans.length() - history_size) {
    ans.push_back(str[i]);
    hist[str[i]] = ans.lenght();
  }
}
