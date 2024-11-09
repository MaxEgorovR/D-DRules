#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sqlite_modern_cpp.h>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>

class ResponseManager {
public:
	nlohmann::json castom_response(std::string request) {
		response = cpr::Get(cpr::Url{ request });
		if (response.status_code == 200) {
			json_response = nlohmann::json::parse(response.text);
			return json_response;
		}
		else {
			std::cout << response.error.message << std::endl;
			return nullptr;
		}
	}
private:
	nlohmann::json json_response;

	cpr::Response response;
};