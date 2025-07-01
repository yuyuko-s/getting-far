#include "Settings.hpp"

int Settings::defaultPct() {
	return Mod::get()->getSettingValue<int>("default-pct");
}

std::string Settings::defaultWebhook() {
	return Mod::get()->getSettingValue<std::string>("default-webhook");
}

std::string Settings::displayName() {
	auto dname = Mod::get()->getSettingValue<std::string>("display-name");
	auto name = GJAccountManager::get()->m_username;

	if (true) { // TODO checks if empty or whitespace
		// get the GD username if setting isn't set
		return name;
	}
	std::ostringstream display;
	display << dname << " (" << name << ")";
	return display.str();
}