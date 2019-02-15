#include <fstream> // for file I/O
#include <sstream> // for string I/O
#include <iostream>
#include <string>
using namespace std;

int main() {
	// cin and cout are "streams": they represent an arbitrary source
	// of input or output that we can read or write data of different types
	// to. They read and write to the console, naturally, but there are 
	// streams that read and write to other sources. Most streams in the
	// standard library follow similar patterns.

	// ifstream: input file stream.
	ifstream babyNames{ "babynames.txt" };
	// The file path is relative to where the executable is running.
	
	string name;
	while (!babyNames.eof()) {
		//babyNames >> name;
		getline(babyNames, name);
		cout << name << endl;
	}
	babyNames.close(); // always close the file when done.

	// ofstream: output file stream.
	ofstream output{ "output.txt" };
	output << "The final name was " << name << endl;
	output.close();

	// Instead of the console or a file, we can also do I/O over strings.
	string toParse = "12345 6789 3.14 Neal";
	istringstream parser{ toParse };
	int value1, value2;
	double value3;
	parser >> value1 >> value2 >> value3 >> name;
	
	// This is how we do the equivalent of "Integer.parseInt":
	istringstream{ "2000" } >> value1;
	// Creates a temporary istringstream, uses it to read an int from "2000",
	// then destroys the stream.

	// There are standard library functions to convert fundamental types
	// to strings:
	string x = std::to_string(value1);
	// But we can also use a ostringstream to "build" a string piece by piece.
	ostringstream os;
	os << value1 << " " << value2 << " " << value3;
	// We extract the built string with .str()
	string fin = os.str();
	cout << fin << endl;



	// SUMMARY:
	// ifstream and ofstream: use to read/write text files.
	// istringstream: use to parse data from strings.
	// ostringstream: use to build up a string from pieces incrementally.
}