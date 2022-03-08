#include <iostream>
#include <fstream>
#include <string>

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

int error(void)
{
    std::cout << "Invalid Arguments: --> ./orthodox CLASS_NAME HEADER_NAME" << std::endl;
    return 1;
}

int main(int argc, char **argv)
{
	if (argc != 3)
		return error();
	std::string raw = "#ifndef HEAD\n# define HEAD\n\n#include <iostream>\n\nclass NAME\n{\nprotected:\n\nprivate:\n\npublic:\n    NAME(void);\n    NAME(const NAME &instance);\n    ~NAME();\n    NAME & operator = (const NAME &instance);\n\n};\n\nstd::ostream &	operator<<( std::ostream & ostr, NAME const & instance);\n\n#endif";
	std::string filter = ReplaceAll(raw, "NAME", argv[1]);
	std::string filter2 = ReplaceAll(filter, "HEAD", argv[2]);
	std::ofstream out(std::string(argv[1]) + ".hpp");
    out << filter2;
    out.close();

    std::string raw_cpp = "#include \"NAME.hpp\"\n\nNAME::NAME(void){\n\n}\n\nNAME::NAME(const NAME &instance){\n    *this = instance;\n}\n\nNAME::~NAME(){\n\n}\n\nNAME & NAME::operator = (const NAME &instance){\n    //this->Attributes = instance.attributes\n    return (*this);\n}";
	std::string filter_cpp = ReplaceAll(raw_cpp, "NAME", argv[1]);
	std::ofstream out_cpp(std::string(argv[1]) + ".cpp");
    out_cpp << filter_cpp;
    out_cpp.close();

}
