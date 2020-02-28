#include <iostream>
#include <algorithm>

int height(int n) {
	int maxi, son;
	std::cin >> son;
	if (son == 0) return n;
	for (int i = 0; i < son; ++i)
		maxi = std::max(maxi, height(n + 1));
	return maxi;
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cout << height(1) << std::endl;
	return 0;
}