#include "Webhook.hpp";
#include "Settings.hpp";

// Statics
std::string url = Settings::defaultWebhook();

web::WebTask Webhook::sendDeath() {
	web::WebRequest req = web::WebRequest();

	matjson::Value myjson = matjson::parse(R"(
	{
		"author": {
			"name": "Getting Far"
		},
			"title" : "**Glames** just died at 78% on **__Aerial Gleam__ by EndLevel**",
			"description" : "**Pointercrate: #65**",
			"thumbnail" : {
			"url": "https://cdn.discordapp.com/attachments/741003526502613122/1333270508061593701/difficulty.png?ex=6798486c&is=6796f6ec&hm=c878d02a2e27afcecb866e7935dde526ca05450b574dde63223bb49e5ea15dda&"
		}
	})").unwrap();
	
	req.bodyJSON(myjson);

	req.header("Content-Type", "application/json");

	return req.post(url);
}