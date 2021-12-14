#include<Windows.h>
#include<string>
#include <sstream>
#include <fstream>

using namespace std;


class GUI_API {
public:
	const string path_to_exec;
	string exchange_data;
	const string* ptr_ex = &exchange_data;

	GUI_API(const string path_to_exec) {
		if (path_exists(path_to_exec)) {
			int res = connect_to_gui(path_to_exec);
		}
		else {
			close(-1);
		}
	}

	char* string_to_chara(string str) {
		char* c = const_cast<char*>(str.c_str());
		return(c);
	}

	int connect_to_gui(const string path_to_exec) {
		ostringstream oss;
		oss << ptr_ex;
		ostringstream soss;
		soss << "start " << path_to_exec << oss.str();
		char* command = string_to_chara(soss.str());
		system(command);
		return(0);
	}

	int send_to_gui(const string data) {
		exchange_data = data;
		return(0);
	}

	string get_from_gui() {
		return(exchange_data);
	}

	bool path_exists(const string path) {
		ifstream file(path);
		if (file.is_open()) {
			file.close();
			return(true);
		}
		else {
			return(false);
		}
	}

	void close(int stat=0) {
		exit(stat);
	}
};