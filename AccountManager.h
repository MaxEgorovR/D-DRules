#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sqlite_modern_cpp.h>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>

class AccountManager {
public:
	AccountManager()
	{
		try {
			db << "create table if not exists users ("
				"	adventuring_rules text,"
				"	appendix_rules text,"
				"	combat_rules text,"
				"	equipment_rules text,"
				"	spellcasting_rules text,"
				"	using_ability_scores_rules text"
				");";
		}
		catch (const std::exception ex) {
			std::cout << ex.what() << std::endl;
		}
	}
	
	bool add_adventuring_rules(std::string rule) {
		try {
			if (this->search("adventuring_rules", rule)) {
				db << "insert into users (adventuring_rules) "
					"values (?);"
					<< rule;
				return true;
			}
			else {
				return false;
			}
		}
		catch (const std::exception ex) {
			std::cout << ex.what() << std::endl;
		}
	}

	bool add_appendix_rules(std::string rule) {
		try {
			if (this->search("appendix_rules", rule)) {
				db << "insert into users (appendix_rules) "
					"values (?);"
					<< rule;
				return true;
			}
			else {
				return false;
			}
		}
		catch (const std::exception ex) {
			std::cout << ex.what() << std::endl;
		}
	}

	bool add_combat_rules(std::string rule) {
		try {
			if (this->search("combat_rules", rule)) {
				db << "insert into users (combat_rules) "
					"values (?);"
					<< rule;
				return true;
			}
			else {
				return false;
			}
		}
		catch (const std::exception ex) {
			std::cout << ex.what() << std::endl;
		}
	}

	bool add_equipment_rules(std::string rule) {
		try {
			if (this->search("equipment_rules", rule)) {
				db << "insert into users (equipment_rules) "
					"values (?);"
					<< rule;
				return true;
			}
			else {
				return false;
			}
		}
		catch (const std::exception ex) {
			std::cout << ex.what() << std::endl;
		}
	}

	bool add_spellcasting_rules(std::string rule) {
		try {
			if (this->search("spellcasting_rules", rule)) {
				db << "insert into users (spellcasting_rules) "
					"values (?);"
					<< rule;
				return true;
			}
			else {
				return false;
			}
		}
		catch (const std::exception ex) {
			std::cout << ex.what() << std::endl;
		}
	}

	bool add_using_ability_scores_rules(std::string rule) {
		try {
			if (this->search("using_ability_scores_rules", rule)) {
				db << "insert into users (using_ability_scores_rules) "
					"values (?);"
					<< rule;
				return true;
			}
			else {
				return false;
			}
		}
		catch (const std::exception ex) {
			std::cout << ex.what() << std::endl;
		}
	}

	bool clear() {
		try {
			if (this->search("index", "1")) {
				db << "DROP DATABASE users;";
				return true;
			}
			else {
				return false;
			}
		}
		catch (const std::exception ex) {
			std::cout << ex.what() << std::endl;
		}
	}

	bool search(std::string param, std::string data) {
		bool check = false;
		try {
			db << "select count(*) from users where ? = ?;"
				<< param
				<< data
				>> check;
		}
		catch (const std::exception ex) {
			std::cout << ex.what() << std::endl;
		}
		return check;
	}

	std::string select(std::string param) {
		std::string result;
		try {
			db << "SELECT ? FROM users;"
				<< param
				>> result;
		}
		catch (const std::exception ex) {
			std::cout << ex.what() << std::endl;
		}
		return result;
	}
private:
	sqlite::database db{ "database.db" };
};