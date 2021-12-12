#include "EasySock.hpp"
#include <regex>

class Network_Scan {
public:
	string root_ip;

	Network_Scan(string root_ip) {
		string root_ip = root_ip;
	};

	vector<string> scan() {
		vector<string> devices;
		for (int i{ 0 }; i < 256; i++) {
			string ip = regex_replace(root_ip, regex(".0"), "." + to_string(i));
			for (int p{ 1 }; p < 1023; p++) {
				EasySock sock(ip, p);
				int r = sock.connect_to_target();
				if (r == 0) {
					devices.emplace_back(ip);
					p = 1023;
				}
			}
		}
		return(devices);
	}


};