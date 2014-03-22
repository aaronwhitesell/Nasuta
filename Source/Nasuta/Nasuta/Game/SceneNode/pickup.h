#ifndef PICKUP_H
#define PICKUP_H

#include "../../Engine/Command/command.h"
#include "../../Engine/SceneNode/entity.h"

#include "Trambo/Resources/resourceHolder.h"

#include <SFML/Graphics/Sprite.hpp>


class Aircraft;

class Pickup : public Entity
{
public:
	enum Type
	{
		HealthRefill,
		MissileRefill,
		FireSpread,
		FireRate,
		TypeCount
	};


public:
							Pickup(Type type, const trmb::TextureHolder& textures);

	virtual unsigned int	getCategory() const;
	virtual sf::FloatRect	getBoundingRect() const;

	void					apply(Aircraft& player) const;


protected:
	virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


private:
	std::string				       toString(Type type) const;
	std::function<void(Aircraft&)> toAction(const std::string& str) const;
	Textures::ID				   toTexture(const std::string& str) const;
	void					       readXML(Type type);


private:
	struct Data
	{
		std::function<void(Aircraft&)>	action;
		Textures::ID					texture;
		sf::IntRect						textureRect;
	};


private:
	Type					mType;
	sf::Sprite				mSprite;

	Data					mData;
};

#endif
