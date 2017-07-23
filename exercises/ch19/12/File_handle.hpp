#ifndef PZwan_File_handle
#define PZwan_File_handle

#include <fstream>

namespace File_handle {

class File_handle {
	string fname;
	ifstream ifs;
public:
	File_handle(const string& n);
	~File_handle();

	ifstream& fs() { return ifs; };
};

File_handle::File_handle(const string& n) :
	ifs{n}
{
	cout << "\tconstructor\n";
	if (!ifs)
		throw runtime_error("couldn't open file: "+n);
}

File_handle::~File_handle()
{
	cout << "\tdestructor\n";
	ifs.close();
}

} // File_handle

#endif
