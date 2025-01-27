#include "Settings.hpp"

int Settings::defaultPct() {
	return Mod::get()->getSettingValue<int>("default-pct");
}

std::string Settings::defaultWebhook() {
	return Mod::get()->getSettingValue<std::string>("default-webhook");
}