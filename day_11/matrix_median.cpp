int lessThanEqualTo(vector<int>& v, int key) {
  int lo = 0;
  int hi = v.size() - 1;
  while (lo <= hi) {
    int midi = (lo + hi) / 2;
    if (v[midi] > key) {
      hi = midi - 1;
    }
    else {
      lo = midi + 1;
    }
  }
  return lo;

}

int getMedian(vector<vector<int>> &matrix)
{
  int halfsize = ((matrix.size() * matrix[0].size()) / 2) + 1;
  int lo = 1; int hi = 1e5;
  int mid = (lo + hi) / 2;

  while (lo <= hi) {
    mid = (lo + hi) / 2;
    int toleft   = 0;

    for (int i = 0; i < matrix.size(); i++) {
      int ind = lessThanEqualTo(matrix[i], mid);
      toleft += ind;
    }

    if (toleft >= halfsize) {
      hi = mid - 1;
    }
    else if (toleft < halfsize) {
      lo = mid + 1;
    }
  }
  return lo;
}
