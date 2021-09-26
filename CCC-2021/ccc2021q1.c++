#include <iostream>

int main()
{
  int N;
  float area = 0;
  std::cin >> N;
  int *H = new int[N + 1];
  int *W = new int[N];

  for (int i = 0; i < N + 1; i++)
  {
    scanf("%d", &H[i]);
  }
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &W[i]);
  }

  for (int i = 0; i < N; i++)
  {
    area += (float(W[i]) * float((H[i]) + float(H[i + 1])) / 2);
  }
  std::cout << area;
}