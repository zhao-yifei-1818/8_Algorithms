void merge(std::vector<Region>& vec, int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Create temporary vectors
  std::vector<Region> L(n1), R(n2);

  // Copy data to temp vectors L[] and R[]
  for (int i = 0; i < n1; i++)
    L[i] = vec[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = vec[mid + 1 + j];

  // Merge the temp vectors back into vec[left..right]
  int i = 0;
  int j = 0;
  int k = left;
  while (i < n1 && j < n2) {
    if (L[i].city <= R[j].city) {
      vec[k] = L[i];
      i++;
    } else {
      vec[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of L[], if there are any
  while (i < n1) {
    vec[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of R[], if there are any
  while (j < n2) {
    vec[k] = R[j];
    j++;
    k++;
  }
}
