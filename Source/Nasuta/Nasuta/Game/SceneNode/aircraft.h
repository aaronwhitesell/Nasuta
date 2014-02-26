#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "projectile.h"

#include "../../Engine/Command/command.h"
#include "../../Engine/Graphics/animation.h"
#include "../../Engine/Resource/resourceIdentifiers.h"
#include "../../Engine/SceneNode/entity.h"
#include "../../Engine/SceneNode/textNode.h"

#include <SFML/Graphics/Sprite.hpp>


class Aircraft : public Entity // inherits SceneNode indirectly 
{
public:
	enum Type
	{
		Eagle,
		Raptor,
		Avenger,
		TypeCount
	};


public:
							Aircraft(Type type, const TextureHolder& textures, const FontHolder& fonts);

	virtual void			updateCurrent(sf::Time dt, CommandQueue& commands);
	virtual unsigned int	getCategory() const;
	virtual sf::FloatRect	getBoundingRect() const;
	virtual void			remove();
	virtual bool			isMarkedForRemoval() const;
	bool					isAllied() const;
	float					getMaxSpeed() const;

	void					increaseFireRate();
	void					increaseSpread();
	void					collectMissiles(unsigned int count);

	void					fire();
	void					launchMissile();
	void					playLocalSound(CommandQueue& commands, SoundEffect::ID effect);


private:
	virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void					updateMovementPattern(sf::Time dt);
	void					checkPickupDrop(CommandQueue& commands);
	void					checkProjectileLaunch(sf::Time dt, CommandQueue& commands);

	void					createBullets(SceneNode& node, const TextureHolder& textures) const;
	void					createProjectile(SceneNode& node, Projectile::Type type, float xOffset, float yOffset, const TextureHolder& textures) const;
	void					createPickup(SceneNode& node, const TextureHolder& textures) const;

	void					updateTexts();
	void					updateRollAnimation();

	std::string				toString(Type type) const;
	Textures::ID			toTexture(const std::string& str) const;
	void					readXML(Type type);


private:
	struct Direction
	{
		Direction(float angle, float distance)
		: angle(angle)
		, distance(distance)
		{
		}

		float angle;
		float distance;
	};

	struct Data
	{
		int								hitpoints;
		float							speed;
		Textures::ID					texture;
		sf::IntRect						textureRect;
		sf::Time						fireInterval;
		std::vector<Direction>			directions;
		bool							hasRollAnimation;
	};


private:
	Type					mType;
	sf::Sprite				mSprite;
	Animation				mExplosion;
	Command					mFireCommand;
	Command					mMissileCommand;
	sf::Time				mFireCountdown;
	bool					mIsFiring;
	bool					mIsLaunchingMissile;
	bool 					mShowExplosion;
	bool					mPlayedExplosionSound;
	bool					mSpawnedPickup;

	int						mFireRateLevel;
	int						mSpreadLevel;
	int						mMissileAmmo;

	Command					mDropPickupCommand;
	float					mTravelledDistance;
	std::size_t				mDirectionIndex;
	TextNode*				mHealthDisplay;
	TextNode*				mMissileDisplay;

	Data					mData;
};

#endif
