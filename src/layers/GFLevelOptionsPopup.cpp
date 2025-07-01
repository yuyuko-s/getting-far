#include "GFLevelOptionsPopup.hpp";


bool GFLevelOptionsPopup::setup() {


	this->setTitle("Getting Far Level Options");

	auto farLabel = CCLabelBMFont::create("Getting far percent", "bigFont.fnt");
	farLabel->setPosition({ 136.0f, 178.0f });
	farLabel->setScale(0.4f);


	auto farInput = TextInput::create(27, "%");

	farInput->getInputNode()->setMaxLabelLength(2);
	farInput->setCommonFilter(CommonFilter::Uint);
	farInput->setPosition({ 45.0f, 178.0f });

	m_mainLayer->addChild(farInput);
	m_mainLayer->addChild(farLabel);

	return true;
}

void GFLevelOptionsPopup::onClose(CCObject*) {
	// TODO : save per-level information somehow....
	return;
}

GFLevelOptionsPopup* GFLevelOptionsPopup::create() {
	log::debug("Creating popup");

	auto ret = new GFLevelOptionsPopup();
	if (ret->initAnchored(360.f, 240.f, "square01_001.png", { 0.f, 0.f, 94.f, 94.f })) {
		ret->autorelease();

		return ret;
	}

	delete ret;
	return nullptr;
}