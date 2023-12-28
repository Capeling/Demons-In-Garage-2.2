#include <Geode/Geode.hpp>
#include <Geode/modify/GJGarageLayer.hpp>

using namespace geode::prelude;

class $modify(GJGarageLayer) {
	bool init() {
		if(!GJGarageLayer::init())
			return false;
		auto winSize = CCDirector::sharedDirector()->getWinSize();

	/* */
		auto demonIcon = CCSprite::createWithSpriteFrameName("diffIcon_06_btn_001.png");
		demonIcon->setPosition({winSize.width - 18, winSize.height - 117});
		demonIcon->setAnchorPoint({0.5, 0.5});
		demonIcon->setScale({0.4});

		CCDictionary* stats = GameStatsManager::sharedState()->m_playerStats;
		CCLabelBMFont* demonText = CCLabelBMFont::create(std::to_string(stats->valueForKey("5")->intValue()).c_str(), "bigFont.fnt");
		demonText->setPosition({demonIcon->getPositionX() - 12, as<CCNode*>(this->getChildren()->objectAtIndex(29))->getPositionY() - 15});
		demonText->setScale({0.34});
		demonText->setAnchorPoint({1, 0.5});

		this->addChild(demonIcon);
		this->addChild(demonText);

		return true;
	}
};