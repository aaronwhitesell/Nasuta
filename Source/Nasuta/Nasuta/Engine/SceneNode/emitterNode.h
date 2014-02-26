#ifndef EMITTER_NODE_H
#define EMITTER_NODE_H

#include "sceneNode.h"
#include "../Graphics/particle.h"


class ParticleNode;

class EmitterNode : public SceneNode
{
public:
	explicit				EmitterNode(Particle::Type type);


private:
	virtual void			updateCurrent(sf::Time dt, CommandQueue& commands);

	void					emitParticles(sf::Time dt);


private:
	sf::Time				mAccumulatedTime;
	Particle::Type			mType;
	ParticleNode*			mParticleSystem;
};

#endif
