#include <iostream>
#include <vector>
#include <string>

int main(){
	std::string str1;
	std::string str2;

	std::cin >> str1;
	std::cin >> str2;

	if (str1.size() < str2.size()){
		swap(str1, str2);
	}
   	
	int m = str1.size();
	int n = str2.size();

	std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

	int max_len = 0;
	int start = 0;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <=n; j++){
			if (str1[i -1] == str2[j - 1]){
				dp[i][j] = dp[i-1][j - 1] + 1;
			}
			else{
				dp[i][j] = 0;
			}

			if (max_len < dp[i][j]){
				max_len = dp[i][j];
				start = i - max_len;
			}
		}
	}

	std::cout << str1.substr(start, max_len);
	return 0;
}
