#ifndef PARTICLE_NODE_H
#define PARTICLE_NODE_H

#include "sceneNode.h"
#include "../Graphics/particle.h"

#include "Trambo/Resources/resourceHolder.h"

#include <SFML/Graphics/VertexArray.hpp>

#include <deque>


class ParticleNode : public SceneNode
{
public:
							ParticleNode(Particle::Type type, const trmb::TextureHolder& textures);

	void					addParticle(sf::Vector2f position);
	Particle::Type			getParticleType() const;
	virtual unsigned int	getCategory() const;


private:
	virtual void			updateCurrent(sf::Time dt, CommandQueue& commands);
	virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	void					addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color& color) const;
	void					computeVertices() const;

	std::string		        toString(Particle::Type type) const;
	void					readXML(Particle::Type type);


private:
	struct Data
	{
		sf::Color			color;
		sf::Time			lifetime;
	};

private:
	std::deque<Particle>	mParticles;
	const sf::Texture&		mTexture;
	Particle::Type			mType;

	mutable sf::VertexArray mVertexArray;
	mutable bool			mNeedsVertexUpdate;

	Data					mData;
};

#endif
