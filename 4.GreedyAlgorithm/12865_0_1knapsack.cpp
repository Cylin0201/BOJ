//백준 12865번: 평범한 배낭 (23-11-01)
//첫 줄에 물품의 수 N(1 ≤ N ≤ 100)과 준서가 버틸 수 있는 무게 K(1 ≤ K ≤ 100, 000)가 주어진다.
//두 번째 줄부터 N개의 줄에 거쳐 각 물건의 무게 W(1 ≤ W ≤ 100, 000)와 해당 물건의 가치 V(0 ≤ V ≤ 1, 000)가 주어진다.
//
//입력으로 주어지는 모든 수는 정수이다.

#include <iostream>
#include <vector>

void knapsack() {
    int N, K; std::cin >> N >> K;
    std::vector<std::vector<int>> P(N + 1, std::vector<int>(K + 1));
    std::vector<int> weight;
    std::vector<int> value;
    weight.push_back(-1);
    value.push_back(-1);

    for (int i = 0; i < N; i++) {
        int w, v;
        std::cin >> w >> v;
        weight.push_back(w);
        value.push_back(v);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            //if (i == 0) P[i][k] = 0; // 가방의 무게 한도가 0일 경우 초기화 과정. (없어도 됨)
            if (weight[i] <= j) P[i][j] = std::max(P[i - 1][j], P[i - 1][j - weight[i]] + value[i]);
            else P[i][j] = P[i - 1][j];
        }
    }

    //for (int col = 1; col <= N; col++) {
    //    for (int row = 1; row <= K; row++)
    //        std::cout << P[col][row] << " ";
    //    std::cout << "\n";
    //}
    std::cout << P[N][K] << "\n";
}

int main() {
    knapsack();
}