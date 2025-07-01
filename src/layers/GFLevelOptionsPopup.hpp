#include "../utils/Settings.hpp"

using namespace geode::prelude;


class GFLevelOptionsPopup : public geode::Popup<> {
protected:
	bool setup() override;
	void onClose(CCObject*) override;
public:
	static GFLevelOptionsPopup* create();
};
