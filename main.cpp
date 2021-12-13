#include "network_scan.hpp"


int main() {
	Network_Scan netscan("192.168.178.0");
	vector<string>devices = netscan.search_for_devices();
	for (int i{ 0 }; i < sizeof(devices); i++) {
		cout << devices[i] << endl;
	}
}