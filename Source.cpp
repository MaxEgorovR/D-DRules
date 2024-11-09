#include <iostream>
#include <string>
#include <vector>
#include <sqlite_modern_cpp.h>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
#include "CLIManager.h"

//https://5e-bits.github.io/docs/api/get-a-rule-by-index?clckid=90f2efc1


int main() {
	std::shared_ptr<CLIManager> manager = std::make_shared<CLIManager>();
	manager->run();
}