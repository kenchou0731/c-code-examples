#include <iostream>
#include <string>
#include <map>

int main() {
	std::map<int, std::string> studentMap = {
		{1, "Tom"},
		{3, "John"},
		{2, "Jack"}
	};
	studentMap[5] = "Tiffany";
	studentMap[4] = "Ann";

	for (const auto& s : studentMap) {
		std::cout << "id: " << s.first << ", name: " << s.second << "\n";
	}
	return 0;
}
