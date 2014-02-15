#include "pickup.h"
#include "aircraft.h"

#include "../../Engine/utility.h"
#include "../../Engine/Command/category.h"
#include "../../Engine/Command/commandQueue.h"
#include "../../Engine/Resource/resourceHolder.h"

#include "../../Third Party/TinyXML2/tinyxml2.h"

#include <SFML/Graphics/RenderTarget.hpp>


// For std::bind() placeholders _1, _2, ...
using namespace std::placeholders;

Pickup::Pickup(Type type, const TextureHolder& textures)
: Entity(1)
, mType(type)
, mSprite()
{
	readXML(mType);
	mSprite.setTexture(textures.get(mData.texture));
	mSprite.setTextureRect(mData.textureRect);

	centerOrigin(mSprite);
}

unsigned int Pickup::getCategory() const
{
	return Category::Pickup;
}

sf::FloatRect Pickup::getBoundingRect() const
{
	return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}

void Pickup::apply(Aircraft& player) const
{
	mData.action(player);
}

void Pickup::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

std::string Pickup::toString(Type type) const
{
	std::string ret;
	switch (type)
	{
		case 0:
			ret = "HealthRefill";
			break;

		case 1:
			ret = "MissileRefill";
			break;

		case 2:
			ret = "FireSpread";
			break;

		case 3:
			ret = "FireRate";
			break;
	}

	// ALW - Will assert if enum does not correspond to a string
	assert(ret.compare("") != 0);
	return ret;
}

std::function<void(Aircraft&)> Pickup::toAction(const std::string& str) const
{
	std::function<void(Aircraft&)> ret;
	bool success = false;
	if (str == "repair")
	{
		ret = [] (Aircraft& a) { a.repair(25); };
		success = true;
	}
	else if (str == "collectMissiles")
	{
		ret = std::bind(&Aircraft::collectMissiles, _1, 3);
		success = true;
	}
	else if (str == "increaseSpread")
	{
		ret = std::bind(&Aircraft::increaseSpread, _1);
		success = true;
	}
	else if (str == "increaseFireRate")
	{
		ret = std::bind(&Aircraft::increaseFireRate, _1);
		success = true;
	}

	assert(success);
	return ret;
}

Textures::ID Pickup::toTexture(const std::string& str) const
{
	Textures::ID ret;
	bool success = false;
	if (str == "Textures::Entities")
	{
		ret = Textures::Entities;
		success = true;
	}

	// ALW - Will assert if str does not correspond to a Textures::ID
	assert(success);
	return ret;
}

void Pickup::readXML(Type type)
{
	const std::string filename("Configs/Pickups.xml");
	tinyxml2::XMLDocument config;
	if (config.LoadFile(filename.c_str()) != tinyxml2::XML_NO_ERROR)
	{
		throw std::runtime_error("TinyXML2 - Failed to load " + filename);
	}

	const tinyxml2::XMLElement* element = config.FirstChildElement()->FirstChildElement(toString(type).c_str());
	if (!element)
	{
		// ALW - Will assert if the type's element does not exist
		assert(element);
	}

	mData.action           = toAction(element->FirstChildElement("action")->Attribute("attribute"));
	mData.texture          = toTexture(element->FirstChildElement("texture")->Attribute("attribute"));

	const int left         = element->FirstChildElement("textureRect")->IntAttribute("attribute0");
	const int top          = element->FirstChildElement("textureRect")->IntAttribute("attribute1");
	const int width        = element->FirstChildElement("textureRect")->IntAttribute("attribute2");
	const int height       = element->FirstChildElement("textureRect")->IntAttribute("attribute3");
	mData.textureRect      = sf::IntRect(left, top, width, height);
}
