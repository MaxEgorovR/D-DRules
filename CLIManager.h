#pragma once
#include "AccountManager.h"
#include "ResponseManager.h"

class CLIManager {
public:
	void run() {
		std::string choise;
		while (true) {
			std::cout << "1 - Adventuring\n2 - Appendix\n3 - Combat\n4 - Equipment\n5 - Spellcasting\n6 - Using ability scores\n7 - Clear data\n8 - Info\nElse - Exit\n";
			std::cin >> choise;
			if (choise == "1") {
				this->adventuring_rules();
			}
			else if (choise == "2") {
				this->appendix_rules();
			}
			else if (choise == "3") {
				this->combat_rules();
			}
			else if (choise == "4") {
				this->equipment_rules();
			}
			else if (choise == "5") {
				this->spellcasting_rules();
			}
			else if (choise == "6") {
				this->using_ability_scores_rules();
			}
			else if (choise == "7") {
				this->clear();
			}
			else if (choise == "8") {
				std::cout << a_manager->select("*");
			}
			else {
				break;
			}
		}
	}

private:
	std::shared_ptr<AccountManager> a_manager = std::make_shared<AccountManager>();

	std::shared_ptr<ResponseManager> r_manager = std::make_shared<ResponseManager>();

	void adventuring_rules() {
		if (!a_manager->search("adventuring_rules", "")) {
			nlohmann::json data1 = r_manager->castom_response("https://www.dnd5eapi.co/api/rules/adventuring");
			nlohmann::json data2;
			std::cout << "Adventuring rules:\n";
			for (int i = 0;i < data1["subsections"].size();i++) {
				data2 = r_manager->castom_response("https://www.dnd5eapi.co" + std::string(data1["subsections"][i]["url"]));
				std::cout << std::string(data2["desc"]);
				a_manager->add_adventuring_rules(data2["desc"]);
			}
		}
		else {
			
			std::cout << std::string(a_manager->select("adventuring_rules")) << std::endl;
		}
	}

	void appendix_rules() {
		if (!a_manager->search("appendix_rules", "")) {
			nlohmann::json data1 = r_manager->castom_response("https://www.dnd5eapi.co/api/rules/appendix");

			nlohmann::json data2;
			std::cout << "Appendix rules:\n";
			for (int i = 0;i < data1["subsections"].size();i++) {
				data2 = r_manager->castom_response("https://www.dnd5eapi.co" + std::string(data1["subsections"][i]["url"]));
				std::cout << std::string(data2["desc"]);
				a_manager->add_adventuring_rules(data2["desc"]);
			}
		}
		else {
			std::cout << std::string(a_manager->select("appendix_rules")) << std::endl;
		}
	}

	void combat_rules() {
		if (!a_manager->search("combat_rules", "")) {
			nlohmann::json data1 = r_manager->castom_response("https://www.dnd5eapi.co/api/rules/combat");

			nlohmann::json data2;
			std::cout << "Combat rules:\n";
			for (int i = 0; i < data1["subsections"].size(); i++) {
				data2 = r_manager->castom_response("https://www.dnd5eapi.co" + data1["subsections"][i]["url"]);
				std::cout << data1["subsections"][i]["url"];
				std::cout << std::string(data2["desc"]);
				a_manager->add_combat_rules(data2["desc"]);
			}
		}
		else {
			std::cout << std::string(a_manager->select("combat_rules")) << std::endl;
		}
	}

	void equipment_rules() {
		if (!a_manager->search("equipment_rules", "")) {
			nlohmann::json data1 = r_manager->castom_response("https://www.dnd5eapi.co/api/rules/equipment");

			nlohmann::json data2;
			std::cout << "Equipment rules:\n";
			for (int i = 0;i < data1["subsections"].size();i++) {
				data2 = r_manager->castom_response("https://www.dnd5eapi.co" + data1["subsections"][i]["url"]);
				std::cout << std::string(data2["desc"]);
				a_manager->add_equipment_rules(data2["desc"]);
			}
		}
		else {
			std::cout << std::string(a_manager->select("equipment_rules")) << std::endl;
		}
	}

	void spellcasting_rules() {
		if (!a_manager->search("spellcasting_rules", "")) {
			nlohmann::json data1 = r_manager->castom_response("https://www.dnd5eapi.co/api/rules/spellcasting");

			nlohmann::json data2;
			std::cout << "Spellcasting rules:\n";
			for (int i = 0;i < data1["subsections"].size();i++) {
				data2 = r_manager->castom_response("https://www.dnd5eapi.co" + data1["subsections"][i]["url"]);
				std::cout << std::string(data2["desc"]);
				a_manager->add_spellcasting_rules(data2["desc"]);
			}
		}
		else {
			std::cout << std::string(a_manager->select("spellcasting_rules")) << std::endl;
		}
	}

	void using_ability_scores_rules() {
		if (!a_manager->search("using_ability_scores_rules", "")) {
			nlohmann::json data1 = r_manager->castom_response("https://www.dnd5eapi.co/api/rules/using-ability-scores");

			nlohmann::json data2;
			std::cout << "Using ability scores rules:\n";
			for (int i = 0;i < data1["subsections"].size();i++) {
				data2 = r_manager->castom_response("https://www.dnd5eapi.co"+data1["subsections"][i]["url"]);
				std::cout << std::string(data2["desc"]);
				a_manager->add_using_ability_scores_rules(data2["desc"]);
			}
		}
		else {
			std::cout << std::string(a_manager->select("using_ability_scores_rules")) << std::endl;
		}
	}

	void clear() {
		a_manager->clear();
	}
};