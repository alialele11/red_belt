#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y) out << (x) << endl << (y) << endl

int main() {
int a=2,b=3;
if(true)
	PRINT_VALUES(std::cout,a,b);
else
	PRINT_VALUES(std::cout,a,b);
}
