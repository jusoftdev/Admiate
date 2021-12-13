#include "EasySock.hpp"
#include <regex>
#include "Thread_Pool.hpp"

class Network_Scan {
public:
	string root_ip;
	vector<string> devices;
	Thread_Pool tp;

	Network_Scan(string root_ip) {};

	int scan(string ip) {
		for (int p{ 1 }; p < 1023; p++) {
			EasySock sock(ip, p);
			int r = sock.connect_to_target();
			if (r == 0) {
				devices.emplace_back(ip);
				return(0);
			}
			sock.clean_up();
		}
		return(1);
	}

	vector<string> search_for_devices() {
		for (int i{ 0 }; i < 256; i++) {
			string ip = regex_replace(root_ip, regex(".0"), "." + to_string(i));
			tp.start_thread(scan, ip);
			int r = scan(ip);
		}
		tp.wait_for_pool();
		return(devices);
	}


};