#ifndef SOUND_NODE_H
#define SOUND_NODE_H

#include "sceneNode.h"

#include <SFML/System/Vector2.hpp>


namespace trmb
{
	class SoundPlayer;
}

namespace SoundEffects
{
	enum class ID;
}

class SoundNode : public SceneNode
{
public:
	explicit				SoundNode(trmb::SoundPlayer& player);
	
	void					playSound(SoundEffects::ID sound, sf::Vector2f position);
	virtual unsigned int	getCategory() const;


private:
	trmb::SoundPlayer&		mSounds;
};

#endif
