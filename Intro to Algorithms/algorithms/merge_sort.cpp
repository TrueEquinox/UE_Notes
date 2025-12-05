#include <iostream>
#include <vector>

void merge_sort(std::vector<int>& a, int p, int r);
void merge(std::vector<int>& a, int p, int q, int r);

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Usage: ./merge_sort num1 num2 num3 ...\n";
		return 1;
	}

	std::vector<int> a;

	for (int i = 1; i < argc; i++)
		a.push_back(std::stoi(argv[i]));

	merge_sort(a, 0, a.size()-1);

	for (int n : a)
		std::cout << n << " ";
	std::cout << std::endl;

	return 0;
}

void merge_sort(std::vector<int>& a, int p, int r) {
	if (p >= r) return;

	int q = (p + r) / 2;
	
	merge_sort(a, p, q);
	merge_sort(a, q+1, r);

	merge(a, p, q, r);
}

void merge(std::vector<int>& a, int p, int q, int r) {
	int left = q - p + 1;
	int right = r - q;
	
	std::vector<int> vec_left(left);
	std::vector<int> vec_right(right);

	for (int i = 0; i < left; i++) {
		vec_left[i] = a[p + i];
	}

	for (int j = 0; j < right; j++) {
		vec_right[j] = a[q + j + 1];
	}

	int i = 0, j = 0;
	int k = p;

	while (i < left && j < right) {
		if(vec_left[i] <= vec_right[j]) {
			a[k] = vec_left[i];
			i++;
		} else {
			a[k] = vec_right[j];
			j++;
		}
		k++;
	}

	while (i < left) {
		a[k] = vec_left[i];
		i++;
		k++;
	}

	while (j < right) {
		a[k] = vec_right[j];
		j++;
		k++;
	}
}
