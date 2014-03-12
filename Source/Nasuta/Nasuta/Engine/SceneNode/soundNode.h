#ifndef SOUND_NODE_H
#define SOUND_NODE_H

#include "sceneNode.h"

#include "../../Game/Resources/resourceIdentifiers.h"


class SoundPlayer;

class SoundNode : public SceneNode
{
public:
	explicit				SoundNode(SoundPlayer& player);
	
	void					playSound(SoundEffect::ID sound, sf::Vector2f position);
	virtual unsigned int	getCategory() const;


private:
	SoundPlayer&			mSounds;
};

#endif
