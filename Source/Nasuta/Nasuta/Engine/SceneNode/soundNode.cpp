#include "soundNode.h"

#include "Trambo/Sounds/soundPlayer.h"


SoundNode::SoundNode(trmb::SoundPlayer& player)
: SceneNode()
, mSounds(player)
{
}

void SoundNode::playSound(SoundEffects::ID sound, sf::Vector2f position)
{
	mSounds.play(sound, position);
}

unsigned int SoundNode::getCategory() const
{
	return Category::SoundEffect;
}