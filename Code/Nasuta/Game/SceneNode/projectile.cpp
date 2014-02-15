#include "projectile.h"

#include "../../Engine/utility.h"
#include "../../Engine/Resource/resourceHolder.h"
#include "../../Engine/SceneNode/emitterNode.h"

#include "../../Third Party/TinyXML2/tinyxml2.h"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <cassert>
#include <cmath>


Projectile::Projectile(Type type, const TextureHolder& textures)
: Entity(1)
, mType(type)
, mSprite()
, mTargetDirection()
{
	readXML(mType);
	mSprite.setTexture(textures.get(mData.texture));
	mSprite.setTextureRect(mData.textureRect);

	centerOrigin(mSprite);

	// Add particle system for missiles
	if (isGuided())
	{
		std::unique_ptr<EmitterNode> smoke(new EmitterNode(Particle::Smoke));
		smoke->setPosition(0.f, getBoundingRect().height / 2.f);
		attachChild(std::move(smoke));

		std::unique_ptr<EmitterNode> propellant(new EmitterNode(Particle::Propellant));
		propellant->setPosition(0.f, getBoundingRect().height / 2.f);
		attachChild(std::move(propellant));

	}
}

void Projectile::guideTowards(sf::Vector2f position)
{
	assert(isGuided());
	mTargetDirection = unitVector(position - getWorldPosition());
}

bool Projectile::isGuided() const
{
	return mType == Missile;
}

void Projectile::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	if (isGuided())
	{
		const float approachRate = 200.f;

		sf::Vector2f newVelocity = unitVector(approachRate * dt.asSeconds() * mTargetDirection + getVelocity());
		newVelocity *= getMaxSpeed();
		float angle = std::atan2(newVelocity.y, newVelocity.x);

		setRotation(toDegree(angle) + 90.f);
		setVelocity(newVelocity);
	}

	Entity::updateCurrent(dt, commands);
}

void Projectile::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

unsigned int Projectile::getCategory() const
{
	if (mType == EnemyBullet)
		return Category::EnemyProjectile;
	else
		return Category::AlliedProjectile;
}

sf::FloatRect Projectile::getBoundingRect() const
{
	return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}

float Projectile::getMaxSpeed() const
{
	return mData.speed;
}

int Projectile::getDamage() const
{
	return mData.damage;
}

std::string Projectile::toString(Type type) const
{
	std::string ret;
	switch (type)
	{
		case 0:
			ret = "AlliedBullet";
			break;

		case 1:
			ret = "EnemyBullet";
			break;

		case 2:
			ret = "Missile";
			break;
	}

	// ALW - Will assert if enum does not correspond to a string
	assert(ret.compare("") != 0);
	return ret;
}

Textures::ID Projectile::toTexture(const std::string& str) const
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

void Projectile::readXML(Type type)
{
	const std::string filename("Configs/Projectiles.xml");
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

	mData.damage           = element->FirstChildElement("damage")->IntAttribute("attribute");
	mData.speed            = element->FirstChildElement("speed")->FloatAttribute("attribute");
	mData.texture          = toTexture(element->FirstChildElement("texture")->Attribute("attribute"));

	const int left         = element->FirstChildElement("textureRect")->IntAttribute("attribute0");
	const int top          = element->FirstChildElement("textureRect")->IntAttribute("attribute1");
	const int width        = element->FirstChildElement("textureRect")->IntAttribute("attribute2");
	const int height       = element->FirstChildElement("textureRect")->IntAttribute("attribute3");
	mData.textureRect      = sf::IntRect(left, top, width, height);
}
