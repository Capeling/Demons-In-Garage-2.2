#include <Geode/Geode.hpp>
#include <Geode/modify/GJGarageLayer.hpp>
#include <capeling.garage-stats-menu/include/StatsDisplayAPI.h>

using namespace geode::prelude;

class $modify(GJGarageLayer) {
	bool init() {
		if (!GJGarageLayer::init())
			return false;

		auto statMenu = this->getChildByID("capeling.garage-stats-menu/stats-menu");

		auto demonItem = StatsDisplayAPI::getNewItem("demons"_spr, CCSprite::createWithSpriteFrameName("GJ_demonIcon_001.png"), GameStatsManager::sharedState()->getStat("5"));

		if (statMenu) {
			statMenu->addChild(demonItem);
			statMenu->updateLayout();
		}

		return true;
	}
};