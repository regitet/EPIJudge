#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> PlusOne(vector<int> A) {
  // TODO - you fill in here.
	int carry = 1;
	for (int i=A.size()-1; i>=0; i--) {
		int sum = carry + A[i];
		A[i]	= sum % 10;
		carry	= sum / 10;
	}
	if (carry != 0)
		A.insert(A.begin(), carry);
	return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "int_as_array_increment.cc",
                         "int_as_array_increment.tsv", &PlusOne,
                         DefaultComparator{}, param_names);
}
