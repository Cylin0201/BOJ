#include <iostream>
#include <vector>
int cnt = 0;
int n;
std::vector<int> col(20);
bool promising(int i);
void queen(int i);

int main() {
    std::cin >> n;
    queen(0);
    std::cout << cnt << "\n";
}

void queen(int i) {
    if (promising(i)) {
        if (i == n) {
            /*for (int idx = 1; idx <= n; idx++)
                std::cout << col[idx] << " ";
            std::cout << "\n";*/
            cnt++;
        }
                    
        else {
            for (int j = 1; j <= n; j++) {
                col[i + 1] = j;
                queen(i + 1);
            }
        }
    }
}

bool promising(int i) {
    bool is_promising = true;
    int k = 1;
    while (k < i && is_promising) {
        if (col[i] == col[k] || abs(col[i] - col[k]) == i - k)
            is_promising = false;
        k++;
    }
    return is_promising;
}