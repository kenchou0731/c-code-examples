#include <iostream>
#include <tuple>

using namespace std;

// std::pair
// std::make_pair
// std::tie

int main(void) {
	pair<string,string> str_str;
	pair<string,int> str_int;
	pair<int,int> int_int;
/*****************************************************************************/
	pair<string,string> p1("James","Joy");
	pair<string,int> name_age("Tom",18);
	pair<string,int> name_age2(name_age);
/*****************************************************************************/
	typedef pair<string,string> Person;
	Person joy("James","Joy");
	Person proust("March","Proust");

	cout << joy.first << " " << joy.second << endl;
/*****************************************************************************/
	int a = 1, b;
	double c = 2.34, d;
	
	pair<int,double> example = make_pair(a, c);
	tie(b, d) = example;

	cout << b << " " << d << endl;
/*****************************************************************************/

	return 0;
}

